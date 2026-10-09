/*
 * file:     unit_021B7560_p01.c
 * unit:     yes
 * function: func_021B7560, func_021B7734, func_021B7798, func_021B7860, func_021B78D0, func_021B78E4
 * address:  0x021B7560
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B7C20 0x021B7C20 thumb ov102
 *   func_021B7908 0x021B7908 thumb ov102
 *   func_02012138 0x02012138 thumb
 *   func_021B8464 0x021B8464 thumb ov102
 *   func_021B7CC8 0x021B7CC8 thumb ov102
 *   func_0201F73C 0x0201F73C thumb
 *   func_021B7DFC 0x021B7DFC thumb ov102
 *   func_021B7D38 0x021B7D38 thumb ov102
 *   func_021B7E60 0x021B7E60 thumb ov102
 *   func_02041F6C 0x02041F6C arm
 *   func_02041FB0 0x02041FB0 arm
 *   func_021B879C 0x021B879C thumb ov102
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_020070A4 0x020070A4 thumb
 *   func_0200A8A0 0x0200A8A0 thumb
 *   func_021B8934 0x021B8934 thumb ov102
 *   func_021B78F4 0x021B78F4 thumb ov102
 *   func_021B7CBC 0x021B7CBC thumb ov102
 *   func_021B7CC0 0x021B7CC0 thumb ov102
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B7F08 0x021B7F08 thumb ov102
 *   func_021B8320 0x021B8320 thumb ov102
 *   func_021B81B0 0x021B81B0 thumb ov102
 *   func_02005D28 0x02005D28 thumb
 *   func_021B63CC 0x021B63CC thumb ov101
 *   d_021B8AD4 0x021B8AD4 data a4
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B89B8 0x021B89B8 thumb ov102
 *   func_021B87BC 0x021B87BC thumb ov102
 *   func_021B85F4 0x021B85F4 thumb ov102
 *   func_021B7DA8 0x021B7DA8 thumb ov102
 *   func_021B7A60 0x021B7A60 thumb ov102
 *   func_021B7C88 0x021B7C88 thumb ov102
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B78EC 0x021B78EC thumb ov102
 *   func_0204B92C 0x0204B92C arm
 *   func_021B87FC 0x021B87FC thumb ov102
 *   func_02005D90 0x02005D90 thumb
 *   func_021B89F0 0x021B89F0 thumb ov102
 *   func_021B87C8 0x021B87C8 thumb ov102
 *   func_021B842C 0x021B842C thumb ov102
 *   func_0204335C 0x0204335C arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020433E0 0x020433E0 arm
 *   func_021B7AB4 0x021B7AB4 thumb ov102
 *   func_021B78FC 0x021B78FC thumb ov102
 *   func_020056A0 0x020056A0 thumb
 *   d_021B8B2C 0x021B8B2C data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7BC0 0x021B7BC0 thumb ov102
 *   func_021B7C04  0x021B7C04  thumb  ov102
 */
#include "../../matched/include/Obj03229.h"
#include "../../matched/include/Obj22136.h"
#include "../../matched/include/Obj22137.h"
#include "../../matched/include/Obj22138.h"
#include "../../matched/include/Obj22139.h"
#include "../../matched/include/Obj22140.h"
#include "../../matched/include/Obj22141.h"

