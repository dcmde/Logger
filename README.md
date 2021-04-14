# Logger

The `Logger` class can be inherited in order to log data in files.

Once a class inherits from `Logger` you can have the following features:

- specify the file location with
    - `open(PATH,NAME)`
    - `setPath(PATH)`

      `PATH` can be relative or absolute but it should end with the `/`. Example `./`, `usr/pi/log/`. The `NAME` should
      not contain the file name. By default it is a `.txt` file.

- create several logger by name
    - `write(NAME)`
- write data to the file using the conventional `<<`