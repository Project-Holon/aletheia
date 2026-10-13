/*
 * function: func_021D4440
 * address: 0x021D4440
 * packet: pkt_ov123_021D4440
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4AB4 0x021D4AB4 thumb ov123
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
extern void func_021D4244(char *, void *, int);
extern void func_021D4AB4(char *p);
typedef struct {
    char pad00[8];
    int f08;
    u16 f0c;
    char pad0e[0x256];
    void *f264;
    char pad268[0x24];
    int f28c;
} Object;
void func_021D4440(Object *p)
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
    func_021D4244((char *)p, func_021D4AB4, 0x1aa);
}
