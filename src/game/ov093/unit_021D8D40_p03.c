/*
 * file:     unit_021D8D40_p03.c
 * unit:     yes
 * function: func_021D8F1C, func_021D8F54, func_021D8F84
 * address:  0x021D8F1C
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D8E00 0x021D8E00 thumb ov093
 *   func_021D8E7C 0x021D8E7C thumb ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D8E00(void *, int);
extern void func_021D8E7C(int, void *, unsigned int, unsigned int, unsigned char);
extern u16 func_021D70A8(struct QQ *p);
void func_021D8F1C(int a, void *b, int c, int *d);
void func_021D8F54(int a, void *b, int c, int *d);
void func_021D8F84(int u, int a, int b, int *p);

void func_021D8F1C(int a, void *b, int c, int *d)
{
    if (*d && c == func_021D775C(2) && func_021D8E00(b, c))
        func_021D8E7C(a, b, c, 0, 0);
}

void func_021D8F54(int a, void *b, int c, int *d)
{
    if (*d && func_021D8E00(b, c)) func_021D8E7C(a, b, c, 0, 0);
}


void func_021D8F84(int u, int a, int b, int *p)
{
    int t;

    if (*p != 0 && func_021D8E00((void *)a, b) != 0) {
        if (b == func_021D775C(2)) {
            t = func_021D775C(0x10);
            if (t != func_021D70A8((void *)u))
                func_021D8E7C(u, (void *)a, b, 0, 0);
        }
    }
}
