/*
 * function: FIELD_BUILDMODEL_PlayGroup
 * address:  0x0218C3E0
 * packet:   pkt_ov021_0218C3E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Dispatches a slot-group operation by mode 0..4.
 *
 * symbols:
 *   FIELD_BUILDMODEL_ResetAnimSet  0x0218C388  thumb  ov021
 *   FIELD_BUILDMODEL_StartGroupOpening  0x0218C23C  thumb  ov021
 *   FIELD_BUILDMODEL_StartGroupClosing  0x0218C2E4  thumb  ov021
 *   FIELD_BUILDMODEL_StartGroupLoop  0x0218C290  thumb  ov021
 *   FIELD_BUILDMODEL_StopGroup  0x0218C350  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_BUILDMODEL_ResetAnimSet(u32 *st);
extern void FIELD_BUILDMODEL_StartGroupOpening(u32 *st, int n);
extern void FIELD_BUILDMODEL_StartGroupClosing(u32 *st, int n);
extern void FIELD_BUILDMODEL_StartGroupLoop(u32 *st, int n);
extern void FIELD_BUILDMODEL_StopGroup(u32 *st, int n);

void FIELD_BUILDMODEL_PlayGroup(u32 *st, int n, int mode)
{
    switch (mode) {
    case 0:
        FIELD_BUILDMODEL_ResetAnimSet(st);
        FIELD_BUILDMODEL_StartGroupOpening(st, n);
        break;
    case 1:
        FIELD_BUILDMODEL_ResetAnimSet(st);
        FIELD_BUILDMODEL_StartGroupClosing(st, n);
        break;
    case 2:
        FIELD_BUILDMODEL_ResetAnimSet(st);
        FIELD_BUILDMODEL_StartGroupLoop(st, n);
        break;
    case 3:
        FIELD_BUILDMODEL_StopGroup(st, n);
        break;
    case 4:
        FIELD_BUILDMODEL_ResetAnimSet(st);
        break;
    }
}
