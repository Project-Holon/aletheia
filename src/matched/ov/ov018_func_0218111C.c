/*
 * function: EVENT_COMM_COMMON_ChangeTalkedPowerShareTargetEvent
 * address:  0x0218111C
 * packet:   pkt_ov018_0218111C
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
 *   MI_CpuCopy8  0x02082D44  arm
 *   EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain  0x02181140  thumb ov018
 */

typedef unsigned int u32;
typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

typedef unsigned char  u8;
extern void GAME_EVENT_Change(char *p, int a1, int a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuCopy8(const void *, void *, u32);
extern int EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain(int x, int *st, u8 *obj);

void EVENT_COMM_COMMON_ChangeTalkedPowerShareTargetEvent(Obj *task, const void *src)
{
    void *dst;

    GAME_EVENT_Change((char *)task, (int)EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    MI_CpuCopy8(src, dst, 0x98);
}
