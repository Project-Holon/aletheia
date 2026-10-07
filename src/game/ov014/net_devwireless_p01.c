/*
 * file:     net_devwireless_p01.c
 * unit:     yes
 * function: func_02177020, func_02177028, func_02177080
 * address:  0x02177020
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021796A0  0x021796A0  data  a4
 *   g_021797A0     0x021797A0  data   a4
 *   d_0217976C     0x0217976C  data   a1
 *   func_02030734  0x02030734  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02177280  0x02177280  thumb  ov014
 *   func_02177AA8 0x02177AA8 thumb ov014
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_0203D798(void);
extern int func_02177280(int a, int b, u32 c, int d);
extern int func_02177AA8(void);
void *func_02177020(void);
int func_02177028(int a, u32 b, int c, int d);
int func_02177080(void (*cb)(void));
extern u32 *g_021797A0;
extern char d_0217976C[];

void *func_02177020(void)
{
    return (void *)0x021796A0;
}


int func_02177028(int a, u32 b, int c, int d)
{
    int ok;
    u32 *p;

    if (g_021797A0 != 0)
        return 0;
    p = func_02030734(a, 8, 1, d_0217976C, 0xb4);
    ok = 1;
    g_021797A0 = p;
    *p = b;
    if (func_0203D798()[0x65] != 5)
        ok = 0;
    return func_02177280(a, c, d, ok);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
int func_02177080(void (*cb)(void))
{
    if (cb != 0) {
        func_02177AA8();
        cb();
    }
    return func_02177AA8();
}
