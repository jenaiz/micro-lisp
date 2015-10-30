µLisp
=====

µLisp is Lisp interpreter using C. It is a personal implementation of list (look the *Story part*).

It is possible to compile all the stuff running:

```
make all
```
or build only the µlisp interpreter with:
```
make mlisp
```
The current implementation is tested in Mac OS X (10.9) and include some rules for Win32 systems (but it is not tested there).

Examples
--------

If you want to see the interpreter working, here there is some code examples.

The first program, a hello world:

```lisp
(print "hello world")
```

Some normal operations using [polish notation](http://en.wikipedia.org/wiki/Polish_notation):

```lisp
(+ 4 5)
```

```lisp
(+ 4 (* 24 5)
```

You could define things, like ```nil``` (that it is not a *builtin* type):

```lisp
(def {nil} {})
```

or ```true``` and ```false```:

```lisp
(def {true} 1)
(def {false} 0)
```

The project include a library ([preluce.lisp](https://github.com/jenaiz/micro-lisp/blob/master/libs/prelude.lisp)) with more examples to use and play with them.

Future
------
Now the challenge is to continue creating more features for µLisp, some of them come from the las two chapters where there some ideas to continue with the implementations

I have finished the book and have some ideas for the next steps. Stay tuned!

Story
-----
Behind of the µlisp's idea was the book: [Build your own Lisp](http://buildyourownlisp.com) from [Daniel Holden](https://github.com/orangeduck). The firsts release was following the tutorial. You can find a copy of the last version in [lispy.c](https://github.com/jenaiz/micro-lisp/blob/master/lispy.c) (I will be updating this file with the version from the book if there is an update).

The principal reason for writing µlisp was to enjoy hacking with C and discover Lisp.

Have fun!

Jesús
