# cplusplus-test

  These are some example of CPP for learning. 
  You can download, compile and run it directly.

## Step1: Clone the example
	Open terminal, and type the following:
```	
	git clone https://github.com/sevencheng798/cplusplus-test.git	
```
## Step 2: to set compile environment if you want to use gtest.
  Open OptionConfig.cmake and modify the variables: GTEST_LIB_DIR and GTEST_INCLUDE_DIR.

## Step3: Run Make to compile
	Create a comile directory.
```
	mkdir cplusplus-build
	cd cplusplus-build
	cmake ${CPLUSPLUS_SOURCE} -DCMAKE_TOOLCHAIN_FILE=${CPLUSPLUS_SOURCE}/OptionConfig.cmake -DCMAKE_INSTALL_PREFIX=./_install -DGTEST_ENABLE=ON
	make
```

## Step4: Run example
```
	./SharedUniqueTEST
```
Running main() from /home/sven/work/3rd/googletest/googletest/src/gtest_main.cc
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from Base
[ RUN      ] Base.createInstance
name: SvenBaseUnique
destory base
[       OK ] Base.createInstance (0 ms)
[ RUN      ] Base.getName
name: BaseUnique
destory base
[       OK ] Base.getName (0 ms)
[ RUN      ] Base.shared_ptr
name: BaseShared
shared_ptr.use_count: 1
getNameFunc : usercount: 2
getNameFunc : name: BaseShared
destory base
[       OK ] Base.shared_ptr (1 ms)
[ RUN      ] Base.unique_ptr
name: BaseUnique
getNameFunc : usercount: 1
getNameFunc : name: BaseUnique
destory base
[       OK ] Base.unique_ptr (0 ms)
[----------] 4 tests from Base (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 4 tests.


