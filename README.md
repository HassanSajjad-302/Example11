# Example11

This is a sample example that addresses few concerns mentioned in this Email 
https://lists.isocpp.org/sg15/2023/08/2018.php
Checked with this commit latest at the time of writing.
https://github.com/HassanSajjad-302/HMake/commit/2c14a00a5c6bbd56f862d39fcc6e85f0a3b08a3a


> Other interesting cases (that you may or may not care about supporting):
>
> duplicate modules (by name) that are in executables and never in the
> same program
> 
> per-target (or, harder, per-source) flags that require distinct module
> compilations (header and/or named)

HMake supports the first case by a concept of module-scope. 
In this example, all targets have same module-scope.
So modules exported by the targets ```sum``` and ```multiply```
can be consumed by the target ```app```.

But if we want the targets to not be able to consume modules from
other targets, we can establish boundary by simply assigning
such targets a different module-scope.

If two modules export same name in a module-scope,
this will be a build-system error.
e.g. if you change ```sum``` in sum.cpp to ```multiply```, and then rebuild.
It is being checked here
https://github.com/HassanSajjad-302/HMake/blob/2c14a00a5c6bbd56f862d39fcc6e85f0a3b08a3a/hconfigure/src/SMFile.cpp#L409

Similarly, if a module is not available in a module-scope,
this will be a build-system error as well.
e.g. if you change ```multiply``` in multiply.cpp to division, and then rebuild.
It is being checked here
https://github.com/HassanSajjad-302/HMake/blob/2c14a00a5c6bbd56f862d39fcc6e85f0a3b08a3a/hconfigure/src/CppSourceTarget.cpp#L1162


HMake supports the second case as-well.
Each target has a unique compile-command.
So, in this example we define a private compile-definition for only ```multiply```
target which is exporting ```multiply``` module. 
As, this compile-definition is not defined for the ```main.cpp``` module-file,
program works as expected.



