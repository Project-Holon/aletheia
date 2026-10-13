/*
 * function: EVENT_COMM_COMMON_ChangeTalkMsgEvent
 * address: 0x021808C4
 * packet: pkt_ov018_021808C4
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
 *   EVENT_COMM_COMMON_TalkMsgEventMain 0x021808E8 thumb ov018
 */
typedef unsigned int u32;
extern void GAME_EVENT_Change(char *p, int a1, int a2);
typedef unsigned char  u8;
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
extern int EVENT_COMM_COMMON_TalkMsgEventMain(int x, int *st, u8 *obj);
void EVENT_COMM_COMMON_ChangeTalkMsgEvent(void *task, const void *src)
{
    void *work;
    GAME_EVENT_Change(task, (int)EVENT_COMM_COMMON_TalkMsgEventMain, 0xA8);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}
