/*
 * file:     unit_021DCAE8_p07.c
 * unit:     yes
 * function: func_021DD2A4, func_021DD2D0, func_021DD2F8, func_021DD320
 * address:  0x021DD2A4
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
 *   func_021DD368 0x021DD368 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021DD338 0x021DD338 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021DD39C 0x021DD39C thumb ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021D775C(int);
extern u8 func_021DD368(void *, int);
extern void func_021DD044(void *, void *, int);
extern u8 func_021DD338(void *, int);
extern int func_021D76BC(int, u32);
extern int func_021DD39C(int, void *, int, int, int);
void func_021DD2A4(void *a, void *b, int c);
void func_021DD2D0(int a, void *b, int c);
void func_021DD2F8(int a, void *b, int c, int *d);
void func_021DD320(int a, void *b, u8 c, int *d);

void func_021DD2A4(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021DD368(b, c) != 4)
            func_021DD044(a, b, c);
    }
}

void func_021DD2D0(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021DD338(b, c) != 4)
        func_021D76BC(0x51, 1);
}

/*
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 */
void func_021DD2F8(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021DD39C(a, b, c, (int)d, 0);
}

/*
 * extent: trailing two-byte alignment padding.
 */
void func_021DD320(int a, void *b, u8 c, int *d)
{
    if (d[6] != 0) func_021DD39C(a, b, c, (int)d, 1);
}
