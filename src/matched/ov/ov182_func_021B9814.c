/*
 * function: func_021B9814
 * address:  0x021B9814
 * packet:   pkt_021B9814
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020111E8  0x020111E8  thumb
 *   func_0204E720  0x0204E720  arm
 */
typedef unsigned int u32;

extern u32 func_020111E8(void);
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);

void func_021B9814(void *a, void *b, void *c)
{
    if (func_020111E8() == 0x15)
        func_0204E720(3, (s32)a, (s32)b, (s32)c);
    else
        func_0204E720(0xc, (s32)a, (s32)b, (s32)c);
}
