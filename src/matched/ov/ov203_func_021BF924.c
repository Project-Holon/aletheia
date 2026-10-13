/*
 * function: func_021BF924
 * address: 0x021BF924
 * packet: pkt_ov203_021BF924
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BE9E8 0x021BE9E8 thumb ov203
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 */
#include "../include/Obj02250.h"
typedef unsigned int   u32;
struct S02031140;
struct Tcbl;
extern void func_021BE9E8(int);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_02049238(void *);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern int GFL_USE_PopBgm(void);
void func_021BF924(char *p)
{
    if(((struct Obj02250 *)p)->f2C) func_021BE9E8(((struct Obj02250 *)p)->f2C);
    TCBL_DeleteAllTasks(((struct Obj02250 *)p)->f20);
    if(((struct Obj02250 *)p)->f19) {
        GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(60);
    }
    func_02049238(((struct Obj02250 *)p)->f28);func_0201D83C(((struct Obj02250 *)p)->f24);func_02031140(((struct Obj02250 *)p)->f20);
}
