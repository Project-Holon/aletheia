/*
 * function: EVENT_COMM_COMMON_ChangeTalkedSearchAsTargetEvent
 * address:  0x02181A74
 * packet:   pkt_ov018_02181A74
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Callback pointer is copied unchanged by GAME_EVENT_Change into task +4;
 * its legacy int parameter represents the same full-word payload.
 * symbols:
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain  0x02181A98  thumb ov018
 */

typedef unsigned int u32;
typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

extern void GAME_EVENT_Change(char *p, int a1, int a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
extern int EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain(void *, int *, void *);

void EVENT_COMM_COMMON_ChangeTalkedSearchAsTargetEvent(Obj *task, const void *src)
{
    void *dst;

    GAME_EVENT_Change((char *)task, (int)EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}
