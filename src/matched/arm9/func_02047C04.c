/*
 * function: func_02047C04
 * address:  0x02047C04
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *
 * Four registrations through func_0206DDA4 (same three-argument shape as
 * src/matched/func_0206A884.c: command, buffer, count), then func_0206DB80
 * and a spin on func_0207DEA4 over the first slot until it reports zero.
 * The value returned is that slot, still holding the 1 it was seeded with.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef signed int     s32;
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DB80(void);
extern int func_0207DEA4(s32 *in);

int func_02047C04(void *obj)
{
    int done;
    int arg;
    int zero;

    done = 1;
    arg  = 0x30C1;
    func_0206DDA4(0x29, &arg, 1);
    zero = 0;
    func_0206DDA4(0x40, &zero, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, obj, 3);
    func_0206DB80();
    while (func_0207DEA4(&done) != 0) {
        ;
    }
    return done;
}
