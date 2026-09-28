/*
 * function: func_021572A8
 * address:  0x021572A8
 * packet:   pkt_ov010_021572A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct Deal {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
} Deal;

void func_021572A8(Deal *d, u32 v)
{
    d->f08[0] = v;
    d->f08[1] = (v & 0xFF00) >> 8;
    d->f08[2] = (v & 0xFF0000) >> 16;
}
