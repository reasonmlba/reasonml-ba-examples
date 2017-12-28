let planetsApiUrl = "https://swapi.co/api/planets";

type planet = {
  name: string,
  rotationPeriod: string,
  orbitalPeriod: string,
  diameter: string,
  climate: string,
  terrain: string,
  population: string
};

module Decode = {
  let planet = (json) : planet =>
    Json.Decode.{
      name: json |> field("name", string),
      rotationPeriod: json |> field("rotation_period", string),
      orbitalPeriod: json |> field("orbital_period", string),
      diameter: json |> field("diameter", string),
      climate: json |> field("climate", string),
      terrain: json |> field("terrain", string),
      population: json |> field("terrain", string)
    };
  let planetList = (json) : list(planet) => Json.Decode.(json |> field("results", list(planet)));
};

let fetchPlanets = () =>
  Js.Promise.(
    Fetch.fetch(planetsApiUrl)
    |> then_(Fetch.Response.json)
    |> then_((json) => json |> Decode.planetList |> ((planets) => resolve(planets)))
  );