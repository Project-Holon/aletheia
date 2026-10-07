/*
 * file:     unit_021D8B50_p01.c
 * unit:     yes
 * function: func_021D8B50, func_021D8B84, func_021D8BB4
 * address:  0x021D8B50
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
 *   d_021F07C0 0x021F07C0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F07B8 0x021F07B8 data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D7AD4(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021D8B50(int a, int b, int c);
void *func_021D8B78(int *p);
void func_021D8B84(int a, int b, int c);
void *func_021D8BA8(int *p);
void func_021D8BB4(int u, int a, int k);
extern unsigned char d_021F07C0[];
extern unsigned int d_021F07B8;


void func_021D8B50(int a, int b, int c)
{
    if(c==func_021D775C(4) && func_021D7AD4(func_021D775C(0x38))==2) func_021D7704(0x35,0xC00);
}


void *func_021D8B78(int *p)
{
    *p = 1;
    return d_021F07C0;
}

void func_021D8B84(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x45)) func_021D7704(0x35, 3 << 11);
}

void *func_021D8BA8(int *p) { *p = 1; return &d_021F07B8; }


void func_021D8BB4(int u, int a, int k)
{
    u32 *r;

    if (k == func_021D775C(2)) {
        if (func_021D5BDC(func_021C7CF4((int *)a, k), 0) != 0) {
            r = func_021C88A4((void *)a, 14, k);
            r[0] |= 2 << 22;
            r[1] = 5;
            ((u8 *)r)[0xf] = 1;
            ((u8 *)r)[0x10] = k;
            ((u8 *)r)[0xc] = 1;
            func_021C88C8((void *)a, r);
        }
    }
}
