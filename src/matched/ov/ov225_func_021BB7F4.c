/*
 * unit: yes
 * function: MANUAL_CATEGORY_DeleteList, MANUAL_CATEGORY_IsListFinished, MANUAL_CATEGORY_TaskNoop
 * address: 0x021BB7F4
 * packet: pkt_ov225_021BB7F4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 94-byte unit; two zero alignment bytes at 021BB852 are outside the unit.
 * followers: parent cleared 021BB844 tail stub and 021BB850 empty Thumb leaf.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA740 0x021BA740 thumb ov225
 *   func_020307B0 0x020307B0 arm
 *   func_021BA760 0x021BA760 thumb ov225
 */
#include "../include/Obj01789.h"
#include "../include/Obj26290.h"
#include "../include/Obj26291.h"
#include "../include/Obj26292.h"
#include "../include/Obj26293.h"
#include "../include/Obj26294.h"
#include "../include/Obj26295.h"
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021BA740(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern int func_021BA760(char *p);
void MANUAL_CATEGORY_DeleteList(char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj01789 *)p)->f20);
    *(u16 *)*(char * *)&((struct Obj01789 *)p)->f0 = ((struct Obj01789 *)p)->f14;
    ((struct Obj26290 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f2 = ((struct Obj01789 *)p)->f16;
    if (((struct Obj01789 *)p)->f18 == 0) ((struct Obj26291 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f4 = 0;
    else if (((struct Obj01789 *)p)->f18 == 1) {
        ((struct Obj26292 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f4 = 1;
        ((struct Obj26294 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f8 = *(u16 *)(*(char * *)&((struct Obj01789 *)p)->f10 + ((struct Obj26293 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f2 * 8);
    }
    func_021BA740(*(char * *)&((struct Obj01789 *)p)->f1C);
    func_020307B0(((struct Obj01789 *)p)->f10);
    func_020307B0(p);
}
int MANUAL_CATEGORY_IsListFinished(char *p)
{
    return func_021BA760(*(char * *)&((struct Obj26295 *)p)->f1C);
}
void MANUAL_CATEGORY_TaskNoop(void)
{
}
