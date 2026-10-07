/*
 * file:     field_place_name_p03.c
 * unit:     yes
 * function: func_021BBFF4, func_021BC030
 * address:  0x021BBFF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0219C98C  0x0219C98C  thumb  ov021
 */
typedef unsigned int u32;

typedef struct { u32 w[5]; } Blk;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    Blk blk;
    u32 f28;
    u32 f2C;
} Obj_021BBFF4;

typedef unsigned char u8;

typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xF];
    void *f20;
    int pad24;
    char f28[1];
} Obj_021BC030;

typedef unsigned short u16;

extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern void func_0219C98C(u32 a, u16 *b);
void func_021BBFF4(u32 a, Obj_021BBFF4 *o);
void func_021BC030(int a0, Obj_021BC030 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021BBFF4(u32 a, Obj_021BBFF4 *o)
{
    u32 *p = (u32 *)func_021AC1AC(a);

    o->blk = *(Blk *)p;
    o->f0C = 0x40;
    o->f00 = 0;
    o->f08 = 0;
    if (o->blk.w[1] == 2) {
        o->f0C = 0;
    }
    func_0216E1A4(p[2], (int)(&o->f2C));
}


void func_021BC030(int a0, Obj_021BC030 *p)
{
    if (p->b10) {
        p->b10 = 0;
        func_0219C98C((u32)p->f20, (u16 *)p->f28);
    }
}
