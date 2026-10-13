/*
 * function: BTL_SERVER_CMD_ReadU24
 * address:  0x021CCB78
 * packet:   pkt_021CCB78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadU24   0x021CCB78  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 pos;
} ByteStream;

/* read a 24-bit big-endian value and advance the cursor */
u32 BTL_SERVER_CMD_ReadU24(ByteStream *s)
{
    u32 pos = s->pos;
    u8 *p = (u8 *)s + pos;
    u32 v = (p[8] << 16) | (p[9] << 8) | p[10];

    s->pos = pos + 3;
    return v;
}
