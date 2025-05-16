// index.js
const { execFile } = require('child_process');
const path = require('path');

function getWindowGeometry(title) {
  const exe = path.resolve(__dirname, 'bin', 'Release','WinGeometry.exe');
    
  return new Promise((resolve, reject) => {
    execFile(exe, [title], { windowsHide: true }, (err, stdout, stderr) => {
      if (err) {
        return reject(new Error(`Failed: ${stderr || err.message}`));
      }

      const line = stdout.trim();

      if (line === 'NOTFOUND') {
        return reject(new Error('Window not found'));
      }

      if (line === 'ERROR') {
        return reject(new Error('Failed to get window rect'));
      }

      const [x, y, width, height] = line
        .split('\t')
        .map(s => parseInt(s, 10));

      resolve({ x, y, width, height });
    });
  });
}

module.exports = { getWindowGeometry };
