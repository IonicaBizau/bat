![BAT - Build Awesome Tools For Desktop using WEB Technologies](/resources/header.png)

This is a minimalist application that is used for building native desktop applications using WEB technologies.

## JavaScript API

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
        <ul>
          <li><code>UNDECORATED</code> - undecorates the window</li>
          <li><code>BOTTOM_MOST</code> - puts the window on the background</li>
          <li><code>TOP_MOST</code> - puts the window on the top</li>
          <li><code>REMOVE_MINIMIZE</code> - removes the minimize button</li>
          <li><code>REMOVE_MAXIMIZE</code> - removes the maximize button</li>
          <li><code>REMOVE_CLOSE</code> - removes the close button</li>
        </ul>
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
      <td><code>$API.setMousePosition (x, y)</code></td>
      <td>
        <code>x</code> - the x coordinate of the mouse,
        <code>y</code> - the y coordinate of the mouse</td>
      <td>Sets the mouse position on the screen.</td>
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
      <td><code>$API.inspectElement ()</code></td>
      <td>No arguments</td>
      <td>Opens the developer tools in the Johnny's Webview</td>
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

## How to hack?

Do you want to contribute? Great! There are few steps to do this.

 1. Fork this repository in your account.
 2. Clone your (forked) repository on your computer.
 3. Make sure that you have Qt installed. If not, [download and install it](http://qt-project.org/downloads).
 4. Open the cloned project (from step 2) in Qt creator.
 5. Compile it.

Now you are able to add new great features or to fix bugs! **Before** doing this create a branch with name `new-feature-[YOUR_FEATURE]` and also create tests.

This helps to keep the repository organised.

## Licence
See the [LICENSE](/LICENSE) file.
