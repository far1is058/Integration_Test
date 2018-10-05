BOOST_AUTO_TEST_SUITE(test_equality)

BOOST_AUTO_TEST_CASE(equal_side) {
    String s = "abc";
    String t = "abc";

    BOOST_TEST(s == t);
}

BOOST_AUTO_TEST_CASE(not_equals) {
    String s = "abac";
    String t = "xyz";

    BOOST_TEST(!(s == t));
}



BOOST_AUTO_TEST_CASE(empty_full) {
    String l = "";
    String r = "cd";

    BOOST_TEST(l.length()==0);
    BOOST_TEST(r.length()==2);
}

BOOST_AUTO_TEST_CASE(full_empty) {
    String l = "ab";
    String r = "";

    BOOST_TEST(l.length()==2);
    BOOST_TEST(r.length()==0);
}
BOOST_AUTO_TEST_CASE(empty__empty) {
    String l = "";
    String r = "";

    BOOST_TEST(l.length()==0);
    BOOST_TEST(r.length()==0);
}



BOOST_AUTO_TEST_SUITE_END()
