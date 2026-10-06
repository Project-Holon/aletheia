/*
 * function: func_02186E94
 * address: 0x02186E94
 * packet: pkt_ov020_02186E94
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02158F58 0x02158F58 thumb ov010
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_020127F0 0x020127F0 thumb
 *   func_021869BC 0x021869BC thumb ov020
 * interface: 020127F0's body loads only r0, forwarding r0 through 0200A864/0200A898.
 */
struct Ctx;
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_020127F0(int a0);
typedef unsigned short u16;
extern void func_021869BC(u16 *p);
int func_02186E94(void *unused, void *p)
{
    func_021869BC((void *)func_020127F0((int)func_020120F4(func_02188C80(*(void **)(func_02158F58((int)func_0215A5F4(p)) + 4)))));
    return 0;
}
