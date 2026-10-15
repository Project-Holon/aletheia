/*
 * function: ZUKAN_StartProc210
 * address: 0x021C9130
 * packet: pkt_ov212_021C9130
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02031348 legacy void(void) forwards untouched r0-r3 to
 * 020314F4; its matched body reads all four and caller sets all four.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PROCSYS_Push 0x02031348 arm
 *   ZUKAN_SetResumeState 0x021C8F90 thumb ov212
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021C0714 0x021C0714 data ov210 a4
 *   ov210_id 0x000000D2 data a1
 */
#include "../include/Obj06702.h"
#include "../include/Obj06703.h"
#include "../include/Obj25668.h"
typedef unsigned short u16;
struct Obj020314F4;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void PROCSYS_Push(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern int ZUKAN_SetResumeState(char *,int);
extern const char d_021C99A0[];
extern const unsigned d_021C0714[];
extern unsigned char ov210_id[];
void ZUKAN_StartProc210(char *p)
{
    char *q;
    q=func_02030734(105,24,0,d_021C99A0,455);
    ((struct Obj06702 *)p)->f28=q;
    ((struct Obj06703 *)q)->f0=**(unsigned * *)&((struct Obj06702 *)p)->f0;
    ((struct Obj06703 *)q)->f4=((struct Obj25668 *)(*(char * *)&((struct Obj06702 *)p)->f0))->f4;
    ((struct Obj06703 *)q)->f8=p+20;
    ((struct Obj06703 *)q)->f10=0;
    ((struct Obj06703 *)q)->f14=0;
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj06702 *)p)->f4,(unsigned)ov210_id,(unsigned)d_021C0714,*(unsigned *)&((struct Obj06702 *)p)->f28);
    ZUKAN_SetResumeState(p,8);
}
