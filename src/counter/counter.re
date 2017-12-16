type action = 
  | Increment (int)
  | Decrement (int); 

type state = { count: int };

let component = ReasonReact.reducerComponent("Counter");

let make = (_children) => {
    ...component,
    initialState: () => {count: 0},
    reducer: (action, state) =>
    switch (action) {
    | Increment(value) => ReasonReact.Update({ count: state.count + value})
    | Decrement(value) => ReasonReact.Update({ count: state.count - value })
    },
    render: ({ state, reduce}) => 
    <div>
        <h1>
            (ReasonReact.stringToElement(state.count |> string_of_int))
        </h1>
        <div>
          <button onClick=(reduce((_e) => Decrement(1))) >
              (ReasonReact.stringToElement("-"))
          </button>
          <button onClick=(reduce((_e) => Increment(1))) >
              (ReasonReact.stringToElement("+"))
          </button>
        </div>
    </div>
};
