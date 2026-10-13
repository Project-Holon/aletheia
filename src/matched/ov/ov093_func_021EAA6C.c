/*
 * function: func_021EAA6C
 * address:  0x021EAA6C
 * packet:   pkt_ov093_021EAA6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   func_021EAB18  0x021EAB18  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 *battle;                /* 0x00 */
    u32 pad[6];
    int (*cb1)(void *, u32);   /* 0x1c */
    int (*cb2)(void *, u32);   /* 0x20 */
    u32 arg;                   /* 0x24 */
    u32 obj;                   /* 0x28 */
} CbSlot;

extern u8 *func_021E9100(u8 *p, int n);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern int func_021EAB18(int *st, u8 *b);

void func_021EAA6C(CbSlot *s, u32 k, u32 n)
{
    u8 *t;

    if (n != 1) {
        t = func_021E9100((u8 *)s, 8);
        t[0] = k;
        t[1] = n;
        t[5] = BTL_MAIN_GetClientTrainerIndex(s->battle, k, 0);
        t[6] = BTL_MAIN_GetClientTrainerIndex(s->battle, k, 1);
        t[7] = BTL_MAIN_GetClientTrainerIndex(s->battle, k, 2);
        t[2] = BTL_MAIN_GetViewPosOfSlot(s->battle, t[5]);
        t[3] = BTL_MAIN_GetViewPosOfSlot(s->battle, t[6]);
        t[4] = BTL_MAIN_GetViewPosOfSlot(s->battle, t[7]);
        s->cb1 = 0;
        s->cb2 = (int (*)(void *, u32))func_021EAB18;
        s->arg = (u32)s;
        s->obj = 0;
    }
}
