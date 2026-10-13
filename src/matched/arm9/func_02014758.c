/*
 * function: FIELD_STATUS_SubProcCallbackEvent
 * address:  0x02014758
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A three-state step machine over a descriptor `a2`.  State 0 forwards five
 * of the descriptor's leading words (four in registers, the fifth on the
 * stack) to FIELD_STATUS_CreateSubProcEvent and hands the result to GAME_EVENT_CallEvent, then bumps
 * the counter.  State 1 calls the descriptor's own callback slot (+0x14) with
 * the pointer at +0x18.  State 2 frees the +0x18 pointer and returns 1.  The
 * `*a1 = *a1 + 1` in state 1 is a separate arm in the source; the compiler
 * cross-jumps it onto state 0's increment, which is why the listing shows the
 * state-1 arm branching backwards into state 0's tail.
 *
 * EXACT*: the compared extent runs four bytes past the body into the next
 * function's alignment pad (the follower at 0x020147B0 saves lr, so its label
 * exists and the extent is only the pad - no byte of it differs).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_STATUS_SubProcCallbackEvent.c \
 *       --func FIELD_STATUS_SubProcCallbackEvent --addr 0x02014758 --cc 1.1p1 --thumb
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 */

typedef struct {
    int   f00;
    int   f04;
    int   f08;
    int   f0c;
    int   f10;
    void (*f14)(void *);
    void *f18;
} S;

struct Evt;
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

int FIELD_STATUS_SubProcCallbackEvent(int a0, int *a1, S *a2)
{
    switch (*a1) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a0, FIELD_STATUS_CreateSubProcEvent((char *)a2->f00, a2->f04, a2->f08, a2->f0c,
                                        a2->f10));
        *a1 = *a1 + 1;
        break;
    case 1:
        if (a2->f14 != 0) {
            a2->f14(a2->f18);
        }
        *a1 = *a1 + 1;
        break;
    case 2:
        if (a2->f18 != 0) {
            func_020307B0(a2->f18);
        }
        return 1;
    }
    return 0;
}
