/*
 * function: func_021CF81C
 * address:  0x021CF81C
 * packet:   pkt_ov093_021CF81C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct QG;
struct UtilWork;
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);

u32 func_021CF81C(u8 *p, void *q, u8 *out)
{
    u8 n = func_021D5448(q);
    u32 r = 4;
    u8 i = 0;
    for (; i < n; i++) {
        if (func_021D5584(q, i) != 0) {
            out[i] = (func_021CF5B0(p, q, func_021D54C0(q, i), 0) == 0) ? 1 : 0;
            if (r == 4 && out[i] != 0) {
                r = i;
            }
        } else {
            out[i] = 0;
        }
    }
    for (; i < 4; i++) {
        out[i] = 0;
    }
    return r;
}
