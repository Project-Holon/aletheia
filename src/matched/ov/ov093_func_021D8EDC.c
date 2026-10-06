/*
 * function: func_021D8EDC
 * address:  0x021D8EDC
 * packet:   pkt_ov093_021D8EDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8E00  0x021D8E00  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D8E7C  0x021D8E7C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D8E00(void *a, int b);
extern int func_021C8288(u8 *p);
extern void func_021D8E7C(int u, void *a, u32 b, u32 c, u8 d);

void func_021D8EDC(int u, int a, int b, int *p)
{
    if (*p != 0 && func_021D8E00((void *)a, b) != 0)
        func_021D8E7C(u, (void *)a, (int)b, (u8)(func_021C8288((u8 *)a) == 1), 1);
}
