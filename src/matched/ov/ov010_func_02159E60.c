/*
 * function: MAP_REPLACE_GetFlagIndex
 * address: 0x02159E60
 * packet: pkt_ov010_02159E60
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
int MAP_REPLACE_GetFlagIndex(int x)
{
    unsigned int i;
    for (i = 0; i < 10; i++) {
        if (x == d_02170FB0[i].f00)
            return i;
    }
    return -1;
}
