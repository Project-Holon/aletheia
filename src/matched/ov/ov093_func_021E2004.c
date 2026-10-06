/*
 * function: func_021E2004
 * address:  0x021E2004
 * packet:   pkt_ov093_021E2004
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Word { unsigned int v; } Word;
extern int func_021D775C(int key);
extern int func_021C7D00(u8 *p, int b);
extern Word func_021E89D4(int a);
extern int func_021D76BC(int a, Word b);

void func_021E2004(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        Word t = func_021E89D4(func_021C7D00((u8 *)a, b));
        func_021D76BC(0x1e, t);
    }
}
