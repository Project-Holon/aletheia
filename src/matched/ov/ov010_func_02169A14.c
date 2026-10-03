/*
 * function: func_02169A14
 * address:  0x02169A14
 * packet:   pkt_ov010_02169A14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 */

typedef unsigned int u32;

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DB80(void);
extern int func_0207DEA4(void *p);

u32 func_02169A14(u32 a)
{
    u32 x;
    u32 y;
    u32 z;

    x = 1;
    y = 0x30C1;
    func_0206DDA4(0x29, &y, 1);
    z = 0;
    func_0206DDA4(0x40, &z, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, (void *)a, 3);
    func_0206DB80();
    while (func_0207DEA4(&x) != 0)
        ;
    return x;
}
