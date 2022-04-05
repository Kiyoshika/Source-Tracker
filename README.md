# Source Tracker
A simplified "git" clone to store local archives of files/code. 

The commands use `strac ...` which is short for `(s)ource (trac)ker`

More to be written as the project develops further.

## Command List
As of now, these current commands are implemented:

`strac init` - this will create a strac repo in the root directory and automatically create a "main" branch which copies everything in the current directory into it (essentially making the main branch a current snapshot of whenever the command was run)

`strac new [branch name]` - this will create a new branch as a clone of the current branch and automatically switch to using this branch.