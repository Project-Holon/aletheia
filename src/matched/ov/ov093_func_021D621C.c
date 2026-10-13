/*
 * function: BTL_POKEPARAM_ClearDependentSick
 * address:  0x021D621C
 * packet:   pkt_ov093_021D621C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CORE_GetZeroMasked  0x021E8918  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Slot { u32 a : 3; u32 rest : 29; };
extern struct Slot BTLV_CORE_GetZeroMasked(void);
struct Unk021D621C { u8 pad[0x40]; struct Slot f40; u8 pad44[0x71]; u8 fB5; };
void BTL_POKEPARAM_ClearDependentSick(struct Unk021D621C *p, int k)
{
    if (k == 2) {
        p->f40 = BTLV_CORE_GetZeroMasked();
        p->fB5 = 0;
    }
}
