add_test([=[Ping.ReturnsPongForPing]=]  /Users/timimaucec/PRO/CPP/WCS/mini-wcs/build/wcs_tests [==[--gtest_filter=Ping.ReturnsPongForPing]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Ping.ReturnsPongForPing]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/timimaucec/PRO/CPP/WCS/mini-wcs/tests/test_ping.cpp:5]==]
    WORKING_DIRECTORY [==[/Users/timimaucec/PRO/CPP/WCS/mini-wcs/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[Ping.EchoesOtherMessages]=]  /Users/timimaucec/PRO/CPP/WCS/mini-wcs/build/wcs_tests [==[--gtest_filter=Ping.EchoesOtherMessages]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Ping.EchoesOtherMessages]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/timimaucec/PRO/CPP/WCS/mini-wcs/tests/test_ping.cpp:9]==]
    WORKING_DIRECTORY [==[/Users/timimaucec/PRO/CPP/WCS/mini-wcs/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(wcs_tests_TESTS [==[Ping.ReturnsPongForPing]==] [==[Ping.EchoesOtherMessages]==])
