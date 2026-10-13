/*
 * function: EVENT_COMM_COMMON_ChangeTalkedPowerGiftAsTargetEvent
 * address: 0x02180BDC
 * packet: pkt_ov018_02180BDC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_EVENT_Change 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain 0x02180C00 thumb ov018
 */
typedef unsigned int u32;
extern void GAME_EVENT_Change(char *p, int a1, int a2);
typedef unsigned char  u8;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuCopy8(const void *, void *, u32);
extern int EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain(int x, int *st, u8 *obj);
void EVENT_COMM_COMMON_ChangeTalkedPowerGiftAsTargetEvent(void *task, const void *src)
{
    void *work;
    GAME_EVENT_Change(task, (int)EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain, 0xA4);
    work = func_020124E8(task);
    MI_CpuCopy8(src, work, 0x98);
}
