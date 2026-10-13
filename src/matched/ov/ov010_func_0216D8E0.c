/*
 * function: FLDMMDL_SetDrawOffsetOutside
 * address:  0x0216D8E0
 * packet:   pkt_ov010_0216D8E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): copies a 12-byte record into the object at
 * +0x5c.  Filed as the sole blocker of ov021 FIELD_PLAYER_CORE_FormStepNormal.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Rec12;

void FLDMMDL_SetDrawOffsetOutside(u8 *p, Rec12 *src)
{
    *(Rec12 *)(p + 0x5c) = *src;
}
