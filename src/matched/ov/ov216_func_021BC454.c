/*
 * function: func_021BC454
 * address: 0x021BC454
 * packet: pkt_ov216_021BC454
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: two Config locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 * symbols:
 *   configA 0x021BDB28 data a2
 *   configB 0x021BDB34 data a2
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   func_021BC3E4 0x021BC3E4 thumb ov216
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   NNS_G2dGetUnpackedCharacterData 0x02062A00 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 */
#include "../include/Obj01783.h"
#include "../include/Obj10946.h"
#include "../include/Obj25771.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {unsigned char a,b,c,pad;u16 first,second,third;} Config;
struct ArcFile;struct NitroFileHeader;
extern const Config configA,configB;
extern int POKEGRA_OpenTrainerHandle(int a0);
extern void func_021BC3E4(u16 *,int *,const Config *,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,u32,u32);
extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *,void **);
extern int NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *,void **);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 POKEGRA_RegisterTrainerCgr(u32,u32,u32,u32);
typedef signed int     s32;
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
void func_021BC454(char *p,u32 handle)
{
    Config a,b;
    struct ArcFile *arc;
    int i;
    ((struct Obj01783 *)p)->f58=POKEGRA_OpenTrainerHandle(((struct Obj01783 *)p)->f0);
    a=configA;
    func_021BC3E4((u16 *)p,(int *)(p+92),&a,handle);
    b=configB;
    arc=func_020490F4(32,((struct Obj01783 *)p)->f2);
    func_021BC3E4((u16 *)p,(int *)(p+128),&b,(u32)arc);
    ((struct Obj01783 *)p)->f114=ARC_TOOL_LoadHandleMember(arc,0,((struct Obj01783 *)p)->f0);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct Obj01783 *)p)->f114,(void **)(p+268));
    ((struct Obj01783 *)p)->f110=((struct Obj25771 *)(*(char * *)&((struct Obj01783 *)p)->f10C))->fC;
    for(i=0;i<16;i++){
        *(void **)(p+i*8+144)=ARC_TOOL_LoadHandleMember(arc,i+49,((struct Obj01783 *)p)->f0);
        NNS_G2dGetUnpackedCharacterData(*(struct NitroFileHeader **)(p+i*8+144),(void **)(p+140+i*8));
    }
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<2;i++){
        char *q=p+i*12;
        ((struct Obj10946 *)q)->f6C=POKEGRA_RegisterTrainerCgr(((struct Obj01783 *)p)->f58,i+2,1,((struct Obj01783 *)p)->f0);
        ((struct Obj10946 *)q)->f68=(u32)POKEGRA_RegisterTrainerPalette(((struct Obj01783 *)p)->f58,i+2,1,(u16)((i+8)<<5),((struct Obj01783 *)p)->f0);
        ((struct Obj10946 *)q)->f70=POKEGRA_RegisterTrainerCellAnim(i+2,0,1,((struct Obj01783 *)p)->f0);
    }
}
