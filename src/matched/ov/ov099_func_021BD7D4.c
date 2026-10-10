/*
 * function: func_021BD7D4
 * address: 0x021BD7D4
 * packet: pkt_ov099_021BD7D4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov099/unit_021BCF9C.c and filed here.
 */

typedef unsigned char  u8;
typedef unsigned long  u32_021BCF9C;
int func_021BD7D4(u8 *p, int b);

/*
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 */
int func_021BD7D4(u8 *p, int b)
{
    *(u32_021BCF9C *)(p + 0x1cc) = 0x15;
    return b;
}
