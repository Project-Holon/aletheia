/*
 * function: func_021CF524
 * address:  0x021CF524
 * packet:   pkt_ov093_021CF524
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021CF58C  0x021CF58C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct QG;
extern u8 func_021D5448(struct QG *p);
extern u32 func_021D54C0(void *q, u8 i);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern u32 func_021D5584(void *q, u8 i);
extern void func_021CF58C(u32 y, u32 x, void *q);

u32 func_021CF524(u32 x, void *q, u32 y)
{
    u32 n = func_021D5448(q);
    u32 c = 0;
    u32 i = 0;
    for (; i < n; i++) {
        if (func_021CF5B0((u8 *)x, q, func_021D54C0(q, i), 0) == 0) {
            if (func_021D5584(q, i) != 0) {
                c++;
            }
        }
    }
    if (c == 0) {
        func_021CF58C(y, x, q);
        return 1;
    }
    return 0;
}
