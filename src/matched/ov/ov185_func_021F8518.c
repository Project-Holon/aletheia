/*
 * function: BR_POKESEARCH_DestroyWork
 * address: 0x021F8518
 * packet: pkt_ov185_021F8518
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   BR_POKESEARCH_ShowBg 0x021F8D5C thumb ov185
 *   BR_POKESEARCH_DestroyDetail 0x021F8E60 thumb ov185
 *   BR_POKESEARCH_DestroyText 0x021F8EE8 thumb ov185
 *   BR_POKESEARCH_DestroySearch 0x021F8F58 thumb ov185
 *   BR_POKESEARCH_DestroyMsgbox 0x021F8FB0 thumb ov185
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 */
#include "../include/Obj03337.h"
#include "../include/Obj04583.h"
extern void BR_POKESEARCH_ShowBg(char *,char *);
extern void BR_POKESEARCH_DestroyDetail(char *,char *);
extern void BR_POKESEARCH_DestroyText(char *p, int *a1);
extern void BR_POKESEARCH_DestroySearch(char *,char *);
extern void BR_POKESEARCH_DestroyMsgbox(char *,char *);
struct PrintSys;
extern void BR_UTIL_DeleteTask(void *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_UTIL_DeleteHandles(char *);
extern void BMP_OAM_DeleteSys(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_02034A5C(int);
extern char ov112_id[];
int BR_POKESEARCH_DestroyWork(int obj,int b,char *q,char *p)
{
    int i;
    BR_POKESEARCH_ShowBg(p,q);
    BR_POKESEARCH_DestroyDetail(p,q);
    BR_POKESEARCH_DestroyText(p,(int *)q);
    BR_POKESEARCH_DestroySearch(p,q);
    BR_POKESEARCH_DestroyMsgbox(p,q);
    BR_UTIL_DeleteTask((void *)(((struct Obj03337 *)p)->f24));
    BR_POKESEARCH_DestroySearch(p,q);
    BR_RES_ReleaseSprite((char *)(*(int *)&((struct Obj04583 *)q)->fC),6);
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(p+i*4+56));
    BMP_OAM_DeleteSys((void *)(((struct Obj03337 *)p)->f28));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03337 *)p)->f2C));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}
