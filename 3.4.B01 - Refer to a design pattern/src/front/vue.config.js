module.exports = {
  devServer: {
    open: false,
    port: 8080,
    proxy: {
      '^/api/': {
        target: 'http://localhost:4000',
        ws: true,
        changeOrigin: true
      }
    }
  }
}
