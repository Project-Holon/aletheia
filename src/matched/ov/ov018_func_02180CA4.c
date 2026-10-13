/*
 * function: EVENT_COMM_COMMON_ChangeTalkedPowerGiftTargetEvent
 * address: 0x02180CA4
 * packet: pkt_ov018_02180CA4
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_EVENT_Change 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain 0x02180CC8 thumb ov018
 */
typedef unsigned int u32;
extern void GAME_EVENT_Change(char *p, int a1, int a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
extern int EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain(void *, int *, void *);
void EVENT_COMM_COMMON_ChangeTalkedPowerGiftTargetEvent(void *task, const void *src)
{
    void *work;
    GAME_EVENT_Change(task, (int)EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}
