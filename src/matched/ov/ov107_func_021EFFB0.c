/*
 * function: MB_COMM_SYS_MainChildFlow
 * address:  0x021EFFB0
 * packet:   pkt_ov107_021EFFB0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MB_COMM_SYS_GetCommStage  0x021F1060  thumb  ov107
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   MB_UTIL_MSG_PrintStream  0x021F1704  thumb  ov107
 *   MB_UTIL_MSG_SetKeyWaitFlag  0x021F1B24  thumb  ov107
 *   MB_COMM_SYS_SetSyncRange  0x021F1028  thumb  ov107
 *   MB_COMM_SYS_HasKind19  0x021F1110  thumb  ov107
 *   MB_COMM_SYS_GetOfferCount  0x021F1118  thumb  ov107
 *   MB_COMM_SYS_GetOfferExtra  0x021F1120  thumb  ov107
 *   MB_COMM_SYS_GetOfferFlagA  0x021F1134  thumb  ov107
 *   MB_COMM_SYS_GetOfferFlagB  0x021F1148  thumb  ov107
 *   MB_COMM_SYS_HasKind20  0x021F115C  thumb  ov107
 *   MB_COMM_SYS_HasKind21  0x021F1164  thumb  ov107
 *   MB_COMM_SYS_GetKind21Value  0x021F116C  thumb  ov107
 *   MB_COMM_SYS_HasMonsReceived  0x021F11BC  thumb  ov107
 *   MB_UTIL_MSG_ClearWindow  0x021F1898  thumb  ov107
 *   MB_UTIL_MSG_SetWindowLayout  0x021F1628  thumb  ov107
 *   MB_UTIL_MSG_CreateWordSet  0x021F18D8  thumb  ov107
 *   MB_UTIL_MSG_SetNumberLeft  0x021F1900  thumb  ov107
 *   MB_UTIL_MSG_DeleteWordSet  0x021F18EC  thumb  ov107
 *   MB_UTIL_MSG_IsStreamIdle  0x021F1B14  thumb  ov107
 *   MB_UTIL_MSG_OpenYesNoMenu  0x021F19E4  thumb  ov107
 *   MB_UTIL_MSG_ProcessYesNoMenu  0x021F1A2C  thumb  ov107
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   func_02007774  0x02007774  thumb
 *   MB_UTIL_MSG_ClearYesNoMenu  0x021F1A24  thumb  ov107
 *   MB_COMM_SYS_SendMessage  0x021F11F0  thumb  ov107
 *   MB_UTIL_MSG_PrintQueued  0x021F17E0  thumb  ov107
 *   MB_UTIL_MSG_SetTimeIconPending  0x021F1B38  thumb  ov107
 *   MB_COMM_SYS_RegisterReceivedMons  0x021EFD98  thumb  ov107
 *   MB_COMM_SYS_ClearMonBuffer  0x021F1184  thumb  ov107
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 *   FIELD_G3D_MAP_StoreBeaconTrainerKey  0x0216BF74  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 */

typedef struct {
    int f00;
    void *f04;
} Ov107Save;

typedef struct {
    unsigned short f00;
    unsigned char pad02[6];
    Ov107Save *f08;
    void *f0C;
    unsigned char pad10[0x10];
    int f20;
    unsigned char pad24;
    unsigned char state;
    unsigned char pad26[0xE];
    int f34;
    unsigned char pad38[8];
    int f40;
    int f44;
    int f48;
    unsigned char pad4C[0x1C];
    void *f68;
} Ov107Main;

