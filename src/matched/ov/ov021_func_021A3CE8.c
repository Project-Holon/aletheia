/*
 * function: FIELD_PLAYER_CORE_FinishFormChange
 * address:  0x021A3CE8
 * packet:   pkt_ov021_021A3CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetLowestFormSlot  0x021A3C94  thumb  ov021
 *   FIELD_PLAYER_CORE_RunFormSteps  0x021A3C6C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3CE8;

int FIELD_PLAYER_CORE_GetLowestFormSlot(u32 x);
u16 FIELD_PLAYER_CORE_RunFormSteps(Obj021A3CE8 *p, int idx);

void FIELD_PLAYER_CORE_FinishFormChange(Obj021A3CE8 *p)
{
    int i = FIELD_PLAYER_CORE_GetLowestFormSlot(p->mask);

    if (i < 10) {
        while (FIELD_PLAYER_CORE_RunFormSteps(p, i) == 0)
            ;
    }
}
