/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_02154668
 * address:  0x021542C0
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005C18  0x02005C18  thumb
 *   func_02005B24  0x02005B24  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009304  0x02009304  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02012444  0x02012444  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_020121CC  0x020121CC  thumb
 *   ov123_id       0x0000007B  data   a1
 *   ov016_id       0x00000010  data   a1
 *   ov115_id       0x00000073  data   a1
 *   ov170_id       0x000000AA  data   a1
 *   d_021DA674     0x021DA674  data   ov123  a4
 *   d_021DA838     0x021DA838  data   ov123  a4
 *   d_021D77B8     0x021D77B8  data   ov016  a4
 *   d_021D6338     0x021D6338  data   ov115  a4
 *   d_021D654C     0x021D654C  data   ov115  a4
 *   d_021EF78C     0x021EF78C  data   ov170  a4
 *   func_02154670  0x02154670  thumb ov000
 */
struct GameSystem;
struct GameEvent;
struct GameData;
struct SaveControl;
struct BoxManager;
struct Party;
struct MyItem;
struct MyStatus;
struct Config;
struct WifiList;
struct FieldMap;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef volatile u16   vu16;

/* Parameter block read by the WiFi login overlay (ov115). */
typedef struct WifiLoginParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
    u32 result;
    u32 reserved[2];
} WifiLoginParam;

/* Parameter block of the second ov115 call (session confirm). */
typedef struct WifiConfirmParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
} WifiConfirmParam;

/* Parameter block read by the box overlay (ov170) when the player picks a Pokemon to sync. */
typedef struct GsyncBoxParam {
    struct GameData *gameData;
    struct BoxManager *boxManager;
    struct Party *party;
    struct MyItem *myItem;
    u8 *myStatus;
    u32 reserved;
    struct Config *config;
    u32 result;
    u8 *pickerBuffer;
    u32 mode;
    u16 reserved2;
    u8 pickedBox;
    u8 pickedSlot;
} GsyncBoxParam;

/* Work of the game-sync event (0x2CC bytes). The first bytes are also the parameter block of the ov123 sync screen. */
typedef struct GsyncEventWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    u8 syncParam[0x44];
    u32 syncResult;
    u8 loginSaveData[0x174];
    u32 menuResult;
    u32 bgmPushed;
    u16 selectedBox;
    u16 selectedSlot;
    u32 savedBgmNo;
    u8 pickerBuffer[0x80];
    WifiLoginParam login;
    WifiConfirmParam confirm;
    GsyncBoxParam box;
    u32 returnToMenu;
} GsyncEventWork;

extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern int func_021BE8D4(void *gameSystem, int fieldMap, int sel, int d);
extern int func_021BE92C(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct GameEvent *event, struct GameEvent **newEvent);
extern int func_020144DC(int gameSystem, int fieldMap);
extern void  func_02082BCC(void *dst, int value, int size);
extern void func_020120B4(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 func_020120F0(const struct GameSystem *gameSystem);
extern u16 func_02005C44(void);
extern void  func_02005C18(void);
extern void  func_02005B24(void);
extern void  func_02005D90(u32 bgmNo, u32 fadeTarget);
extern void func_02005DF8(u32 frames);
extern void *func_020145CC(void *gameSystem);
extern int func_02005E9C(void);
extern void func_02005DE4(void *param);
extern int func_02005E64(void);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct WifiList *func_02009448(void *saveControl);
extern u8 func_02009304(const struct WifiList *wifiList);
extern struct BoxManager *func_0201293C(const struct GameData *gameData);
extern struct Party *func_02012934(const struct GameData *gameData);
extern struct MyItem *func_0201292C(const struct GameData *gameData);
extern u8 *func_02012944(void *gameData);
extern int func_020079A0(void *boxManager);
extern struct Config *func_0200873C(void *saveControl);
extern void func_02012444(struct GameEvent *event, u32 overlayId, u32 procData, u32 param);
extern u32 func_0200FB24(void);
extern void  func_0200FB38(void);
extern u32 func_0200F7B8(u32 a0);
extern u32 func_020121CC(struct GameSystem *gameSystem);
extern void *func_02154670(void *gameSystem);
u32 func_021542C0(struct GameEvent *event, u32 *seq, GsyncEventWork *work);
void *func_02154668(void *gameSystem);
extern char ov123_id[];
extern char ov016_id[];
extern char ov115_id[];
extern char ov170_id[];
extern char d_021DA674[];
extern char d_021DA838[];
extern char d_021D77B8[];
extern char d_021D6338[];
extern char d_021D654C[];
extern char d_021EF78C[];


u32 func_021542C0(struct GameEvent *event, u32 *seq, GsyncEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    u32 fieldMap = (u32)func_0201210C(gameSystem);
    int wifiFlag;

    switch (*seq) {
    case 0:
        func_02012374(event, (struct GameEvent **)func_021BE8D4(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, (struct GameEvent **)func_020144DC((int)gameSystem, fieldMap));
        work->returnToMenu = 0;
        *seq = 2;
        break;
    case 2:
        func_02082BCC(work->syncParam, 0, 0x44);
        work->syncResult = 0;
        func_020120B4(gameSystem, (u32)ov123_id, d_021DA674, work);
        (*seq)++;
        break;
    case 3:
        if (func_020120F0(gameSystem) == 0) {
            if (work->menuResult == 2)
                *seq = 16;
            else if (work->menuResult == 3)
                *seq = 5;
            else
                *seq = 10;
        }
        break;
    case 5:
        (*seq)++;
        break;
    case 6:
        work->savedBgmNo = func_02005C44();
        func_02005C18();
        func_020120B4(gameSystem, (u32)ov016_id, d_021D77B8, work);
        (*seq)++;
        break;
    case 7:
        if (func_020120F0(gameSystem) == 0)
            *seq = 14;
        break;
    case 14:
        {
            vu16 *regIme = (vu16 *)0x04000208;
            u16 prevIme = *regIme;
            *regIme = 1;
            (void)prevIme;
        }
        func_02005B24();
        func_02005D90(work->savedBgmNo, 0xFFFF);
        func_02005DF8(0x3C);
        *seq = 15;
        break;
    case 15:
        work->returnToMenu = 1;
        *seq = 2;
        break;
    case 10:
        func_02012374(event, func_020145CC(gameSystem));
        (*seq)++;
        break;
    case 11:
        func_02012374(event, (struct GameEvent **)func_021BE92C(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 12:
        if (work->bgmPushed) {
            func_02005E9C();
            func_02005DE4(0);
            func_02005DF8(0x3C);
            work->bgmPushed = 0;
        }
        (*seq)++;
        break;
    case 13:
        return 1;
    case 16:
        wifiFlag = func_02009304(func_02009448(func_02012EBC(func_020120F4(gameSystem))));
        if (func_020079A0(func_0201293C(func_020120F4(gameSystem))) == 0 && wifiFlag == 0) {
            work->menuResult = 4;
            *seq = 19;
        } else {
            work->login.useSaveData = 0;
            func_02005DE4((void *)1);
            func_02005E64();
            work->bgmPushed = 1;
            (*seq)++;
        }
        break;
    case 17:
        work->login.saveData = work->loginSaveData;
        func_020120B4(gameSystem, (u32)ov115_id, d_021D6338, &work->login);
        (*seq)++;
        break;
    case 18:
        if (func_020120F0(gameSystem) == 0) {
            if (work->login.result == 1) {
                *seq = 10;
            } else {
                if (func_02009304(func_02009448(work->saveControl)) == 0) {
                    work->menuResult = 3;
                    *seq = 19;
                } else {
                    work->menuResult = 0;
                    *seq = 19;
                }
            }
        }
        break;
    case 19:
        func_020120B4(gameSystem, (u32)ov123_id, d_021DA838, work);
        (*seq)++;
        break;
    case 20:
        if (func_020120F0(gameSystem) == 0) {
            if (work->menuResult == 1) {
                work->returnToMenu = 0;
                *seq = 2;
            } else if (work->menuResult == 5) {
                *seq = 21;
            } else if (work->menuResult == 4) {
                *seq = 21;
            } else if (work->menuResult == 7) {
                work->login.useSaveData = 1;
                *seq = 17;
            } else {
                *seq = 23;
            }
        }
        break;
    case 21:
        work->box.gameData = func_020120F4(gameSystem);
        work->box.boxManager = func_0201293C(work->box.gameData);
        work->box.party = func_02012934(work->box.gameData);
        work->box.myItem = func_0201292C(work->box.gameData);
        work->box.myStatus = func_02012944(work->box.gameData);
        work->box.config = func_0200873C(func_02012EBC(work->box.gameData));
        work->box.pickerBuffer = work->pickerBuffer;
        work->box.result = 0;
        work->box.mode = 5;
        func_02012444(event, (u32)ov170_id, (u32)d_021EF78C, (u32)&work->box);
        (*seq)++;
        break;
    case 22:
        if (func_0200FB24()) {
            func_0200FB38();
            func_0200F7B8(0);
            work->login.useSaveData = 1;
            *seq = 17;
        } else {
            u8 box, slot;
            box = work->box.pickedBox;
            work->selectedBox = box;
            slot = work->box.pickedSlot;
            work->selectedSlot = slot;
            if (box == 0xff && slot == 0xff) {
                *seq = 23;
            } else {
                if (work->menuResult == 4)
                    work->menuResult = 2;
                else
                    work->menuResult = 1;
                *seq = 19;
            }
        }
        break;
    case 23:
        work->confirm.gameData = func_020120F4(gameSystem);
        work->confirm.loginType = 1;
        work->confirm.loginOption = 0;
        func_020120B4(gameSystem, (u32)ov115_id, d_021D654C, &work->confirm);
        (*seq)++;
        break;
    case 24:
        if (func_020120F0(gameSystem) == 0) {
            func_020121CC(gameSystem);
            *(vu16 *)0x04000304 |= 0x8000;  /* POWCNT1: swap the two screens */
            work->returnToMenu = 0;
            *seq = 2;
            if (work->bgmPushed) {
                func_02005E9C();
                func_02005DE4(0);
                func_02005DF8(0x3C);
                work->bgmPushed = 0;
            }
        }
        break;
    }
    return 0;
}


/*
 * Thumb tail call through r3 (ldr r3, =target; bx r3). Labelled in wave D8.
 * Overlay entry point: forwards to the event constructor.
 */
void *func_02154668(void *gameSystem)
{
    return func_02154670(gameSystem);
}
