/*
 * file:     field_msgbg_p63.c
 * unit:     yes
 * function: func_02190A28, func_02190A64
 * address:  0x02190A28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F878  0x0201F878  thumb  arm9
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_0201F898  0x0201F898  thumb
 */
struct Slot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_02190A28;

typedef struct Pair {
    u32 a;
    u32 b;
} Pair;

typedef signed short   s16_02190A64;

typedef signed char    s8;

extern u32 func_02190A20(int n, u32 d);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_0201F898(u32, u32, u32, u32);
u32 func_02190A28(const Pair *arr, int n, u32 c, u16 d);
int func_02190A64(u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
u32 func_02190A28(const Pair *arr, int n, u32 c, u16 d)
{
    u32 obj;
    int i;

    obj = func_02190A20(n, d);
    for (i = 0; i < n; i++)
        func_0201F878((struct Slot *)obj, c, arr[i].a, arr[i].b, d);
    return obj;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02190A64(u32 a, u32 b, u32 c, u32 d)
{
return func_0201F898(a, b, c, d);
}
