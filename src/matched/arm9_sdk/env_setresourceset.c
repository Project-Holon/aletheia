/*
 * function: ENV_SetResourceSet
 * address:  0x0206434C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062FF0   0x02062FF0  arm
 *   func_0206419C   0x0206419C  arm
 *
 * Original (24 bytes):
 *   push {r4, lr}
 *   mov  r4, r0
 *   bl   #0x02062FF0
 *   mov  r0, r4
 *   bl   #0x0206419C
 *   pop  {r4, pc}
 */

extern void func_02062FF0(void *p);
extern void func_0206419C(void *p);

void ENV_SetResourceSet(void *p)
{
    func_02062FF0(p);
    func_0206419C(p);
}
