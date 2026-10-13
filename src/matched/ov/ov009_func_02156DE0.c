/*
 * function: DWC_RAP_SetErrorHookCallback
 * address: 0x02156DE0
 * packet: pkt_ov009_02156DE0
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker of owned ov123 021D920C; parent ownership audit passed.
 * extent: next labelled function 02156DFC follows the 28-byte leaf.
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 */
extern int *g_021A8264;
void DWC_RAP_SetErrorHookCallback(int a, int b)
{
    *(int *)((char *)g_021A8264+0x294)=a;
    *(int *)((char *)g_021A8264+0x298)=b;
}
