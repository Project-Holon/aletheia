/*
 * function: MB_InitSendGameInfoStatus
 * address:  0x021F3F78
 * packet:   pkt_ov107_021F3F78
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o).  decl_line 407.  Line map
 * 409/410/411/412/413 at +0x0/+0xc/+0x10/+0x1c/+0x18.
 *
 * symbols:
 *   d_021F6EF4   0x021F6EF4  data
 */
typedef unsigned long u32;
typedef unsigned char u8;

extern char d_021F6EF4[];
extern void MBi_ClearSendStatus(void);

void MB_InitSendGameInfoStatus(void)
{
    *(u32 *)(d_021F6EF4 + 0x18) = 0;
    *(u32 *)(d_021F6EF4 + 0x1C) = 0;
    *(u8 *)(d_021F6EF4 + 0x24) = 1;
    *(u32 *)(d_021F6EF4 + 0x14) = 0;
    MBi_ClearSendStatus();
}
