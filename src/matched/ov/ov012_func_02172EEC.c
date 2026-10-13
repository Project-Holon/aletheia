/*
 * function: UNION_COMM_UpdateConnectSync
 * address:  0x02172EEC
 * packet:   pkt_ov012_02172EEC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   UNION_COMMAND_SendConnectSync  0x021739CC  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0x5E];
    u8 f5E;
    u8 step : 7;
    u8 active : 1;
} Sub;

typedef struct {
    u8 pad[0x2830];
    Sub sub;
} Work;

typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern int UNION_COMMAND_SendConnectSync(void);
extern int func_02080D24(u8 a);
extern int GFL_NET_GetNegotiationNum(void);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 GFL_NET_IsParentAid(void);
extern void UNION_COMM_RequestShutdown(u8 *p);

void UNION_COMM_UpdateConnectSync(Work *w)
{
    Sub *s = &w->sub;

    if (s->active == 0) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    switch (s->step) {
    case 0:
        if (UNION_COMMAND_SendConnectSync() == 1) {
            s->step++;
        }
        break;
    case 1:
        if (func_02080D24(s->f5E) >= GFL_NET_GetNegotiationNum()) {
            GFL_NET_SetLoginOption(0);
            s->step++;
        }
        break;
    case 2:
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1) {
                UNION_COMM_RequestShutdown((u8 *)w);
                s->step++;
            }
        } else {
            UNION_COMM_RequestShutdown((u8 *)w);
            s->step++;
        }
        break;
    }
}
