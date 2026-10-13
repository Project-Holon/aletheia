/*
 * function: func_0215A214
 * address:  0x0215A214
 * packet:   pkt_ov010_0215A214
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u32 pad[15]; int f3c; } O8;
typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Ctx;

extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern u32 func_020307B0(void *p);

int func_0215A214(void *a, u32 *st, Ctx *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    int v;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)p0, (int)c->f4));
        *st = 2;
        break;
    case 2:
        func_02012374(a, func_02014910(p0, (int)c->f4, (int)c->f8, (int)c->fC));
        *st = 3;
        break;
    case 3:
        func_02012374(a, FIELD_STATUS_CreateFieldOpenEvent(p0));
        *st = 4;
        break;
    case 4:
        func_02012374(a, func_021BE92C(p0, c->f4, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        v = c->f8->f3c;
        if (v <= 5) {
            *c->f14 = v;
            *c->f10 = 1;
        } else {
            *c->f14 = 0;
            *c->f10 = 0;
        }
        func_020307B0(c->f8);
        if (c->fC != 0)
            func_020307B0(c->fC);
        return 1;
    }
    return 0;
}
