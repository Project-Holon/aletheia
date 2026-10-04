/*
 * function: func_021DFFF8
 * address: 0x021DFFF8
 * packet: pkt_ov137_021DFFF8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02021640 0x02021640 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021E0338 0x021E0338 thumb ov137
 */
#include "../include/Obj00835.h"
#include "../include/Obj03306.h"
#include "../include/Obj23772.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0201F5BC(u32,u32,u32,u32,u16);
struct GfFont;
struct MsgBank;
struct PalAnmSlot;
struct U16Vec;
struct WordSet;
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201C440(void *);
extern void func_021E0338(u8 *,int);
void func_021DFFF8(u8 *p)
{
    int i;
    u8 *s=p+0xce0;
    func_0201F5BC(1,1,15,0,114);
    func_02021640(((struct Obj00835 *)p)->fD78,5,3,114,0,32,224);
    func_02021640(((struct Obj00835 *)p)->fD78,23,5,114,0,32,240);
    ((struct Obj03306 *)s)->f4=func_0201D7EC(23,0,0,0,114);
    ((struct Obj03306 *)s)->f8=func_02045B38(0,2,41,114);
    ((struct Obj03306 *)s)->fC=func_0201EC64(114);
    ((struct Obj03306 *)s)->f10=func_020450F0(1,2,19,26,4,15,1);
    ((struct Obj03306 *)s)->f5C=func_020457B0(256,114);
    for(i=0;i<5;i++) {*(void **)(p+0xa4+i*4)=func_020457B0(8,114);}
    ((struct Obj03306 *)s)->f28=((struct Obj03306 *)s)->f10;
    ((struct Obj03306 *)s)->f2C=0;
    ((struct Obj03306 *)s)->f58=func_0201C440((void *)114);
    func_021E0338(p,((struct Obj23772 *)(*(u8 * *)&((struct Obj00835 *)p)->fD8))->f8);
}
