/*
 * file:     unit_02179824_p01.c
 * unit:     yes
 * function: func_02179824, func_02179840
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
 */
typedef unsigned char u8;

extern void func_02179A4C(void *, u8, u8);
void func_021799B4(unsigned v);
int func_02179824(void *dst, int a, int unused, void (*cb)(int));
int func_02179840(int v);

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
