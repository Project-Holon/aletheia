/*
 * function: BTL_MAIN_GetTrainerHandle
 * address: 0x021BA064
 * packet: pkt_ov093_021BA064
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 */
typedef unsigned char  u8;
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
typedef unsigned int u32;
int BTL_MAIN_GetTrainerHandle(char *p, int i)
{
    if (BTL_MAIN_IsTrainerSlotNpc((u8 *)p, i)) return 0;
    return *(int *)((u32)p + (u32)i * 0x28 + 0x20);
}
