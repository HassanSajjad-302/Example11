# Example11

This is a sample example that answers few points mentioned in this Email 
https://lists.isocpp.org/sg15/2023/08/2018.php
Checked with and links are from this commit latest at the time of writing.
https://github.com/HassanSajjad-302/HMake/commit/2c14a00a5c6bbd56f862d39fcc6e85f0a3b08a3a


> Other interesting cases (that you may or may not care about supporting):
>
> duplicate modules (by name) that are in executables and never in the
> same program
> 
> per-target (or, harder, per-source) flags that require distinct module
> compilations (header and/or named)

2 duplicate modules should not be in same target sources or any of its dependencies sources.

Every target has unique compile command.

Such a source or header-unit must be separated out in a separate target.
