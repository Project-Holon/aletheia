/*
 * function: GAME_DATA_GetIntrudeIdByte
 * address:  0x0215841C
 * packet:   pkt_0215841C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte out of the arm9 reader, zero-extended.
 *
 * symbols:
 *   GAME_DATA_GetIntrudeId   0x02012B80  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);

u8 GAME_DATA_GetIntrudeIdByte(void *p)
{
    return (u8)(unsigned)GAME_DATA_GetIntrudeId(p);
}

