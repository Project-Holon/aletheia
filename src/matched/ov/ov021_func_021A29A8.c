/*
 * function: func_021A29A8
 * address:  0x021A29A8
 * packet:   pkt_ov021_021A29A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 */

typedef unsigned short u16;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    char pad8[8];
    int f10;
} Obj;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
    u16 fc;
} Src;

int func_0204A6C8(int a, int b, int c, int d, int e);
int func_0204AC18(int a, int b, int c, int d, int e, int f, int g);
typedef signed int     s32;
typedef unsigned int   u32;
s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);

void func_021A29A8(Obj *o, Src *s, int heap)
{
    if (s->f2 != 0) {
        o->f2 = func_0204A6C8(o->f10, s->f6, 0, 0, heap);
        o->f4 = func_0204AC18(o->f10, s->f8, 0, 0, 0, 1, heap);
        o->f6 = func_0204AF28((void *)o->f10, s->fa, s->fc, heap);
        o->f0 = 1;
    }
}
