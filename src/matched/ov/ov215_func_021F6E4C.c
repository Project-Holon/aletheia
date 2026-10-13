/*
 * function: func_021F6E4C
 * address:  0x021F6E4C
 * packet:   pkt_021F6E4C
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void PARTICLE_ExitManager(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021F6E4C(char *a)
{
    PARTICLE_ExitManager();
    func_020307B0(a);
}