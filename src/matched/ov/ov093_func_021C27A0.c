/*
 * function: BTL_SERVER_FLOW_TryApplySick
 * address:  0x021C27A0
 * packet:   pkt_ov093_021C27A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The fifth parameter is a one-word struct passed by value and handed on
 * to BTL_SERVER_FLOW_CheckSickImmunity by value (`add r3, sp, #0x20; ldr r3, [r3]`, the
 * push-r0-r3 struct idiom); a plain u32 folds to `ldr r3, [sp, #0x20]`.
 * The caller BTL_SERVER_FLOW_ApplyMoveSick passes it as a plain u32 word. Declaring s
 * before t puts s in [sp, #8].
 *
 * symbols:
 *   BTL_SERVER_FLOW_CheckSickImmunity  0x021C282C  thumb  ov093
 *   BTL_SERVER_FLOW_PushSickFailedMessage  0x021C5C74  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   BTL_SERVER_FLOW_QuerySickBlockedEvent  0x021C2B3C  thumb  ov093
 *   BTL_SERVER_FLOW_RunSickAppliedEvent  0x021C2BA4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u32 v; } S;
extern int BTL_SERVER_FLOW_CheckSickImmunity(u8 *p, u32 x, u32 z, S a, u8 b);
extern void BTL_SERVER_FLOW_PushSickFailedMessage(u8 *p, u8 *a, int kind, u32 v);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_QuerySickBlockedEvent(u8 *p, u8 *a, u8 *b, u32 c);
extern void BTL_SERVER_FLOW_RunSickAppliedEvent(u8 *p, u8 *a, u8 *b, u32 c);

int BTL_SERVER_FLOW_TryApplySick(u8 *p, u32 x, u32 y, u32 z, S a, u8 b, u32 c)
{
    int r;
    u32 s;
    int t;
    r = BTL_SERVER_FLOW_CheckSickImmunity(p, x, z, a, b);
    if (r != 0) {
        if (c != 0)
            BTL_SERVER_FLOW_PushSickFailedMessage(p, (u8 *)x, r, z);
        return 1;
    }
    s = func_021CC8D8(p + 0x1D74, 7779);
    t = BTL_SERVER_FLOW_QuerySickBlockedEvent(p, (u8 *)y, (u8 *)x, z);
    if (t != 0 && c != 0) {
        BTL_SERVER_FLOW_RunSickAppliedEvent(p, (u8 *)x, (u8 *)y, z);
        p[0x78A] |= 0x10;
    }
    func_021CC95C((u32 *)(p + 0x1D74), s, 7792);
    return t;
}
