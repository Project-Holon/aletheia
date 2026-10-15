/*
 * function: BEACON_DETAIL_GRA_DrawWindowRecord
 * address: 0x021BD07C
 * packet: pkt_ov216_021BD07C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_FillRect 0x02043AF4 arm
 *   BEACON_DETAIL_GRA_DrawRecord 0x021BDA54 thumb ov216
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021BDD8A 0x021BDD8A data a2
 */
struct Four { unsigned short a; unsigned char b,c; };
extern const struct Four d_021BDD8A[];
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bmp;
struct Cfg;
struct Descriptor;
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
typedef unsigned short u16;
extern void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(unsigned int);
void BEACON_DETAIL_GRA_DrawWindowRecord(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e)
{
    void *x;
    BMP_FillRect(q[1],(short)(a*8),0,(unsigned short)(c*8),(unsigned short)(d*8),d_021BDD8A[e].b);
    BEACON_DETAIL_GRA_DrawRecord(p,(char *)q,b,0,v,d_021BDD8A[e].a);
    x=q[0];
    BMP_WIN_TransferChars(x); BMP_WIN_MakeScreen(x); BG_SYS_PushTile(BMP_WIN_GetBgLayer(x));
}
