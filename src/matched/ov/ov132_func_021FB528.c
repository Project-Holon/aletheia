/*
 * function: func_021FB528
 * address: 0x021FB528
 * packet: pkt_ov132_021FB528
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Void callback return omits the extra zero result instruction.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   func_021FAE4C 0x021FAE4C thumb ov132
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 */
#include "../include/Obj08163.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetActorSystem(char *p);
extern int func_021FAE4C(char *,int *);
extern void func_021F8054(void *,unsigned int *,const unsigned int *);
extern void func_021FADF8(char *p, char *q);
void func_021FB528(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetActorSystem(((struct Obj08163 *)p)->f4); result=func_021FAE4C(p+4,pos); func_021F8054(ctx,*(unsigned int * *)&((struct Obj08163 *)p)->f0,(unsigned int *)pos); if(result==1)func_021FADF8(((struct Obj08163 *)p)->f30,((struct Obj08163 *)p)->f34); }
