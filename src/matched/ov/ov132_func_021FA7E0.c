/*
 * function: STA_ACT_BUTTON_CreateActors
 * address: 0x021FA7E0
 * packet: pkt_ov132_021FA7E0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 021FA99A zero halfword is alignment padding before labelled 021FA99C.
 * ABI: B294 forwards an address-valued u32 payload and returns the actor in r0; ABF0 tail-forwards AC18's index despite void declaration.
 * symbols:
 *   STA_ACTING_GetActorCount 0x021F9E0C thumb ov132
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_GetElemSizeFlags 0x021F4F70 thumb ov112
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   STA_ACT_BUTTON_LoadCharacter 0x021FA99C thumb ov132
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj00151.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {s16 x,y,index;u8 a,b;} Params;
struct Bank;
extern u32 STA_ACTING_GetActorCount(u8 *p);
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *,int);
extern int MUSICAL_MCSS_GetElemSizeFlags(int *);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16),CLACT_RegisterCharacter(void *,u32,u32,u32,u16),CLACT_RegisterCellAnim(void *,u32,u32,u32),CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void STA_ACT_BUTTON_LoadCharacter(u8 *p, u16 slot, int resource, u32 type);
void STA_ACT_BUTTON_CreateActors(char *p)
{
    Params configs[2];
    u8 *table;
    void *narc;
    u8 i=0;
    int format;
    table=(u8 *)STA_ACTING_GetActorCount((u8 *)(*(char * *)&((struct Obj00151 *)p)->f4));
    ((struct Obj00151 *)p)->f18=CLACT_CreateUnit(5,0,((struct Obj00151 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj00151 *)p)->f18);
    narc=func_020490F4(47,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f1C=CLACT_RegisterPaletteEx(narc,0,1,0,0,2,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f28=CLACT_RegisterCharacter(narc,6,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f34=CLACT_RegisterCellAnim(narc,18,21,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f20=CLACT_RegisterPaletteEx(narc,1,1,64,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f2C=CLACT_RegisterCharacter(narc,7,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f38=CLACT_RegisterCellAnim(narc,19,22,((struct Obj00151 *)p)->f0);
    ARC_TOOL_DeleteHandle(narc);
    narc=func_020490F4(46,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f24=CLACT_RegisterPalette(narc,0,1,96,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f30=CLACT_RegisterCharacter(narc,26,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f3C=CLACT_RegisterCellAnim(narc,18,22,((struct Obj00151 *)p)->f0);
    ARC_TOOL_DeleteHandle(narc);
    for(i=0;i<2;i++) {
        if(*(u16 *)(p+i*2+0x48)!=255) {
            format=MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table,*(u16 *)(p+i*2+0x48)));
            if(i==0) configs[1].x=32;
            else configs[1].x=224;
            configs[1].y=160;
            configs[1].index=i;
            configs[1].a=10;
            configs[1].b=0;
            *(void **)(p+i*4+0x4c)=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00151 *)p)->f18,((struct Obj00151 *)p)->f28,((struct Obj00151 *)p)->f1C,((struct Obj00151 *)p)->f34,&configs[1],1,((struct Obj00151 *)p)->f0);
            configs[1].index=0;
            *(void **)(p+i*4+0x54)=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00151 *)p)->f18,((struct Obj00151 *)p)->f2C,((struct Obj00151 *)p)->f20,((struct Obj00151 *)p)->f38,&configs[1],1,((struct Obj00151 *)p)->f0);
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x4c),0);
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x54),0);
            STA_ACT_BUTTON_LoadCharacter((u8 *)p,i,*(u16 *)(p+i*2+0x48),format);
        }
    }
    configs[0].x=128; configs[0].y=96; configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct Obj00151 *)p)->f5C=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00151 *)p)->f18,((struct Obj00151 *)p)->f30,((struct Obj00151 *)p)->f24,((struct Obj00151 *)p)->f3C,&configs[0],1,((struct Obj00151 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00151 *)p)->f5C,0);
    CLACT_SetActorAutoAnim(((struct Obj00151 *)p)->f5C,1);
}
