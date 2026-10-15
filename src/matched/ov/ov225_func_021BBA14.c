/*
 * unit: yes
 * function: MANUAL_CATEGORY_DeleteDetailList, MANUAL_CATEGORY_IsDetailFinished, MANUAL_CATEGORY_DetailTaskNoop
 * address: 0x021BBA14
 * packet: pkt_ov225_021BBA14
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 94-byte unit; two zero alignment bytes at 021BBA72 are outside the unit.
 * followers: parent cleared 021BBA64 tail stub and 021BBA70 empty Thumb leaf.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA740 0x021BA740 thumb ov225
 *   func_020307B0 0x020307B0 arm
 *   func_021BA760 0x021BA760 thumb ov225
 */
#include "../include/Obj01790.h"
#include "../include/Obj26296.h"
#include "../include/Obj26297.h"
#include "../include/Obj26298.h"
#include "../include/Obj26299.h"
#include "../include/Obj26300.h"
#include "../include/Obj26301.h"
#include "../include/Obj26302.h"
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021BA740(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern int func_021BA760(char *p);
void MANUAL_CATEGORY_DeleteDetailList(char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj01790 *)p)->f20);
    ((struct Obj26296 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f6 = ((struct Obj01790 *)p)->f14;
    ((struct Obj26297 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f8 = ((struct Obj01790 *)p)->f16;
    if (((struct Obj01790 *)p)->f18 == 0) ((struct Obj26298 *)(*(char * *)&((struct Obj01790 *)p)->f0))->fC = 0;
    else if (((struct Obj01790 *)p)->f18 == 1) {
        ((struct Obj26299 *)(*(char * *)&((struct Obj01790 *)p)->f0))->fC = 1;
        ((struct Obj26301 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f10 = *(u16 *)(*(char * *)&((struct Obj01790 *)p)->f10 + ((struct Obj26300 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f8 * 8);
    }
    func_021BA740(*(char * *)&((struct Obj01790 *)p)->f1C);
    func_020307B0(((struct Obj01790 *)p)->f10);
    func_020307B0(p);
}
int MANUAL_CATEGORY_IsDetailFinished(char *p)
{
    return func_021BA760(*(char * *)&((struct Obj26302 *)p)->f1C);
}
void MANUAL_CATEGORY_DetailTaskNoop(void)
{
}
