/*
 * file:     box2_main_p13.c
 * unit:     yes
 * function: func_021DF1BC, func_021DF1DC, func_021DF228, func_021DF254, func_021DF288, func_021DF324
 * address:  0x021DF1BC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021EF798 0x021EF798 data a1
 *   func_021EF224  0x021EF224  thumb  ov170
 *   func_02030734 0x02030734 arm
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02031348 0x02031348 arm
 *   d_021F1400 0x021F1400 data a1
 *   d_021DC800 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj05437.h"
#include "../../matched/include/Obj04901.h"
#include "../../matched/include/Obj12155.h"

typedef struct {
    void *mon;
    void *f4;
    void *save;
    unsigned char kind, mode, count, slot, zero;
    char pad[7];
    void *f18;
    char pad1C[12];
} Request;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_021EF224(int, int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern unsigned func_0201AA18(void *p);
extern void func_02031348(void *p, int a, const void *b, void *c);
extern u32 func_020307B0(void *p);
int func_021DF1BC(int a, int b, unsigned char *r);
int func_021DF1DC(short x, int y);
int func_021DF228(void *p, int a, int *b);
int func_021DF254(unsigned char *p, short x, short y);
int func_021DF288(char *p);
int func_021DF324(char *p);
extern const unsigned char d_021EF798[];
extern const char d_021F1400[];
extern const unsigned d_021DC800[];
extern const char ov131_id[];

/*
 * Signed containment test: 1 when a is inside [r[0],r[1]] and b
 *   inside [r[2],r[3]).  Return-1 arm is the fall-through.
 */
int func_021DF1BC(int a, int b, unsigned char *r)
{
    if (a >= r[0] && a <= r[1] && b >= r[2] && b < r[3])
        return 1;
    return 0;
}


int func_021DF1DC(short x, int y)
{
    if (func_021DF1BC(x, y, (unsigned char *)d_021EF798) == 1) {
        if (x < 0xC)
            x = 0;
        else if (x >= 0x9C)
            x = 5;
        else
            x = (short)((x - 0xC) / 0x18);
        y -= 0x28;
        return x + (short)(y / 0x18) * 6;
    }
    return 0xFF;
}



/*
 * Scan the six 4-byte entries of the third argument; the first one that
 * func_021DF1BC accepts returns i + 0x1e, else 0xff.
 */
int func_021DF228(void *p, int a, int *b)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        if (func_021DF1BC((int)p, a, (unsigned char *)(b + i)) == 1)
            return i + 0x1e;
    return 0xff;
}

/*
 * Wrap the -1/0xff query into the 0xc0..0xff window and hand the
 *   wrapped value back; 0xff is the error.  The three byte fields are
 *   unsigned char (ldrb) and the comparison is unsigned (blo).
 */
int func_021DF254(unsigned char *p, short x, short y)
{
    int v = func_021EF224(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA180),
                          *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA184));
    unsigned w;
    if (v == 0xff)
        return v;
    w = v - 0x24 + p[0x19];
    if (w >= p[0x15])
        w -= p[0x15];
    if (w == p[0x14])
        return 0xff;
    return v;
}

int func_021DF288(char *p)
{
    Request *r;
    unsigned mode;
    r = func_02030734(0x4B, 0x28, 0, d_021F1400, 0xEAC);
    if (((struct Obj05437 *)p)->f16 < 30) {
        r->mon = (void *)func_021DD2D0((void ***)p, ((struct Obj05437 *)p)->f17, 0);
        r->kind = 2;
        r->count = 30;
        r->slot = ((struct Obj05437 *)p)->f16;
    } else {
        r->mon = (*(void ***)p)[2];
        r->kind = 1;
        r->count = func_0201AA18((*(void ***)p)[2]);
        r->slot = ((struct Obj05437 *)p)->f16 - 30;
    }
    mode = 0;
    r->zero = 0;
    r->save = (*(void ***)p)[0];
    r->f4 = (*(void ***)p)[6];
    r->f18 = (*(void ***)p)[7];
    if ((*(int **)p)[5] == 1) {
        r->mode = 6;
    } else {
        r->mode = 0;
    }
    func_02031348(((struct Obj05437 *)p)->f4, (int)ov131_id, d_021DC800, r);
    *(Request * *)&((struct Obj05437 *)p)->fC = r;
    return 0;
}

/*
 * Clamp p[0x16] to 0x1e below the limit of the p+0xc object's
 *   byte 0xf, then hand the object to the SDK.  The callee argument is the
 *   re-read expression, not the local, which is why the image re-loads it.
 */
int func_021DF324(char *p)
{
    int q = ((struct Obj04901 *)p)->fC;
    if (((struct Obj04901 *)p)->f18 == 0) {
        if (((struct Obj04901 *)p)->f16 < 0x1e)
            ((struct Obj04901 *)p)->f16 = ((struct Obj12155 *)q)->fF;
        else
            ((struct Obj04901 *)p)->f16 = ((struct Obj12155 *)q)->fF + 0x1e;
    }
    func_020307B0((void *)(((struct Obj04901 *)p)->fC));
    return 0;
}
