/*
 * function: BTL_MAIN_SetRecordInvalid
 * address: 0x021B9184
 * packet: pkt_ov093_021B9184
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef struct { u8 pad[0xC1]; unsigned char flag:1; unsigned char rest:7; } Flags;
void BTL_MAIN_SetRecordInvalid(Flags **p)
{
    (*p)->flag = 1;
}
