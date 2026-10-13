/*
 * function: SCRCMD_PALPARK_GetSaveValue
 * address:  0x021CC5D8
 * packet:   pkt_ov021_021CC5D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: reads a mode byte and a result variable, then stores one of two values from the save-data block selected by the mode.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1A4  0x0200C1A4  thumb
 *   func_0200C184  0x0200C184  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x14];
    u8 *pc;
} ScriptVM;

struct Big;
struct Blk34;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *ctx);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *p);
extern u8 func_0200C1A4(struct Blk34 *p);
extern u32 func_0200C184(struct Blk34 *p);

int SCRCMD_PALPARK_GetSaveValue(ScriptVM *vm, void *ctx)
{
    u8 mode;
    u16 *dst;
    void *p;

    mode = *vm->pc;
    vm->pc++;
    dst = SCRIPT_WORK_ReadWorkPointer(vm, ctx);
    p = func_0200C0F0(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(ctx)));

    switch (mode) {
    case 0:
        *dst = func_0200C1A4(p);
        break;
    case 1:
        *dst = func_0200C184(p);
        break;
    }
    return 0;
}
