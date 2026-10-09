/*
 * file:     unit_021E0628.c
 * unit:     yes
 * function: func_021E0628, func_021E0680, func_021E068C, func_021E06D0
 * address:  0x021E0628
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   d_021F2664     0x021F2664  data   ov093  a4
 *   d_021F2614     0x021F2614  data   ov093  a4
 */
typedef unsigned short u16;

typedef unsigned int   u32;

struct S {
    int f0;
    int f4;
    int f8;
    int fC;
    u16 f10;
    u16 f12;
};

typedef struct { unsigned v; } Word;

extern int func_021D775C(int key);
extern int func_021EF948(int k);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021E8940(u32 a);
extern void func_021C88C8(void *a, void *b);
extern void func_021C88B4(void *a, int k, int b);
extern Word func_021E899C(int a);
extern void func_021C8838(void *p, int a, int b);
void func_021E0628(int a, void *b, int c);
int *func_021E0680(int *p);
void func_021E068C(int a, void *b, int c);
int *func_021E06D0(int *p);
extern int d_021F2664[];
extern int d_021F2614[];


void func_021E0628(int a, void *b, int c)
{
    struct S *p;

    if (c == func_021D775C(3)) {
        if (func_021EF948(2) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            p->f4 = 2;
            p->f8 = func_021E8940(5);
            p->f12 = (p->f12 & ~0xff) | 1;
            p->f10 = 0x75;
            func_021C88C8(b, p);
            func_021C88B4(b, 0x35, c);
        }
    }
}


int *func_021E0680(int *p)
{
    *p = 1;
    return d_021F2664;
}


void func_021E068C(int a, void *b, int c)
{
    int *p;

    if (c == func_021D775C(3)) {
        p = func_021C88A4(b, 0x1b, c);
        p[1] = 4;
        *(Word *)(p + 2) = func_021E899C(c);
        func_021C8838(p + 4, 1, 0x72);
        func_021C88C8(b, p);
    }
}


/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
int *func_021E06D0(int *p)
{
    *p = 1;
    return d_021F2614;
}
