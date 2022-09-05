#include "test.h"

START_TEST(all_empty) {
    char str[] = "";
    char trim_ch[] = "";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(str_empty) {
    char str[] = "";
    char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_empty) {
    char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char trim_ch[] = "";
    char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
    char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
    char expected[] = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test1) {
    char str[] = "+!!++Abo+ba++00";
    char trim_ch[] = "+!0-";
    char expected[] = "Abo+ba";
    char *got = (char *)s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test2) {
    char str[] = "Ab000cd0";
    char trim_ch[] = "003";
    char expected[] = "Ab000cd";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test3) {
    char str[] = "DoNotTouch";
    char trim_ch[] = "Not";
    char expected[] = "DoNotTouch";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test4) {
    char str[] = "&* !!sc21 * **";
    char trim_ch[] = "&!* ";
    char expected[] = "sc21";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(trim_test5) {
    char str[] = " Good morning!    ";
    char trim_ch[] = " ";
    char expected[] = "Good morning!";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(empty_spaces) {
    char str[] = "        abc         ";
    char trim_ch[] = "";
    char expected[] = "abc";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(null_ptr_trim_chars) {
    char str[] = "        abc         ";
    char *trim_ch = NULL;
    char expected[] = "abc";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

Suite *s21_Suite_trim() {
    Suite *s = suite_create("suite_trim");
    TCase *tc = tcase_create("trim_tc");

    tcase_add_test(tc, all_empty);
    tcase_add_test(tc, str_empty);
    tcase_add_test(tc, trim_empty);
    tcase_add_test(tc, trim_and_str_eq);

    tcase_add_test(tc, trim_test1);
    tcase_add_test(tc, trim_test2);
    tcase_add_test(tc, trim_test3);
    tcase_add_test(tc, trim_test4);
    tcase_add_test(tc, trim_test5);
    tcase_add_test(tc, empty_spaces);
    tcase_add_test(tc, null_ptr_trim_chars);

    suite_add_tcase(s, tc);
    return s;
}

// START_TEST(s21_trim_test1) {
//     const char *src = "My string";
//     const char *trim = "sd";
//     char *res;
//     res = s21_trim(src, trim);
//     char right[] = "My string";
//     ck_assert_str_eq(right, res);
//     free(res);
// } END_TEST

// START_TEST(s21_trim_test2) {
//     char src[] = "\n\t\v\r\fMy stringsw\n\t\v\r\f";
//     char trim[] = "";
//     void *res;
//     char right[] = "My stringsw";
//     res = s21_trim(src, trim);
//     ck_assert_str_eq(res, right);
//     free(res);
// } END_TEST


// START_TEST(s21_trim_test3) {
//     char src[] = "My string";
//     char trim[] = "Mg";
//     void *res;
//     char right[] = "y strin";
//     res = s21_trim(src, trim);
//     ck_assert_str_eq(res, right);
//     free(res);
// } END_TEST

// Suite *s21_Suite_trim() {
//     Suite *s;

//     s = suite_create("Trim Unit Test");

//     TCase *tc1_s21_trim = tcase_create("test1_s21_trim");
//     TCase *tc2_s21_trim = tcase_create("test2_s21_trim");
//     TCase *tc3_s21_trim = tcase_create("test3_s21_trim");

//     tcase_add_test(tc1_s21_trim, s21_trim_test1);
//     tcase_add_test(tc2_s21_trim, s21_trim_test2);
//     tcase_add_test(tc3_s21_trim, s21_trim_test3);

//     suite_add_tcase(s, tc1_s21_trim);
//     suite_add_tcase(s, tc2_s21_trim);
//     suite_add_tcase(s, tc3_s21_trim);

//     return s;
// }
