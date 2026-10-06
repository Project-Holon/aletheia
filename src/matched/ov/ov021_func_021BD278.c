/*
 * function: func_021BD278
 * address:  0x021BD278
 * packet:   pkt_ov021_021BD278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    void *f0;
    u16 h4;
    u16 h6;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u16 h12;
    int f14;
} Desc;

typedef struct {
    char pad[8];
    void *f8;
    void *fC;
} Obj;

struct Grid;
struct Param;
struct Sys;
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);

void func_021BD278(Obj *p, int a, u16 b, int c)
{
    Desc d;

    d.f0 = p->f8;
    d.h4 = 0;
    d.h6 = 0;
    d.f8 = c;
    d.fC = 0;
    d.b10 = 0;
    d.b11 = 0;
    d.h12 = b;
    d.f14 = 0;
    p->fC = func_020255A0((struct Sys *)a, (const struct Param *)(&d));
}
