/*
 * function: SCRCMD_MUSICAL_AddOwnedProp
 * address:  0x0215D864
 * packet:   pkt_0215D864
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:   wild=4
 *
 * The slot index is truncated to a byte before the arm9 pair call.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue   0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveBlock2A   0x02012F44  thumb
 *   MUSICAL_SAVE_AddProp   0x0200A6BC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveBlock2A(void *p);
struct Big;
extern void MUSICAL_SAVE_AddProp(struct Big *p, u32 index);

int SCRCMD_MUSICAL_AddOwnedProp(void *a0, void *a1)
{
    int v = SCRIPT_WORK_ReadWorkValue(a0, a1);

    MUSICAL_SAVE_AddProp((struct Big *)GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(a1)), (u8)v);

    return 0;
}

