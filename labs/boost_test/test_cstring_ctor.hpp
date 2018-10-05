BOOST_AUTO_TEST_SUITE(test_cstring_ctor)


BOOST_AUTO_TEST_CASE(typical) {
    String s("abc");

    BOOST_TEST(s[0] == 'a');
    BOOST_TEST(s[1] == 'b');
    BOOST_TEST(s[2] == 'c');
    BOOST_TEST(s.length() == 3);
    BOOST_TEST(s.capacity() == (STRING_SIZE - 1));
}

BOOST_AUTO_TEST_CASE(boundary) {
    String s("abc");

    BOOST_TEST(s[0] == 'a');
    
    BOOST_TEST(s[2] == 'c');
    
}

BOOST_AUTO_TEST_CASE(empty) {
    String s("");

     BOOST_TEST(s.length() == 0);

}

BOOST_AUTO_TEST_CASE(concat) {
    String left("abc");
    String right("xyz");
    String result = left + right;
    BOOST_TEST(left == "abc");
    BOOST_TEST(right == "xyz");
    BOOST_TEST(result == "abcxyz");
    BOOST_TEST(result.length() == 6);

}


BOOST_AUTO_TEST_SUITE_END()
