/*
 * function: INTRUDE_COMM_PartyProcMain
 * address:  0x02176504
 * packet:   pkt_ov011_02176504
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     loads overlay 93 (id 0x5D) in state 2 and passes two ov093-resident
 *           data addresses; they carry an ov093 token for that reason.
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_SetUserInfo  0x0203A424  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   ov093_id       0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  ov093  a4
 *   d_021EFDAC     0x021EFDAC  data  ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u8 b4;
} Obj;

typedef struct {
    u8 pad0[0xC];
    int w0C;
    u8 pad10[0x8];
    u16 h18;
    u8 pad1A[0x7];
    u8 b21;
    u8 pad22[0x76 - 0x22];
    u16 h76;
    u8 pad78[0x84 - 0x78];
    u16 h84;
    u8 pad86[0xF4 - 0x86];
    u32 wF4;
    u32 wF8;
    int wFC;
} Work;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern u32 PROCSYS_Main(void *a);
extern u32 func_0200FB24(void);
extern int GFL_NET_IsSessionNull(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void BTL_SETUP_SetupCommSingle(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void BTL_SETUP_SetParty(void *p, void *src, int i);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);
extern int func_02034AC4(int id);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void PROCSYS_Push(u32 a, int b, void *c, Work *w);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void func_02034A5C(int handle);
extern void BTL_SETUP_FreeSlots(Work *w);
extern char d_021F03C4[];
extern u8 ov093_id[];
extern char d_021EFDAC[];

int INTRUDE_COMM_PartyProcMain(void *a0, int *state, Obj *obj, Work *work)
{
    int h;
    int busy;

    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)obj->w0);
    GAMESYSTEM_GetGameComm((const struct Ctx *)obj->w0);
    busy = PROCSYS_Main((void *)work->wF4);
    if (func_0200FB24() != 0 || GFL_NET_IsSessionNull() == 1) {
        if (*state > 0 && *state < 6) {
            *state = 7;
        }
    }
    switch (*state) {
    case 0:
        BTL_SETUP_SetupCommSingle((u32)work, h, (int)GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        BTL_SETUP_SetParty(work, (void *)work->wF8, 0);
        if (GFL_NET_SYSTEM_GetCurrentAid() < obj->b4) {
            work->b21 = 0;
        } else {
            work->b21 = 1;
        }
        work->w0C = 15;
        work->h18 = 0x490;
        work->h84 = (1 << obj->b4) | (1 << GFL_NET_SYSTEM_GetCurrentAid());
        work->h76 = 30;
        (*state)++;
        break;
    case 1:
        GFL_NET_HANDLE_SetUserInfo((char *)((int)GFL_NET_HANDLE_GetCurrentHandle()), 0x15, 2, (u16)((1 << obj->b4) | (1 << GFL_NET_SYSTEM_GetCurrentAid())));
        (*state)++;
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x15, 2) == 1) {
            func_02034AC4((int)ov093_id);
            work->wFC = 1;
            GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
            (*state)++;
        }
        break;
    case 3:
        GFL_NET_HANDLE_SetUserInfo((char *)((int)GFL_NET_HANDLE_GetCurrentHandle()), 0x16, 2, (u16)((1 << obj->b4) | (1 << GFL_NET_SYSTEM_GetCurrentAid())));
        (*state)++;
        break;
    case 4:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 2) == 1) {
            (*state)++;
        }
        break;
    case 5:
        PROCSYS_Push(work->wF4, -1, d_021EFDAC, work);
        (*state)++;
        break;
    case 6:
        if (busy == 0) {
            (*state)++;
        }
        break;
    case 7:
        if (work->wFC == 1) {
            if (GFL_NET_GetRunState() == 1) {
                GFL_NET_COMMAND_DeleteCommandTable(0x100);
            }
            func_02034A5C((int)ov093_id);
        }
        BTL_SETUP_FreeSlots(work);
        return 1;
    }
    return 0;
}
