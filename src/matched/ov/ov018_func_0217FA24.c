/*
 * function: EVENT_COMM_COMMON_CreateReturnPalaceEvent
 * address: 0x0217FA24
 * packet: pkt_ov018_0217FA24
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   EVENT_COMM_COMMON_ReturnPalaceEventMain 0x0217FA38 thumb ov018
 */
typedef unsigned int u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int EVENT_COMM_COMMON_ReturnPalaceEventMain(void *a, int *state);
void *EVENT_COMM_COMMON_CreateReturnPalaceEvent(void *owner)
{
    return func_020122C0(owner, 0, EVENT_COMM_COMMON_ReturnPalaceEventMain, 0);
}
