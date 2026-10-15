/*
 * function: ZUKAN_LIST_CreateWindows
 * address: 0x021BD398
 * packet: pkt_ov209_021BD398
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   ZUKAN_LIST_DrawHeaderRegional 0x021BD5D4 thumb ov209
 *   gZukanListWindowDefs 0x021BE990 data a1
 */
typedef unsigned char u8;
extern void BMP_WIN_Init(unsigned short);
extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern void ZUKAN_LIST_DrawHeaderRegional(char *);
extern const u8 gZukanListWindowDefs[][6];
void ZUKAN_LIST_CreateWindows(char *p)
{
    unsigned i;
    BMP_WIN_Init(107);
    for (i = 0; i < 3; i++)
        *(unsigned *)(p + i * 8 + 32) = BMP_WIN_Create(gZukanListWindowDefs[i][0], gZukanListWindowDefs[i][1], gZukanListWindowDefs[i][2], gZukanListWindowDefs[i][3], gZukanListWindowDefs[i][4], gZukanListWindowDefs[i][5], 1);
    ZUKAN_LIST_DrawHeaderRegional(p);
}
