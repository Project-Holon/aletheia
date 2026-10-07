/*
 * file:     psel_graphic_p04.c
 * unit:     yes
 * function: func_021BC274, func_021BC2CC, func_021BC30C, func_021BC34C, func_021BC3F0, func_021BC498, func_021BC4F4, func_021BC508, func_021BC514, func_021BC520, func_021BC52C, func_021BC538
 * address:  0x021BC274
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9D4C 0x021B9D4C thumb ov223
 *   func_021BA2B4 0x021BA2B4 thumb ov223
 *   func_021BB964 0x021BB964 thumb ov223
 *   func_021B9C58 0x021B9C58 thumb ov223
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021BB954 0x021BB954 thumb ov223
 *   func_021BADFC 0x021BADFC thumb ov223
 *   func_021BAD68 0x021BAD68 thumb ov223
 *   func_021BAA30 0x021BAA30 thumb ov223
 *   func_021BA050 0x021BA050 thumb ov223
 *   func_021B9A6C 0x021B9A6C thumb ov223
 *   func_021BB3AC 0x021BB3AC thumb ov223
 *   func_021BAEE0 0x021BAEE0 thumb ov223
 *   func_021BAB74 0x021BAB74 thumb ov223
 *   func_021B9848 0x021B9848 thumb ov223
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BC960 0x021BC960 data a4
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BC54C 0x021BC54C thumb ov223
 *   func_021BC5F0 0x021BC5F0 thumb ov223
 *   func_021BC660 0x021BC660 thumb ov223
 *   d_021BCB08 0x021BCB08 data a1
 *   d_021BC980 0x021BC980 data a4
 *   func_021BC6CC 0x021BC6CC thumb ov223
 *   func_021BC630 0x021BC630 thumb ov223
 *   func_021BC5AC 0x021BC5AC thumb ov223
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BC64C  0x021BC64C  thumb  ov223
 *   func_021BC5E4  0x021BC5E4  thumb  ov223
 *   func_021BC6DC 0x021BC6DC thumb ov223
 *   func_021BC6F0 0x021BC6F0 thumb ov223
 *   func_021BC65C 0x021BC65C thumb ov223
 *   func_021BC6F8 0x021BC6F8 thumb ov223
 *   func_021BC5E8  0x021BC5E8  thumb  ov223
 *   func_021BC654  0x021BC654  thumb  ov223
 */
#include "../../matched/include/Obj00738.h"
#include "../../matched/include/Obj05571.h"

struct Main;
struct Node;
struct PrintSys;
struct DispVram;
typedef signed int     s32;

typedef unsigned int   u32;

typedef enum { TOON, HIGHLIGHT } Shading;

typedef unsigned short u16;

extern void func_021B9C58(char *);
extern void func_021B9A8C(char *p);
extern void func_020061E4(u32 a);
extern void func_021B9D4C(char *);
extern void func_021BA2B4(struct Main *p);
extern void func_021BB964(char *);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021BB954(char *);
extern void func_021BADFC(char *);
extern void func_021BAD68(char *);
extern void func_021BAA30(char *);
extern void func_021BA050(char *);
extern void func_021B9A6C(char *);
extern int func_021BB3AC(int *);
extern void func_021BAEE0(char *p);
extern void func_021BAB74(int *);
extern void func_021B9848(int *);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(unsigned short,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BC54C(void *,int);
extern void func_021BC5F0(int *,int,int);
extern void func_021BC660(int *,int);
extern void *func_020056A0(void (*)(void *,char *),void *,int);
extern void func_021BC6CC(int *);
extern void func_021BC630(char *);
extern void func_021BC5AC(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BC64C(void *);
extern void func_021BC5E4(void *);
extern void func_021BC6DC(int *);
extern void func_021BC6F0(unsigned char *);
extern unsigned func_021BC65C(const unsigned *);
extern unsigned func_021BC6F8(unsigned char *);
extern void func_021BC5E8(void *);
extern void func_021BC654(void *);
int func_021BC274(char *p,unsigned *state);
int func_021BC2CC(char *p);
int func_021BC30C(int *p);
int func_021BC348(void);
void func_021BC34C(void);
void *func_021BC3F0(int a,int heap);
void func_021BC498(unsigned *p);
void func_021BC4F4(char *p);
void func_021BC508(unsigned char *p);
void func_021BC514(unsigned char *p);
unsigned func_021BC520(unsigned char *p);
unsigned func_021BC52C(unsigned char *p);
void func_021BC538(void *unused, char *p);
extern char d_021BC960[];
extern char d_021BCB08[];
extern unsigned d_021BC980[];

int func_021BC274(char *p,unsigned *state)
{
    func_021B9C58(p);
    func_021B9D4C(p); func_021BA2B4((struct Main *)p); func_021BB964(p);
    switch(*state) {
    case 0: func_0204E720(12,0,16,2); (*state)++; break;
    case 1: if(!func_0204E804()) { ((struct Obj00738 *)p)->f10=0; return 11; } break;
    }
    (((struct Obj00738 *)p)->f10)++;
    return 10;
}

int func_021BC2CC(char *p)
{
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_021BB954(p); func_021BADFC(p); func_021BAD68(p);
    func_021BAA30(p); func_021BA050(p); func_021B9A6C(p);
    ((struct Obj05571 *)p)->f10=0;
    return 12;
}

int func_021BC30C(int *p)
{
    func_021BB3AC(p); func_021BAEE0((char *)p); func_021BAB74(p); func_021B9848(p);
    func_02030EAC((void *)p[8]); func_0201C6EC((struct PrintSys *)p[7]); func_0201C4C0((struct PrintSys *)p[7]);
    func_0201D83C((void *)p[6]); func_021BC498((unsigned *)p[5]);
    return 13;
}

/*
 * trailing: parent-cleared Thumb follower 021BC348 is movs r0,#13; bx lr.
 */
int func_021BC348(void) { return 13; }

static inline void shading(Shading s)
{
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3002)|(s<<1));
}

static inline void priority(int p)
{
    *(volatile unsigned short *)0x04000008=(unsigned short)((*(volatile unsigned short *)0x04000008 & ~3)|p);
}

void func_021BC34C(void)
{
    unsigned i;
    func_020434DC(1,1);
    priority(0);
    shading(HIGHLIGHT);
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|16);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3004;
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|8);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) func_02046A94((unsigned char)i,(const u16 *)(d_021BC960+i*8));
    func_02046BE0(0,0);
}

void *func_021BC3F0(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BCB08,463);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BC980);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BC54C(p,heap);
    func_021BC5F0((int *)(p+1),(int)d_021BC980,heap);
    func_021BC660((int *)(p+2),heap);
    p[3]=(unsigned)func_020056A0(func_021BC538,p,0);
    return p;
}

/*
 * volatile: hardware accesses at 0x021BC4BA-0x021BC4D4.
 */
void func_021BC498(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_021BC6CC((int *)(p+2));
    func_021BC630((char *)(p+1));
    func_021BC5AC(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}


void func_021BC4F4(char *p)
{
    func_021BC64C(p + 4);
    func_021BC5E4(p);
}

void func_021BC508(unsigned char *p){func_021BC6DC((int *)(p+8));}

void func_021BC514(unsigned char *p){func_021BC6F0(p+8);}

unsigned func_021BC520(unsigned char *p){return func_021BC65C((const unsigned *)(p+4));}

unsigned func_021BC52C(unsigned char *p){return func_021BC6F8(p+8);}


/*
 * Addresses are Black-image addresses.
 */
void func_021BC538(void *unused, char *p)
{
    func_021BC5E8(p);
    func_021BC654(p + 4);
}
