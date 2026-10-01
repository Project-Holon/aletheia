/*
 * function: func_021E9920
 * address: 0x021E9920
 * packet: pkt_ov093_021E9920
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller does not read result.
 * symbols:
 *   func_021E9928 0x021E9928 thumb ov093
 */
typedef unsigned int u32;
extern void func_021E9928(void *);
void func_021E9920(void *p)
{
    func_021E9928(p);
}
