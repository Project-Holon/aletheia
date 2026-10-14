/*
 * function: func_021DCE48
 * address: 0x021DCE48
 * packet: pkt_ov183_021DCE48
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00050.h"
#include "../include/Obj02893.h"
#include "../include/Obj24572.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void BR_UTIL_Delete(u8 *p);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void func_020409B4(u32 index);
void func_021DCE48(char *p,char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD4) {
        for(i=0;i<12;i++) {
            slot=p+i*4;
            if(((struct Obj02893 *)slot)->f80) {
                CLACT_SetActorDrawEnable(((struct Obj02893 *)slot)->f80,0);
                CLACT_DeleteActor(((struct Obj02893 *)slot)->f80);
                *(int *)&((struct Obj02893 *)slot)->f80=0;
            }
            if(((struct Obj02893 *)slot)->f50!=-1) { CLACT_ReleaseCharacter(((struct Obj02893 *)slot)->f50); ((struct Obj02893 *)slot)->f50=-1; }
        }
        if(((struct Obj00050 *)p)->f48!=-1) { CLACT_ReleasePalette(((struct Obj00050 *)p)->f48); ((struct Obj00050 *)p)->f48=-1; }
        if(((struct Obj00050 *)p)->f4C!=-1) { CLACT_ReleaseCellAnim(((struct Obj00050 *)p)->f4C); ((struct Obj00050 *)p)->f4C=-1; }
        for(i=0;i<5;i++) {
            slot=p+i*4;
            if(((struct Obj02893 *)slot)->f30) { BR_UTIL_Delete(((struct Obj02893 *)slot)->f30); *(int *)&((struct Obj02893 *)slot)->f30=0; }
        }
        BR_RES_ApplyBgSet(((struct Obj24572 *)q)->f10,6);
        func_020409B4(1);
        ((struct Obj00050 *)p)->fD4=0;
    }
}
