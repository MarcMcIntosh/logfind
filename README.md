# Project logfind

Ex26 from Learn C the hard way.
It's a project to build a tool called logfind.
the tool takes an input and search the common places that log files are on the system and check them for occurrences of the input, if an occurrence is found the file is printed out.

features:
* This tool takes any sequence of words and assumes I mean "and" for them.  So ``logfind zedshaw smart guy`` will find all files that have ``zedshaw`` *and* ``smart`` *and* ``guy`` in them.
* It takes an optional argument of ``-o`` if the parameters are meant to be *or* logic.
* It loads the list of allowed log files from ``~/.logfind``.


