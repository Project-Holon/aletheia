/*
 * function: BTLV_CORE_AbortMoveMenu
 * address: 0x021E98AC
 * packet: pkt_ov093_021E98AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller does not read result.
 * symbols:
 *   BTLV_CORE_AbortInput 0x021E9928 thumb ov093
 */
typedef unsigned int u32;
extern void BTLV_CORE_AbortInput(char *p);
void BTLV_CORE_AbortMoveMenu(void *p)
{
    BTLV_CORE_AbortInput(p);
}
