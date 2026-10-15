/*
 * function: BR_GRAPHIC_End3d
 * address: 0x021FC640
 * packet: pkt_ov186_021FC640
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDCNT 04000050 and DISPCNT 04000000, read-modify-write at 021FC64A..021FC650.
 * symbols:
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_0220099C 0x0220099C data a4
 */
typedef struct BgTemplate {unsigned words[8];} BgTemplate;
typedef struct Record {unsigned id;BgTemplate template;unsigned type,enable;} Record;
extern const Record d_0220099C[];
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
typedef unsigned int   u32;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void func_02040588(unsigned char which, unsigned char enable);
void BR_GRAPHIC_End3d(void)
{
    unsigned i,id;
    const Record *r;
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    GX_SetGraphicsMode(1,0,0);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        if(id<4){BG_SYS_InitBgLayer((unsigned char)id,&r->template,(unsigned char)r->type);BG_SYS_FreeSlot(id);}
        func_02040588((unsigned char)id,(unsigned char)r->enable);
    }
}