int MB_COMM_SYS_GetCommStage(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
signed char MSG_SPEED_GetWait(void);
void MB_UTIL_MSG_PrintStream(void *, int, int);
void MB_UTIL_MSG_SetKeyWaitFlag(void *, int);
void MB_COMM_SYS_SetSyncRange(int *p);
int MB_COMM_SYS_HasKind19(void *);
int MB_COMM_SYS_GetOfferCount(void *);
int MB_COMM_SYS_GetOfferExtra(void *);
int MB_COMM_SYS_GetOfferFlagA(void *);
int MB_COMM_SYS_GetOfferFlagB(void *);
int MB_COMM_SYS_HasKind20(void *);
int MB_COMM_SYS_HasKind21(void *);
int MB_COMM_SYS_GetKind21Value(void *);
int MB_COMM_SYS_HasMonsReceived(void *);
void MB_UTIL_MSG_ClearWindow(void *);
void MB_UTIL_MSG_SetWindowLayout(void *, int);
void MB_UTIL_MSG_CreateWordSet(void *);
void MB_UTIL_MSG_SetNumberLeft(void *, int, int, int);
void MB_UTIL_MSG_DeleteWordSet(void *);
int MB_UTIL_MSG_IsStreamIdle(void *);
void MB_UTIL_MSG_OpenYesNoMenu(void *, int);
int MB_UTIL_MSG_ProcessYesNoMenu(void *);
u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
int func_02007774(void *);
void MB_UTIL_MSG_ClearYesNoMenu(u8 *p);
int MB_COMM_SYS_SendMessage(void *p, unsigned char kind, unsigned int val);
void MB_UTIL_MSG_PrintQueued(void *, int);
void MB_UTIL_MSG_SetTimeIconPending(u8 *p, u32 v);
void MB_COMM_SYS_RegisterReceivedMons(Ov107Main *);
void MB_COMM_SYS_ClearMonBuffer(void *);
void *GAME_DATA_GetMyItem(const struct BigObj *p);
u8 *GAME_DATA_GetMyStatus(void *p);
void *GAME_DATA_GetMiscSave(int *p);
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *, int, void *);
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *, int, void *);
u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);

