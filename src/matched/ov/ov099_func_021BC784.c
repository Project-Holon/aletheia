/*
 * function: WIFICLUB_StateExitDeclined
 * address: 0x021BC784
 * packet: pkt_ov099_021BC784
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov099/unit_021BB954.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned long  u32;
int WIFICLUB_StateExitDeclined(u8 *p, int b);

int WIFICLUB_StateExitDeclined(u8 *p, int b)
{
    p[0x1353] = 0x4a;
    *(u32 *)(p + 0x1cc) = 0x8a;
    return b;
}
