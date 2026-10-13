/*
 * function: SCRCMD_WORK_CmdSetMiscByte
 * address:  0x0215B138
 * packet:   pkt_0215B138
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The third argument of the arm9 pair call is the slot the overlay index
 * returned, with a literal one alongside.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue   0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMiscSave   0x02012F08  thumb
 *   func_0200C2F0   0x0200C2F0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Blk34;
extern void *GAME_DATA_GetMiscSave(int *p);
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);

int SCRCMD_WORK_CmdSetMiscByte(void *a0, void *a1)
{
    void *v = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);

    func_0200C2F0(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(a1)), (u32)v, 1);

    return 0;
}

