/*
 * function: EVENT_WORLDTRADE_Create
 * address:  0x021542CC
 * packet:   pkt_ov004_021542CC
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   WORLDTRADE_GetFromSave  0x0200AD6C  thumb
 *   func_02008B08  0x02008B08  thumb
 *   POKEPARTY_GetSaveData  0x0201AD0C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   WIFILIST_GetGsProfileId  0x02009CC0  thumb
 *   EVENT_WORLDTRADE_Main  0x02154390  thumb  ov004
 */

typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Blk37;
struct Comm;
struct Ctx;
struct Desc;
struct Obj;
struct Sub0200852CObj;
struct Sub02008700Obj;
struct Sub02008AECObj;
struct Sub02008C20Obj;
struct Sub02009470Obj;
void *ICA_ANIME_GetField1C(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Ctx;
unsigned int ICA_ANIME_GetField24(const struct Ctx *p);
u32 GAME_COMM_GetKind(void *obj);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);
void *func_020124E8(struct Obj *p);
void MI_CpuFill8(void *p, int v, int n);
void *GAME_DATA_GetSaveControl(struct Big *p);
void *WORLDTRADE_GetFromSave(void *sys);
struct Sub02008AECObj *func_02008B08(void *sys);
void *POKEPARTY_GetSaveData(void *sys);
u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
void *ZUKAN_SAVE_GetFromGameData(void *a);
u32 GAME_DATA_GetField1A0(const struct BigObj *p);
struct Sub02009470Obj *func_02009470(void *sys);
struct Sub0200852CObj *func_02008730(void *sys);
struct Sub02008700Obj *func_0200873C(void *sys);
struct Sub02008C20Obj *func_02008C58(void *sys);
void *GAME_DATA_GetMyItem(const struct BigObj *p);
u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
int WIFILIST_GetGsProfileId(void *a0);
u32 EVENT_WORLDTRADE_Main(void *obj, u32 *mode, u32 *args);

int EVENT_WORLDTRADE_Create(int a, int b, int c)
{
    int r6;
    int h;
    int *p;

    r6 = (int)ICA_ANIME_GetField1C((const struct Ctx *)a);
    h = (int)func_020122C0((void *)a, 0, EVENT_WORLDTRADE_Main, 0x54);
    if (GAME_COMM_GetKind((void *)ICA_ANIME_GetField24((const struct Ctx *)a)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)ICA_ANIME_GetField24((const struct Ctx *)a));
    p = func_020124E8((struct Obj *)h);
    MI_CpuFill8(p, 0, 0x54);
    p[1] = a;
    p[2] = b;
    p[18] = (int)GAME_DATA_GetSaveControl((struct Big *)r6);
    p[3] = (int)WORLDTRADE_GetFromSave((void *)p[18]);
    p[4] = (int)func_02008B08((void *)p[18]);
    p[5] = (int)POKEPARTY_GetSaveData((void *)p[18]);
    p[6] = GAME_DATA_GetBoxManager((const struct BigObj *)r6);
    p[7] = (int)ZUKAN_SAVE_GetFromGameData((void *)r6);
    p[8] = GAME_DATA_GetField1A0((const struct BigObj *)r6);
    p[9] = (int)func_02009470((void *)p[18]);
    p[10] = (int)func_02008730((void *)p[18]);
    p[11] = (int)func_0200873C((void *)p[18]);
    p[12] = (int)func_02008C58((void *)p[18]);
    *(void **)&p[13] = GAME_DATA_GetMyItem((const struct BigObj *)r6);
    p[19] = a;
    p[14] = ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)p[7]);
    p[15] = WIFILIST_GetGsProfileId((void *)p[8]);
    p[16] = 0;
    p[17] = 0;
    return h;
}
