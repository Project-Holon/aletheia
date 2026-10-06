/*
 * function: func_0220C27C
 * address: 0x0220C27C
 * packet: pkt_ov197_0220C27C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00315.h"
#include "../include/Obj25022.h"
#include "../include/Obj25023.h"
#include "../include/Obj25024.h"
#include "../include/Obj25025.h"
#include "../include/Obj25026.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204ABF0(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct PalAnmSlot;
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049238(void *);
void func_0220C27C(char *p)
{
    void *arc = func_020490F4(99,(u16)((((struct Obj25022 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    ((struct Obj00315 *)p)->f560=func_0204A6C8(arc,13,1,1,((struct Obj25023 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f584=func_0204ABF0(arc,14,1,224,((struct Obj25024 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f590=func_0204AF28(arc,15,16,((struct Obj25025 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    func_020216B4(((struct Obj00315 *)p)->f8,(void *)((unsigned)arc),14,((struct Obj25026 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC,3,32,112);
    func_02049238(arc);
}
