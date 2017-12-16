
module BasicComponent = {
  let component = ReasonReact.statelessComponent("Basic Component");

  let make = (~name, _children) => {
    ...component,
      render: (_) => 
        <h2>
          (ReasonReact.stringToElement("Hola " ++ name))
        </h2>
  };
};


ReactDOMRe.renderToElementWithId(<BasicComponent name="ReasonML BA" />, "index");
