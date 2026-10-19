/*
 * function: BTL_SERVER_FLOW_CheckMoveRestricted
 * address:  0x021BE3A8
 * packet:   pkt_ov093_021BE3A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_FIELD_IsStaticSlotInUse  0x021EF948  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMoveExecuteFail  0x021C0450  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_FIELD_IsStaticSlotInUse(int k);
extern void BTL_SERVER_FLOW_ProcMoveExecuteFail(u8 *p, u8 *q, u16 c, int k);

int BTL_SERVER_FLOW_CheckMoveRestricted(u8 *p, u8 *a, u16 *s)
{
    u16 t = *s;
    int k = 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0xF) && WAZA_TOOL_GetFlag(t, 0xC)) {
        k = 0xD;
    } else if (BTL_FIELD_IsStaticSlotInUse(2) && WAZA_TOOL_GetFlag(t, 9)) {
        k = 0x14;
    }
    if (k) {
        BTL_SERVER_FLOW_ProcMoveExecuteFail(p, a, t, k);
        return 1;
    }
    return 0;
}
