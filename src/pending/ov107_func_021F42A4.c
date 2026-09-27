/*
 * function: MBi_InitSendVolatBeacon
 * address:  0x021F42A4
 * packet:   pkt_ov107_021F42A4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o).  decl_line 569.
 *
 * symbols:
 *   d_021F6EF4   0x021F6EF4  data
 */
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021F6EF4[];

void MBi_InitSendVolatBeacon(void)
{
    *(u16 *)(*(char **)(d_021F6EF4 + 0x1C) + 0x4B0) = 1;
    *(u8 *)(d_021F6EF4 + 0x26) = *(u8 *)(*(char **)(d_021F6EF4 + 0x1C) + 0x4B4);
    *(u8 *)(d_021F6EF4 + 0x24) = 5;
}
