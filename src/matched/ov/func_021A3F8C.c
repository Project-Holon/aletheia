/*
 * function: FIELD_PLAYER_CORE_FormStepSlot5Done
 * address:  0x021A3F8C
 * packet:   pkt_021A3F8C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FIELD_PLAYER_CORE_FinishFormSlotChange(its own argument 1, 0x5) and returns 0x0.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_FinishFormSlotChange  0x021A3D6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FIELD_PLAYER_CORE_FinishFormSlotChange(u32 a1, u32 a2);

u32 FIELD_PLAYER_CORE_FormStepSlot5Done(u32 a1)
{
    FIELD_PLAYER_CORE_FinishFormSlotChange(a1, 0x5);

    return 0x0;
}

