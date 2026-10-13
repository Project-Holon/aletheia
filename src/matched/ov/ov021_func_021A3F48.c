/*
 * function: FIELD_PLAYER_CORE_FormStepSlot4
 * address:  0x021A3F48
 * packet:   pkt_ov021_021A3F48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_ChangeToFormSlot  0x021A3D50  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F48;

typedef unsigned int   u32;
int FIELD_PLAYER_CORE_ChangeToFormSlot(u32 a, u32 b);

int FIELD_PLAYER_CORE_FormStepSlot4(Obj021A3F48 *p)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot((u32)p, 4) != 1)
        p->step++;
    return 0;
}
