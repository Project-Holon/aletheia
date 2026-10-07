/*
 * file:     unit_021DCAE8_p06.c
 * unit:     yes
 * function: func_021DD240, func_021DD26C
 * address:  0x021DD240
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
 *   func_021DD338 0x021DD338 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021DD368 0x021DD368 thumb ov093
 */
typedef unsigned char u8;

extern int func_021D775C(int);
extern u8 func_021DD338(void *, int);
extern void func_021DD044(void *, void *, int);
extern u8 func_021DD368(void *, int);
void func_021DD240(void *a, void *b, int c);
void func_021DD26C(void *a, void *b, int c);

void func_021DD240(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021DD338(b, c) != 4)
            func_021DD044(a, b, c);
    }
}

void func_021DD26C(void *a, void *b, int c)
{
    int v;
    if (c == func_021D775C(2)) {
        v = func_021D775C(0x2e);
        if (v != 2 && v != 0) return;
        if (func_021DD368(b, c) != 4)
            func_021DD044(a, b, c);
    }
}
