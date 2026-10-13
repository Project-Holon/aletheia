/*
 * function: UNION_ONESELF_IdleStart
 * address: 0x0217BB3C
 * packet: pkt_ov019_0217BB3C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_COMM_InitConnectInfo 0x02173524 thumb ov012
 *   UNION_COMM_SetSituationParam 0x021734A8 thumb ov012
 *   UNION_MSG_CloseAllWindows 0x0217F074 thumb ov019
 *   UNION_ONESELF_SetFieldBusy 0x0217BAF0 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { struct { void *f0; } *head; } Work;
extern void UNION_COMM_InitConnectInfo(Work *w, u8 *p);
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
extern void UNION_MSG_CloseAllWindows(void *ctx);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
int UNION_ONESELF_IdleStart(u8 *ctx, u8 *obj, int a)
{
    UNION_COMM_InitConnectInfo((Work *)ctx, obj + 0x14);
    UNION_COMM_SetSituationParam(ctx, 4, 0);
    UNION_MSG_CloseAllWindows(ctx);
    UNION_ONESELF_SetFieldBusy((char *)ctx, a, 0);
    ctx[0x282E] = 0;
    return 1;
}
