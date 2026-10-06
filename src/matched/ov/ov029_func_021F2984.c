/*
 * function: func_021F2984
 * address: 0x021F2984
 * packet: pkt_ov029_021F2984
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F26E0 0x021F26E0 thumb ov029
 *   func_020307B0 0x020307B0 arm
 */
extern void func_021F26E0(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021F2984(char *p)
{
    func_021F26E0(p);
    func_020307B0((void *)((int)p));
}
