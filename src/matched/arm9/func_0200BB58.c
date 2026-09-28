/*
 * function: func_0200BB58
 * address:  0x0200BB58
 * packet:   pkt_0200BAF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02017550  0x02017550  thumb
 *   sub_0201AA18  0x0201AA18  thumb
 *   sub_0201AB28  0x0201AB28  thumb
 *   sub_020185F4  0x020185F4  thumb
 *   sub_0200BAD4  0x0200BAD4  thumb
 *
 * Clear the six 0x88-byte slots of a0, then walk a1's list.  The bound of the
 * second loop is a call - sub_0201AA18(a1) is re-invoked at the bottom of
 * every iteration and its result compared against the counter (`cmp r5, r0`
 * right after the `bl`), and the entry test is the peeled copy of that same
 * call, which is exactly how mwcc lowers `for (i = 0; i < f(a1); i++)`.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void sub_02017550(u8 *p);
extern int sub_0201AA18(u8 *a1);
extern void *sub_0201AB28(u8 *a1, u32 i);
extern void *sub_020185F4(void *p);
extern void sub_0200BAD4(u8 *a0, u32 i, u32 j, void *v);

void func_0200BB58(u8 *a0, u8 *a1)
{
    u32 i;
    u32 k = 0;

    for (i = 0; i < 6; i++)
        sub_02017550(a0 + i * 0x88);

    for (i = 0; i < (u32)sub_0201AA18(a1); i++)
        sub_0200BAD4(a0, k, i, sub_020185F4(sub_0201AB28(a1, i)));
}