struct Obj0203159C;
struct Big;
struct Ctx;
struct Sub02007084Ctrl;
struct Row;
struct State;
struct S020315D4;
struct Obj;
struct DispVram;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_0203064C(u32 src,u32 dst,u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void func_021B7C20(u32 *,u16);
extern void func_021B7908(u32 *,u16);
extern u32 func_02012138(const struct Ctx *p);
extern void func_021B8464(struct State *p, int bg, const struct Row *rows, int count, void *object, u16 heap);
extern void func_021B7CC8(void *,int,int,u8,u8,u8,u8,u16);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021B7DFC(u8 *,void *,int,int,s16);
extern void func_021B7D38(u8 *,int,int,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B7E60(u8 *,void *,int);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B879C(void *,u32);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern void *func_0200A8A0(void *);
extern void func_021B8934(u8 *a, void *b, void *c, int d);
extern unsigned func_021B78F4(unsigned *p);
extern int func_021B7CBC(void *);
extern int func_021B7CC0(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B7F08(unsigned p, unsigned x);
extern void func_021B8320(u8 *,u16 *);
extern void func_021B81B0(u8 *,u16 *);
extern void func_02005D28(void);
extern void func_021B63CC(int *,int);
extern void func_021B71C0(void *p);
extern void func_021B89B8(u8 *p);
extern void func_021B87BC(void *);
extern void func_021B85F4(u8 *p);
extern void func_021B7DA8(void *);
extern void func_021B7A60(unsigned *p);
extern void func_021B7C88(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned);
extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern u32 func_021B78EC(void *, int);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021B87FC(int *);
extern void func_02005D90(u32, u16);
extern void func_021B89F0(u8 *);
extern void func_021B87C8(u8 *p);
extern void func_021B842C(unsigned char *p);
extern void func_0204335C(unsigned);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_021B7AB4(void *,const void *,unsigned);
extern void func_021B78FC(unsigned,void *);
extern unsigned func_020056A0(void (*)(unsigned,void *),void *,unsigned);
extern void func_02030EAC(struct Node *);
extern void func_021B7BC0(void *);
extern void func_021B7C04(void *);
int func_021B7560(void *owner,int unused,void *arg);
int func_021B7734(unsigned a,int b,int c,char *p);
int func_021B7798(void *unused, u32 *state, int unused2, char *p);
void func_021B7860(char *p,unsigned b);
void func_021B78D0(void *p);
void func_021B78E4(void *p);
extern u32 d_021B8AD4[];
extern unsigned d_021B8B2C[];




int func_021B7560(void *owner,int unused,void *arg)
{
    u8 *p;
    void *save;
    u32 handle;
    int first,second;
    func_0203064C(1,59,0x40000);
    p=func_0203159C(owner,0x4a4,59);
    func_02082BCC(p,0,0x4a4);
    ((struct Obj03229 *)p)->f48C=arg;
    func_021B7C20((u32 *)(p+0x9c),59);
    func_021B7860((char *)p,59);
    func_021B7908((u32 *)(p+0x94),59);
    if(**(void ** *)&((struct Obj03229 *)p)->f48C) func_02012138(**(void ** *)&((struct Obj03229 *)p)->f48C);
    func_021B8464((struct State *)(p+0xc0),2,(const struct Row *)d_021B8AD4,2,p+0x9c,59);
    func_021B7CC8(p+0xac,5,1,18,30,5,8,59);
    func_0201F73C(((struct Obj03229 *)p)->fAC,0,(u16)(((struct Obj03229 *)p)->f94),6);
    func_021B7DFC(p+0xac,p+0x9c,5,0,0);
    func_021B7D38(p+0x46c,7,6,3,20,5,8,1,1,59);
    func_021B7E60(p+0x46c,p+0x9c,10);
    func_02041F6C(7,3,0x1000);
    func_02041F6C(7,6,0x1000);
    func_02041FB0(7,9,128);
    func_02041FB0(7,12,40);
    func_021B879C(p+0xfc,59);
    save=**(void ** *)&((struct Obj03229 *)p)->f48C;
    if(save) save=func_02012EBC(func_020120F4(save));
    else save=func_020070A4();
    func_021B8934((u8 *)((int)(p+0x118)),(void *)((int)p),(void *)((int)func_0200A8A0(save)),59);
    handle=func_021B78F4((unsigned int *)p);
    first=func_021B7CBC(p+0x9c);
    second=func_021B7CC0(p+0x9c);
    ((struct Obj03229 *)p)->f468=func_021B70DC(2,handle,0,14,0,2,first,second,59);
    switch(((struct Obj22136 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f8) {
    case 0: func_021B7F08((unsigned int)p,(unsigned int)func_021B81B0); break;
    case 1: func_021B7F08((unsigned int)p,(unsigned int)func_021B8320); break;
    case 2: func_021B7F08((unsigned int)p,(unsigned int)func_021B81B0); break;
    }
    func_02005D28();
    func_021B63CC(*(int * *)&((struct Obj22137 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f4,0);
    return 1;
}




/*
 * func_021B71C0 0x021B71C0 thumb ov101
 * func_021B89B8 0x021B89B8 thumb ov102
 * func_021B87BC 0x021B87BC thumb ov102
 * func_021B85F4 0x021B85F4 thumb ov102
 * func_021B7DA8 0x021B7DA8 thumb ov102
 * func_021B7A60 0x021B7A60 thumb ov102
 * func_021B78D0 0x021B78D0 thumb ov102
 * func_021B7C88 0x021B7C88 thumb ov102
 * func_020315D4 0x020315D4 arm
 * func_020306F0 0x020306F0 arm
 */
int func_021B7734(unsigned a,int b,int c,char *p) {
 func_021B71C0((void *)(((struct Obj22138 *)p)->f468));
 func_021B89B8((u8 *)(p+0x118));
 func_021B87BC(p+0xfc);
 func_021B85F4((u8 *)(p+0xc0));
 func_021B7DA8(p+0x46c);
 func_021B7DA8(p+0xac);
 func_021B7A60((unsigned int *)(p+0x94));
 func_021B78D0(p);
 func_021B7C88(p+0x9c);
 func_020315D4((struct S020315D4 *)a);
 func_020306F0(0x3b);
 return 1;
}



int func_021B7798(void *unused, u32 *state, int unused2, char *p)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_0204E720(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) {
            func_0204B92C((void *)func_021B78EC(p, 31), 1);
            func_021B87FC((int *)(p + 0xfc));
            func_02005D90(0x52a, 0xffff);
            *state = 3;
        }
        break;
    case 3:
        func_021B89F0((u8 *)(p + 0x118));
        func_021B87C8((u8 *)(p + 0xfc));
        (*(void (**)(char *, char *))(p + 0x480))(p, p + 0x484);
        if (((struct Obj22139 *)p)->f488 != 0) *state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    func_021B842C((unsigned char *)p);
    return 0;
}


/*
 * volatile: 0x021B787A and 0x021B7884 read display registers for update.
 * func_02082BCC 0x02082BCC arm
 * func_0204335C 0x0204335C arm
 * func_0204363C 0x0204363C arm
 * func_0204361C 0x0204361C arm
 * func_020433E0 0x020433E0 arm
 * func_021B7AB4 0x021B7AB4 thumb ov102
 * func_021B78FC 0x021B78FC thumb ov102
 * func_020056A0 0x020056A0 thumb
 * d_021B8B2C 0x021B8B2C data a4
 */
void func_021B7860(char *p,unsigned b) {
 func_02082BCC(p,0,0x94);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 func_0204335C(0);
 func_0204363C(0);
 func_0204361C();
 func_020433E0((const struct DispVram *)d_021B8B2C);
 func_021B7AB4(p,d_021B8B2C,b);
 ((struct Obj22140 *)p)->f90=func_020056A0(func_021B78FC,p,0);
}


void func_021B78D0(void *p) { func_02030EAC(*(struct Node * *)&((struct Obj22141 *)p)->f90); func_021B7BC0(p); }


/*
 * evidence: func_021B7C04 is ov102's own code ("ldr r3, =0x0204A600; bx r3"
 * after the pop at 0x021B7C00), inside ov102's window, so only ov102 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov102's own listing.  The old hint ov021
 * named a different overlay's function mapped over the same address.
 */
void func_021B78E4(void *p) { func_021B7C04(p); }
