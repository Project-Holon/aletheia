/*
 * file:     pokemontrade_proc_p06.c
 * unit:     yes
 * function: func_021D90D4, func_021D90E8
 * address:  0x021D90D4
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
 *   func_021D9038  0x021D9038  thumb  ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021D9038(int a, int b, int c, int d, int e, int f);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
int func_021D90D4(int a, int b, int c, int d, int e);
void func_021D90E8(u32 a, u32 b, u32 c, u8 *base, void *e);


/*
 * Third entry point of the encoder session getter.
 */
int func_021D90D4(int a, int b, int c, int d, int e)
{
    return func_021D9038(a, b, c, d, e, 2);
}

void func_021D90E8(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (c == func_0203D1A4((struct Link *)func_020399A8()))
            *(u32 *)(base + b * 4 + 0xff0) = a;
        else
            *(u32 *)(base + b * 4 + 0xffc) = a;
    }
}
