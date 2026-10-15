/*
 * function: FIELD_CLOCK_Update
 * address:  0x02168EEC
 * packet:   pkt_ov010_02168EEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   GF_STANDARD_CopyCachedRtc  0x0203F49C  arm
 *   FIELD_CLOCK_CalcElapsed  0x02168F54  thumb
 *   func_02008BE0  0x02008BE0  thumb
 *   FIELD_CLOCK_UpdateMinutes  0x02169068  thumb
 *   FIELD_CLOCK_UpdateDays  0x02169004  thumb
 */

struct Big;
struct Sub02008AECSession;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
typedef unsigned int   u32;
struct RtcDate;
struct RtcTime;
extern void GF_STANDARD_CopyCachedRtc(struct RtcDate *date, struct RtcTime *time);
extern int FIELD_CLOCK_CalcElapsed(int *, int *, int *, int *, int *);
extern void func_02008BE0(struct Sub02008AECSession *s, u32 n);
extern void FIELD_CLOCK_UpdateMinutes(int, int, int *);
extern void FIELD_CLOCK_UpdateDays(int, int);

void FIELD_CLOCK_Update(int a)
{
    int A[4];
    int B[3];
    int y;
    int x;
    int *p = (int *)func_02008B14(GAME_DATA_GetSaveControl((struct Big *)a));
    if (*p == 0)
        return;
    GF_STANDARD_CopyCachedRtc((struct RtcDate *)A, (struct RtcTime *)B);
    if (FIELD_CLOCK_CalcElapsed(p, A, B, &y, &x) == 0)
        return;
    if (x == 0 && y != 0)
        return;
    if (x != 0) {
        func_02008BE0((struct Sub02008AECSession *)p, x);
        FIELD_CLOCK_UpdateMinutes(a, x, B);
    }
    if (y != 0)
        FIELD_CLOCK_UpdateDays(a, y);
}
