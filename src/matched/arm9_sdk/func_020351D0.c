/*
 * function: func_020351D0
 * address:  0x020351D0
 * packet:   pkt_020351D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020351BC 0x020351BC arm
 *   g_021469BC 0x021469BC data
 */

typedef unsigned int   u32;
struct Obj0203515C;
extern u32 func_020351BC(struct Obj0203515C *p, u32 mask);
extern void g_021469BC(void);

asm void func_020351D0(void)
{
    ldr r2, =g_021469BC
    mov	r1, r0
    ldr	r0, [r2]
    ldr ip, =func_020351BC
    bx	ip
}
