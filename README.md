# Project Euler

... something I look at after finishing advent of code every year...

# How to install the repo

Clone down the repository to any place of your choosing, preferably some linux set up. If you'd like the 
pre-commit hooks to work, install pre-commit as well plus clangd-format. 

# To run puzzle answers.

To run any of the puzzle answers, run the command for the appropriate puzzle:

```
make run <puzzle number>
```

Both the Makefile and the clangd settings will have the appropriate version (C++ 20). And that's it!



# Some lessons learned

Ended up learning quite a bit about Makefiles and bash more generally when trying to build a makefile
to be as simple/foolproof as possible. Probably created a lot of footguns here, but am learning along
the way.
