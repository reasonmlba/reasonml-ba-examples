let component = ReasonReact.statelessComponent("InteropSetState");

type state = {. "libs": array(string), "editing": Js.boolean};

let filterLibs = (libs: array(string), lib: string) : array(string) =>
  Array.of_list(List.filter((item) => item != lib, Array.to_list(libs)));

let make = (~setState: state => unit, ~libs: array(string), ~editing: Js.boolean, children) => {
  ...component,
  render: (self) => {
    Js.log(editing);
    <div>
      <h1> (ReasonReact.stringToElement("ReasonReact Component")) </h1>
      (
        Js.to_bool(editing) == true ?
          <h3> (ReasonReact.stringToElement("Editando")) </h3> : ReasonReact.nullElement
      )
      <ul>
        (
          ReasonReact.arrayToElement(
            Array.map(
              (lib) =>
                <li key=lib>
                  (ReasonReact.stringToElement(lib))
                  <button
                    onClick=(
                      (e) =>
                        if (Js.to_bool(editing) == true) {
                          setState({"libs": filterLibs(libs, lib), "editing": editing})
                        }
                    )>
                    (ReasonReact.stringToElement("x"))
                  </button>
                </li>,
              libs
            )
          )
        )
      </ul>
      <button onClick=((_) => setState({"libs": libs, "editing": Js.Boolean.to_js_boolean(true)}))>
        (ReasonReact.stringToElement("Editando: true"))
      </button>
      <button
        onClick=((_) => setState({"libs": libs, "editing": Js.Boolean.to_js_boolean(false)}))>
        (ReasonReact.stringToElement("Editando: false"))
      </button>
    </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) =>
      make(~setState=jsProps##setState, ~libs=jsProps##libs, ~editing=jsProps##editing, [||])
  );