/*
 * file:     unit_021C2464_p01.c
 * unit:     yes
 * function: func_021C2464, func_021C2490
 * address:  0x021C2464
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0DA4  0x021C0DA4  arm  ov114
 *   func_021C2BB0  0x021C2BB0  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021841B0(u32);
extern void func_0217EAE0(u8 *);
extern u8 *func_021C0DA4(int);
extern void func_021C2BB0(u8 *);
void func_021C2464(u8 *p);
void func_021C2490(int a, int b);


/*
 * Releases the +0x00 handle, clears it, then tears the record down.
 */
void func_021C2464(u8 *p)
{
    if (*(u32 *)p != 0)
        func_021841B0(*(u32 *)p);
    *(u32 *)p = 0;
    func_0217EAE0(p);
}


/*
 * Flushes the object selected by `a`, then applies `b`.
 */
void func_021C2490(int a, int b)
{
    u8 *p = func_021C0DA4(a);
    if (p != 0)
        func_021C2BB0(p);
    func_021C2464((u8 *)b);
}
