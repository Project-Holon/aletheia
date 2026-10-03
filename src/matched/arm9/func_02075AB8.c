/*
 * function: func_02075AB8
 * address:  0x02075AB8
 * packet:   pkt_02075AB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988 0x02087988  arm
 *   func_0208799C 0x0208799C  arm
 *   func_02060614 0x02060614  arm
 *   func_020605B4 0x020605B4  arm
 *   func_02075B28 0x02075B28  arm
 *
 * The unlink walk holds the interrupt state in the lowest callee-saved
 * register and the next link in r6, so the state survives the two calls in
 * the body; declaring `n` inside the loop (rather than hoisting it) is what
 * keeps r6 out of the prologue's push.
 */

typedef unsigned int u32;

extern u32  func_02087988(void);
extern void func_0208799C(u32);
struct DList;
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_02075B28(void *);

void func_02075AB8(void *a, u32 v)
{
    u32 state = func_02087988();
    void *p = func_02060614(a, 0);

    while (p != 0) {
        void *n = func_02060614(a, p);

        if (*(u32 *)((char *)p + 8) == v) {
            func_020605B4(a, p);
            func_02075B28(p);
        }
        p = n;
    }
    func_0208799C(state);
}
