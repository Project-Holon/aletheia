/*
 * function: INTRUDE_COMM_RecvSymbolPage
 * address: 0x02174898
 * packet: pkt_ov011_02174898
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_021743B4.c and filed here.
 */

typedef unsigned char  u8;
typedef struct { int d[21]; } B54;
typedef struct { u8 pad[0x8f8]; u8 f0 : 1; u8 f1 : 1; u8 f2 : 1; u8 f3 : 5; } F_02174854;
void INTRUDE_COMM_RecvSymbolPage(int a, int b, B54 *c, u8 *p);

void INTRUDE_COMM_RecvSymbolPage(int a, int b, B54 *c, u8 *p)
{
    *(B54 *)(p + 0x82c) = *c;
    ((F_02174854 *)p)->f1 = 1;
    ((F_02174854 *)p)->f2 = 0;
}
