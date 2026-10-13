/*
 * function: BTL_SIDE_Clear
 * address: 0x021B9424
 * packet: pkt_ov093_021B9424
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_Delete 0x021D53B8 thumb ov093
 *   BTL_SLOT_Clear 0x021B9B40 thumb ov093
 */
extern void BTL_POKEPARAM_Delete(void *);
typedef unsigned char  u8;
extern void BTL_SLOT_Clear(u8 *p);
void BTL_SIDE_Clear(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            BTL_POKEPARAM_Delete(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
    for (i = 0; i < 4; i++) BTL_SLOT_Clear((u8 *)(p + 4 + i * 28));
}
