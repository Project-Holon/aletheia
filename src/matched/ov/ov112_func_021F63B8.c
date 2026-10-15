/*
 * function: MUSICAL_MCSS_LoadCellBank
 * address: 0x021F63B8
 * packet: pkt_ov112_021F63B8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: an unqualified resource pointer keeps constant r2 setup before resource loads.
 * prototype: 6469C receives the sequence in r1 despite its one-argument matched definition.
 * prototype: 48F60/49F34/30734 heap inputs are narrowed immediately before each original call.
 * symbols:
 *   NNSi_G2dInitVramHandle 0x02063790 arm
 *   NNSi_G2dInitVramHandleEx 0x020637D4 arm
 *   ARC_UTIL_LoadCellBankFromArchive 0x02049FBC arm
 *   ARC_UTIL_LoadMultiCellBankFromArchive 0x0204A03C arm
 *   ARC_UTIL_LoadAnimBankFromArchive 0x0204A0BC arm
 *   ARC_UTIL_LoadMultiAnimBankFromArchive 0x0204A13C arm
 *   NNS_G2dGetAnimSequenceByIdx 0x020627D8 arm
 *   MUSICAL_MCSS_InitMCAnim 0x021F659C thumb ov112
 *   NNS_G2dSetAnimSequenceToMCAnimation 0x0206469C arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadBgCharDataFromArchive 0x02049DB4 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   MCSS_TOOL_DrawSpindaSpots 0x020172D8 thumb
 *   func_020056A0 0x020056A0 thumb
 *   MUSICAL_MCSS_FreeCellBank 0x021F6540 thumb ov112
 *   d_021F83D4 0x021F83D4 data a4
 */
#include "../include/Obj00722.h"
#include "../include/Obj13834.h"
#include "../include/Obj22550.h"
#include "../include/Obj22551.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
extern void NNSi_G2dInitVramHandle(u32 *);
extern void NNSi_G2dInitVramHandleEx(u32 *);
extern void *ARC_UTIL_LoadCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadMultiCellBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadAnimBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32,u32,u32,u32,u16);
extern struct AnimSequence *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *,u32);
extern void MUSICAL_MCSS_InitMCAnim(char *,int);
extern void NNS_G2dSetAnimSequenceToMCAnimation(struct Obj0206469C *o, void *bank);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void MCSS_TOOL_DrawSpindaSpots(u8 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern void MUSICAL_MCSS_FreeCellBank(void *,void **);
extern const char d_021F83D4[];
void MUSICAL_MCSS_LoadCellBank(u8 *a,int index,u32 *res,u32 mode)
{
    u8 *q=(*(u8 ***)(a+4))[index];
    void **job;
    struct AnimSequence *sequence;
    u8 *table;
    ((struct Obj00722 *)q)->fEC |= 4;
    NNSi_G2dInitVramHandle((u32 *)(q+144));
    NNSi_G2dInitVramHandleEx((u32 *)(q+180));
    ((struct Obj00722 *)q)->f0=ARC_UTIL_LoadCellBankFromArchive(res[0],res[3],0,(u32)(q+4),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f10=ARC_UTIL_LoadMultiCellBankFromArchive(res[0],res[4],1,(u32)(q+20),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f8=ARC_UTIL_LoadAnimBankFromArchive(res[0],res[5],0,(u32)(q+12),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f18=ARC_UTIL_LoadMultiAnimBankFromArchive(res[0],res[6],0,(u32)(q+28),((struct Obj00722 *)q)->fF4);
    sequence=NNS_G2dGetAnimSequenceByIdx(*(struct AnimBank * *)&((struct Obj00722 *)q)->f1C,0);
    MUSICAL_MCSS_InitMCAnim((char *)q,1);
    NNS_G2dSetAnimSequenceToMCAnimation((struct Obj0206469C *)(q+40),sequence);
    table=ARC_TOOL_LoadMember(res[0],res[7],(u16)(((struct Obj00722 *)q)->fF4));
    *(u8 * *)&((struct Obj00722 *)q)->f20=table;
    *(u8 * *)&((struct Obj00722 *)q)->f24=table+4+56* ((struct Obj22550 *)table)->f0;
    job=func_02030734((u16)((struct Obj00722 *)q)->fF4,36,1,d_021F83D4,1104);
    job[2]=q+144;
    job[3]=q+180;
    job[6]=*(u8 * *)&((struct Obj13834 *)a)->fC+index*16384;
    job[7]=*(u8 * *)&((struct Obj13834 *)a)->f10+index*32;
    job[8]=q;
    job[4]=ARC_UTIL_LoadBgCharDataFromArchive(res[0],res[1],1,(u32)job,((struct Obj00722 *)q)->fF4);
    job[5]=ARC_UTIL_LoadPaletteBlockFromArchive(res[0],res[2],(u32)(job+1),(u16)(((struct Obj00722 *)q)->fF4));
    if(res[7]==6548) MCSS_TOOL_DrawSpindaSpots(*(u8 * *)&((struct Obj22551 *)((u8 *)job[0]))->f14,res[8]);
    if(mode==1) func_020056A0((u32)MUSICAL_MCSS_FreeCellBank,(u32)job,0);
    else MUSICAL_MCSS_FreeCellBank(0,job);
}
