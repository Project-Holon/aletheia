/*
 * file:     pdc_p02.c
 * unit:     yes
 * function: func_021B61C4, func_021B61E8, func_021B6308, func_021B632C, func_021B6364, func_021B636C, func_021B6438, func_021B644C
 * address:  0x021B61C4
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov094_id 0x0000005E data
 *   func_02030734 0x02030734 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_021B6144 0x021B6144 thumb ov098
 *   func_021F73F0 0x021F73F0 thumb ov094
 *   func_021F7544 0x021F7544 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   func_021B613C 0x021B613C thumb ov098
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02202058 0x02202058 thumb ov094
 *   func_0203101C 0x0203101C arm
 *   func_021B6140 0x021B6140 thumb ov098
 *   func_021B6150 0x021B6150 thumb ov098
 *   func_021B67D4 0x021B67D4 thumb ov098
 *   func_02008254 0x02008254 thumb
 *   d_021B6E68 0x021B6E68 data a1
 *   d_021B6D80 0x021B6D80 data a2
 *   func_020310C4 0x020310C4 arm
 *   func_021F78E4 0x021F78E4 thumb ov094
 *   func_02202228 0x02202228 thumb ov094
 *   func_02031140 0x02031140 arm
 *   func_021B68DC 0x021B68DC thumb ov098
 *   func_021F7808 0x021F7808 thumb ov094
 *   func_022021F4 0x022021F4 thumb ov094
 *   func_0201D83C 0x0201D83C thumb
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204044C 0x0204044C arm
 *   func_020434DC 0x020434DC arm
 *   d_021B6DF4 0x021B6DF4 data a4
 *   d_021B6DB0 0x021B6DB0 data a4
 *   d_021B6DD8 0x021B6DD8 data a4
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02046788 0x02046788 arm
 *   func_021B6B5C  0x021B6B5C  thumb  ov098
 *   func_021B6B68  0x021B6B68  thumb  ov098
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021B67A4  0x021B67A4  thumb  ov098
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021B6910  0x021B6910  thumb  ov098
 *   func_021B6A3C  0x021B6A3C  thumb  ov098
 *   func_021B6154  0x021B6154  thumb  ov098
 *   func_021F8090  0x021F8090  thumb  ov094
 *   func_021B6504  0x021B6504  thumb  ov098
 */
#include "../../matched/include/Obj10196.h"
#include "../../matched/include/Obj05258.h"
#include "../../matched/include/Obj00381.h"

