/*
 * function: GX_BeginLoadClearImage
 * address:  0x0207FB2C
 * packet:   pkt_0207FB2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208098C 0x0208098C arm
 *   g_02150E2C 0x02150E2C data
 */

typedef unsigned long u32;
typedef struct {
    int clrImg;
    u32 texLCDCBlk1;
    u32 texPlttLCDCBlk;
    int texPltt;
    u32 clrImgLCDCBlk;
    int tex;
    u32 texLCDCBlk2;
    u32 szTexBlk1;
} GXLoad3DState;
#define sClrImg (*(GXLoad3DState *)0x02150E2C)
extern int func_0208098C(void);

void GX_BeginLoadClearImage(void)
{
    int fmt = func_0208098C();
    sClrImg.clrImg = fmt;
    switch (fmt) {
    case 2:
    case 3:
        sClrImg.clrImgLCDCBlk = 0x06800000;
        break;
    case 8:
    case 12:
        sClrImg.clrImgLCDCBlk = 0x06840000;
        break;
    case 1:
        sClrImg.clrImgLCDCBlk = 0x067E0000;
        break;
    case 4:
        sClrImg.clrImgLCDCBlk = 0x06820000;
        break;
    }
}
