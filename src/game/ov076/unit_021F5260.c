/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F5270, func_021F5280, func_021F5290, func_021F52A0, func_021F52B0, func_021F52D8, func_021F5324
 * address:  0x021F5260
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF560 0x021CF560 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5334  0x021F5334  thumb  ov076
 *   func_0202E688 0x0202E688 thumb
 */
struct Ctx;
struct Desc;
typedef unsigned int u32;

extern int func_02189A08(unsigned char *p);
extern u32 func_021CF560(u32 *);
extern void *func_0201210C(const struct Ctx *p);
extern u32 *func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5334(void *task, int *st);
extern void func_0202E688(u32);
void *func_021F5260(void *a, u32 b, int c);
void *func_021F5270(void *a, u32 b, int c);
void *func_021F5280(void *a, u32 b, int c);
void *func_021F5290(void *a, u32 b, int c);
void *func_021F52A0(void *a, u32 b, int c);
void *func_021F52B0(void *a, u32 b, int c);
void *func_021F52D8(void *a, u32 b, u32 c, u32 d, int e);
void func_021F5324(u32 *p);

void *func_021F5260(void *a, u32 b, int c) { return func_021F52D8(a,b,7,6,c); }

void *func_021F5270(void *a, u32 b, int c) { return func_021F52D8(a,b,9,8,c); }

void *func_021F5280(void *a, u32 b, int c) { return func_021F52D8(a,b,5,4,c); }

void *func_021F5290(void *a, u32 b, int c) { return func_021F52D8(a,b,3,2,c); }

/*
 * Extent tail: two bytes of alignment padding.
 */
void *func_021F52A0(void *a, u32 b, int c) { return func_021F52D8(a,b,1,0,c); }

void *func_021F52B0(void *a, u32 b, int c) {
    void *h;
    h = func_021F52D8(a,b,11,10,c);
    *(u32 *)(func_021CF560((u32 *)func_02189A08((unsigned char *)b)) + 0x40) = 0x7F3;
    return h;
}


void *func_021F52D8(void *a, u32 b, u32 c, u32 d, int e)
{
    u32 *w;
    void *h;

    w = func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(a))), 0x44, 0x50);
    h = func_020122C0(a, 0, func_021F5334, 0);
    w[1] = b;
    w[0xB] = c;
    w[0xC] = d;
    w[0x10] = -1;
    if (e != 0) {
        w[0xD] = 0xC;
    } else {
        w[0xD] = 3;
    }
    return h;
}

void func_021F5324(u32 *p) { func_0202E688(*(u32 *)(func_021CF560(p) + 0x28)); }
