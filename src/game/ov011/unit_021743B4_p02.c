/*
 * file:     unit_021743B4_p02.c
 * unit:     yes
 * function: func_02174630, func_02174660
 * address:  0x02174630
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_020266AC 0x020266AC thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 */
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct Entry *func_020399A8(void);
u32 func_0203D1A4(struct Link *p);
void func_020266AC(u32 a, u32 b, u32 c);
int func_021736D8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02174630(int a, int b, u8 *c, u8 *p);
int func_02174660(int a, ...);

/*
 * extent: existing follower ov011_func_02174660.c stays separate.
 */
void func_02174630(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((u32)func_020399A8())) && (p[0x8fb] & (1 << a))) {
        func_020266AC(((u32 *)p)[1], a, *c);
    }
}


/*
 * Handed as 0x02174662; the function starts at the push {r0-r3} at 0x02174660.
 */
int func_02174660(int a, ...)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x223, 1, (u32)(&a));
}
