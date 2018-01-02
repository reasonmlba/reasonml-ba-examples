import React, { Component } from "react";
import ReactDom from "react-dom";
import ReasonComponent from "./reasonComponent.bs.js";

class InteropJsComponent extends Component {
  constructor(props) {
    super(props);
    this.state = {
      libs: ["Angular", "React", "Ember", "Preact", "Svelte", "Om"],
      editing: false
    };
  }
  render() {
    const { libs, editing } = this.state;
    return (
      <div style={{ display: "flex" }}>
        <div style={{ border: "1px solid black" }}>
          <h1> {"ReactJS Component"} </h1>
          {editing ? <h3>'Editando'</h3> : null}
          <ul>{libs.map(lib => <li key={lib}>{lib}</li>)}</ul>
          <button onClick={() => this.setState({ editing: true })}>
            {"Editando: true"}
          </button>
          <button onClick={() => this.setState({ editing: false })}>
            {"Editando: false"}
          </button>
        </div>
        <div style={{ border: "1px solid black" }}>
          <ReasonComponent
            setState={state => this.setState(state)}
            libs={libs}
            editing={editing}
          />
        </div>
      </div>
    );
  }
}

ReactDom.render(
  React.createElement(InteropJsComponent, null),
  document.getElementById("index")
);
