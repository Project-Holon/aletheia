/*
 * function: func_0217303C
 * address:  0x0217303C
 * packet:   pkt_ov012_0217303C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 * Lever: func_02173840 reads the entry Work pointer still live in r0;
 * the guard uses r1 only when that input is explicitly forwarded.
 * symbols:
 *   func_02173840  0x02173840  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_02167590  0x02167590  thumb  ov010
 *   func_0216786C  0x0216786C  thumb  ov010
 *   func_02174C90  0x02174C90  thumb  ov012
 *   func_0217FF78  0x0217FF78  thumb  ov019
 *   func_02175110  0x02175110  thumb  ov012
 *   func_02175144  0x02175144  thumb  ov012
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

extern int func_02173840(u8 *w);
extern int func_02174268(u8 *p);
struct Report;
struct Work;
extern void func_02167590(void *a, struct Work *w);
extern int func_0216786C(struct Work *w, struct Report *out);
typedef unsigned int   u32;
extern u32 func_02174C90(u32 a);
extern void func_0217FF78(u32 *p);
extern void func_02175110(u8 *p);
extern void func_02175144(u8 *p);

void func_0217303C(Work *w)
{
    if (w->q != 0 && ((Sub *)((u8 *)w->q + 0xC8))->flag) {
    if (func_02173840((u8 *)w) == 1) {
        if (func_02174268((u8 *)w) == 0) {
            func_02167590((void *)w->head->f0c, (struct Work *)w->q->f0);
            if (w->q->f16F == 0) {
                if (func_0216786C((struct Work *)w->q->f0, (struct Report *)((u8 *)w->q + 4)) == 1) {
                    w->q->f16F = 1;
                }
            }
            if (w->q->f16F == 1) {
                if (func_02174C90((u32)((u8 *)w->q + 4)) == 1) {
                    w->q->f16F = 0;
                }
            }
        }
        func_0217FF78((u32 *)w->q);
    }
    func_02175110((u8 *)w->q);
    func_02175144((u8 *)w->q);
    }
}
