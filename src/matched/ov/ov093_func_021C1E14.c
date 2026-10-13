/*
 * function: BTL_SERVER_FLOW_RecoverHpFromDrain
 * address:  0x021C1E14
 * packet:   pkt_ov093_021C1E14
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C78F4  0x021C78F4  thumb  ov093
 *   BTL_SERVER_FLOW_IsHpRecoverUnneeded  0x021C3370  thumb  ov093
 *   BTL_SERVER_FLOW_TryRecoverHp  0x021C334C  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(void *lock, int line);
extern u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s);
extern int BTL_SERVER_FLOW_IsHpRecoverUnneeded(u8 *p, void *q);
extern int BTL_SERVER_FLOW_TryRecoverHp(u8 *p, u8 *q, int a, int b);
extern void func_021CC95C(u32 *p, u32 v, int line);

int BTL_SERVER_FLOW_RecoverHpFromDrain(u8 *p, u8 *q, u32 a, u32 b)
{
    u32 s = func_021CC8D8(p + 0x1D74, 7154);
    int r = 0;
    u8 *t = (u8 *)func_021C78F4(p, q, (u8 *)a, b);
    if (t) {
        if (BTL_SERVER_FLOW_IsHpRecoverUnneeded(p, q) == 0) {
            r = BTL_SERVER_FLOW_TryRecoverHp(p, q, (int)t, 1);
        }
    }
    func_021CC95C((u32 *)(p + 0x1D74), s, 7168);
    return r;
}
