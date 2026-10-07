/*
 * file:     mb_comm_sys_p06.c
 * unit:     yes
 * function: func_021EFCA8, func_021EFD24
 * address:  0x021EFCA8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0DDC 0x021F0DDC thumb ov107
 *   func_021F0AE4 0x021F0AE4 thumb ov107
 *   func_021F0D28 0x021F0D28 thumb ov107
 *   func_0208459C 0x0208459C arm
 *   func_02179570 0x02179570 thumb ov014
 *   d_021F6EA0 0x021F6EA0 data ov107 a4
 *   func_021EFC10 0x021EFC10 thumb ov107
 *   func_021F11C4 0x021F11C4 thumb ov107
 *   func_021F17E0 0x021F17E0 thumb ov107
 *   func_021F1B38 0x021F1B38 thumb ov107
 *   func_021EFD98 0x021EFD98 thumb ov107
 *   func_0200C184 0x0200C184 thumb
 *   func_021F11E0 0x021F11E0 thumb ov107
 *   func_0200C18C 0x0200C18C thumb
 *   func_021EFC1C 0x021EFC1C thumb ov107
 */
#include "../../matched/include/Obj22279.h"
#include "../../matched/include/Obj02457.h"

struct Blk34;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern unsigned func_021F0DDC(void);
extern void func_021F0AE4(void);
extern u16 func_021F0D28(void);
extern void func_0208459C(int clear, u32 irqFlags);
extern int func_02179570(void (*cb)(int));
extern int func_021EFC10(void);
extern u8 func_021F11C4(u8 *p);
extern void func_021F17E0(void *,int);
extern void func_021F1B38(u8 *p, u32 v);
extern void func_021EFD98(void *);
extern u32 func_0200C184(struct Blk34 *p);
extern int func_021F11E0(unsigned char *a);
extern void func_0200C18C(struct Blk34 *p, u32 v);
extern void func_021EFC1C(u8 *p, int mode);
void func_021EFCA8(u8 *p);
void func_021EFD24(u8 *p);
extern u8 d_021F6EA0[];

void func_021EFCA8(u8 *p) {
 unsigned v=func_021F0DDC();
 if(v==1) func_021F0AE4();
 while(func_021F0D28()!=0&&func_021F0D28()!=5) func_0208459C(1,1);
 if(((struct Obj22279 *)p)->f1C==1) {
 *(int *)(d_021F6EA0+8)=0;
 while(func_02179570((void (*)(int))((int)func_021EFC10))) func_0208459C(1,1);
 while(*(int *)(d_021F6EA0+8)==0) func_0208459C(1,1);
 }
}

/*
 * extent: two bytes of alignment padding after the return.
 */
void func_021EFD24(u8 *p) {
 unsigned v=func_021F11C4(((struct Obj02457 *)p)->fC);
 unsigned old,cur;
 func_021F17E0(((struct Obj02457 *)p)->f68,6);func_021F1B38(((struct Obj02457 *)p)->f68,1);func_021EFD98(p);
 if(p[40]==0) {
 old=(u16)func_0200C184(((struct Obj02457 *)p)->f4C);cur=func_021F11E0(((struct Obj02457 *)p)->fC);
 if(old<cur) {func_0200C18C(((struct Obj02457 *)p)->f4C,cur);func_021EFC1C(p,1);}
 else if(v==0) func_021EFC1C(p,2);else func_021EFC1C(p,0);
 if(((struct Obj02457 *)p)->f38<cur) ((struct Obj02457 *)p)->f38=cur;
 ((struct Obj02457 *)p)->f3C=((struct Obj02457 *)p)->f3C+v;
 }
}
