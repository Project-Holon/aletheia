/*
 * file:     fldmmdl_blact_p17.c
 * unit:     yes
 * function: func_0219DC7C, func_0219DC88
 * address:  0x0219DC7C
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
 *   func_0219DC34  0x0219DC34  thumb
 *   func_0219E370  0x0219E370  thumb  ov021
 *   func_0219E6C8  0x0219E6C8  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed short   s16;

extern int func_0219DC34(u32 a, u32 b);
extern void func_0219E370(u32 a, u32 b, u32 c);
extern void func_0219E6C8(u32, u16);
extern int func_0216D60C(int a0, int a1);
extern void func_0216D674(u32, u32);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D7CC(u8 *p);
u32 func_0219DC7C(u32 a1);
void func_0219DC88(u32 a, u32 b, u32 c, u32 d);


/*
 * Calls func_0219DC34(its own argument 1, 0x3) and returns 0x1.
 */
u32 func_0219DC7C(u32 a1)
{
    func_0219DC34(a1, 0x3);

    return 0x1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219DC88(u32 a, u32 b, u32 c, u32 d)
{
    func_0219E370(a, (u16)b, c);
    func_0219E6C8(a, b);
    func_0216D60C((u32)a, (u16)b);
    func_0216D674(a, d);
    func_0216D568((void *)a, 0x20);
    func_0216D7CC((u8 *)a);
}
