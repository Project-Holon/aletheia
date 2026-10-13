#ifndef BTL_CALC_TYPES_H
#define BTL_CALC_TYPES_H
/*
 * ov093 battle calculation: the random number state and the calculation work
 * area.
 */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

typedef unsigned long long u64;

/* Parameters of the 64 bit linear congruential generator. */
typedef struct {
    u64 seed;
    u64 mul;
    u64 add;
} BtlRngState;

/* The calculation state at 021F6360. */
struct BtlCalcWork {
    u32 reserved;
    u16 *workTable;
    BtlRngState rng;
};

#endif
