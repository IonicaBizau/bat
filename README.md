[![BAT - Build Awesome Tools For Desktop using WEB Technologies](/resources/header.png)](http://ionicabizau.github.io/bat/)

A tiny tool for building native desktop applications using WEB technologies.

## Installation

### Linux
You can compile it from source, using the scripts or, just download the latest binary using the following commands:

```sh
# Download the deb package
$ wget https://github.com/IonicaBizau/bat/raw/master/dists/deb/64bit/dev-release.deb


# And install it
$ sudo dpkg -i dev-release.deb
```

### Mac OS X

You can just download the latest binary package using the following commands:

```sh
# Download the binary package
# Using curl
$ sudo curl https://github.com/IonicaBizau/bat/raw/master/dists/osx/Bat -o /usr/bin/bat

# (OR) Using wget
$ sudo wget -O /usr/bin/bat https://github.com/IonicaBizau/bat/raw/master/dists/osx/Bat
```

If you prefer to compile it from source, execute the following command(inside `source` directory) before running the provided scripts:
```sh
# Add CONFIG -= app_bundle into Bat.pro file
$ echo "CONFIG -= app_bundle" >> Bat.pro
```

### Windows
There are no binaries available for Windows. The application needs to be compiled on Windows. Contributions are welcome! :smile:

## Help

```sh
$ bat --help
Usage: bat [options]

Options:
  -h, --help                          Displays this help.
  -v, --version                       Displays version information.
  -t, --title <title>                 Sets the window title on start.
  -s, --size <WxH>                    Sets the BAT window size.
  -d, --document <path/to/file.html>  The path to the document you want BAT to
                                      load.
  -u, --undecorate                    Starts BAT with an undecorated window.
  --tt, --tooltip                     Starts BAT with a tooltip window.
  -m, --most                          If TOP is provided, then the window is
                                      keept on the top of the other windows. If
                                      BOTTOM is provided, the window will be in
                                      the behind of all windows.
  --debug                             Starts BAT in the debug mode.
```


## Demo

![Demo](/resources/demo.png)

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
      <td><code>BAT.closeWindow()</code></td>
      <td>No arguments</td>
      <td>Closes the window</td>
    </tr>
    <tr>
      <td><code>BAT.resize(width, height);</code></td>
      <td>
        <code>width</code> - the new width of the window,
        <code>height</code> - the new height of the window</td>
      <td>Resizes the window</td>
    </tr>
    <tr>
      <td><code>BAT.setWindowFlags(type)</code></td>
      <td>
        <ul>
          <li><code>UNDECORATED</code> - undecorates the window</li>
          <li><code>BOTTOM_MOST</code> - puts the window on the background</li>
          <li><code>TOP_MOST</code> - puts the window on the top</li>
          <li><code>REMOVE_MINIMIZE</code> - removes the minimize button</li>
          <li><code>REMOVE_MAXIMIZE</code> - removes the maximize button</li>
          <li><code>REMOVE_CLOSE</code> - removes the close button</li>
          <li><code>TOOLTIP</code> - converts the window in a tooltip</li>
        </ul>
      </td>
      <td>Sets the window flags</td>
    </tr>
    <tr>
      <td><code>BAT.setWindowState(value)</code></td>
      <td>One of the following values:
        <code>MAXIMIZED</code>,
        <code>MINIMIZED</code>,
        <code>FULLSCREEN</code>,
        <code>ACTIVE</code>,
        <code>RESTORED</code></td>
      <td>Sets the window state</td>
    </tr>
    <tr>
      <td><code>BAT.getWindowSize()</code></td>
      <td>No argumnets</td>
      <td>Returns an object that contains <code>width</code> and <code>height</code> fields that represent the sizes of the window.</td>
    </tr>
    <tr>
      <td><code>BAT.getWindowPosition()</code></td>
      <td>No argumnets</td>
      <td>Returns an object that contains <code>top</code> and <code>left</code> fields that represent the coordinates of the window.</td>
    </tr>
    <tr>
      <td><code>BAT.setWindowPosition(top, left)</code></td>
      <td><code>top</code> and <code>left</code> coordinates for the new position of the window</td>
      <td>Sets the new position of the window on the screen.</td>
    </tr>
    <tr>
      <td><code>BAT.getMousePosition()</code></td>
      <td>No argumnets</td>
      <td>Gets the mouse position on the screen.</td>
    </tr>
    <tr>
      <td><code>BAT.setMousePosition(x, y)</code></td>
      <td>
        <code>x</code> - the x coordinate of the mouse,
        <code>y</code> - the y coordinate of the mouse</td>
      <td>Sets the mouse position on the screen.</td>
    </tr>
    <tr>
      <td><code>BAT.debug(message)</code></td>
      <td><code>message</code>  - string that will be printed in the console</td>
      <td>Outputs a message in the terminal.</td>
    </tr>
    <tr>
      <td><code>BAT.setWindowTitle(newTitle)</code></td>
      <td><code>newTitle</code> - string that represents the new title that you want to set to the window</td>
      <td>Sets the new window title.</td>
    </tr>
    <tr>
      <td><code>BAT.inspectElement()</code></td>
      <td>No arguments</td>
      <td>Opens the BAT developer tools window.</td>
    </tr>
    <tr>
      <td><code>BAT.runBash(command)</code></td>
      <td><code>command</code> - string that represents the command that you want to run in the bash via BAT.</td>
      <td>Runs a bash command.</td>
    </tr>
    <tr>
      <td><code>BAT.getScreenSize()</code></td>
      <td>No arguments</td>
      <td>Returns an object that contains <code>width</code> and <code>height</code> fields that represent the sizes of the screen.</td>
    </tr>
  </tbody>
</table>

## How to hack?
Do you want to contribute? Great! There are few steps to do this.

1. File an issue in the repository, using the bug tracker, describing the
   contribution you'd like to make. This will help us to get you started on the
   right foot.
2. Fork the project in your account and create a new branch:
   `your-great-feature`.
3. Commit your changes in that branch.
4. Open a pull request, and reference the initial issue in the pull request
   message.



## Licence
See the [LICENSE](/LICENSE) file.
