/*
 * file:     th_award_graphic_p02.c
 * unit:     yes
 * function: func_021BA260, func_021BA298, func_021BA29C, func_021BA2A4, func_021BA2E4, func_021BA300, func_021BA308
 * address:  0x021BA260
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021BA458 0x021BA458 data a4
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../../matched/include/Obj14783.h"
#include "../../matched/include/Obj26063.h"

struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void*,int,u32);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
void func_021BA260(void*p);
void func_021BA298(void *p);
void func_021BA29C(void *p);
void func_021BA2A4(unsigned char *p, int a, int b);
void func_021BA2E4(char *p);
void func_021BA300(void *p);
void func_021BA308(void *p);
extern const u8 d_021BA458[];

void func_021BA260(void*p){u32 i;for(i=0;i<3;i++)func_020403F4((u8)(*(u32*)(d_021BA458+i*44)));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

void func_021BA298(void *p){}

void func_021BA29C(void *p){func_020419E4();}


void func_021BA2A4(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BA40C, a, b);
    ((struct Obj14783 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270((void *)((struct Obj14783 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021BA2E4(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26063 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

void func_021BA300(void *p){func_0204A600();}


/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
void func_021BA308(void *p)
{
    func_0204A648();
}
