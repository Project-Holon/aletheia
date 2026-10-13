/*
 * function: NHTTPi_InitMutex
 * address:  0x021B9B4C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02086004(void);

void NHTTPi_InitMutex(int *mutex_p)
{
    func_02086004();
}
