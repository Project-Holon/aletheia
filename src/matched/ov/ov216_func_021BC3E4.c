/*
 * function: BEACON_DETAIL_GRA_RegisterActorGfx
 * address: 0x021BC3E4
 * packet: pkt_ov216_021BC3E4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 */
typedef struct { unsigned char a,b,c,pad; unsigned short first,second,third; } Config;
extern void MI_CpuFill8(void *,int,int);
extern signed int CLACT_RegisterPaletteEx(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned short e, unsigned short f, unsigned short g);
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
void BEACON_DETAIL_GRA_RegisterActorGfx(unsigned short *p,int *out,const Config *cfg,void *handle)
{
    MI_CpuFill8(out,0,12);
    out[0]=CLACT_RegisterPaletteEx(handle,cfg->first,cfg->a,(unsigned short)(cfg->b<<5),0,cfg->c,*p);
    out[1]=CLACT_RegisterCharacter((void *)handle,cfg->second,0,cfg->a,*p);
    out[2]=CLACT_RegisterCellAnim((void *)handle,cfg->third,cfg->third+1,*p);
}
