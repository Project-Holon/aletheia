/*
 * function: MYSTERY_UTIL_SetListValue
 * address: 0x021DA84C
 * packet: pkt_ov121_021DA84C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole overlay blocker of MYSTERY_TaskMenu.
 */
typedef unsigned char u8;
typedef unsigned int u32;
void MYSTERY_UTIL_SetListValue(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}
