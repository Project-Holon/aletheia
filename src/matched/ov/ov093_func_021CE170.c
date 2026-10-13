/*
 * function: func_021CE170
 * address:  0x021CE170
 * packet:   pkt_ov093_021CE170
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_StartTimeLimit  0x021CE068  thumb  ov093
 *   BTL_CLIENT_PollTimeLimitReady  0x021CE08C  thumb  ov093
 *   BTL_CLIENT_SetSubFn  0x021CE150  thumb  ov093
 *   BTL_CLIENT_RunSubFn  0x021CE160  thumb  ov093
 *   func_021CE308  0x021CE308  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_CLIENT_StartTimeLimit(u8 *p);
extern int BTL_CLIENT_PollTimeLimitReady(u8 *p);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern u32 BTL_CLIENT_RunSubFn(u8 *p);
extern u32 func_021CE308(u8 *p);

u32 func_021CE170(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        BTL_CLIENT_SetSubFn(p, (void *)((u32)func_021CE308));
        BTL_CLIENT_StartTimeLimit(p);
        *st = *st + 1;
        break;
    case 1:
        BTL_CLIENT_PollTimeLimitReady(p);
        if (BTL_CLIENT_RunSubFn(p) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
