/*
 * function: C_GEAR_Destroy
 * address: 0x021F2984
 * packet: pkt_ov029_021F2984
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_Cleanup 0x021F26E0 thumb ov029
 *   func_020307B0 0x020307B0 arm
 */
extern void C_GEAR_Cleanup(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void C_GEAR_Destroy(char *p)
{
    C_GEAR_Cleanup(p);
    func_020307B0((void *)((int)p));
}
