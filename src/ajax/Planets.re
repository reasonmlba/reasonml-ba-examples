type webData('a) =
  | NotAsked
  | Pending
  | Success('a)
  | Error(string);

type action =
  | Loading
  | Result(list(PlanetsData.planet))
  | Failure;

type state = {planets: webData(list(PlanetsData.planet))};

let component = ReasonReact.reducerComponent("Planets");

let make = (_children) => {
  ...component,
  initialState: () => {planets: NotAsked},
  reducer: (action, _state) =>
    switch action {
    | Loading => ReasonReact.Update({planets: Pending})
    | Result(p) => ReasonReact.Update({planets: Success(p)})
    | Failure => ReasonReact.Update({planets: Error("Error loading the planets")})
    },
  didMount: (self) => {
    let handlePlanetsLoaded = self.reduce((planets) => Result(planets));
    let handleError = self.reduce((_) => Failure);
    PlanetsData.fetchPlanets()
    |> Js.Promise.then_(
         (planets) => {
           handlePlanetsLoaded(planets);
           Js.Promise.resolve()
         }
       )
    |> Js.Promise.catch(
         (_err) => {
           handleError();
           Js.Promise.resolve()
         }
       )
    |> ignore;
    ReasonReact.Update({planets: Pending})
  },
  render: (self) => {
    let planets =
      switch self.state.planets {
      | NotAsked => ReasonReact.stringToElement("")
      | Pending => ReasonReact.stringToElement("Loading")
      | Success(planets) =>
        planets
        |> List.map(
             (p: PlanetsData.planet) =>
               <div key=p.name> (ReasonReact.stringToElement(p.name)) </div>
           )
        |> Array.of_list
        |> ReasonReact.arrayToElement
      | Error(e) => ReasonReact.stringToElement(e)
      };
    <div className="Planets-list">
      <h1> (ReasonReact.stringToElement("Reason Planets")) </h1>
      planets
    </div>
  }
};