/*
 * file:     unit_021B95A0_p04.c
 * unit:     yes
 * function: func_021B9A34, func_021B9A50, func_021B9A60, func_021B9A70, func_021B9AE0, func_021B9B00, func_021B9B24, func_021B9B54, func_021B9B64
 * address:  0x021B9A34
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C4948  0x021C4948  thumb  ov127
 *   func_021C5704  0x021C5704  thumb  ov127
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4A8C  0x021C4A8C  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021C5864  0x021C5864  thumb  ov127
 *   func_021C5814  0x021C5814  thumb  ov127
 *   func_021BA594  0x021BA594  thumb
 *   func_021BA5DC  0x021BA5DC  thumb  ov099
 *   func_021BA5F0  0x021BA5F0  thumb  ov099
 *   func_021B9BC4  0x021B9BC4  thumb  ov099
 *   func_021B984C  0x021B984C  thumb  ov099
 *   func_021BA794  0x021BA794  thumb  ov099
 *   func_021BA7BC  0x021BA7BC  thumb  ov099
 *   func_021BA660  0x021BA660  thumb  ov099
 */
#include "../../matched/include/Obj18147.h"
#include "../../matched/include/Obj18148.h"
#include "../../matched/include/Obj04411.h"

typedef unsigned char  u8;

typedef struct {
    void *f0;
    void *f4;
    char pad[0x14];
} Obj;

typedef unsigned short u16;

typedef unsigned long  u32_021B9A50;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021B9A60;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    unsigned short fc;
    unsigned short fe;
    int f10;
    int f14;
    int f18;
} Ent;

typedef unsigned int u32_021B9AE0;

typedef unsigned long  u32_021B9B00;

typedef unsigned long  u32_021B9B24;

typedef unsigned long  u32_021B9B54;

typedef unsigned long  u32_021B9B64;

extern void func_021C5704(u8 *p);
extern void func_021C4948(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern int func_021C49A4(u8 *p, unsigned int i);
extern unsigned char func_021C4A8C(int i);
extern void func_021C57D8(u8 *p, int v);
extern void func_021C5864(u8 *p, int b);
extern void func_021C5814(void *p, Pos pos);
extern void func_021BA594(char *p, int a, int b, int c);
extern int func_021BA5DC(void *b);
extern void func_021BA5F0(void *a, char *b, u8 c);
extern int func_021B9BC4(void *p);
extern int func_021B984C(void *p);
extern void func_021BA794(u8 *p, u8 b);
extern void func_021BA7BC(char *p);
extern void func_021BA660(int unused, void *p);
void func_021B9A34(Obj *p);
u8 func_021B9A50(char *p);
unsigned char func_021B9A60(char *p);
void func_021B9A70(void *o, Ent *e, int n);
void func_021B9AE0(void *w,u8 *s);
void func_021B9B00(void *a, char *b, u8 c);
void func_021B9B24(char *p);
void func_021B9B54(char *p);
void func_021B9B64(char *p);


/*
 * ("ldr r3, =0x02082BCC; movs r1, #0; movs r2, #0x18; bx r3"); witness
 * bl from ov099 at 0x021B9A40. Seeding it (ov127 lane) makes this EXACT.
 */
void func_021B9A34(Obj *p)
{
    func_021C5704(p->f4);
    func_021C4948(p->f0);
    func_02082BCC(p, 0, sizeof(Obj));
}


u8 func_021B9A50(char *p)
{
    return (u8)func_021C49A4(((struct Obj18147 *)p)->f0, 4);
}


/*
 * Two ov127 calls, the second on the first one's answer.
 *
 * NOT EXACT.  MATCH: 16 bytes, the call sequence and the first relocation are
 * right; the second target 0x021C4A8C has no witness.  It is not a `func_` label
 * in any overlay listing, yet nine overlays overlap the address (ov016, ov021,
 * ov093, ov111, ov114, ov127, ov136, ov172, ov208), so a region hint cannot name
 * one either.  It turns EXACT as soon as 0x021C4A8C is labelled or matched.
 *
 * UNBLOCKED: 0x021C4A8C is now an EXACT entry in layout/matched/ov127;
 * the second call site resolves as matched, verdict promoted to EXACT.
 */
unsigned char func_021B9A60(char *p)
{
    return func_021C4A8C(func_021C49A4(((struct Obj18148 *)p)->f0, 6));
}


void func_021B9A70(void *o, Ent *e, int n)
{
    Pos s;

    e->f14 = e->f10;
    e->f10 = 0x021BA591;
    e->fe = e->fc;
    e->fc = 5;
    func_021BA594(o, 0, n, func_021C49A4(e->f0, 4));
    func_021C57D8(e->f4, 0);
    func_021C5864(e->f4, n);
    s.x = func_021C49A4(e->f0, 0);
    s.y = func_021C49A4(e->f0, 1);
    func_021C5814(e->f4, s);
}

void func_021B9AE0(void *w,u8 *s) { if (s) { if (((struct Obj04411 *)s)->f14) { ((struct Obj04411 *)s)->f10=((struct Obj04411 *)s)->f14; ((struct Obj04411 *)s)->f14=0; ((struct Obj04411 *)s)->fC=((struct Obj04411 *)s)->fE; func_021C57D8(((struct Obj04411 *)s)->f4,1); } } }


void func_021B9B00(void *a, char *b, u8 c)
{
    if (func_021BA5DC(b) == 0) {
        b[0xB] = c;
    } else {
        func_021BA5F0(a, b, c);
    }
}


void func_021B9B24(char *p)
{
    if (func_021B9BC4(p) == 1) {
        s8 x = (s8)func_021B984C(p);
        s8 y = x - 3;

        func_021BA794((u8 *)(p + 0x574), y);
    }
}


void func_021B9B54(char *p)
{
    func_021BA7BC(p + 0x574);
}


void func_021B9B64(char *p)
{
    if (*(u32_021B9B64 *)0x02FFFC3C & 1) {
        func_021BA660((int)p, p + 0x574);
    }
}
