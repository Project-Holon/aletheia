/*
 * function: func_0220C304
 * address: 0x0220C304
 * packet: pkt_ov197_0220C304
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   func_020215BC 0x020215BC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00315.h"
#include "../include/Obj25027.h"
#include "../include/Obj25028.h"
#include "../include/Obj25029.h"
#include "../include/Obj25030.h"
#include "../include/Obj25031.h"
#include "../include/Obj25032.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
typedef signed int     s32;
typedef unsigned int   u32;
struct PalAnmSlot;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
void func_0220C304(char *p)
{
    void *arc = func_020490F4(11,(u16)((((struct Obj25027 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    char *data;
    void *buf;
    ((struct Obj00315 *)p)->f564=func_0204A6C8(arc,119,0,1,((struct Obj25028 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f588=func_0204AC18(arc,116,1,256,4,1,((struct Obj25029 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f594=func_0204AF28(arc,120,121,((struct Obj25030 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    buf=func_02049F78(arc,116,(u32)(&data),(u16)((((struct Obj25031 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    func_020215BC(((struct Obj00315 *)p)->f8,*(char * *)&((struct Obj25032 *)data)->fC+128,3,128,32);
    func_020307B0(buf);
    func_02049238(arc);
}
