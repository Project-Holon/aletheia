/*
 * function: BEACON_DETAIL_GRA_LoadPalette
 * address: 0x021BCD08
 * packet: pkt_ov216_021BCD08
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 */
extern void DWCi_ScreenDC_FlushRange(void *,unsigned);
extern void GX_LoadBGPltt(void *,unsigned,unsigned);
extern void func_0207E468(void *,unsigned,unsigned);
extern void GX_LoadOBJPltt(void *,unsigned,unsigned);
extern void func_0207E5D0(void *,unsigned,unsigned);
void BEACON_DETAIL_GRA_LoadPalette(void *p,unsigned mode,unsigned a,unsigned b)
{
    unsigned x=a*2,y=b*2;
    DWCi_ScreenDC_FlushRange(p,y);
    switch(mode) {
    case 0: GX_LoadBGPltt(p,x,y); break;
    case 1: func_0207E468(p,x,y); break;
    case 2: GX_LoadOBJPltt(p,x,y); break;
    case 3: func_0207E5D0(p,x,y); break;
    }
}
