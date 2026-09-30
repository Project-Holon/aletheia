/*
 * function: func_021F61D8
 * address: 0x021F61D8
 * packet: pkt_ov112_021F61D8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int u32;
extern void func_020307B0(void *);
void func_021F61D8(char *a, char *p)
{
    func_020307B0(*(void **)(p));
    func_020307B0(*(void **)(p+16));
    func_020307B0(*(void **)(p+8));
    func_020307B0(*(void **)(p+24));
    func_020307B0(*(void **)(p+140));
    func_020307B0(*(void **)(p+32));
    (*(u32 **)(a+4))[*(u32 *)(p+240)] = 0;
    func_020307B0(p);
}
