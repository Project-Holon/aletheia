/*
 * function: func_021B9798
 * address: 0x021B9798
 * packet: pkt_ov214_021B9798
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAF30 0x021BAF30 thumb ov214
 *   func_021BA43C 0x021BA43C thumb ov214
 *   func_021BA39C 0x021BA39C thumb ov214
 *   func_021BA018 0x021BA018 thumb ov214
 *   func_021BAE10 0x021BAE10 thumb ov214
 *   func_021BAC3C 0x021BAC3C thumb ov214
 *   func_02045C04 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BB220 0x021BB220 thumb ov214
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj00636.h"
struct Rec;
extern const char ov067_id[];
typedef unsigned char  u8;
extern void func_021BAF30(int unused, u8 *p);
extern void func_021BA43C(int unused,char *p);
extern void func_021BA39C(int unused,char *p);
extern void func_021BA018(int unused,char *p);
extern void func_021BAE10(int unused,char *p);
extern void func_021BAC3C(int unused, u8 *p);
extern unsigned int func_02045C04(struct Rec *rec);
struct Node;
struct PrintSys;
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern void func_021BB220(char *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
int func_021B9798(void *owner,int unused,int state,char *p)
{
    func_021BAF30(state,(u8 *)p);
    func_021BA43C(state,p);
    func_021BA39C(state,p);
    func_021BA018(state,p);
    func_021BAE10(state,p);
    func_021BAC3C(state,(u8 *)p);
    func_02045C04(*(struct Rec * *)&((struct Obj00636 *)p)->f58);
    func_02030EAC((struct Node *)(((struct Obj00636 *)p)->f4C));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    func_0201D83C(((struct Obj00636 *)p)->f8);
    func_021BB220(*(char * *)&((struct Obj00636 *)p)->f4);
    func_020315D4(owner);
    func_020306F0(117);
    func_02034A5C((int)ov067_id);
    return 1;
}
