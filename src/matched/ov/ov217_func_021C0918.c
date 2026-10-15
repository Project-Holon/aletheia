/*
 * function: RESEARCH_GRAPH_OpenComm
 * address:  0x021C0918
 * packet:   pkt_ov217_021C0918
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_SetNotifyFlag  0x02026498  thumb
 *   RESEARCH_GRAPH_GetContext  0x021BF734  thumb  ov217
 *
 * Opens the +0x10 record (GAMESYSTEM_GetGameComm on the result of RESEARCH_GRAPH_GetContext),
 * tags it with 1, and releases it when GAME_COMM_GetKind reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
struct Comm;
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_COMM_SetNotifyFlag(void *obj, u32 flag);
extern u32 RESEARCH_GRAPH_GetContext(u8 *);
void RESEARCH_GRAPH_OpenComm(u8 *a0)
{
    u32 v1 = GAMESYSTEM_GetGameComm((const struct Ctx *)RESEARCH_GRAPH_GetContext(a0));
    GAME_COMM_SetNotifyFlag((void *)v1, 1);
    if (GAME_COMM_GetKind((void *)v1) == 2) {
    GAME_COMM_RequestExitNoCallback((struct Comm *)v1);
    }
}
