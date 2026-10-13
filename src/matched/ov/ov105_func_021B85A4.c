/*
 * unit: yes
 * function: IRC_RESULT_UpdateRankFade, IRC_RESULT_StartRankFade, IRC_RESULT_IsRankFadeFinished
 * address: 0x021B85A4
 * packet: pkt_ov105_021B85A4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 376-byte lead,20-byte reset871C,4-byte getter8730; no tail data.
 * lever: 3-byte table rows unify index array and count field relocations.
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   IRC_RESULT_BlendPaletteEntry 0x021B8734 thumb ov105
 *   sResultRankFadeRows 0x021B8984 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void IRC_RESULT_BlendPaletteEntry(u16 *,int,u8,u8,u8,u16,u16);
typedef struct { u8 index[2]; u8 count; } Row;
extern const Row sResultRankFadeRows[];
#define W(off) (*(unsigned *)(p+(off)))
#define H(off) (*(u16 *)(p+(off)))
void IRC_RESULT_UpdateRankFade(u8 *p)
{
    int i;
    if (!W(0x50)) return;
    switch(W(0x58)) {
    case 0:
        if(H(0x56)>H(0x54)) {
            if(W(0x5c)) W(0x58)=1;
            else { W(0x4c)=1; W(0x50)=0; }
            return;
        }
        if(!W(0x48)) GFL_USE_PlaySeDefaultVolume(2000+H(0x56));
        for(i=0;i<sResultRankFadeRows[H(0x56)].count;++i) {
            int index=sResultRankFadeRows[H(0x56)].index[i];
            IRC_RESULT_BlendPaletteEntry((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,0x7fff,((u16 *)(p+8))[index]);
        }
        if(W(0x48)++>=40) { W(0x48)=0; ++H(0x56); }
        break;
    case 1:
        if(W(0x48)++>=60) { W(0x48)=0; W(0x58)=2; }
        break;
    case 2:
        if(!W(0x48)) GFL_USE_PlaySeDefaultVolume(1998+H(0x56));
        for(i=0;i<sResultRankFadeRows[H(0x56)-1].count;++i) {
            int index=sResultRankFadeRows[H(0x56)-1].index[i];
            IRC_RESULT_BlendPaletteEntry((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,((u16 *)(p+8))[index],0x7fff);
        }
        if(W(0x48)++>=40) { W(0x48)=0; W(0x4c)=1; W(0x50)=0; }
        break;
    }
}
void IRC_RESULT_StartRankFade(u8 *p)
{
    W(0x50)=1; W(0x4c)=0; H(0x56)=1; W(0x58)=0; W(0x48)=0;
}
unsigned IRC_RESULT_IsRankFadeFinished(u8 *p)
{
    return W(0x4c);
}