void MB_COMM_SYS_MainChildFlow(Ov107Main *p)
{
    int a;
    int b;
    void *c;
    void *d;
    void *e;

    switch (p->state) {
    case 0:
        if (MB_COMM_SYS_GetCommStage(p->f0C) == 10 || MB_COMM_SYS_GetCommStage(p->f0C) == 12) {
            MB_UTIL_MSG_PrintStream(p->f68, 0x29, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
            MB_COMM_SYS_SetSyncRange(p->f0C);
            p->f20 = 0x1B;
        }
        if (MB_COMM_SYS_GetCommStage(p->f0C) == 11) {
            MB_UTIL_MSG_PrintStream(p->f68, 0x2C, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
            MB_COMM_SYS_SetSyncRange(p->f0C);
            p->f20 = 0x1B;
        }
        if (MB_COMM_SYS_HasKind19(p->f0C) == 1) {
            a = MB_COMM_SYS_GetOfferCount(p->f0C);
            b = MB_COMM_SYS_GetOfferExtra(p->f0C);
            if (a != 0) {
                MB_UTIL_MSG_ClearWindow(p->f68);
                MB_UTIL_MSG_SetWindowLayout(p->f68, 5);
                MB_UTIL_MSG_CreateWordSet(p->f68);
                MB_UTIL_MSG_SetNumberLeft(p->f68, 0, a + b, 3);
                MB_UTIL_MSG_PrintStream(p->f68, 0x16, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
                MB_UTIL_MSG_DeleteWordSet(p->f68);
                p->state = 1;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 1:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->f68, 1);
            p->state = 2;
        }
        break;
    case 2:
        p->f34 = MB_UTIL_MSG_ProcessYesNoMenu(p->f68);
        if (p->f34 == 1) {
            b = MB_COMM_SYS_GetOfferCount(p->f0C);
            a = (unsigned short)func_02007774((void *)GAME_DATA_GetBoxManager(p->f08->f04));
            MB_UTIL_MSG_ClearYesNoMenu(p->f68);
            if ((unsigned int)a < (unsigned int)b) {
                p->f40 = 1;
                p->state = 0xD;
            } else {
                p->f40 = 0;
                p->state = 3;
            }
        } else if (p->f34 == 2) {
            p->state = 0xD;
        }
        break;
    case 3:
        if (MB_COMM_SYS_GetOfferExtra(p->f0C) != 0) {
            a = MB_COMM_SYS_GetOfferCount(p->f0C);
            MB_UTIL_MSG_ClearWindow(p->f68);
            MB_UTIL_MSG_SetWindowLayout(p->f68, 1);
            MB_UTIL_MSG_CreateWordSet(p->f68);
            MB_UTIL_MSG_SetNumberLeft(p->f68, 0, a, 3);
            MB_UTIL_MSG_PrintStream(p->f68, 0x24, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
            MB_UTIL_MSG_DeleteWordSet(p->f68);
            p->state = 4;
        } else {
            p->state = 5;
        }
        break;
    case 4:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            p->state = 5;
        }
        break;
    case 5:
        if (MB_COMM_SYS_GetOfferFlagA(p->f0C) == 1) {
            MB_UTIL_MSG_ClearWindow(p->f68);
            MB_UTIL_MSG_SetWindowLayout(p->f68, 5);
            MB_UTIL_MSG_PrintStream(p->f68, 0x1A, MSG_SPEED_GetWait());
            p->state = 6;
        } else {
            p->state = 0xD;
        }
        break;
    case 6:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->f68, 1);
            p->state = 7;
        }
        break;
    case 7:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->f68);
        if (a == 1) {
            if (MB_COMM_SYS_GetOfferFlagB(p->f0C) == 1) {
                MB_UTIL_MSG_PrintStream(p->f68, 0x1B, MSG_SPEED_GetWait());
                p->state = 8;
            } else {
                p->state = 0xD;
            }
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 8:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->f68, 1);
            p->state = 9;
        }
        break;
    case 9:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->f68);
        if (a == 1) {
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 10:
        MB_UTIL_MSG_PrintStream(p->f68, 0x1C, MSG_SPEED_GetWait());
        p->state = 0xB;
        break;
    case 11:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            MB_UTIL_MSG_OpenYesNoMenu(p->f68, 1);
            p->state = 0xC;
        }
        break;
    case 12:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->f68);
        if (a == 1) {
            p->f34 = 2;
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 5;
        }
        break;
    case 13:
        if (p->f34 == 1) {
            if (p->f40 == 1) {
                a = 2;
            } else {
                a = 0;
            }
        } else {
            a = 1;
        }
        if (MB_COMM_SYS_SendMessage(p->f0C, 0xF, a) == 1) {
            if (a == 0) {
                p->state = 0xE;
                MB_UTIL_MSG_ClearWindow(p->f68);
                MB_UTIL_MSG_SetWindowLayout(p->f68, 1);
                MB_UTIL_MSG_PrintQueued(p->f68, 0x19);
                MB_UTIL_MSG_SetTimeIconPending(p->f68, 1);
            } else if (a == 2) {
                p->state = 0x11;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 14:
        if (MB_COMM_SYS_HasMonsReceived(p->f0C) == 1) {
            MB_COMM_SYS_RegisterReceivedMons(p);
            p->state = 0xF;
        }
        if (MB_COMM_SYS_HasKind20(p->f0C) == 1) {
            a = MB_COMM_SYS_GetOfferCount(p->f0C);
            MB_UTIL_MSG_ClearWindow(p->f68);
            MB_UTIL_MSG_SetWindowLayout(p->f68, 1);
            MB_UTIL_MSG_CreateWordSet(p->f68);
            MB_UTIL_MSG_SetNumberLeft(p->f68, 0, a, 3);
            MB_UTIL_MSG_PrintStream(p->f68, 0x1E, MSG_SPEED_GetWait());
            MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
            MB_UTIL_MSG_DeleteWordSet(p->f68);
            p->state = 0x10;
            p->f44 = 1;
        }
        break;
    case 15:
        if (MB_COMM_SYS_SendMessage(p->f0C, 0, 0) == 1) {
            MB_COMM_SYS_ClearMonBuffer(p->f0C);
            p->state = 0xE;
        }
        break;
    case 16:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 17:
        MB_UTIL_MSG_ClearWindow(p->f68);
        MB_UTIL_MSG_SetWindowLayout(p->f68, 5);
        MB_UTIL_MSG_PrintStream(p->f68, 0x18, MSG_SPEED_GetWait());
        p->state = 0x12;
        break;
    case 18:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 19:
        if (MB_COMM_SYS_HasKind21(p->f0C) == 1) {
            if (MB_COMM_SYS_GetKind21Value(p->f0C) == 1) {
                MB_UTIL_MSG_ClearWindow(p->f68);
                MB_UTIL_MSG_SetWindowLayout(p->f68, 5);
                MB_UTIL_MSG_PrintStream(p->f68, 0x1F, MSG_SPEED_GetWait());
                p->state = 0x14;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 20:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            p->state = 0x15;
            MB_UTIL_MSG_OpenYesNoMenu(p->f68, 1);
        }
        break;
    case 21:
        a = MB_UTIL_MSG_ProcessYesNoMenu(p->f68);
        if (a == 1 || a == 2) {
            c = GAME_DATA_GetMyItem(p->f08->f04);
            d = GAME_DATA_GetMyStatus(p->f08->f04);
            e = GAME_DATA_GetMiscSave(p->f08->f04);
            if (a == 1 && FIELD_G3D_MAP_CheckBeaconTrainerKey(e, 0, d) == 1) {
                p->f34 = 2;
                p->state = 0x16;
                MB_UTIL_MSG_ClearWindow(p->f68);
                MB_UTIL_MSG_SetWindowLayout(p->f68, 1);
                MB_UTIL_MSG_PrintStream(p->f68, 0x25, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
            } else {
                p->f34 = a;
                p->state = 0x17;
            }
        }
        break;
    case 22:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            p->state = 0x17;
        }
        break;
    case 23:
        a = 1;
        if (p->f34 != 1) {
            a = 0;
        }
        if (MB_COMM_SYS_SendMessage(p->f0C, 0x10, a) == 1) {
            if (a == 1) {
                c = GAME_DATA_GetMyItem(p->f08->f04);
                d = GAME_DATA_GetMyStatus(p->f08->f04);
                e = GAME_DATA_GetMiscSave(p->f08->f04);
                MB_UTIL_MSG_ClearWindow(p->f68);
                MB_UTIL_MSG_SetWindowLayout(p->f68, 1);
                MB_UTIL_MSG_PrintStream(p->f68, 0x21, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
                FIELD_G3D_MAP_StoreBeaconTrainerKey(e, 0, d);
                func_02007E50(c, 0x215, 1, p->f00);
                p->f48 = 1;
                p->state = 0x18;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 24:
        if (MB_UTIL_MSG_IsStreamIdle(p->f68) == 1) {
            p->state = 0x19;
        }
        break;
    case 25:
        if (p->f44 == 1 || p->f48 == 1) {
            if (MB_COMM_SYS_SendMessage(p->f0C, 0x11, 0) == 1) {
                p->f20 = 0x13;
            }
        } else {
            if (MB_COMM_SYS_GetOfferCount(p->f0C) == 0 && MB_COMM_SYS_GetKind21Value(p->f0C) == 0) {
                MB_UTIL_MSG_ClearWindow(p->f68);
                MB_UTIL_MSG_SetWindowLayout(p->f68, 1);
                MB_UTIL_MSG_PrintStream(p->f68, 0x28, MSG_SPEED_GetWait());
                MB_UTIL_MSG_SetKeyWaitFlag(p->f68, 1);
            }
            p->f20 = 0x1B;
        }
        break;
    }
}
