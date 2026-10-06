/*
 * function: func_0220B72C
 * address: 0x0220B72C
 * packet: pkt_ov207_0220B72C
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C60/0201CCE4 matched void forwarders leave r0 live; this caller tests/stores it.
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C38 0x02035C38 arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F164 0x0201F164 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0220B9E0 0x0220B9E0 thumb ov207
 */
#include "../include/Obj00181.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Tcbl;
struct WordSet;
struct Descriptor;
struct CharBuf;
struct U16Vec;
extern void func_020310C4(struct Tcbl *);
extern u32 func_0201CE30(void *);
extern u32 func_0203630C(void);
extern void func_020355D8(u8);
extern int func_02035C38(void);
typedef signed int     s32;
struct Rec;
struct Rec3;
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE38(void *);
extern void func_020061E4(u32);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201F164(struct WordSet *,u32,u32,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201ED04(struct WordSet *p);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_0220B9E0(int *);
int func_0220B72C(char *p)
{
    int done=0,flag;
    u32 value;
    struct WordSet *ws;
    switch(((struct Obj00181 *)p)->f3C) {
    case 0: break;
    case 1:
        func_020310C4(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=func_0201CE30(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=2;((struct Obj00181 *)p)->f4C=1;break;}
        switch(value) {
        case 0:
            flag=0;
            if(func_0203630C()&3) {func_020355D8(0);flag=1;}
            else if(func_02035C38()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) func_0201CE5C(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(func_020362DC()&3) {func_020355D8(0);flag=1;}
            else if(func_02035C60()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {func_0201CE38(((struct Obj00181 *)p)->f28);func_020061E4(0x547);}
            break;
        }
        break;
    case 2:
        if(((struct Obj00181 *)p)->f40==2) break;
        if(((struct Obj00181 *)p)->f40==0) {
            if(*(u32 *)&((struct Obj00181 *)p)->f8==0) {((struct Obj00181 *)p)->f3C=5;break;}
            func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00181 *)p)->f24),15);
            func_0201CE48(((struct Obj00181 *)p)->f28);
            func_02045808(*(struct U16Vec * *)&((struct Obj00181 *)p)->f2C);
            ws=func_0201EC64(((struct Obj00181 *)p)->f0);
            func_0201EEF4(ws,0,((struct Obj00181 *)p)->f4);
            func_0201F164(ws,1,((struct Obj00181 *)p)->fC,((struct Obj00181 *)p)->f10);
            *(struct U16Vec * *)&((struct Obj00181 *)p)->f2C=func_020457B0(64,((struct Obj00181 *)p)->f0);
            func_0201F250(ws,((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f8);
            func_0201ED04(ws);
            *(u32 *)&((struct Obj00181 *)p)->f28=func_0201CCE4(*(u32 *)&((struct Obj00181 *)p)->f24,0,0,*(u32 *)&((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f18,func_02012FFC(),*(u32 *)&((struct Obj00181 *)p)->f34,2,((struct Obj00181 *)p)->f0,15);
            ((struct Obj00181 *)p)->f3C=3;
        } else ((struct Obj00181 *)p)->f3C=5;
        break;
    case 3:
        func_020310C4(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=func_0201CE30(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=4;break;}
        switch(value) {
        case 0:
            flag=0;
            if(func_0203630C()&3) {func_020355D8(0);flag=1;}
            else if(func_02035C38()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) func_0201CE5C(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(func_020362DC()&3) {func_020355D8(0);flag=1;}
            else if(func_02035C60()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {func_0201CE38(((struct Obj00181 *)p)->f28);func_020061E4(0x547);}
            break;
        }
        break;
    case 4:
        ++((struct Obj00181 *)p)->f44;
        if(((struct Obj00181 *)p)->f44==60) ((struct Obj00181 *)p)->f3C=5;
        break;
    case 5: done=1; break;
    }
    func_0220B9E0((int *)p);
    return done;
}
