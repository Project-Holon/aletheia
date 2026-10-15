/*
 * function: SCRCMD_SYMBOL_GetState
 * address:  0x0216AD70
 * packet:   pkt_ov010_0216AD70
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   SYMBOL_MAP_IsHomeCell  0x02166618  thumb  ov010
 *   SYMBOL_MAP_IsBlankCell  0x0216662C  thumb  ov010
 *   SCRCMD_SYMBOL_GetTargetObjectKey  0x0216AEE8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

typedef struct {
    u32 lo : 11;
    u32 pad : 12;
    u32 f : 6;
    u32 rest : 3;
} Bits;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBlock(void *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *a, void *b);
extern int GAME_DATA_GetSymbolMapFlag(unsigned char *base);
extern int SYMBOL_MAP_IsHomeCell(int a0);
extern int SYMBOL_MAP_IsBlankCell(int a0);
extern void SCRCMD_SYMBOL_GetTargetObjectKey(int vm, int *out);

int SCRCMD_SYMBOL_GetState(int a0, int a1)
{
    int kind;
    u16 *out;
    void *x;
    void *y;
    int t;
    Bits v;
    Bits w;

    kind = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    x = SCRCMD_WORK_GetGameSystem((void *)a1);
    y = SCRCMD_WORK_GetGameData((void *)a1);
    SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl((struct Big *)y));
    t = GAMESYSTEM_GetGameComm(x);
    switch (kind) {
    case 0:
        if (INTRUDE_COMM_GetPartnerSlot((void *)t, y) == 4)
            *out = 1;
        else
            *out = 0;
        break;
    case 1:
        *out = SYMBOL_MAP_IsHomeCell(GAME_DATA_GetSymbolMapFlag(y));
        break;
    case 2:
        *out = SYMBOL_MAP_IsBlankCell(GAME_DATA_GetSymbolMapFlag(y));
        break;
    case 3:
        SCRCMD_SYMBOL_GetTargetObjectKey(a1, (int *)(&v));
        *out = v.lo;
        break;
    case 4:
        SCRCMD_SYMBOL_GetTargetObjectKey(a1, (int *)(&w));
        *out = w.f;
        break;
    }
    return 0;
}
