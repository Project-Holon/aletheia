/*
 * function: SCRCMD_MUSICAL_WifiListCommand
 * address:  0x0215E1C0
 * packet:   pkt_ov010_0215E1C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the save-data block func_02009448 returns;
 * sub-commands 0, 1 and 4 write a halfword result through the destination
 * variable, 5 formats a value into the word set.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009370  0x02009370  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   PDW_POSTMAN_CountUnreceivable  0x021B76F8  thumb  ov021
 *   PDW_POSTMAN_CreateListEvent  0x021B7794  thumb  ov021
 *   PDW_POSTMAN_ReceiveItems  0x021B76B4  thumb  ov021
 *   PDW_POSTMAN_GetUnreceivableItem  0x021B7740  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   WORDSET_SetSlotFromMsg118  0x0201EF5C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern u16 SCRCMD_WORK_GetHeapId(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
extern void *SCRCMD_WORK_GetScriptWork(void *vm);
struct Big;
struct Ctx;
struct Sub02009448Obj;
struct WordSet;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
struct Sub02009210Obj;
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int PDW_POSTMAN_CountUnreceivable(void *p, int key, void *q);
extern void *PDW_POSTMAN_CreateListEvent(void *p);
extern void PDW_POSTMAN_ReceiveItems(void *a0, int a1, int a2);
extern void *PDW_POSTMAN_GetUnreceivableItem(void *p, int key, void *q, int idx);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern void WORDSET_SetSlotFromMsg118(struct WordSet *p, u32 i, u32 v);

int SCRCMD_MUSICAL_WifiListCommand(void *c, void *vm)
{
    u32 cmd;
    u16 *dst;
    u16 v;
    void *sys;
    void *x;
    void *blk;
    u32 lim;
    void *t;
    void *ws;

    cmd = SCRIPT_WORK_ReadWorkValue(c, vm);
    dst = SCRIPT_WORK_ReadWorkPointer(c, vm);
    v = SCRCMD_WORK_GetHeapId(vm);
    sys = SCRCMD_WORK_GetGameSystem(vm);
    x = SCRCMD_WORK_GetGameData(vm);
    blk = func_02009448(GAME_DATA_GetSaveControl(x));
    lim = (int)func_02009370(blk);
    if (GAMESYSTEM_GetFieldMap(sys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *dst = (int)func_02009370(blk) > 0 ? 1 : 0;
        break;
    case 1:
        if (PDW_POSTMAN_CountUnreceivable(x, v, blk) < lim) {
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 2:
        t = PDW_POSTMAN_CreateListEvent(sys);
        SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork(vm), t);
        return 1;
    case 3:
        PDW_POSTMAN_ReceiveItems(x, v, (int)blk);
        break;
    case 5:
        ws = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(vm));
        WORDSET_SetSlotFromMsg118(ws, 0, (u32)PDW_POSTMAN_GetUnreceivableItem(x, v, blk, *dst));
        break;
    case 4:
        *dst = PDW_POSTMAN_CountUnreceivable(x, v, blk);
        break;
    }
    return 0;
}
