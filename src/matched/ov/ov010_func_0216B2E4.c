/*
 * function: FIELD_INTRUDE_EVENT_GetEdgePosition
 * address:  0x0216B2E4
 * packet:   pkt_ov010_0216B2E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 12-byte vector, then overwrites one component per case 0-3
 * (cases 4-9 leave it as copied).
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V12;

void FIELD_INTRUDE_EVENT_GetEdgePosition(V12 *src, int kind, V12 *dst)
{
    *dst = *src;
    switch (kind) {
    case 0:
        dst->z = 0x62 << 14;
        break;
    case 1:
        dst->z = 0x26 << 14;
        break;
    case 2:
        dst->x = 0x6A << 14;
        break;
    case 3:
        dst->x = 0x16 << 14;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}
