/*
 * function: OEKAKI_ClearStrokeGroup
 * address: 0x02186938
 * packet: pkt_ov023_02186938
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x02186956.
 */
typedef unsigned char u8;
typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec;
void OEKAKI_ClearStrokeGroup(Rec *p)
{
    int i;
    for (i = 0; i < 5; i++) p[i].mid = 0;
}
