/*
 * function: func_021B68E0
 * address: 0x021B68E0
 * packet: pkt_ov101_021B68E0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012950 0x02012950 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02012950(void *, u32);
extern int func_02008468(void);
extern void func_02082D44(void *, const void *, u32);
extern u32 func_020399A8(void);
extern u16 func_02039338(void);
void func_021B68E0(u32 a, int b, int c, int *d, u32 e)
{
    void *p;
    if (*(int *)d[0] != 0) {
        p = func_02012950((void *)*(int *)d[0], a);
        func_02082D44((void *)(c + 12), p, func_02008468());
    }
    if (e == func_020399A8()) {
        if (a != func_02039338())
            d[9] = 1;
    }
}
