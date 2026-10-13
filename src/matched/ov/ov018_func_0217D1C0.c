/*
 * function: INTRUDE_SUBDISP_Update
 * address:  0x0217D1C0
 * packet:   pkt_ov018_0217D1C0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm            0x02012138  thumb
 *   GAMESYSTEM_GetGameData            0x020120F4  thumb
 *   GAMESYSTEM_GetMyPlayerWork            0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId            0x02012AC8  thumb
 *   GAME_DATA_GetWifiList            0x0201283C  thumb
 *   WIH_DWC_PollStatus            0x0201058C  thumb
 *   GFL_NET_WM_ICON_EasyObjWindowOn            0x02037174  arm
 *   INTRUDE_COMM_GetWorkIfRunning            0x02158344  thumb  ov010
 *   INTRUDE_SUBDISP_UpdateTownState            0x0217F008  thumb  ov018
 *   GAME_DATA_GetIntrudeCount            0x02012B70  thumb
 *   func_020061E4            0x020061E4  thumb
 *   TCBL_Main            0x020310C4  arm
 *   PRINTSYS_QUE_Main            0x0201C4E4  thumb
 *   func_02045770            0x02045770  arm
 *   func_0201C6C4            0x0201C6C4  thumb
 *   BMP_WIN_TransferChars            0x02045334  arm
 *   BMP_OAM_UploadChars            0x020257D0  thumb
 *   INTRUDE_SUBDISP_IsTownBlinking            0x0217F0FC  thumb  ov018
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   INTRUDE_SUBDISP_UpdateTouch            0x0217EC7C  thumb  ov018
 *   GAME_DATA_GetIntrudeIdByte            0x0215841C  thumb  ov010
 *   GFL_NET_IsConnectMember            0x0203D1C0  arm
 *   INTRUDE_COMM_SendUnionInfoRequest            0x021746AC  thumb  ov011
 *   INTRUDE_COMM_GetUnionInfoReceived            0x02158428  thumb  ov010
 *   GAMESYSTEM_GetFieldMap            0x0201210C  thumb
 *   FIELDMAP_GetSubscreen            0x02188CCC  thumb  ov021
 *   func_02034714            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 */
#include "../include/Obj00399.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8;

extern char str_02183B28[];

struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *);
struct BigObj;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Tcbl;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *);
u32 GAME_DATA_GetWifiList(const struct BigObj *p);
u32 WIH_DWC_PollStatus(void *key);
void GFL_NET_WM_ICON_EasyObjWindowOn(void);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void INTRUDE_SUBDISP_UpdateTownState(char *p, char *q);
int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
void func_020061E4(u32 a);
void TCBL_Main(struct Tcbl *p);
u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
void *func_02045770(struct Descriptor *p);
u32 func_0201C6C4(struct PrintSys *p, void *v);
void BMP_WIN_TransferChars(struct Descriptor *d);
void BMP_OAM_UploadChars(struct Obj *o);
int INTRUDE_SUBDISP_IsTownBlinking(u8 *w);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
void INTRUDE_SUBDISP_UpdateTouch(u8 *p, u8 *w, int q);
u8 GAME_DATA_GetIntrudeIdByte(void *p);
u32 GFL_NET_IsConnectMember(u32 index);
int INTRUDE_COMM_SendUnionInfoRequest(char *a, int b);
u8 INTRUDE_COMM_GetUnionInfoReceived(u8 *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
u32 FIELDMAP_GetSubscreen(u8 *p);
void func_02034714(const char *expr, u32 line, const char *file);

#define REG_DB_BLDCNT_SUB (*(volatile u16 *)0x04001050)

void INTRUDE_SUBDISP_Update(u8 *w, int b)
{
    void *s1;
    void *s2;
    u8 *p;
    int q;
    int i;
    int v;
    void *h;

    s1 = (void *)GAMESYSTEM_GetGameComm(((struct Obj00399 *)w)->f0);
    s2 = GAMESYSTEM_GetGameData(((struct Obj00399 *)w)->f0);
    p = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)s1);
    q = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(((struct Obj00399 *)w)->f0));
    WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(s2));
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (p == 0 || (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 0)) {
        INTRUDE_SUBDISP_UpdateTownState((char *)w, (char *)p);
    }
    if (w[0x11E] < w[0xDA]) {
        if (GAME_DATA_GetIntrudeCount(s2) == 1) {
            func_020061E4(0x699);
        }
        w[0x11E] = w[0xDA];
    }
    TCBL_Main(((struct Obj00399 *)w)->f20);
    PRINTSYS_QUE_Main(((struct Obj00399 *)w)->f28);
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x48] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f44)) == 0) {
            BMP_WIN_TransferChars(((struct Obj00399 *)w)->f44);
            w[0x48] = 0;
        }
    }
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x50] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f4C)) == 0) {
            BMP_WIN_TransferChars(((struct Obj00399 *)w)->f4C);
            w[0x50] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (func_0201C6C4(((struct Obj00399 *)w)->f28, *(void **)(w + 0xB4 + i * 4)) == 0) {
            BMP_OAM_UploadChars(*(void **)(w + 0xC0 + i * 4));
        }
    }
    if (b == 0) {
        if (INTRUDE_SUBDISP_IsTownBlinking(w) == 1 || w[0x116] == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
            return;
        }
    } else {
        REG_DB_BLDCNT_SUB = 0;
    }
    if (b == 1) {
        INTRUDE_SUBDISP_UpdateTouch(p, w, q);
    }
    if (p != 0 && w[0x106] == 1) {
        v = GAME_DATA_GetIntrudeIdByte(s2);
        if ((int)GFL_NET_IsConnectMember((u8)v) == 0) {
            w[0x106] = 0;
            return;
        }
        switch (w[0x107]) {
        case 0:
            if (INTRUDE_COMM_SendUnionInfoRequest((char *)p, (u8)v) == 1) {
                w[0x107]++;
            }
            break;
        case 1:
            if (INTRUDE_COMM_GetUnionInfoReceived(p) == 1) {
                FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap(((struct Obj00399 *)w)->f0));
                ((struct Obj00399 *)w)->f110 = 0x126;
                w[0x112] = 1;
                w[0x106] = 0;
            }
            break;
        default:
            func_02034714(str_02183B28, 0, str_02183B28);
            break;
        }
    }
}
