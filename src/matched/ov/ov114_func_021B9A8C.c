/*
 * function: NHTTP_RAP_EvilCheckFreeArray
 * address: 0x021B9A8C
 * packet: pkt_ov114_021B9A8C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: unlabelled 8-byte tail-call stub (ldr r3,[pc,#0]; bx r3; .word
 * 0x020307B0), the leaf blocking ov175 021D67BC and 021D9B2C.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void NHTTP_RAP_EvilCheckFreeArray(void *buf)
{
    func_020307B0(buf);
}
