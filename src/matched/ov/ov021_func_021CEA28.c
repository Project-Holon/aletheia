/*
 * function: COMM_ENTRY_MENU_SnapshotStates
 * address:  0x021CEA28
 * packet:   pkt_ov021_021CEA28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

typedef struct {
    u8 f0;
    u8 pad1[0x2B];
} Slot;

typedef struct {
    u8 pad0[0x70];
    Slot slots[4];
    u8 pad120[0x550 - 0x120];
    u8 f550[4];
} Work;

void COMM_ENTRY_MENU_SnapshotStates(Work *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        p->f550[i] = p->slots[i].f0;
    }
}
