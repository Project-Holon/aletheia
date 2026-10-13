/*
 * function: BTL_CALC_SpeedBoostOnTurnEnd
 * address:  0x021D8BB4
 * packet:   pkt_ov093_021D8BB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void BTL_CALC_SpeedBoostOnTurnEnd(int u, int a, int k)
{
    u32 *r;

    if (k == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4((int *)a, k), 0) != 0) {
            r = func_021C88A4((void *)a, 14, k);
            r[0] |= 2 << 22;
            r[1] = 5;
            ((u8 *)r)[0xf] = 1;
            ((u8 *)r)[0x10] = k;
            ((u8 *)r)[0xc] = 1;
            func_021C88C8((void *)a, r);
        }
    }
}
