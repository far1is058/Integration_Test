BOOST_AUTO_TEST_SUITE(test_default_ctor)


BOOST_AUTO_TEST_CASE(typical) {
    String s;

    BOOST_TEST(s.length() == 0);
    BOOST_TEST(s.capacity() == (STRING_SIZE - 1));
    //BOOST_TEST(s[0] == '\0');
}

BOOST_AUTO_TEST_SUITE_END()
