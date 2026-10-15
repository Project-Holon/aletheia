/*
 * function: WF2DMAP_SCRDRAW_LoadPalette
 * address: 0x021C5AAC
 * packet: pkt_ov127_021C5AAC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sWf2dmapPaletteDesc 0x021C60C4 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u32 a[4]; u8 b[12]; u32 c; } Descriptor;
extern const Descriptor sWf2dmapPaletteDesc;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_InitBgLayer(u8,void *,int);
extern void func_02040588(unsigned char which, unsigned char enable);
void WF2DMAP_SCRDRAW_LoadPalette(void *unused, u32 id, u8 *p)
{
    Descriptor d;
    d=sWf2dmapPaletteDesc;
    d.b[1]=p[2]; d.b[2]=p[3]; d.b[3]=p[4];
    d.b[8]=p[5]; d.b[9]=p[6]; d.b[10]=0; d.c=p[7];
    BG_SYS_FreeLayerBuf((u8)id);
    BG_SYS_InitBgLayer(id,&d,0);
    func_02040588(id,1);
}
