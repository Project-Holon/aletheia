/*
 * function: UNION_COMM_UpdateColosseum
 * address:  0x0217303C
 * packet:   pkt_ov012_0217303C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 * Lever: UNION_MAIN_IsFieldReady reads the entry Work pointer still live in r0;
 * the guard uses r1 only when that input is explicitly forwarded.
 * symbols:
 *   UNION_MAIN_IsFieldReady  0x02173840  thumb  ov012
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   COMM_PLAYER_Update  0x02167590  thumb  ov010
 *   COMM_PLAYER_UpdateMyPackage  0x0216786C  thumb  ov010
 *   COLOSSEUM_SendPackage  0x02174C90  thumb  ov012
 *   func_0217FF78  0x0217FF78  thumb  ov019
 *   COLOSSEUM_FlushChoiceReplies  0x02175110  thumb  ov012
 *   COLOSSEUM_UpdateReadyState  0x02175144  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    u8 flag : 1;
} Sub;

typedef struct {
    int f0;
    u8 pad[0xC4];
    u8 flag : 1;
    u8 pad2[0x16F - 0xC9];
    u8 f16F;
} Q;

typedef struct {
    struct { int pad[3]; int f0c; } *head;
    u8 pad[0x355C - 4];
    Q *q;
} Work;

extern int UNION_MAIN_IsFieldReady(u8 *w);
extern int UNION_MAIN_IsScenePending(u8 *p);
struct Report;
struct Work;
extern void COMM_PLAYER_Update(void *a, struct Work *w);
extern int COMM_PLAYER_UpdateMyPackage(struct Work *w, struct Report *out);
typedef unsigned int   u32;
extern u32 COLOSSEUM_SendPackage(u32 a);
extern void func_0217FF78(u32 *p);
extern void COLOSSEUM_FlushChoiceReplies(u8 *p);
extern void COLOSSEUM_UpdateReadyState(u8 *p);

void UNION_COMM_UpdateColosseum(Work *w)
{
    if (w->q != 0 && ((Sub *)((u8 *)w->q + 0xC8))->flag) {
    if (UNION_MAIN_IsFieldReady((u8 *)w) == 1) {
        if (UNION_MAIN_IsScenePending((u8 *)w) == 0) {
            COMM_PLAYER_Update((void *)w->head->f0c, (struct Work *)w->q->f0);
            if (w->q->f16F == 0) {
                if (COMM_PLAYER_UpdateMyPackage((struct Work *)w->q->f0, (struct Report *)((u8 *)w->q + 4)) == 1) {
                    w->q->f16F = 1;
                }
            }
            if (w->q->f16F == 1) {
                if (COLOSSEUM_SendPackage((u32)((u8 *)w->q + 4)) == 1) {
                    w->q->f16F = 0;
                }
            }
        }
        func_0217FF78((u32 *)w->q);
    }
    COLOSSEUM_FlushChoiceReplies((u8 *)w->q);
    COLOSSEUM_UpdateReadyState((u8 *)w->q);
    }
}
