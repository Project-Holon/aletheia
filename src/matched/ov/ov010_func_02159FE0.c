/*
 * function: MAP_REPLACE_FindFlyTargetIndex
 * address:  0x02159FE0
 * packet:   pkt_ov010_02159FE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (push {r4,r5} only, so disasm.py prints it as .word
 * data): a 1-based index lookup over a 17-entry, 0x14-byte table.
 * Callee of ov020 EVENT_MAPCHANGE_ApplyLocation.
 *
 * symbols:
 *   d_02170FEC     0x02170FEC  data  ov010  a4
 */

typedef unsigned short u16;

typedef struct Ent {
    u16 h0;
    u16 on : 1;
    u16 h4;
    char pad[0x14 - 6];
} Ent;

extern Ent d_02170FEC[];

int MAP_REPLACE_FindFlyTargetIndex(int v)
{
    unsigned int i;

    for (i = 0; i < 17; i++) {
        if (v == d_02170FEC[i].h4 && d_02170FEC[i].on)
            return i + 1;
    }
    return 0;
}
