/*
 * function: PLACE_NAME_LETTER_StepY
 * address:  0x021BD430
 * packet:   pkt_ov021_021BD430
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   PLACE_NAME_LETTER_IsYDone  0x021BD394  thumb  ov021
 *   _fdiv          0x0209CE10  arm
 *   _fadd          0x0209C95C  arm
 */

typedef struct {
    char pad00[4];
    float f04;
    char pad08[4];
    float f0c;
    char pad10[4];
    float f14;
    char pad18[4];
    float f1c;
    char pad20[0xc];
    int f2c;
} T;

typedef struct {
    char pad00[0x10];
    T t;
} S;

extern int PLACE_NAME_LETTER_IsYDone(void *p);

void PLACE_NAME_LETTER_StepY(S *p)
{
    T *q;

    if (PLACE_NAME_LETTER_IsYDone(p) == 1) {
        return;
    }
    q = &p->t;
    q->f04 = q->f04 + (q->f0c + q->f14 / 2.0f);
    q->f0c = q->f0c + q->f14;
    q->f2c = q->f2c - 1;
    if (q->f2c == 0) {
        q->f04 = q->f1c;
    }
}
