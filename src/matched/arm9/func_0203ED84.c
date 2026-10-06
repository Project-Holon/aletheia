/*
 * function: func_0203ED84
 * address:  0x0203ED84
 * packet:   pkt_0203EC7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F4      0x021469F4  data
 */

typedef unsigned char u8;
struct S {
    unsigned int a : 2;
    unsigned int b : 30;
};
extern int *g_021469F4;
typedef signed int     s32;
typedef unsigned int   u32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_0203ED84(int a0)
{
    struct S sv;
    int t;
    if (*(int *)((char *)g_021469F4 + 0x2c) == 1)
        t = (int)func_0203996C(0xff);
    else
        t = (int)func_020399A8();
    sv.a = a0;
    sv.b = *(int *)((char *)g_021469F4 + 0x24);
    return func_0203D4D0(t, *(u8 *)((char *)g_021469F4 + 0x28), 0xf, 4, (u32)(&sv), 0, 1, 0);
}
