/*
 * function: TH_AWARD_CreateBgActors
 * address: 0x021B9B64
 * packet: pkt_ov220_021B9B64
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021B9B88 stores count byte, 021B9B8E immediately rereads it; only that reread is volatile.
 * prototype: 0204B294 original caller stores its live r0 return as actor despite owning void declaration.
 * symbols:
 * func_020490F4 0x020490F4 arm
 * CLACT_RegisterPaletteEx 0x0204AC18 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * MI_CpuFill8 0x02082BCC arm
 * TH_AWARD_GRAPHIC_GetActor 0x021BA1E0 thumb ov220
 * CLACT_CreateActor 0x0204B294 arm
 * CLACT_SetActorAnimSeq 0x0204B878 arm
 * CLACT_SetActorAutoAnim 0x0204B92C arm
 * table 0x021BA3AC data ov220 a1
 * coords 0x021BA338 data ov220 a2
 */
#include "../include/Obj01181.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Param {s16 x,y;u32 zero;};
extern const u8 table[],coords[];
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPaletteEx(void*,u32,u32,u32,u16,u16,u16),CLACT_RegisterCharacter(void*,u32,u32,u32,u16),CLACT_RegisterCellAnim(void*,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void*),MI_CpuFill8(void*,u32,u32);
extern u32 TH_AWARD_GRAPHIC_GetActor(u8 *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj*,u32);
void TH_AWARD_CreateBgActors(char *p)
{
    void *owner;
    struct Param param;
    u8 i=0;
    ((struct Obj01181 *)p)->f84=0;
    if(((struct Obj01181 *)p)->fB0!=7){
        ((struct Obj01181 *)p)->f84=*(const u8*)((u32)table+((struct Obj01181 *)p)->fB0*12);
        if(*(volatile u8 *)&((struct Obj01181 *)p)->f84){
            owner=func_020490F4(201,((struct Obj01181 *)p)->f0);
            *(int *)&((struct Obj01181 *)p)->f8C=CLACT_RegisterPaletteEx(owner,1,0,0,0,1,((struct Obj01181 *)p)->f0);
            *(int *)&((struct Obj01181 *)p)->f88=CLACT_RegisterCharacter(owner,3,0,0,((struct Obj01181 *)p)->f0);
            *(int *)&((struct Obj01181 *)p)->f90=CLACT_RegisterCellAnim(owner,6,7,((struct Obj01181 *)p)->f0);
            ARC_TOOL_DeleteHandle(owner);
            MI_CpuFill8(&param,0,8);
            for(;i<((struct Obj01181 *)p)->f84;i++){
                param.x=*(const s16*)((u32)coords+(u32)i*4);
                param.y=*(const s16*)((u32)coords+(u32)i*4+2);
                *(void**)((u32)p+(u32)i*4+0x94)=CLACT_CreateActor((void *)TH_AWARD_GRAPHIC_GetActor(*(void* *)&((struct Obj01181 *)p)->f8),((struct Obj01181 *)p)->f88,((struct Obj01181 *)p)->f8C,((struct Obj01181 *)p)->f90,&param,0,((struct Obj01181 *)p)->f0);
                CLACT_SetActorAnimSeq(*(void**)((u32)p+(u32)i*4+0x94),0);
                CLACT_SetActorAutoAnim(*(void**)((u32)p+(u32)i*4+0x94),1);
            }
        }
    }
}
