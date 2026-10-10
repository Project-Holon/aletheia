/*
 * function: func_02157948
 * address: 0x02157948
 * packet: pkt_ov010_02157948
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov010/delivery_beacon.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad00[0x670]; u16 f670; } Dress_02157948;

void func_02157948(Dress_02157948 *d)
{
    d->f670 = 1;
}
