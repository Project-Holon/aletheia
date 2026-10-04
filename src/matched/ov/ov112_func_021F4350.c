/*
 * function: func_021F4350
 * address: 0x021F4350
 * packet: pkt_ov112_021F4350
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021F4794 0x021F4794 thumb ov112
 *   func_021F485C 0x021F485C thumb ov112
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_0200A640 0x0200A640 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F4804 0x021F4804 thumb ov112
 *   func_0200FB24 0x0200FB24 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_02045334 0x02045334 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 */
#include "../include/Obj00226.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[8]; } Box;
extern const Box d_021F8290;
extern void func_020061E4(u32);
extern u32 func_020221A4(void);
extern void func_021F4794(u8 *,u32);
extern void func_021F485C(u8 *);
extern void func_02027974(void *);
struct Actor;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Rec3;
struct TaskMenu;
struct Tcbl;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern void *func_0200A640(void *);
extern void func_02082D44(const void *,void *,u32);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern void func_021F4804(u8 *,u32);
extern u32 func_0200FB24(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const Box *);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_0201CE30(void *);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_02045334(struct Descriptor *d);
extern void func_020310C4(struct Tcbl *p);
extern void func_02041EE4(u32,u32,u32);
void func_021F4350(u8 *p)
{
    u8 v;
    switch (((struct Obj00226 *)p)->f4) {
    case 0:
        ((struct Obj00226 *)p)->f4=1;
        func_020061E4(1583);
    case 1:
        if(func_020221A4()==1) {
            if(((struct Obj00226 *)p)->fC==1) {
                func_021F4794(p,3);
                ((struct Obj00226 *)p)->f4=2;
            } else ((struct Obj00226 *)p)->f4=5;
        }
        break;
    case 2:
        if(!((struct Obj00226 *)p)->f24) {
            func_021F485C(p);
            ((struct Obj00226 *)p)->f4=3;
        }
        break;
    case 3:
        func_02027974(((struct Obj00226 *)p)->f3C);
        if(func_020279E8(((struct Obj00226 *)p)->f3C)==1) {
            v=func_02027A04(*(u8 * *)&((struct Obj00226 *)p)->f3C);
            func_02027858(((struct Obj00226 *)p)->f3C);
            if(v==0) func_02082D44(((struct Obj00226 *)p)->f10,func_0200A640(((struct Obj00226 *)p)->f14),432);
            if(*(int *)&((struct Obj00226 *)p)->f44) {
                ((struct Obj00226 *)p)->f4=4;
                func_021FCDEC(*(int *)&((struct Obj00226 *)p)->f44,71);
                func_021F4804(p,6);
            } else ((struct Obj00226 *)p)->f4=7;
        } else if(func_0200FB24()!=0) {
            func_02027858(((struct Obj00226 *)p)->f3C);
            ((struct Obj00226 *)p)->f4=7;
        }
        break;
    case 4:
        if(func_021FCE00(((struct Obj00226 *)p)->f44,71)==1) ((struct Obj00226 *)p)->f4=7;
        else if(func_0200FB24()!=0) ((struct Obj00226 *)p)->f4=7;
        break;
    case 5:
        if((func_020362DC()&2)||!func_02035C08(&d_021F8290)) {
            func_020061E4(1361);
            ((struct Obj00226 *)p)->f4=6;
            func_0204B878(((struct Obj00226 *)p)->f58,9);
            func_0204B92C(((struct Obj00226 *)p)->f58,1);
        }
        break;
    case 6:
        if(!func_0204B98C(((struct Obj00226 *)p)->f58)) ((struct Obj00226 *)p)->f4=7;
        break;
    case 7: break;
    }
    if(((struct Obj00226 *)p)->f24&&func_0201CE30(((struct Obj00226 *)p)->f24)==2) {
        func_0201CE48(((struct Obj00226 *)p)->f24);
        ((struct Obj00226 *)p)->f24=0;
    }
    func_0201C4E4(((struct Obj00226 *)p)->f38);
    if(((struct Obj00226 *)p)->f30==1&&func_0201C6B4(((struct Obj00226 *)p)->f38)==1) {
        ((struct Obj00226 *)p)->f30=0;
        *(u8 * *)&((struct Obj00226 *)p)->f34=func_0202EE8C(*(u32 *)&((struct Obj00226 *)p)->f18,((struct Obj00226 *)p)->f1C,15,16,((struct Obj00226 *)p)->f0);
        func_02045334(((struct Obj00226 *)p)->f1C);
    }
    func_020310C4(((struct Obj00226 *)p)->f18);
    (*(volatile u8 *)&((struct Obj00226 *)p)->f8)++;
    if(*(volatile u8 *)&((struct Obj00226 *)p)->f8>1) {
        *(volatile u8 *)&((struct Obj00226 *)p)->f8=0;
        func_02041EE4(7,1,1);
        func_02041EE4(7,5,1);
    }
}
