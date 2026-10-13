/*
 * function: FIELD_PLAYER_CORE_FormStepSlot8
 * address:  0x021A408C
 * packet:   pkt_ov021_021A408C
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
} Obj021A408C;

typedef unsigned int   u32;
int FIELD_PLAYER_CORE_ChangeToFormSlot(u32 a, u32 b);

int FIELD_PLAYER_CORE_FormStepSlot8(Obj021A408C *p)
{
    if (FIELD_PLAYER_CORE_ChangeToFormSlot((u32)p, 8) != 1)
        p->step++;
    return 0;
}
