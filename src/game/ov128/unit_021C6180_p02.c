/*
 * file:     unit_021C6180_p02.c
 * unit:     yes
 * function: func_021C6520, func_021C658C, func_021C6638, func_021C665C, func_021C6664, func_021C6698
 * address:  0x021C6520
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A1C 0x02009A1C thumb
 *   func_02009864 0x02009864 thumb
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0204363C 0x0204363C arm
 *   func_020490F4 0x020490F4 arm
 *   func_021C66A8 0x021C66A8 thumb ov128
 *   func_021C67A8 0x021C67A8 thumb ov128
 *   func_021C692C 0x021C692C thumb ov128
 *   func_021C69C4 0x021C69C4 thumb ov128
 *   func_021C6CB0 0x021C6CB0 thumb ov128
 *   func_021C6A84 0x021C6A84 thumb ov128
 *   func_021CA0BC 0x021CA0BC thumb ov128
 *   func_0203D34C 0x0203D34C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021CA478 0x021CA478 thumb ov128
 *   func_020310C4 0x020310C4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_021CA10C 0x021CA10C thumb ov128
 *   func_021C6DAC 0x021C6DAC thumb ov128
 *   func_021C6AC0 0x021C6AC0 thumb ov128
 *   func_021C6A5C 0x021C6A5C thumb ov128
 *   func_021C6980 0x021C6980 thumb ov128
 *   func_021C68C4 0x021C68C4 thumb ov128
 *   func_021C6790 0x021C6790 thumb ov128
 *   func_02049238 0x02049238 arm
 *   func_020433E0  0x020433E0  arm
 *   d_021CA5CC     0x021CA5CC  data
 */
#include "../../matched/include/Obj03808.h"
#include "../../matched/include/Obj03812.h"
#include "../../matched/include/Obj06477.h"
#include "../../matched/include/Obj00725.h"

struct BigObj;
struct Sub020097BCObj;
struct PrintSys;
struct Tcbl;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern void func_02082BCC(void *,int,int);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0204363C(u32 swap);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021C66A8(char *p, int heap);
extern void func_021C67A8(char *p, int heap);
extern void func_021C692C(u8 *p, int heap);
extern void func_021C69C4(void *,void *,int);
extern void func_021C6CB0(char *p, int heap);
extern void func_021C6A84(void *,int);
extern void func_021CA0BC(void *,int);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021CA478(char *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021CA10C(u8 *);
extern void func_021C6DAC(u8 *);
extern void func_021C6AC0(u8 *);
extern void func_021C6A5C(u8 *);
extern void func_021C6980(u8 *);
extern void func_021C68C4(char *p);
extern void func_021C6790(u8 *);
extern void func_02049238(void *);
extern void func_020433E0(const struct DispVram *c);
void func_021C6520(char *p);
void func_021C658C(char *p,void *q,int heap);
void func_021C6638(u8 *p);
void func_021C665C(void *p);
void func_021C6664(u8 *p);
void func_021C6698(void *a0);
extern char d_021CA5CC[];

/*
 * lever: direct assignment from postincrement preserves the old count load;
 *   the two-byte tail at 021C658A is zero padding.
 */
void func_021C6520(char *p)
{
    int i;
    void *v;
    func_02082BCC(p+16,0,72);
    v=(void *)func_0201283C(((struct Obj03808 *)p)->f4);
    ((struct Obj03808 *)p)->f10=0;
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==1) {
            *(u8 *)(p+((struct Obj03808 *)p)->f10+24)=i;
            if(func_02009864(v,i,9)==2) *(u8 *)(p+((struct Obj03808 *)p)->f10+56)=255;
            else *(u8 *)(p+((struct Obj03808 *)p)->f10+56)=(((struct Obj03808 *)p)->f14)++;
            ((struct Obj03808 *)p)->f10=((struct Obj03808 *)p)->f10+1;
        }
    }
}

/*
 * calls: 021C6698 receives live r0=0x180 although its own body ignores it;
 *   021CA0BC heap is widened because this caller has no truncation.
 * volatile: hardware register stores at 021C65A6 and 021C65A8
 */
void func_021C658C(char *p,void *q,int heap)
{
    func_02043534(0); func_020435F4(0);
    *(volatile u16 *)0x04000050=0; *(volatile u16 *)0x04001050=0;
    func_0207D534((void *)0x0400006c,-16); func_0207D534((void *)0x0400106c,-16);
    func_0204363C(0);
    ((struct Obj03812 *)p)->f8=func_020490F4(63,heap); ((struct Obj03812 *)p)->f180=heap;
    func_021C6698((void *)0x180);
    func_021C66A8(p,heap); func_021C67A8(p,heap); func_021C692C((u8 *)p,heap);
    func_021C69C4(p,q,heap); func_021C6CB0(p,heap); func_021C6A84(p,heap); func_021CA0BC(p,heap);
    func_0203D34C(1,52); func_020434DC(16,1); func_02043598(16,1);
}

void func_021C6638(u8 *p) { if(((struct Obj06477 *)p)->f34) { func_0201C4E4(((struct Obj06477 *)p)->f34);func_021CA478((char *)p); } if(((struct Obj06477 *)p)->f28) func_020310C4(((struct Obj06477 *)p)->f28);func_0204A600(); }

/*
 * calls: preserves incoming r0 at the tail call; callers load its argument
 *   even though func_0204A648's own body ignores that register.
 */
void func_021C665C(void *p) { func_0204A648(); }

void func_021C6664(u8 *p) {func_021CA10C(p);func_021C6DAC(p);func_021C6AC0(p);func_021C6A5C(p);func_021C6980(p);func_021C68C4((char *)p);func_021C6790(p);func_02049238(((struct Obj00725 *)p)->f8);}


/*
 * Addresses are Black-image addresses.
 */
void func_021C6698(void *a0)
{
    func_020433E0((const struct DispVram *)d_021CA5CC);
}
