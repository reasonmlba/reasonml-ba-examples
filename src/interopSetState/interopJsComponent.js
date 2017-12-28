import React, { Component } from 'react'
import ReactDom from 'react-dom'
import ReasonComponent from './reasonComponent.bs.js'

class InteropJsComponent extends Component {
  constructor(props) {
    super(props)
    this.state = {
      libs: ['Angular', 'React', 'Ember', 'Preact', 'Svelte', 'Om'],
      editing: false
    }
  }
  render() {
    const { libs, editing } = this.state
    return React.createElement(
      'div',
      {
        style: {
          display: 'flex'
        }
      },
      React.createElement(
        'div',
        {
          style: {
            border: '1px solid black'
          }
        },
        React.createElement('h1', null, 'ReactJS Component'),
        editing ? React.createElement('h3', null, 'Editando') : null,
        React.createElement(
          'ul',
          null,
          libs.map(lib => React.createElement('li', { key: lib }, lib))
        ),
        React.createElement(
          'button',
          {
            onClick: () => this.setState({ editing: true })
          },
          'Editando: true'
        ),
        React.createElement(
          'button',
          {
            onClick: () => this.setState({ editing: false })
          },
          'Editando: false'
        )
      ),
      React.createElement(
        'div',
        {
          style: {
            border: '1px solid black'
          }
        },
        React.createElement(ReasonComponent, {
          setState: state => this.setState(state),
          libs,
          editing
        })
      )
    )
  }
}

ReactDom.render(
  React.createElement(InteropJsComponent, null),
  document.getElementById('index')
)
