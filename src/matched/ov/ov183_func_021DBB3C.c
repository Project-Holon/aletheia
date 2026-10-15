/*
 * function: BR_CODEIN_RecordDestroy
 * address: 0x021DBB3C
 * packet: pkt_ov183_021DBB3C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_RecordDeleteProfileScreen 0x021DCE28 thumb ov183
 *   BR_CODEIN_RecordDeleteActors 0x021DCE48 thumb ov183
 *   BR_CODEIN_RecordDeleteButtons 0x021DD054 thumb ov183
 *   BR_CODEIN_RecordDeleteTextWin 0x021DD0F4 thumb ov183
 *   BR_CODEIN_RecordTeardownTextWin 0x021DD1D4 thumb ov183
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj00050.h"
#include "../include/Obj06598.h"
#include "../include/Obj24541.h"
extern void BR_CODEIN_RecordDeleteProfileScreen(char *,char *);
extern void BR_CODEIN_RecordDeleteActors(char *,char *);
extern void BR_CODEIN_RecordDeleteButtons(char *,char *);
extern void BR_CODEIN_RecordDeleteTextWin(char *,char *);
extern void BR_CODEIN_RecordTeardownTextWin(char *,char *);
typedef unsigned int   u32;
struct PrintSys;
extern void BG_SYS_PushTile(u32 index);
extern void BR_UTIL_DeleteTextWin(void *,int);
extern void BR_UTIL_DeleteHandles(char *);
extern void BR_UTIL_DeleteTask(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BMP_OAM_DeleteSys(void *p);
struct Proc;
extern void func_020315D4(struct Proc *p);
int BR_CODEIN_RecordDestroy(int task,int b,char *q,char *p)
{
    int i;
    BR_CODEIN_RecordDeleteProfileScreen(p,q);
    BR_CODEIN_RecordDeleteActors(p,q);
    BR_CODEIN_RecordDeleteButtons(p,q);
    BR_CODEIN_RecordDeleteTextWin(p,q);
    BR_CODEIN_RecordTeardownTextWin(p,q);
    ((struct Obj06598 *)q)->f4=((struct Obj00050 *)p)->fC8;
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    if(((struct Obj00050 *)p)->f18) {
        BR_UTIL_DeleteTextWin(((struct Obj00050 *)p)->f18,((struct Obj24541 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        ((struct Obj00050 *)p)->f18=0;
    }
    for(i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(p+i*4+0xc));
    BR_UTIL_DeleteTask((void *)(((struct Obj00050 *)p)->f8));
    PRINTSYS_QUE_Delete(((struct Obj00050 *)p)->f4);
    BMP_OAM_DeleteSys((void *)(((struct Obj00050 *)p)->f0));
    func_020315D4((struct Proc *)task);
    return 1;
}
