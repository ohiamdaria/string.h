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

START_TEST(s21_trim_test) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = s21_trim(str_to_trim, empty_format);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!  !");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str == s21_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

START_TEST(trim_1) {
    char *str1 = "Hello World";
    char *str2 = "H";
    char *str3 = (char *)s21_trim(str1, str2);
    ck_assert_str_eq(str3, "ello World");
    free(str3);
} END_TEST

START_TEST(trim_2) {
    char *str1 = "Hello World";
    char *str2 = "Hedl";
    char *str3 = (char *)s21_trim(str1, str2);
    ck_assert_str_eq(str3, "o Wor");
    free(str3);
} END_TEST

START_TEST(trim_3) {
    char *str1 = "";
    char *str2 = "";
    char *str3 = (char *)s21_trim(str1, str2);
    ck_assert_str_eq(str3, "");
    free(str3);
} END_TEST

START_TEST(trim_4) {
    char *str = "empty";
    char *str2 = "empty";
    char *str3 = (char *)s21_trim(str, str2);
    ck_assert_str_eq(str3, "");
    free(str3);
} END_TEST

START_TEST(trim_5) {
    char *str = s21_NULL;
    char *str2 = s21_NULL;
    char *str3 = (char *)s21_trim(str, str2);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(trim_6) {
    char *str = "";
    char *str2 = s21_NULL;
    char *str3 = (char *)s21_trim(str, str2);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(trim_7) {
    char *str = s21_NULL;
    char *str2 = "          ";
    char *str3 = (char *)s21_trim(str, str2);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(trim_8) {
    char *str = "empty";
    char *str2 = "t";
    char *str3 = (char *)s21_trim(str, str2);
    ck_assert_str_ne(str3, "em");
    free(str3);
} END_TEST

START_TEST(s21_trim_test1) {
    const char *src = "My string";
    const char *trim = "sd";
    char *res;
    res = s21_trim(src, trim);
    char right[] = "My string";
    ck_assert_str_eq(right, res);
    free(res);
} END_TEST

START_TEST(s21_trim_test2) {
    char src[] = "\n\t\v\r\fMy stringsw\n\t\v\r\f";
    char trim[] = "";
    void *res;
    char right[] = "My stringsw";
    res = s21_trim(src, trim);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST


START_TEST(s21_trim_test3) {
    char src[] = "My string";
    char trim[] = "Mg";
    void *res;
    char right[] = "y strin";
    res = s21_trim(src, trim);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST

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
    tcase_add_test(tc, s21_trim_test);
    tcase_add_test(tc, trim_1);
    tcase_add_test(tc, trim_2);
    tcase_add_test(tc, trim_3);
    tcase_add_test(tc, trim_4);
    tcase_add_test(tc, trim_5);
    tcase_add_test(tc, trim_6);
    tcase_add_test(tc, trim_7);
    tcase_add_test(tc, trim_8);

    tcase_add_test(tc, s21_trim_test1);
    tcase_add_test(tc, s21_trim_test2);
    tcase_add_test(tc, s21_trim_test3);


    suite_add_tcase(s, tc);
    return s;
}
