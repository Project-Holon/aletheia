/*
 * function: PLACE_NAME_LETTER_StepX
 * address:  0x021BD3EC
 * packet:   pkt_ov021_021BD3EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLACE_NAME_LETTER_IsXDone  0x021BD36C  thumb  ov021
 *   _fdiv          0x0209CE10  arm
 *   _fadd          0x0209C95C  arm
 */

typedef struct {
    float f00;
    char pad04[4];
    float f08;
    char pad0c[4];
    float f10;
    char pad14[4];
    float f18;
    char pad1c[0xc];
    int f28;
} T;

typedef struct {
    char pad00[0x10];
    T t;
} S;

extern int PLACE_NAME_LETTER_IsXDone(void *p);

void PLACE_NAME_LETTER_StepX(S *p)
{
    T *q;

    if (PLACE_NAME_LETTER_IsXDone(p) == 1) {
        return;
    }
    q = &p->t;
    p->t.f00 = p->t.f00 + (q->f08 + q->f10 / 2.0f);
    q->f08 = q->f08 + q->f10;
    q->f28 = q->f28 - 1;
    if (q->f28 == 0) {
        q->f00 = q->f18;
    }
}
