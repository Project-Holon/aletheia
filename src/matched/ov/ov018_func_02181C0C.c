/*
 * function: EVENT_COMM_COMMON_SearchFoundEventMain
 * address:  0x02181C0C
 * packet:   pkt_ov018_02181C0C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_CMD_SendProposal  0x0217405C  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   INTRUDE_COMM_SendSupportMode  0x0217456C  thumb  ov011
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   EVENT_COMM_COMMON_CreateMissionResultEvent  0x021804F8  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_02183950     0x02183950  data  a2
 *   d_0218395A     0x0218395A  data  a2
 *   d_02183964     0x02183964  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 0x02];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43;
    u8 f44[0x5C - 0x44]; /* 0x44 */
    u8 f5C[0x98 - 0x5C]; /* 0x5C */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    int fA0;            /* 0xA0 */
} Ov018Outer;

extern const u16 d_02183950[];
extern const u16 d_0218395A[];
extern const u16 d_02183964[];

struct Obj;
struct S0201235C;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_CMD_SendProposal(char *a, char *b);
int INTRUDE_COMM_GetJoinStatus(char *p, u8 *q);
int INTRUDE_COMM_SendSupportMode(int a, int b, int c, ...);
void INTRUDE_COMM_SetWordSetRequest(void *, void *, void *, u32);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, u16 a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void GFL_USE_PlaySeDefaultVolume(u32 a);
void EVENT_COMM_COMMON_ExitCommonWork(void *v, Ov018Outer *c);
void *EVENT_COMM_COMMON_CreateMissionResultEvent(void *, int);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_SearchFoundEventMain(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    u8 *v;
    int r;

    sub = GAME_EVENT_GetGameSystem(a);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(sub)));
    if (v == 0 && *state <= 2 && *state < 6) {
        EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
        *state = 6;
        c->f98 = 1;
        return 0;
    }
    switch (*state) {
    case 0:
        if (INTRUDE_CMD_SendProposal((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        r = c->fA0 = INTRUDE_COMM_GetJoinStatus((char *)v, v + 0x1AC);
        switch (r) {
        case 1:
            *state = 2;
            break;
        case 2:
            *state = 5;
            break;
        }
        break;
    case 2:
        if (INTRUDE_COMM_SendSupportMode((int)v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 3:
        c->f9C = 1;
        INTRUDE_COMM_SetWordSetRequest(c->f44, c->f5C, c->obj.f00, c->f00);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183950[c->f42]);
        (*state)++;
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, d_0218395A[c->f42]);
            GFL_USE_PlaySeDefaultVolume(0x5E0);
            *state = 6;
        }
        break;
    case 5:
        c->f9C = 1;
        INTRUDE_COMM_SetWordSetRequest(c->f44, c->f5C, c->obj.f00, c->f00);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183964[c->f42]);
        *state = 6;
        break;
    case 6:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 7;
        }
        break;
    case 7:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 8;
        }
        break;
    case 8:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        if (c->fA0 == 1) {
            GAME_EVENT_ChangeEvent(a, EVENT_COMM_COMMON_CreateMissionResultEvent(sub, c->f9C));
            return 0;
        }
        return 1;
    }
    return 0;
}
