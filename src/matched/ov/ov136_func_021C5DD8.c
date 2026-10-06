/*
 * function: func_021C5DD8
 * address: 0x021C5DD8
 * packet: pkt_ov136_021C5DD8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0202DB0C 0x0202DB0C thumb
 *   func_0202DE5C 0x0202DE5C thumb
 */
#include "../include/Obj04535.h"
#include "../include/Obj23533.h"
#include "../include/Obj23534.h"
#include "../include/Obj23535.h"
#include "../include/Obj23536.h"
#include "../include/Obj23537.h"
#include "../include/Obj23538.h"
typedef unsigned char u8;
extern unsigned int func_0201C440(void *p);
typedef unsigned int   u32;
struct Bank;
struct PmsDraw;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
typedef unsigned short u16;
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
void func_021C5DD8(u8 *p)
{
    ((struct Obj23533 *)(*(u8 * *)&((struct Obj04535 *)p)->f8))->f36C = (void *)func_0201C440((void *)102);
    ((struct Obj23534 *)(*(u8 * *)&((struct Obj04535 *)p)->f8))->f368 = func_0204B100(8,2,102);
    ((struct Obj23537 *)(*(u8 * *)&((struct Obj04535 *)p)->f8))->f35C = func_0202DB0C((u32)(((struct Obj23535 *)(*(u8 * *)&((struct Obj04535 *)p)->f8))->f368),1,(u32)(((struct Obj23536 *)(*(u8 * *)&((struct Obj04535 *)p)->f8))->f36C),(u32)(((struct Obj04535 *)p)->f18),4,4,102);
    func_0202DE5C(((struct Obj23538 *)(*(u8 * *)&((struct Obj04535 *)p)->f8))->f35C,0);
}
