/*
 * function: MAP_REPLACE_FindFlagEntry
 * address: 0x02159F04
 * packet: pkt_ov010_02159F04
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02170FB0 0x02170FB0 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Ent { u8 f00; u8 f01; u16 f02; u16 f04; } Ent;
extern Ent d_02170FB0[];
Ent *MAP_REPLACE_FindFlagEntry(int unused, int x)
{
    unsigned int i;
    for (i = 0; i < 10; i++) {
        Ent *p = &d_02170FB0[i];
        if (p->f01 == x)
            return p;
    }
    return 0;
}