#define P(k) (*(void **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
struct S020315D4;
struct GfFont;
struct Tcbl;
struct Obj;
struct S02031140;
struct DispVram;
struct DispConfig;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Halves { u16 a,b,c,d; };

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern int func_021B6144(void *);
extern void *func_021F73F0(int,int,void *,int,u16 *,int,int,u16);
extern void func_021F7544(void *,int,u16);
extern u32 func_020307B0(void *p);
extern int func_021B613C(void *);
extern int func_021F86E0(void);
extern struct Obj *func_02202058(int a, int b, int c, int d, int e, u16 k);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern int func_021B6140(void *);
extern u32 func_021B6150(u8 *);
extern u8 *func_021B67D4(void *,void *,void *,u32);
extern void *func_02008254(u32);
extern void func_020310C4(struct Tcbl *p);
extern void func_021F78E4(void);
extern void func_02202228(void **);
extern void func_02031140(struct S02031140 *p);
extern void func_021B68DC(u8 *p);
extern void func_021F7808(void);
extern void func_022021F4(struct Obj *p);
extern unsigned int func_0201D83C(void *ptr);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *);
extern void func_02046440(u32, u32, u32, u32, u16, u32, void (*)(void));
extern void func_02046BE0(u32, u32);
extern void func_0207DC44(int, int, int, int);
extern void func_0204A48C(const struct Cfg *, u32, u32);
extern void func_0204044C(u32);
extern void func_020434DC(u32, u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0204A5AC(void);
extern void func_02046788(void);
extern void func_021B6B5C(char *p);
extern int func_021B6B68(char *p);
extern void func_021F7EE8(void *m, int key);
extern void func_021F7998(u32 a);
extern void func_021B67A4(int a);
extern int func_021F7EB4(void);
extern void func_021B6910(int a, int b);
extern int func_021B6A3C(u8 *p);
extern int func_021B6154(void *p);
extern void func_021F8090(u32 a, u32 b, u32 c);
extern int func_021B6504(char *p);
int func_021B61C4(void *a, int b, int c, void **p);
u8 *func_021B61E8(void *input,u8 heap);
int func_021B6308(unsigned p);
void func_021B632C(unsigned p);
void func_021B6364(u8 *p, u32 v);
void func_021B636C(u16 heap);
void func_021B6438(void);
int func_021B644C(char *p);
extern char ov094_id[];
extern const char d_021B6E68[];
extern const struct Halves d_021B6D80;
extern const struct DispVram d_021B6DF4;
extern struct DispConfig d_021B6DB0;
extern const struct Cfg d_021B6DD8;

int func_021B61C4(void *a, int b, int c, void **p)
{
    func_021B632C((unsigned int)(*p));
    func_020315D4(a);
    func_020306F0(0x85);
    func_02034A5C((int)ov094_id);
    return 1;
}

u8 *func_021B61E8(void *input,u8 heap)
{
    u8 *p;
    struct Halves h;
    void *q;
    int ctx;
    p=func_02030734(heap,0x78,1,d_021B6E68,0x5e);
    H(0x6c)=heap;
    P(0)=input;
    func_021B636C(H(0x6c));
    P(8)=func_0201D7EC(23,0,0,0,H(0x6c));
    P(12)=func_0201D7EC(23,2,0,0,H(0x6c));
    *(u32 *)(p+0x60)=0;
    h=d_021B6D80;
    q=func_021F73F0(0,0,(void *)func_021B6144(input),0,(u16 *)&h,0,0,H(0x6c));
    func_021F7544(q,(int)P(12),H(0x6c));
    func_020307B0(q);
    ctx=func_021B613C(input);
    P(16)=(void *)func_02202058(ctx,0,func_021F86E0(),(int)P(8),(int)(p+0x74),H(0x6c));
    P(24)=func_0203101C(heap,heap,64,128);
    *(int *)(p+4)=func_021B6140(input);
    P(20)=func_021B67D4(P(8),(void *)func_021B6150(input),P(24),H(0x6c));
    P(0x70)=func_02008254(H(0x6c));
    func_021B6364(p,(u32)func_021B644C);
    return p;
}

int func_021B6308(unsigned p)
{
    int (*cb)(unsigned);
    func_020310C4(((struct Obj10196 *)p)->f18);
    func_021F78E4();
    func_02202228(*(void ** *)&((struct Obj10196 *)p)->f10);
    cb = *(int (**)(unsigned))(p + 0x68);
    if (cb != 0) return cb(p);
    return 0;
}

void func_021B632C(unsigned p)
{
    func_02031140(((struct Obj05258 *)p)->f18);
    func_021B68DC(((struct Obj05258 *)p)->f14);
    func_021F7808();
    func_022021F4(((struct Obj05258 *)p)->f10);
    func_0201D83C(((struct Obj05258 *)p)->f8);
    func_0201D83C(((struct Obj05258 *)p)->fC);
    func_021B6438();
    func_020307B0(((struct Obj05258 *)p)->f70);
    func_020307B0((void *)p);
}


void func_021B6364(u8 *p, u32 v) { *(u32 *)&((struct Obj00381 *)p)->f60 = 0; ((struct Obj00381 *)p)->f68 = v; }

void func_021B636C(u16 heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0201DD60();
    func_020433E0(&d_021B6DF4);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28(&d_021B6DB0);
    func_02046440(0, 1, 0, 1, 0, heap, 0);
    func_02046BE0(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    func_0207DC44(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0204A48C(&d_021B6DD8, (u32)&d_021B6DF4, heap);
    func_0204044C(1);
    func_020434DC(16, 1);
}

void func_021B6438(void)
{
    func_020450C8(); func_0203F9B4(); func_0204A5AC(); func_02046788();
}


int func_021B644C(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        func_021B6B5C((char *)(((struct Obj00381 *)p)->f14));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6B68((char *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_021F7EE8(((struct Obj00381 *)p)->f4, 1);
            func_021F7998(0x231);
            func_021B67A4(2);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021B6910(((struct Obj00381 *)p)->f14, *(int *)&((struct Obj00381 *)p)->f0);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 3:
        if (func_021B6A3C((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            r = func_021B6154(((struct Obj00381 *)p)->f0);
            func_021F8090(r, func_021B6140(((struct Obj00381 *)p)->f0), 1);
            func_021B6B5C((char *)(((struct Obj00381 *)p)->f14));
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 4:
        if (func_021B6B68((char *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_021F7998(0x23e);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0)
            func_021B6364((u8 *)p, (u32)func_021B6504);
        break;
    }
    return 0;
}
