# WinGeometry

**WinGeometry** is a lightweight Node.js module that retrieves the screen position and size of a window based on its title (INI path or window name), using a native Windows executable.

> ⚠️ Works only on **Windows** systems.

---

## 📦 Installation

```bash
npm install win-geometry
````

---

## 🛠️ Usage

```js
const { getWindowGeometry } = require('win-geometry');

getWindowGeometry('window-title')
  .then(({ x, y, width, height }) => {
    console.log('Window Geometry:', { x, y, width, height });
  })
  .catch(err => {
    console.error('Error:', err.message);
  });
```

---

## 📋 Output Format

If the window is found, the function returns a Promise that resolves to an object:

```js
{
  x: Number,
  y: Number,
  width: Number,
  height: Number
}
```

If the window is not found or an error occurs, the Promise is rejected with an appropriate error message.

---

## 🧱 Native Dependency

This module depends on a native executable called `WinGeometry.exe`, located in the `bin/` folder. This executable performs the actual window geometry retrieval using Windows API calls.

Make sure `WinGeometry.exe` is included when packaging or publishing.

---

## 🧪 Example Output

```bash
Geometry: { x: 123, y: 456, width: 800, height: 600 }
```

---

## 🚫 Limitations

* Windows-only (due to native `.exe` dependency)
* Requires the exact window title.

---

## 📃 License

MIT © [nstechbytes](https://github.com/NSTechBytes)

