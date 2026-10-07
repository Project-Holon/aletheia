/*
 * file:     pokemontrade_proc_p03.c
 * unit:     yes
 * function: func_021D8EC8, func_021D8EEC
 * address:  0x021D8EC8
 * region:   ov119
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
 */
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
u32 func_021D8EC8(u32 a, u32 b);
void func_021D8EEC(u32 a, u32 b, u8 *src, u8 *base, void *e);

u32 func_021D8EC8(u32 a, u32 b)
{
    if (a == func_0203D1A4((struct Link *)func_020399A8()))
        return b + 0x10;
    return b + 0x2e6;
}

void func_021D8EEC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        u32 idx = (a == func_0203D1A4((struct Link *)func_020399A8())) ? 0 : 1;
        *(base + idx + 0x11e8) = *src;
    }
}
