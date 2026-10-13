/*
 * function: UNION_ONESELF_ConnectParentStart
 * address: 0x0217BE44
 * packet: pkt_ov019_0217BE44
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   UNION_MSG_SetupPrintTalkMsg 0x0217F210 thumb ov019
 */
typedef unsigned int u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
typedef unsigned char  u8;
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
int UNION_ONESELF_ConnectParentStart(void *ctx, void *unused, u8 *a)
{
    GFL_USE_PlaySeDefaultVolume(0x547);
    UNION_MSG_SetupPrintTalkMsg(ctx, a, 0xE2);
    return 1;
}
