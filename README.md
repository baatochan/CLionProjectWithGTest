# CLion Project with GTest
CLion project stub with Google Tests integrated.

## Using the repo

1. Clone the repo
1. Initialize the GTest submodule (if not done during cloning)
1. Reset git `master` branch to 'Init commit'
1. Change `origin` to new empty/uninitialized repo
1. Change the project and target name in `CMakeLists.txt`
	* `project` in project root
	* `add_executable` in `src/`
1. Change the project `LICENSE` if you're not okay with the Unlicense
1. Open the project with CLion
1. Add Google Test Run/Debug Configuration for `runAllTests` target and (optionally) remove `gtest`/`gmock` and `runAllTests` Application Run/Debug Configuration
