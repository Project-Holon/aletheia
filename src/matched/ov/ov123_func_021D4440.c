/*
 * function: GSYNC_MENU_StateStartFadeOut
 * address: 0x021D4440
 * packet: pkt_ov123_021D4440
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StateWaitFadeOut 0x021D4AB4 thumb ov123
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern int GFL_NET_GetRunState(void);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Comm;
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
extern void GSYNC_MENU_StateWaitFadeOut(char *p);
typedef struct {
    char pad00[8];
    int f08;
    u16 f0c;
    char pad0e[0x256];
    void *f264;
    char pad268[0x24];
    int f28c;
} Object;
void GSYNC_MENU_StateStartFadeOut(Object *p)
{
    p->f28c = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, p->f0c);
    switch (p->f08) {
    case 2:
    case 3:
        if (GFL_NET_GetRunState())
            GAME_COMM_RequestExitNoCallback((struct Comm *)GAMESYSTEM_GetGameComm(p->f264));
        break;
    }
    GSYNC_MENU_ChangeState((char *)p, GSYNC_MENU_StateWaitFadeOut, 0x1aa);
}
