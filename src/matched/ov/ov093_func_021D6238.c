/*
 * function: BTL_POKEPARAM_CureSick
 * address:  0x021D6238
 * packet:   pkt_ov093_021D6238
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetZeroMasked  0x021E8918  thumb  ov093
 *   BTL_CALC_HasDefaultSickCont  0x021D7D6C  thumb  ov093
 *   BTL_POKEPARAM_ClearMajorStatus  0x021D61F0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
struct Slot { u32 a : 3; u32 rest : 29; };
extern struct Slot BTLV_CORE_GetZeroMasked(void);
struct UtilSlots { u8 pad[0x1c]; struct Slot s[16]; u8 pad5C[0x50]; u8 b[16]; };
extern int BTL_CALC_HasDefaultSickCont(int x);
extern void BTL_POKEPARAM_ClearMajorStatus(struct UtilSlots *p);

void BTL_POKEPARAM_CureSick(struct UtilSlots *p, int k)
{
    if (BTL_CALC_HasDefaultSickCont(k) != 0) {
        BTL_POKEPARAM_ClearMajorStatus(p);
        return;
    }
    p->s[k] = BTLV_CORE_GetZeroMasked();
    p->b[k] = 0;
}
