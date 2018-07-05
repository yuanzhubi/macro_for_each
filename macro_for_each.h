#ifnodef MACRO_FOR_EACH
#define MACRO_FOR_EACH

#define CO_EXPAND(x) x
#define CO_EMPTY_EXPAND(x)
#define CO_COMMA_GEN(...) ,

//We add a "ignored_data" because visual C++ compiler can not "perfect forward" empty __VA_ARGS__.
#define CO_FE_0(...) 
#define CO_FE_1(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) 
#define CO_FE_2(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_1(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_3(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_2(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_4(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_3(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_5(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_4(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_6(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_5(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_7(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_6(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_8(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_7(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_9(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_8(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))
#define CO_FE_10(op_sep, sep, op_data, ignored_data, x, ...) op_data(x) op_sep(sep) CO_EXPAND(CO_FE_9(op_sep, sep, op_data, ignored_data, ##__VA_ARGS__))

#define CO_GET_NTH_ARG( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,  N, ...) N

#define CO_FOR_EACH_IMPL(op_sep, op_data, sep, ...) CO_EXPAND(CO_GET_NTH_ARG(__VA_ARGS__, CO_FE_10, CO_FE_9, CO_FE_8, CO_FE_7, \
    CO_FE_6, CO_FE_5, CO_FE_4, CO_FE_3, CO_FE_2, CO_FE_1, CO_FE_0)(op_sep, sep, op_data, __VA_ARGS__))

#define CO_FOR_EACH(op_data, ...) CO_FOR_EACH_IMPL(CO_EMPTY_EXPAND, op_data, EMPTY_SEPERATOR, IGNORED_ARG, ##__VA_ARGS__)

#define CO_FOR_EACH_COMMA(op_data, ...) CO_FOR_EACH_IMPL(CO_COMMA_GEN, op_data, EMPTY_SEPERATOR, IGNORED_ARG, ##__VA_ARGS__)

#define CO_FOR_EACH_SEP(op_data, sep, ...) CO_FOR_EACH_IMPL(CO_EXPAND, op_data, sep, IGNORED_ARG, ##__VA_ARGS__)

#endif
