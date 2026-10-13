/*
 * function: FIELD_STATUS_SubProcNoFadeCallbackEvent
 * address:  0x020147B0
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-for-byte the twin of FIELD_STATUS_SubProcCallbackEvent (same 86-byte shape, same three
 * states) with func_020146F8 replaced by func_02014728.  The only other
 * difference is the literal pool holding 0x020307B0: 0x02014758's pool is
 * reachable with `blx 0x20307b0`'s 26-bit reach, this one needs no change.
 *
 * EXACT*: the compared extent runs into the four-byte alignment pad before
 * the next labelled function; no byte of the body differs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_STATUS_SubProcNoFadeCallbackEvent.c \
 *       --func FIELD_STATUS_SubProcNoFadeCallbackEvent --addr 0x020147B0 --cc 1.1p1 --thumb
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
extern void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

int FIELD_STATUS_SubProcNoFadeCallbackEvent(int a0, int *a1, S *a2)
{
    switch (*a1) {
    case 0:
        func_02012374((struct Evt *)a0, func_02014728((char *)a2->f00, a2->f04, a2->f08, a2->f0c,
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
