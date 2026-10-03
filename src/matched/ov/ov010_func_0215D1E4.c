/*
 * function: func_0215D1E4
 * address:  0x0215D1E4
 * packet:   pkt_ov010_0215D1E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u32 pad[15]; u32 f3c; } O8;
typedef struct { u8 pad[15]; u8 fF; } OC;
typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    OC *fC;
    u16 *f10;
} Ctx;

extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020144DC(void *, void *);
extern void *func_02014910(void *, void *, void *, void *);
extern void *func_020145CC(void *);
extern void func_020307B0(void *);

int func_0215D1E4(void *a, u32 *st, Ctx *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, func_020144DC(p0, c->f4));
        c->f8->f3c = c->fC->fF;
        *st = 2;
        break;
    case 2:
        func_02012374(a, func_02014910(p0, c->f4, c->f8, c->fC));
        *st = 3;
        break;
    case 3:
        func_02012374(a, func_020145CC(p0));
        *st = 4;
        break;
    case 4:
        func_02012374(a, func_021BE92C(p0, c->f4, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        *c->f10 = c->f8->f3c;
        func_020307B0(c->f8);
        func_020307B0(c->fC);
        return 1;
    }
    return 0;
}
