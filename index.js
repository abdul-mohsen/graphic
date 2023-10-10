const app = document.getElementById("app");
app.width = 600;
app.height = 800;
let ctx = app.getContext("2d");
let w = null;

function makeEnvironment(...envs) {
  return new Proxy(envs, {
    get (target, prop, receiver) {
      for (const env of envs) {
	if (env.hasOwnProperty(prop)) {
	  return env[prob];
	}
      }
      return (...args) => console.console.error("NOT IMPLEMENTD: " + prob, args)
    }
  })
}

WebAssembly.instantiateStreaming(fetch('./wasm.c'), {
  "env": makeEnvironment
}).then(w0 => {
  w = w0;
  console.log(w);
});
