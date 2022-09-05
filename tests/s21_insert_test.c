#include "test.h"
START_TEST(insert_test1) {
    char str[] = "Shlepa";
    char src[] = "I love my . He is very kind!";
    s21_size_t index = 10;
    char expected[] = "I love my Shlepa. He is very kind!";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test2) {
    char str[] = "Hello, ";
    char src[] = "Aboba!";
    s21_size_t index = 0;
    char expected[] = "Hello, Aboba!";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test3) {
    char str[] = "";
    char src[] = "";
    s21_size_t index = 100;
    char *expected = NULL;
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test4) {
    char *src = s21_NULL;
    char *str = s21_NULL;
    s21_size_t index = 100;
    char *expected = s21_NULL;
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_ptr_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test5) {
    char str[] = "Monkey";
    char src[] = "Space  ";
    s21_size_t index = 6;
    char expected[] = "Space Monkey ";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_str_null) {
    char *str = NULL;
    char src[] = "Space  ";
    s21_size_t index = 6;
    char expected[] = "Space  ";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 15);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("Hello!", ", world!!", 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!!!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 10);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 25);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(insert_1) {
    char str1[7] = "this +";
    char str2[6] = " this";
    char *str3 = (char*)s21_insert(str1, str2, 6);
    ck_assert_str_eq(str3, "this + this");
    free(str3);
} END_TEST

START_TEST(insert_2) {
    char str1[1] = "";
    char str2[14] = "checking null";
    char *str3 = (char*)s21_insert(str1, str2, 1);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(insert_3) {
    char str1[8] = "splitme";
    char str2[2] = " ";
    char *str3 = (char*)s21_insert(str1, str2, 5);
    ck_assert_str_eq(str3, "split me");
    free(str3);
} END_TEST

START_TEST(insert_4) {
    char str1[14] = "checking null";
    char *str2 = s21_NULL;
    char *str3 = (char*)s21_insert(str1, str2, 0);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(insert_5) {
    char str1[4] = "end";
    char str2[6] = "start";
    char *str3 = (char*)s21_insert(str1, str2, 0);
    ck_assert_str_eq(str3, "startend");
    free(str3);
} END_TEST

START_TEST(insert_6) {
    char str1[7] = "caseof";
    char str2[8] = "mistake";
    char *str3 = (char*)s21_insert(str1, str2, -1);
    ck_assert_ptr_eq(str3, NULL);
    free(str3);
} END_TEST

START_TEST(insert_7) {
    char *str1 = s21_NULL;
    char str2[14] = "checking null";
    char *str3 = (char*)s21_insert(str1, str2, 1);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(insert_8) {
    char str1[2] = " ";
    char str2[32] = "if strlen src lesser than index";
    char *str3 = (char*)s21_insert(str1, str2, 3);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(insert_9) {
    char *str1 = s21_NULL;
    char str2[1] = "";
    char *str3 = (char*)s21_insert(str1, str2, 0);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(insert_10) {
    char *str1 = s21_NULL;
    char *str2 = s21_NULL;
    char *str3 = (char*)s21_insert(str1, str2, 0);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(insert_11) {
    char str1[4] = "";
    char str2[6] = "";
    char *str3 = (char*)s21_insert(str1, str2, 1);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
} END_TEST

START_TEST(s21_insert_test1) {
    char src[] = "My string";
    char str[] = "aloha!";
    s21_size_t start_index = 3;
    void *res;
    char right[] = "My aloha!string";
    res = s21_insert(src, str, start_index);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST

START_TEST(s21_insert_test2) {
    char str1[] = "";
    char str2[] = "check";
    s21_size_t start = 0;
    char *res;
    char right[] = "check";
    res = s21_insert(str1, str2, start);
    ck_assert_str_eq(res, right);
    free(res);
} END_TEST


START_TEST(s21_insert_test3) {
    char str1[] = "Ma string";
    char str2[] = "";
    s21_size_t start = 5;
    char *res;
    char right[] = "Ma string";
    res = s21_insert(str1, str2, start);
    ck_assert_str_eq(right, res);
    free(res);
} END_TEST

Suite *s21_Suite_insert() {
    Suite *s = suite_create("suite_insert");
    TCase *tc = tcase_create("insert_tc");

    tcase_add_test(tc, insert_test1);
    tcase_add_test(tc, insert_test2);
    tcase_add_test(tc, insert_test3);
    tcase_add_test(tc, insert_test4);
    tcase_add_test(tc, insert_test5);
    tcase_add_test(tc, insert_str_null);
    tcase_add_test(tc, s21_insert_test);
    tcase_add_test(tc, s21_insert_test1);
    tcase_add_test(tc, s21_insert_test2);
    tcase_add_test(tc, s21_insert_test3);

    tcase_add_test(tc, insert_1);
    tcase_add_test(tc, insert_2);
    tcase_add_test(tc, insert_3);
    tcase_add_test(tc, insert_4);
    tcase_add_test(tc, insert_5);
    tcase_add_test(tc, insert_6);
    tcase_add_test(tc, insert_7);
    tcase_add_test(tc, insert_8);
    tcase_add_test(tc, insert_9);
    tcase_add_test(tc, insert_10);
    tcase_add_test(tc, insert_11);

    suite_add_tcase(s, tc);
    return s;
}

