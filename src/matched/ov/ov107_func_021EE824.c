/*
 * function: func_021EE824
 * address: 0x021EE824
 * packet: pkt_ov107_021EE824
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034FB8 0x02034FB8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0200566C 0x0200566C thumb
 *   func_020370C8 0x020370C8 arm
 *   func_02005D28 0x02005D28 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020143CC 0x020143CC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021F0E40 0x021F0E40 thumb ov107
 *   func_021F1520 0x021F1520 thumb ov107
 *   func_021EF080 0x021EF080 thumb ov107
 */
#include "../include/Obj00979.h"
#include "../include/Obj22274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Node;
extern void func_02034FB8(u32 v);
extern void func_02030EAC(struct Node *n);
extern void func_0200566C(void);
extern void func_020370C8(void);
extern void func_02005D28(void);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern void func_021F0E40(void *);
extern void func_021F1520(char *p);
extern void func_021EF080(char *p);
void func_021EE824(u8 *p) {
 void *q; u16 *a,*b;
 func_02034FB8(16); func_02030EAC(((struct Obj00979 *)p)->f4);func_0200566C();func_020370C8();
 if(p[40]==1) func_02005D28();
 else { q=(void *)func_0201296C(((struct Obj22274 *)(*(u8 * *)&((struct Obj00979 *)p)->f8))->f4); a=(u16 *)func_020143CC((u32)q,16384);b=(u16 *)func_020143CC((u32)q,16385);*a=((struct Obj00979 *)p)->f38;*b=((struct Obj00979 *)p)->f3A; }
 if(((struct Obj00979 *)p)->f60) func_020307B0(((struct Obj00979 *)p)->f60);
 func_021F0E40(((struct Obj00979 *)p)->fC);func_021F1520(((struct Obj00979 *)p)->f68);func_021EF080((char *)p);
}
