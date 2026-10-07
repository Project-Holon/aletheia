/*
 * file:     townmap_p16.c
 * unit:     yes
 * function: func_021BB5EC, func_021BB6AC, func_021BB6DC, func_021BB6E4, func_021BB6E8, func_021BB738, func_021BB758, func_021BB764, func_021BB778, func_021BB784, func_021BB790, func_021BB7BC, func_021BB80C
 * address:  0x021BB5EC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BB820  0x021BB820  thumb  ov072
 *   func_021BB9B8  0x021BB9B8  thumb  ov072
 *   func_020056A0  0x020056A0  thumb
 *   d_021BBD6C     0x021BBD6C  data  ov072  a1
 *   d_021BBBDC     0x021BBBDC  data  ov072
 *   func_02030EAC 0x02030EAC arm
 *   func_021BBAB4 0x021BBAB4 thumb ov072
 *   func_021BB968 0x021BB968 thumb ov072
 *   func_020307B0 0x020307B0 arm
 *   func_021BBAFC  0x021BBAFC  thumb
 *   d_021BBC28 0x021BBC28 data a4
 *   func_021BBB14  0x021BBB14  thumb
 *   func_021BBB0C  0x021BBB0C  thumb
 *   func_021BBB1C 0x021BBB1C thumb ov072
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_020434CC  0x020434CC  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_021BBB04 0x021BBB04 thumb ov072
 *   func_021BB9B0 0x021BB9B0 thumb ov072
 */
#include "../../matched/include/G_Ent.h"

struct Node;
struct DispVram;
typedef unsigned int u32;

struct V { int x; int y; int z; };

struct Obj {
    struct V a;
    struct V b;
    int f18;
    int f1c;
    int f20;
    struct V c;
};

typedef struct { u32 x,y,z; } Vec;

typedef unsigned short u16;

typedef unsigned char u8;

extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0207CA00(struct V *a, struct V *b, struct V *c);
extern int func_0207CBD0(struct V *a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021BB820(u32 *p, u32 a);
extern void func_021BB9B8(u32 *p, char *s, u32 a);
extern u32  func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_02030EAC(struct Node *n);
extern void func_021BBAB4(u32 *);
extern void func_021BB968(void *);
extern u32 func_020307B0(void *p);
void func_021BBAFC(int x);
unsigned int func_021BBB14(void *p, int n);
unsigned int func_021BBB0C(void *p, int n);
extern int func_021BBB1C(char *,int);
extern void func_0204335C(u32 a);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 a);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);
extern void func_021BBB04(void *);
extern void func_021BB9B0(void *);
void func_021BB5EC(struct Obj *p);
int func_021BB6AC(u32 *p,Vec *v,u32 *out);
void func_021BB6DC(int *p);
void func_021BB6E4(void *a, void *b);
u32 *func_021BB6E8(u32 heap);
void func_021BB738(u32 *p);
void func_021BB758(char *p);
u8 func_021BB764(int unused, u32 i);
unsigned int func_021BB778(char *p, int n);
unsigned int func_021BB784(char *p, int n);
void func_021BB790(char *p,int *a,int *b,int *c);
void func_021BB7BC(void);
void func_021BB80C(int unused, char *p);
extern char d_021BBD6C[];
extern char d_021BBBDC[];
extern struct Ent d_021BBC28;


void func_021BB5EC(struct Obj *p)
{
    u32 y;
    u32 x;

    p->f1c = 0;
    if (func_02035D20(&y, &x)) {
        if (x <= 0xA8) {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
        return;
    }
    if (func_02035CB8(&y, &x)) {
        if (x <= 0xA8) {
            if (p->f20 != 0) {
                p->a = p->b;
                p->f20 = 0;
            }
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
            func_0207CA00(&p->b, &p->a, &p->c);
            if (func_0207CBD0(&p->c) >= 0x1000) {
                p->f1c = 1;
            }
        } else {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
    }
}

int func_021BB6AC(u32 *p,Vec *v,u32 *out) { if(p[7]!=0) { if(v!=0) *v=*(Vec *)(p+9); if(out!=0) *out=p[6]; return 1; } return 0; }

/*
 * note:     listing extent (12) runs past the compiled function (6) into an
 *           unlabelled Thumb leaf (a `bx lr` at 0x021BB6E4), no byte
 *           difference.
 */
void func_021BB6DC(int *p)
{
    p[8] = 1;
}

/*
 * Unlabelled empty task callback (a lone `bx lr`) whose address
 * func_021B95A0 passes to func_020056A0 through its pool word 0x021BB6E5.
 */
void func_021BB6E4(void *a, void *b)
{
}


u32 *func_021BB6E8(u32 heap)
{
    u32 *p;

    p = func_02030734(heap, 0x2C, 0, d_021BBD6C, 0xEC);
    func_02082BCC(p, 0, 0x2C);
    func_021BB7BC();
    func_021BB820(p, heap);
    func_021BB9B8(p + 1, d_021BBBDC, heap);
    p[10] = func_020056A0((void (*)(void))func_021BB80C, p, 1);
    return p;
}

void func_021BB738(u32 *p) { func_02030EAC((void *)p[10]); func_021BBAB4(p+1); func_021BB968(p); func_020307B0(p); }


/*
 * bx r3` veneer followed by its own pool) in ov072, so no `label` branch and
 * no `sole-ref/code` function start attests it; the only pool word naming it
 * is this function's own. All 12 bytes and the relocation field are right.
 *
 * UNBLOCKED: func_021BBAFC is now an EXACT entry in layout/matched/ov072;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BB758(char *p)
{
    func_021BBAFC((int)(p + 4));
}

u8 func_021BB764(int unused, u32 i) { return *(u32 *)((u32)&(*(u32 *)&d_021BBC28) + i*40); }


unsigned int func_021BB778(char *p, int n)
{
    return func_021BBB14(p + 4, n);
}


unsigned int func_021BB784(char *p, int n)
{
    return func_021BBB0C(p + 4, n);
}

void func_021BB790(char *p,int *a,int *b,int *c) { *a=func_021BBB1C(p+4,0); *b=func_021BBB1C(p+4,1); *c=func_021BBB1C(p+4,2); }


void func_021BB7BC(void)
{
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BBBDC);
    func_0204363C(0);
    func_0204361C();
    func_020434CC();
    func_0201DD60();
}

void func_021BB80C(int unused, char *p) { func_021BBB04(p+4); func_021BB9B0(p); }
