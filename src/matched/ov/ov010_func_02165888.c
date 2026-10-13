/*
 * function: func_02165888
 * address:  0x02165888
 * packet:   pkt_ov010_02165888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02165888 0x02165888 thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   GAME_BEACON_GetNextNewLogIndex 0x02026CA0 thumb
 *   GAME_BEACON_GetLog 0x02026C1C thumb
 *   func_02165960 0x02165960 thumb ov010
 *   GAME_BEACON_ClearNewFlag 0x02026CE0 thumb
 */

struct RtcTime;
extern void func_0203F4CC(struct RtcTime *time);
extern int GAME_BEACON_GetNextNewLogIndex(int *);
extern void *GAME_BEACON_GetLog(int n);
struct Queue;
struct Rec;
extern int func_02165960(struct Queue *q, struct Rec *rec, int tag, int mode);
typedef unsigned int   u32;
extern void GAME_BEACON_ClearNewFlag(u32 n);

int func_02165888(int a0)
{
    int t[3];
    int cur;
    int n;
    int h;
    int k;
    int r;

    n = 0;
    cur = 0;
    func_0203F4CC((struct RtcTime *)t);
    h = (unsigned short)((t[0] << 8) | t[1]);
    for (;;) {
        k = GAME_BEACON_GetNextNewLogIndex(&cur);
        if (k == 0x1e) {
            break;
        }
        r = func_02165960((struct Queue *)a0, (struct Rec *)((int)GAME_BEACON_GetLog(k)), h, 0);
        if (r == 0x1e) {
            break;
        }
        GAME_BEACON_ClearNewFlag(k);
        n++;
    }
    return n;
}
