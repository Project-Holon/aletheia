/*
 * file:     demo3d_graphic_p01.c
 * unit:     yes
 * function: func_021BDDD8, func_021BDE98, func_021BDF00, func_021BDF18, func_021BDF24, func_021BDF30, func_021BDF3C, func_021BDF74, func_021BDF88, func_021BDFA8
 * address:  0x021BDDD8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BE938 0x021BE938 thumb ov203
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BDFC0 0x021BDFC0 thumb ov203
 *   func_021BE084 0x021BE084 thumb ov203
 *   func_020056A0 0x020056A0 thumb
 *   func_021BE0F4 0x021BE0F4 thumb ov203
 *   d_021C3CCC 0x021C3CCC data a1
 *   d_021BFBC4 0x021BFBC4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BE12C 0x021BE12C thumb ov203
 *   func_021BE0C4 0x021BE0C4 thumb ov203
 *   func_021BE02C 0x021BE02C thumb ov203
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BE0E0  0x021BE0E0  thumb  ov203
 *   func_021BE078  0x021BE078  thumb  ov203
 *   func_021BE13C 0x021BE13C thumb ov203
 *   func_021BE148 0x021BE148 thumb ov203
 *   func_021BE0F0 0x021BE0F0 thumb ov203
 *   func_02048CDC 0x02048CDC arm
 *   func_02048C58 0x02048C58 arm
 *   func_0207CDB8 0x0207CDB8 arm
 *   func_02048CA4 0x02048CA4 arm
 *   func_021BE07C  0x021BE07C  thumb  ov203
 *   func_021BE0E8  0x021BE0E8  thumb  ov203
 */
#include "../../matched/include/Obj08374.h"
#include "../../matched/include/Obj10861.h"
#include "../../matched/include/Obj25309.h"
#include "../../matched/include/Obj25310.h"
#include "../../matched/include/Obj25311.h"

struct DispVram;
struct Node;
struct LightSlot;
struct Rgb555;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

struct Block {int tag;struct LightSlot *slots;};

struct Obj {int a,b;struct Block block;};

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, unsigned, unsigned);
extern int func_021BE938(void *);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BDFC0(void *, unsigned);
extern void func_021BE084(unsigned char *, int, int);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BE0F4(unsigned char *, int);
extern void func_02030EAC(struct Node *n);
extern void func_021BE12C(int *);
extern void func_021BE0C4(char *);
extern void func_021BE02C(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BE0E0(void *a0);
extern void func_021BE078(void *a0);
extern void func_021BE13C(void *);
extern void func_021BE148(void *);
extern int func_021BE0F0(void *);
extern void func_02048CDC(struct LightSlot *,unsigned,unsigned short *);
extern void func_02048C58(struct LightSlot *);
extern void func_0207CDB8(int, void *);
extern void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in);
extern void func_021BE07C(void *a0);
extern void func_021BE0E8(u8 *);
void *func_021BDDD8(unsigned swap, void *config, unsigned heap);
void func_021BDE98(char *ctx);
void func_021BDF00(u8 *p);
void func_021BDF18(char *p);
void func_021BDF24(char *p);
int func_021BDF30(char *p);
void func_021BDF3C(struct Obj *obj, unsigned short *a, int a2);
void func_021BDF74(char *p,unsigned i,unsigned short val);
void func_021BDF88(char *p, int a, int b);
void func_021BDFA8(u32 a, u8 *p);
extern const char d_021C3CCC[];
extern const unsigned char d_021BFBC4[][48];

/*
 * volatile: 04000050/04001050 hardware stores DE06/DE0C; 04000000/04001000 rereads DE10/DE1A.
 */
void *func_021BDDD8(unsigned swap, void *config, unsigned heap)
{
    unsigned char *ctx = func_02030734(heap, 24, 0, d_021C3CCC, 0x15a);
    func_02082BCC(ctx, 0, 24);
    ((struct Obj08374 *)ctx)->f14 = func_021BE938(config);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BFBC4[((struct Obj08374 *)ctx)->f14]);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    if (((struct Obj08374 *)ctx)->f14 == 0) {
        func_021BDFC0(ctx, heap);
        func_021BE084(ctx + 4, (int)d_021BFBC4, heap);
        ((struct Obj08374 *)ctx)->f10 = func_020056A0((unsigned)func_021BDFA8, (unsigned)ctx, 0);
    }
    func_021BE0F4(ctx + 8, heap);
    return ctx;
}

void func_021BDE98(char *ctx)
{
    if (((struct Obj10861 *)ctx)->f14 == 0) func_02030EAC(((struct Obj10861 *)ctx)->f10);
    func_021BE12C((int *)(ctx + 8));
    if (((struct Obj10861 *)ctx)->f14 == 0) {
        func_021BE0C4(ctx + 4);
        func_021BE02C(ctx);
    }
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    func_02082BCC(ctx, 0, 24);
    func_020307B0(ctx);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BDF00(u8 *p)
{
    if (((struct Obj25309 *)p)->f14 == 0) {
        func_021BE0E0(p + 4);
        func_021BE078(p);
    }
}

void func_021BDF18(char *p){func_021BE13C(p+8);}

void func_021BDF24(char *p){func_021BE148(p+8);}

int func_021BDF30(char *p){return func_021BE0F0(p+4);}

void func_021BDF3C(struct Obj *obj, unsigned short *a, int a2){struct Block *p=&obj->block;func_02048CDC(p->slots,0,a);func_02048CDC(p->slots,1,a+1);func_02048CDC(p->slots,2,a+2);func_02048CDC(p->slots,3,a+3);func_02048C58(p->slots);}

void func_021BDF74(char *p,unsigned i,unsigned short val){func_02048CDC(*(struct LightSlot **)(p+12),i,&val);}


void func_021BDF88(char *p, int a, int b)
{
    int buf[2];
    func_0207CDB8(b, buf);
    func_02048CA4(((struct Obj25310 *)p)->fC, a, (struct Rgb555 *)buf);
}


void func_021BDFA8(u32 a, u8 *p)
{
    if (((struct Obj25311 *)p)->f14 == 0) {
        func_021BE07C(p);
        func_021BE0E8(p + 4);
    }
}
