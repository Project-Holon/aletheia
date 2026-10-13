/*
 * function: BTLV_TIMER_Redraw
 * address:  0x02209540
 * packet:   pkt_ov094_02209540
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * note: the 0/1 icon offset is an enum-constant ternary (an int spelling flips the bne polarity).
 *
 * symbols:
 *   _ll_udiv    0x0209C00C  arm
 *   sBtlvTimerWarningSeconds  0x0220ABB8  data  a4
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Digits { void *icon; void *m10; void *m1; void *colon; void *s10; void *s1; void *pad; } Digits;
typedef struct Timer {
    int pad0;
    int pad4;
    Digits d[2];
    int pad40[3];
    int limit[2];
    u64 start[2];
    int base[2];
} Timer;
typedef enum { B_FALSE, B_TRUE } Bool;
typedef struct Pair { int v[2]; } Pair;
extern const Pair sBtlvTimerWarningSeconds;
extern u64 func_020870D0(void);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void BTLV_TIMER_Redraw(Timer *p, int idx)
{
    Pair tbl = sBtlvTimerWarningSeconds;
    int icon = idx == 0 ? B_FALSE : B_TRUE;
    int r = p->limit[idx] - (int)(((func_020870D0() - p->start[idx]) * 64) / 33514000);
    int min, sec, m10, m1, s10, s1;
    if (p->d[idx].icon == 0)
        return;
    if (r < 0)
        r = 0;
    min = r / 60;
    sec = r % 60;
    m10 = min / 10;
    m1 = min % 10;
    s10 = sec / 10;
    s1 = sec % 10;
    if (r == tbl.v[idx])
        p->base[idx] = 13;
    CLACT_SetActorAnimSeq(p->d[idx].icon, icon + p->base[idx]);
    if (m10 == 0) {
        CLACT_SetActorDrawEnable(p->d[idx].m10, 0);
    } else {
        CLACT_SetActorDrawEnable(p->d[idx].m10, 1);
        CLACT_SetActorAnimSeq(p->d[idx].m10, m10 + 3 + p->base[idx]);
    }
    if (m10 == 0 && m1 == 0) {
        CLACT_SetActorDrawEnable(p->d[idx].m1, 0);
        CLACT_SetActorDrawEnable(p->d[idx].colon, 0);
    } else {
        CLACT_SetActorDrawEnable(p->d[idx].m1, 1);
        CLACT_SetActorDrawEnable(p->d[idx].colon, 1);
        CLACT_SetActorAnimSeq(p->d[idx].m1, m1 + 3 + p->base[idx]);
        CLACT_SetActorAnimSeq(p->d[idx].colon, p->base[idx] + 2);
    }
    if (m10 == 0 && m1 == 0 && s10 == 0) {
        CLACT_SetActorDrawEnable(p->d[idx].s10, 0);
    } else {
        CLACT_SetActorDrawEnable(p->d[idx].s10, 1);
        CLACT_SetActorAnimSeq(p->d[idx].s10, s10 + 3 + p->base[idx]);
    }
    CLACT_SetActorAnimSeq(p->d[idx].s1, s1 + 3 + p->base[idx]);
}
