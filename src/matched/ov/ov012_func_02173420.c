/*
 * function: UNION_COMM_ReleaseWorks
 * address:  0x02173420
 * packet:   pkt_ov012_02173420
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   UNION_APP_Delete  0x02183BE0  thumb  ov022
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    struct { int pad[3]; int f0c; } *head;
    u8 pad[0x3528 - 4];
    void *f3528;
    u8 pad2[0x3534 - 0x352C];
    void *f3534;
    void *f3538;
    void *f353C;
    void *f3540;
    void *f3544;
    u8 pad3[0x355C - 0x3548];
    void *f355C;
} Work;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void UNION_APP_Delete(void *p);
extern void COLOSSEUM_Delete(int *p, int x);

void UNION_COMM_ReleaseWorks(Work *w)
{
    w->f353C = 0;
    if (w->f3540 != 0) {
        func_020307B0(w->f3540);
        w->f3540 = 0;
    }
    if (w->f3544 != 0) {
        func_020307B0(w->f3544);
        w->f3544 = 0;
    }
    if (w->f3538 != 0) {
        func_020307B0(w->f3538);
        w->f3538 = 0;
    }
    if (w->f3534 != 0) {
        func_020307B0(w->f3534);
        w->f3534 = 0;
    }
    if (w->f3528 != 0) {
        UNION_APP_Delete(w->f3528);
        w->f3528 = 0;
    }
    if (w->f355C != 0) {
        COLOSSEUM_Delete(w->f355C, w->head->f0c);
        w->f355C = 0;
    }
}
