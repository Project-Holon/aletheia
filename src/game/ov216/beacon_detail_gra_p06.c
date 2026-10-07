/*
 * file:     beacon_detail_gra_p06.c
 * unit:     yes
 * function: func_021BC8A8, func_021BC920, func_021BC930, func_021BC9D0, func_021BCA24, func_021BCA38, func_021BCA44, func_021BCA58, func_021BCAB8, func_021BCAF0
 * address:  0x021BC8A8
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   sub_0202DBC4  0x0202DBC4  thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BCAFC 0x021BCAFC thumb ov216
 *   d_021BDDC0 0x021BDDC0 data a1
 *   d_021BDBD8 0x021BDBD8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BCB70 0x021BCB70 thumb ov216
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BCB90  0x021BCB90  thumb  ov216
 *   func_021BCBA0 0x021BCBA0 thumb ov216
 *   func_021BCAF4  0x021BCAF4  thumb  ov216
 *   func_021BCB98  0x021BCB98  thumb  ov216
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BDBAC 0x021BDBAC data a4
 *   d_021BDC28 0x021BDC28 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
#include "../../matched/include/Obj01437.h"
#include "../../matched/include/Obj05553.h"

struct Descriptor;
struct Obj;
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct Entry { unsigned id; char fields[32]; unsigned a,b; };

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0202DC08(struct Obj *p);
extern int sub_0202DBC4(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BCAFC(void **p, void *a, int heap);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_021BCB70(char *p);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BCB90(void *);
extern u32 func_021BCBA0(u32 *p);
extern void func_021BCAF4(void *);
extern void func_021BCB98(void *);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021BC8A8(char *p);
int func_021BC920(u32 *p);
void *func_021BC930(int a,int heap);
void func_021BC9D0(unsigned *p);
void func_021BCA24(char *p);
void *func_021BCA38(char *p);
void func_021BCA44(void *unused, char *p);
void func_021BCA58(void *p,int heap);
void func_021BCAB8(void *p);
void func_021BCAF0(void *p);
extern char d_021BDDC0[];
extern unsigned d_021BDBD8[];
extern const unsigned d_021BDBAC[];
extern const struct Entry d_021BDC28[];

void func_021BC8A8(char *p)
{
    int i=0,j;
    char *base=p+0x15c;
    for(;i<2;i++) {
        char *q=base+i*128;
        func_0204B3DC(((struct Obj05553 *)q)->f78,0); func_0204B3B4(((struct Obj05553 *)q)->f78);
        func_0204B3DC(((struct Obj05553 *)q)->f74,0); func_0204B3B4(((struct Obj05553 *)q)->f74);
        func_020452E8(((struct Obj05553 *)q)->f60);
        for(j=0;j<2;j++) func_020452E8(*(void **)(q+0x40+j*16));
        for(j=0;j<4;j++) func_020452E8(*(void **)(q+j*16));
        func_020452E8(((struct Obj05553 *)q)->f70);
    }
    func_0202DC08(((struct Obj01437 *)p)->f158);
}


/*
 * Tail-call getter: loads p[0x56] and tail-calls sub_0202DBC4.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC920(u32 *p)
{
    return sub_0202DBC4(p[0x56]);
}

/*
 * volatile: hardware accesses 0x021BC956-0x021BC96A.
 */
void *func_021BC930(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BDDC0,317);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BDBD8);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BCA58(p,heap);
    func_021BCAFC((void **)(p+1),d_021BDBD8,heap);
    p[3]=(unsigned)func_020056A0((void (*)(void *, void *))func_021BCA44,p,0);
    return p;
}

void func_021BC9D0(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_021BCB70((char *)(p+1));
    func_021BCAB8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BCA24(char *p)
{
    func_021BCB90(p + 4);
    func_021BCAF0(p);
}

void *func_021BCA38(char *p){return (void *)func_021BCBA0((u32 *)(p+4));}


void func_021BCA44(void *unused, char *p)
{
    func_021BCAF4(p);
    func_021BCB98(p + 4);
}

void func_021BCA58(void *p,int heap)
{
    unsigned i;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021BDBAC);
    for(i=0;i<8;i++) {
        const struct Entry *e=&d_021BDC28[i];
        unsigned id=e->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        func_020414AC(id);
        func_02040588(id,e->b);
    }
}

void func_021BCAB8(void *p){unsigned base=(unsigned)d_021BDC28;unsigned i;for(i=0;i<8;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

void func_021BCAF0(void *p) {}
