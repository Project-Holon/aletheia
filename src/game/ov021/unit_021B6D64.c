/*
 * file:     unit_021B6D64.c
 * unit:     yes
 * function: func_021B6D64, func_021B6D98
 * address:  0x021B6D64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_02158F74  0x02158F74  thumb ov010
 *   d_021D9984     0x021D9984  data  a4
 *   d_021D9978     0x021D9978  data  a4
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int (*fn_021B6D64)(void *, void *, void *);
    u8 pad[0x14];
} IntFnEntry;

typedef struct {
    void (*fn_021B6D98)(void *, void *, void *);
    u8 pad[0x14];
} VoidFnEntry;

extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *);
int func_021B6D64(int idx, void *x, void *c);
int func_021B6D98(int idx, void *x, void *y, void *z);
extern IntFnEntry d_021D9984[];
extern VoidFnEntry d_021D9978[];


int func_021B6D64(int idx, void *x, void *c)
{
    void *r;
    int (*fn_021B6D64)(void *, void *, void *);

    r = func_02158F74(func_0215A5F4(c));
    fn_021B6D64 = d_021D9984[idx].fn_021B6D64;
    if (x != 0 && fn_021B6D64 != 0) {
        return fn_021B6D64(r, x, c);
    }
    return 8;
}


int func_021B6D98(int idx, void *x, void *y, void *z)
{
    void (*fn_021B6D98)(void *, void *, void *) = d_021D9978[idx].fn_021B6D98;

    if (z != 0 && fn_021B6D98 != 0) {
        fn_021B6D98(x, y, z);
        return 1;
    }
    return 0;
}
