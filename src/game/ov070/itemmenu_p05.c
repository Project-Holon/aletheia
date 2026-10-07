/*
 * file:     itemmenu_p05.c
 * unit:     yes
 * function: func_021B7CD0, func_021B7D20
 * address:  0x021B7CD0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021BB0BC  0x021BB0BC  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 */
typedef unsigned short u16;

typedef struct Obj_021B7CD0 {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj_021B7CD0;

typedef unsigned int   u32;

typedef struct Obj_021B7D20 {
    unsigned char pad000[0x18];
    void *gfx;
    unsigned char pad01C[0x544 - 0x1C];
    u16 f544;
    unsigned char pad546[0x810 - 0x546];
    int timerA;
    int timerB;
    unsigned char pad818[0x84C - 0x818];
    int cell;
} Obj_021B7D20;

typedef unsigned char  u8;

extern void func_020414EC(u32 i);
extern void func_021B6138(char *p);
extern void func_021BA6A4(char *p);
extern void func_021BB0BC(char *p);
extern void func_0204B92C(struct Obj_021B7CD0 *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern void func_021B8AF4(void *p);
extern int func_021B61B8(unsigned char *p);
extern void *func_021B616C(unsigned char *p, int i);
extern int func_021B61C8(unsigned char *p);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
void func_021B7CD0(Obj_021B7CD0 *o);
void func_021B7D20(Obj_021B7D20 *o, int x);


void func_021B7CD0(Obj_021B7CD0 *o)
{
    func_020414EC(3);
    o->f818 = 0xFFFF;
    func_021B6138((char *)o);
    o->f83E = 1;
    func_021BA6A4((char *)o);
    func_021BB0BC((char *)o);
    func_0204B92C(o->f6A8, 1);
    func_021BB3F4((int)o, 1);
    func_021B8AF4(o);
}


void func_021B7D20(Obj_021B7D20 *o, int x)
{
    int v;

    func_021B616C((unsigned char *)o, func_021B61B8((unsigned char *)o));
    func_02007F1C(o->gfx, o->cell, x, o->f544);
    if (func_02007FB8(o->gfx, o->cell, o->f544) != 0)
        return;
    if (func_021B61C8((unsigned char *)o) + 1 < 7) {
        v = o->timerA - 1;
        if (v <= 0)
            v = 0;
        o->timerA = v;
    } else {
        v = o->timerB - 1;
        if (v < -1)
            v = -1;
        o->timerB = v;
    }
}
