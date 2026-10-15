/*
 * function: BEACON_DETAIL_GRA_Init
 * address: 0x021BBD80
 * packet: pkt_ov216_021BBD80
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 3159C allocator result remains live in r0 and is consumed here;
 * 3064C receives visibly loaded r2 beyond legacy two-argument declaration.
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BEACON_DETAIL_GRA_Create 0x021BC930 thumb ov216
 *   func_021BBFEC 0x021BBFEC thumb ov216
 *   func_021BC0C8 0x021BC0C8 thumb ov216
 *   func_021BC1E4 0x021BC1E4 thumb ov216
 *   func_021BC6D8 0x021BC6D8 thumb ov216
 *   func_021BC454 0x021BC454 thumb ov216
 *   func_021BC650 0x021BC650 thumb ov216
 *   func_021BC70C 0x021BC70C thumb ov216
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_021BC398 0x021BC398 thumb ov216
 *   ov067_id 0x00000043 data
 *   ov072_id 0x00000048 data
 */
#include "../include/Obj00366.h"
struct Obj0203159C;
extern unsigned char ov067_id[],ov072_id[];
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *,int,int);
extern void *BEACON_DETAIL_GRA_Create(int,int);
typedef unsigned char  u8;
extern void func_021BBFEC(u8 *p);
extern void func_021BC0C8(char *);
typedef unsigned short u16;
extern void func_021BC1E4(char *p, u16 heap);
extern void func_021BC6D8(char *);
typedef unsigned int   u32;
extern void func_021BC454(char *p, u32 handle);
extern void func_021BC650(char *);
extern void func_021BC70C(char *);
extern void *func_021BCA38(char *p);
extern void *func_021BC398(void *,unsigned);
int BEACON_DETAIL_GRA_Init(struct Obj0203159C *obj,int unused1,void *config)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov072_id);
    GFL_HEAP_CreateChildHeap(1,119,3<<16);
    p=PROCSYS_AllocProcWork(obj,620,119);
    MI_CpuFill8(p,0,620);
    ((struct Obj00366 *)p)->f14=config;
    ((struct Obj00366 *)p)->f0=119;
    ((struct Obj00366 *)p)->f2=0x8077;
    ((struct Obj00366 *)p)->f50=BEACON_DETAIL_GRA_Create(0,((struct Obj00366 *)p)->f0);
    func_021BBFEC((u8 *)p);
    func_021BC0C8(p);
    func_021BC1E4(p,((struct Obj00366 *)p)->f0);
    func_021BC6D8(p);
    func_021BC454(p,(u32)(((struct Obj00366 *)p)->f54));
    func_021BC650(p);
    func_021BC70C(p);
    ((struct Obj00366 *)p)->f124=func_021BC398(func_021BCA38(((struct Obj00366 *)p)->f50),((struct Obj00366 *)p)->f0);
    return 1;
}
