/*
 * function: CURSOR_MOVE_GetNeighbour
 * address:  0x02025F60
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 CURSOR_MOVE_GetNeighbour(const u8 *ptr, u32 idx, u32 type)
{
    switch (type) {
    case 0:
        idx = (ptr + idx * 12)[4];
        break;
    case 1:
        idx = (ptr + idx * 12)[5];
        break;
    case 2:
        idx = (ptr + idx * 12)[6];
        break;
    case 3:
        idx = (ptr + idx * 12)[7];
        break;
    }

    return idx;
}
