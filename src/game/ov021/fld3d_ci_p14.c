/*
 * file:     fld3d_ci_p14.c
 * unit:     yes
 * function: func_021C3490, func_021C34B4
 * address:  0x021C3490
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
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_021C341C  0x021C341C  thumb  ov021
 */
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0200BC2C(void *e, int i);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern int func_021C341C(u32 *p, u32 b);
int func_021C3490(void **p, int i);
int func_021C34B4(void **a, int b);


/*
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 */
int func_021C3490(void **p, int i)
{
    int lv = func_02017E1C(func_0200BC2C(p[2], i), 0x9E, 0);

    return func_021C341C((u32 *)p, i) - lv;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C34B4(void **a, int b)
{
return ((func_021C3490((void **)a, b) + 1) * 100);
}
