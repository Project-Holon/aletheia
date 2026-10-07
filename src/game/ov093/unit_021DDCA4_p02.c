/*
 * file:     unit_021DDCA4_p02.c
 * unit:     yes
 * function: func_021DDD8C, func_021DDDC4, func_021DDDFC, func_021DDE30, func_021DDE74
 * address:  0x021DDD8C
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
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_021C7CF4(int *p, int i);
extern int func_021D775C(int);
extern int func_021DCFF8(int, int);
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);
void func_021DDD8C(int a, void *b, int c);
void func_021DDDC4(int a, void *b, int c);
void func_021DDDFC(int a, void *b, int c);
void func_021DDE30(int a, int b, int c, int d, int e);
int func_021DDE74(int a, void *b, int c, unsigned int d);


/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
void func_021DDD8C(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        func_021DDE30(a, (int)b, c, func_021DCFF8(a, 2), 1);
    }
}


void func_021DDDC4(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        func_021DDE30(a, (int)b, c, func_021DCFF8(a, 2), 0);
    }
}


void func_021DDDFC(int a, void *b, int c)
{
    func_021C7CF4(b, c);
    if (func_021DDEA4(b, c, func_021DCFF8(a, 2)) != 0) func_021DD044((void *)a, b, c);
}


void func_021DDE30(int a, int b, int c, int d, int e)
{
    int r;

    if (c == func_021D775C(2)) {
        if (e != 0)
            r = func_021DDE74(a, (void *)b, c, d);
        else
            r = func_021DDEA4((void *)b, c, d);
        if (r != 0)
            func_021DD044((void *)a, (void *)b, c);
    }
}


int func_021DDE74(int a, void *b, int c, unsigned int d)
{
    if (c == func_021D775C(2) && (unsigned char)func_021D775C(46) <= 1) return func_021DDEA4(b, c, d);
    return 0;
}
