/*
 * function: EVENT_GTSNEGO_Main
 * address:  0x021542C0
 * packet:   pkt_ov001_021542C0
 * region:   ov001
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode (17 states), same family as ov003 EVENT_GTSNEGO_Main.
 * Pooled small words 0x73/0x78/0x77/0xC3 are linker overlay ids
 * (ov115/ov120/ov119/ov195) handed to GAMESYSTEM_CallProc with a table in that
 * overlay's window.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov115_id       0x00000073  data   a1
 *   ov120_id       0x00000078  data   a1
 *   ov119_id       0x00000077  data   a1
 *   ov195_id       0x000000C3  data   a1
 *   gNetSaveMainProc     0x021D6338  data   ov115  a4
 *   gNetSaveRetryProc     0x021D654C  data   ov115  a4
 *   d_021D890C     0x021D890C  data   ov120  a4
 *   d_021E759C     0x021E759C  data   ov119  a4
 *   d_02208C40     0x02208C40  data   ov195  a4
 *   d_021546A0     0x021546A0  data   ov001  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct IcaAnime;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
struct Evt;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern int   GFL_NET_GetRunState(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void  GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a0, u32 a1, u32 a2);
extern u32   GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a0, u32 a1, u32 a2);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 a0, u32 a1);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);

extern char ov115_id[];
extern char ov120_id[];
extern char ov119_id[];
extern char ov195_id[];
extern char gNetSaveMainProc[];
extern char gNetSaveRetryProc[];
extern char d_021D890C[];
extern char d_021E759C[];
extern char d_02208C40[];
extern char d_021546A0[];

typedef struct Req {
    u32 f00;
    u32 f04;
    u16 f08;
    u8  f0a;
    u8  f0b;
    u32 f0c;
    u32 f10;
} Req;

#define F(o) (*(u32 *)(args + (o)))

u32 EVENT_GTSNEGO_Main(void *obj, u32 *mode, char *args)
{
    u32 h = F(0x17c);
    u32 v08 = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)h);
    void *v0c = GAMESYSTEM_GetFieldMap((void *)h);
    Req *p;

    switch (*mode) {
    case 0:
        F(0x0) = GFL_USE_GetBgmNo();
        GFL_USE_FadeOutBgm(6);
        (*mode)++;
        break;
    case 1:
        if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)h)) == 0) {
            GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(h, (int)v0c));
            (*mode)++;
        }
        break;
    case 2:
        F(0x378) = (u32)(args + 8);
        F(0x374) = 0x33;
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov115_id, gNetSaveMainProc, args + 0x368);
        (*mode)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (F(0x384) == 0)
                (*mode)++;
            else
                *mode = 14;
        }
        break;
    case 4:
        F(0x334) = 0;
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov120_id, d_021D890C, args + 0x184);
        (*mode)++;
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (F(0x334) == 1) {
                *mode = 12;
            } else if (F(0x334) == 0) {
                F(0x37c) = 1;
                *mode = 2;
            } else {
                F(0x340) = 0;
                (*mode)++;
            }
        }
        break;
    case 6:
        F(0x34c) = v08;
        F(0x350) = (u32)(args + 0x184);
        F(0x35c) = (u32)(args + 8);
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov119_id, d_021E759C, args + 0x338);
        (*mode)++;
        break;
    case 7:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            if (GFL_NET_GetRunState() == 0) {
                F(0x37c) = 1;
                *mode = 2;
            } else if (F(0x340) == 2) {
                *mode = 4;
            } else if (F(0x340) == 1) {
                *mode = 10;
            } else {
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0xc);
                GFL_NET_SetAutoExit(0);
                GFL_NET_SetLoginOption(0);
                F(0x4) = 100;
                *mode = 8;
            }
        }
        break;
    case 8:
        F(0x4)--;
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0xc))
            *mode = 9;
        if ((int)F(0x4) < 0)
            *mode = 9;
        break;
    case 9:
        GFL_NET_STATE_WifiDisconnect(1);
        *mode = 4;
        break;
    case 10:
        p = func_02030734(4, 0x14, 0, d_021546A0, 0xcc);
        p->f00 = F(0x34c);
        p->f04 = F(0x3ac);
        p->f08 = F(0x344);
        p->f0a = 0;
        p->f0b = F(0x348);
        p->f0c = 1;
        p->f10 = 0;
        F(0x358) = (u32)p;
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov195_id, d_02208C40, p);
        (*mode)++;
        break;
    case 11:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0) {
            func_020307B0((void *)F(0x358));
            if (GFL_NET_GetRunState() == 0) {
                F(0x37c) = 1;
                *mode = 2;
            } else {
                F(0x340) = 1;
                *mode = 6;
            }
        }
        break;
    case 12:
        GAMESYSTEM_CallProc((struct IcaAnime *)h, (u32)ov115_id, gNetSaveRetryProc, args + 0x390);
        (*mode)++;
        break;
    case 13:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)h) == 0)
            (*mode)++;
        break;
    case 14:
        func_020307B0((void *)F(0x198));
        func_020307B0((void *)F(0x19c));
        func_020307B0((void *)F(0x3ac));
        GFL_USE_CancelChangeAndPlayBgm(F(0x0), 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)h));
        (*mode)++;
        break;
    case 15:
        (*mode)++;
        break;
    case 16:
        return 1;
    }
    return 0;
}
