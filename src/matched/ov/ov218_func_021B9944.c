/*
 * function: UN_SELECT_RequestBrightness
 * address: 0x021B9944
 * packet: pkt_ov218_021B9944
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BRIGHTNESS_ChangeReset 0x02023F98 thumb
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void BRIGHTNESS_ChangeReset(u32);
extern void BRIGHTNESS_ChangeRequest(void *,u16,s16,s16,u32);
void UN_SELECT_RequestBrightness(void)
{
    BRIGHTNESS_ChangeReset(1);
    BRIGHTNESS_ChangeRequest((void *)8,0,-8,60,1);
}
