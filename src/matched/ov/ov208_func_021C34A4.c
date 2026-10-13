/*
 * function: func_021C34A4
 * address: 0x021C34A4
 * packet: pkt_ov208_021C34A4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021C32FC 0x021C32FC thumb ov208
 *   func_021C2FEC 0x021C2FEC thumb ov208
 *   func_021C2E6C 0x021C2E6C thumb ov208
 *   func_021C3280 0x021C3280 thumb ov208
 *   func_021C3480 0x021C3480 thumb ov208
 *   func_021C3678 0x021C3678 thumb ov208
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p,u32 v);
extern void func_021C32FC(u16 *heap,u8 *p,int key);
struct S;
extern void func_021C2FEC(void *unused, struct S *p, u32 unused2, u32 i);
extern void func_021C2E6C(u16 *heap, u8 *p, int key, u32 slot);
struct Key;
extern void func_021C3280(u16 *heap, u8 *p, struct Key *key);
extern void func_021C3480(int unused, char *p, int key);
extern void func_021C3678(u16 *heap,u8 *p,int key);
void func_021C34A4(u16 *heap,u8 *p,int key)
{
    if(*(struct Obj **)(p+((struct Obj00146 *)p)->f5C*4+0x54))
        CLACT_SetActorDrawEnable(*(struct Obj **)(p+((struct Obj00146 *)p)->f5C*4+0x54),0);
    ((struct Obj00146 *)p)->f5C=(((struct Obj00146 *)p)->f5C+1)%2;
    func_021C32FC(heap,p,key);
    func_021C2FEC(heap,(struct S *)p,key,((struct Obj00146 *)p)->f5C);
    func_021C2E6C(heap,p,key,((struct Obj00146 *)p)->f5C);
    func_021C3280(heap,p,(struct Key *)key);
    func_021C3480((int)heap,(char *)p,key);
    func_021C3678(heap,p,key);
}
