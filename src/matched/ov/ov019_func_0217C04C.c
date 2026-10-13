/*
 * function: UNION_ONESELF_ConnectChildStart
 * address: 0x0217C04C
 * packet: pkt_ov019_0217C04C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   UNION_MSG_SetupPrintTalkMsg 0x0217F210 thumb ov019
 *   UNION_ONESELF_SetFieldBusy 0x0217BAF0 thumb ov019
 */
typedef unsigned int u32;
extern void func_020061E4(u32 id);
typedef unsigned char  u8;
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
int UNION_ONESELF_ConnectChildStart(void *ctx, void *unused, u8 *a)
{
    func_020061E4(0x806);
    UNION_MSG_SetupPrintTalkMsg(ctx, a, 7);
    UNION_ONESELF_SetFieldBusy(ctx, (int)a, 1);
    return 1;
}
