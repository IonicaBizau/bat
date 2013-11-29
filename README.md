Johnny's Webview
================

A simple web page loader as a desktop application.

## Implemented functions

The following functions are implemented for the Javascript API.

<table>
  <thead>
    <tr>
      <th>Function name</th>
      <th>Arguments</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>$API.closeWindow()</code></td>
      <td>No arguments</td>
      <td>Closes the window</td>
    </tr>
    <tr>
      <td><code>$API.resize(width, height);</code></td>
      <td>
        <code>width</code> - the new width of the window,
        <code>height</code> - the new height of the window</td>
      <td>Resizes the window</td>
    </tr>
    <tr>
      <td><code>$API.setWindowFlags (type)</code></td>
      <td>
        <code>UNDECORATED</code> - undecorates the window
        <code>BOTTOM_MOST</code> - puts the window on the background
        <code>TOP_MOST</code> - puts the window on the top
        <code>REMOVE_MINIMIZE</code> - removes the minimize button
        <code>REMOVE_MAXIMIZE</code> - removes the maximize button
        <code>REMOVE_CLOSE</code> - removes the close button
      </td>
      <td>Sets the window flags</td>
    </tr>
    <tr>
      <td><code>$API.setWindowState (value)</code></td>
      <td>One of the following values:
        <code>MAXIMIZED</code>,
        <code>MINIMIZED</code>,
        <code>FULLSCREEN</code>,
        <code>ACTIVE</code>,
        <code>RESTORED</code></td>
      <td>Sets the window state</td>
    </tr>
    <tr>
      <td><code>$API.getWindowSize ()</code></td>
      <td>No argumnets</td>
      <td>Returns an object that contains <code>width</code> and <code>height</code> fields that represent the sizes of the window.</td>
    </tr>
    <tr>
      <td><code>$API.getWindowPosition ()</code></td>
      <td>No argumnets</td>
      <td>Returns an object that contains <code>top</code> and <code>left</code> fields that represent the coordinates of the window.</td>
    </tr>
    <tr>
      <td><code>$API.setWindowPosition (top, left)</code></td>
      <td><code>top</code> and <code>left</code> coordinates for the new position of the window</td>
      <td>Sets the new position of the window on the screen.</td>
    </tr>
    <tr>
      <td><code>$API.getMousePosition ()</code></td>
      <td>No argumnets</td>
      <td>Gets the mouse position on the screen.</td>
    </tr>
    <tr>
      <td><code>$API.debug (message)</code></td>
      <td><code>message</code>  - string that will be printed in the console</td>
      <td>Outputs a message in the terminal.</td>
    </tr>
    <tr>
      <td><code>$API.setWindowTitle (newTitle)</code></td>
      <td><code>newTitle</code> - string that represents the new title that you want to set to the window</td>
      <td>Sets the new window title.</td>
    </tr>
    <tr>
      <td><code>$API.runBash (command)</code></td>
      <td><code>command</code> - string that represents the command that you want to run in the bash via Johnny's Web view.</td>
      <td>Runs a bash command.</td>
    </tr>
    <tr>
      <td><code>$API.getScreenSize ()</code></td>
      <td>No arguments</td>
      <td>Returns an object that contains <code>width</code> and <code>height</code> fields that represent the sizes of the screen.</td>
    </tr>
  </tbody>
</table>

## Licence

See licence file.
