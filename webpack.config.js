const path = require('path')

module.exports = {
  entry: {
    counter: './src/counter/counterIndex.bs.js',
    basic: './src/basic/basicIndex.bs.js',
    interopSetState: './src/interopSetState/interopJsComponent.js'
  },
  output: {
    path: path.join(__dirname, 'build'),
    filename: '[name].js'
  }
}
