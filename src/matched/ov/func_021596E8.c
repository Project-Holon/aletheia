/*
 * function: SCRIPT_WORK_CmdSetProcAction
 * address:  0x021596E8
 * packet:   pkt_021596E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The record's arm9 handle and the caller's second argument are the two
 * operands of the arm9 pair call.
 *
 * symbols:
 *   VM_GetU16   0x02011330  thumb
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMoveModelSys   0x02012B38  thumb
 *   func_02014474   0x02014474  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern void func_02014474(void *, void *);

int SCRIPT_WORK_CmdSetProcAction(void *a0, void *a1)
{
    void *v = (void *)VM_GetU16(a0);

    func_02014474(GAME_DATA_GetMoveModelSys(SCRCMD_WORK_GetGameData(a1)), v);

    return 0;
}

