/*
 * function: func_021D2000
 * address:  0x021D2000
 * packet:   pkt_ov093_021D2000
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (filed for the blocker of func_021D2030, lane S15).
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *func_021B98AC(char *const *q, u8 b);
extern int BTL_CALC_GetCurseTargetKind(void *p);
extern u32 func_0201BD28(u32 v, u32 n);

u32 func_021D2000(u32 *p, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return func_0201BD28(k, 0x1B);
    }
    r = func_021B98AC((char *const *)p[1], b);
    if (r) {
        return BTL_CALC_GetCurseTargetKind(r);
    }
    return func_0201BD28(k, 0x1B);
}
