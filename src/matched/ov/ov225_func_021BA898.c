/*
 * function: func_021BA898
 * address: 0x021BA898
 * packet: pkt_ov225_021BA898
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: index before 0x60 keeps field offset in immediate; distinct loop
 * parent local restores r7 parent / r6 destination allocation.
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   MANUAL_GRAPHIC_GetClactUnit 0x021B9A08 thumb ov225
 *   func_021BA9D0 0x021BA9D0 thumb ov225
 *   d_021BBF8C 0x021BBF8C data ov225 a2
 *   d_021BBF94 0x021BBF94 data ov225 a2
 */
#include "../include/Obj00074.h"
#include "../include/Obj14804.h"
#include "../include/Obj14805.h"
#include "../include/Obj26185.h"
#include "../include/Obj26186.h"
#include "../include/Obj26187.h"
#include "../include/Obj26188.h"
#include "../include/Obj26189.h"
#include "../include/Obj26190.h"
#include "../include/Obj26191.h"
#include "../include/Obj26192.h"
#include "../include/Obj26193.h"
#include "../include/Obj26194.h"
#include "../include/Obj26195.h"
#include "../include/Obj26196.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Quad { short x,y,z,w; };
extern const struct Quad d_021BBF8C,d_021BBF94;
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *,u32,u32,u32,u32,u32,u32,u16);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 MANUAL_GRAPHIC_GetClactUnit(const u8 *p);
extern void func_021BA9D0(char *);
void func_021BA898(char *p)
{
    struct Quad q[2];
    u8 i;
    char *parent;
    func_02049B68(((struct Obj26185 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,0,4,0,0x40,((struct Obj26186 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    func_02049658(((struct Obj26187 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,2,4,0,0,0,((struct Obj26188 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt(((struct Obj26189 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,5,4,0,0,0,0,((struct Obj26190 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f54=CLACT_RegisterPaletteEx(((struct Obj26191 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,1,1,0,0,1,((struct Obj26192 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f50=CLACT_RegisterCharacter(((struct Obj26193 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,3,0,1,((struct Obj26194 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f58=CLACT_RegisterCellAnim(((struct Obj26195 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,7,8,((struct Obj26196 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    q[1]=d_021BBF8C;
    parent=*(char * *)&((struct Obj00074 *)p)->f4;
    ((struct Obj00074 *)p)->f5C=CLACT_CreateActor((void *)MANUAL_GRAPHIC_GetClactUnit(((struct Obj14804 *)parent)->f8),((struct Obj00074 *)p)->f50,((struct Obj00074 *)p)->f54,((struct Obj00074 *)p)->f58,&q[1],1,((struct Obj14804 *)parent)->f4);
    CLACT_SetActorDrawEnable(((struct Obj00074 *)p)->f5C,0);
    CLACT_SetActorAutoAnim(((struct Obj00074 *)p)->f5C,1);
    q[0]=d_021BBF94;
    for(i=0;i<8;i++) {
        char *loopparent;
        q[0].y=i*24-8;
        loopparent=*(char * *)&((struct Obj00074 *)p)->f4;
        *(void **)(p+i*4+0x60)=CLACT_CreateActor((void *)MANUAL_GRAPHIC_GetClactUnit(((struct Obj14805 *)loopparent)->f8),((struct Obj00074 *)p)->f50,((struct Obj00074 *)p)->f54,((struct Obj00074 *)p)->f58,&q[0],1,((struct Obj14805 *)loopparent)->f4);
        CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x60),0);
        CLACT_SetActorAutoAnim(*(void **)(p+i*4+0x60),1);
    }
    func_021BA9D0(p);
}
