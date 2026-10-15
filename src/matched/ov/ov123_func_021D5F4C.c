/*
 * function: GSYNC_DISP_InitBgLayers
 * address: 0x021D5F4C
 * packet: pkt_ov123_021D5F4C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGsyncDispBgTemplates 0x021DA758 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BgTemplate {
    u32 unk00, unk04, bufSize, unk0c;
    u8 unk10, unk11, unk12, unk13;
    u32 unk14;
    u8 unk18, unk19, unk1a, unk1b;
    u32 unk1c;
};
extern const struct BgTemplate gGsyncDispBgTemplates[7];
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020409B4(u32);
extern void BG_SYS_Init(u32,u32,u32,u32);
extern void func_02041300(u32,u32,u32,u32,u8,u8,u8);
void GSYNC_DISP_InitBgLayers(u8 *p)
{
    struct BgTemplate b[7];
    b[6]=gGsyncDispBgTemplates[0]; BG_SYS_InitBgLayer(0,&b[6],0); func_02040588(0,1); func_020409B4(0);
    b[5]=gGsyncDispBgTemplates[1]; BG_SYS_InitBgLayer(1,&b[5],0); func_02040588(1,1); func_020409B4(1);
    b[4]=gGsyncDispBgTemplates[2]; BG_SYS_InitBgLayer(3,&b[4],0); func_02040588(3,1); func_020409B4(3);
    b[3]=gGsyncDispBgTemplates[3]; BG_SYS_InitBgLayer(4,&b[3],0); func_02040588(4,1); func_020409B4(4);
    b[2]=gGsyncDispBgTemplates[4]; BG_SYS_InitBgLayer(5,&b[2],0);
    BG_SYS_Init(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=gGsyncDispBgTemplates[5]; BG_SYS_InitBgLayer(6,&b[1],0); func_02040588(6,1);
    BG_SYS_Init(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=gGsyncDispBgTemplates[6]; BG_SYS_InitBgLayer(7,&b[0],0); func_02040588(7,1); func_020409B4(7);
}
