/*
 * file:     unit_02179824_p01.c
 * unit:     yes
 * function: func_02179824, func_02179840, func_0217984C
 * address:  0x02179824
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02179A4C 0x02179A4C thumb ov015
 *   func_021799B4  0x021799B4  thumb ov015
 *   func_02179D3C  0x02179D3C  thumb  ov015
 *   func_02179B24  0x02179B24  thumb  ov015
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02179A4C(void *, u8, u8);
void func_021799B4(unsigned v);
int func_02179D3C(void);
int func_02179B24(void);
/* * extent: two zero alignment bytes at 0217983E. */ int func_02179824(void *dst, int a, int unused, void (*cb)(int));
int func_02179840(int v);
int func_0217984C(void);


/*
 * extent: two zero alignment bytes at 0217983E.
 */
int func_02179824(void *dst, int a, int unused, void (*cb)(int))
{
    func_02179A4C(dst, (u8)a, 0);
    if (cb != 0) cb(1);
    return 1;
}



int func_02179840(int v)
{
    func_021799B4(v);
    return 1;
}


/*
 * Guard/forward wrapper: returns the follower's result only when the predicate
 * holds, otherwise zero.
 */
int func_0217984C(void)
{
    if (func_02179D3C())
        return func_02179B24();
    return 0;
}
