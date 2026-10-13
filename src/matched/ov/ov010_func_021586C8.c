/*
 * function: INTRUDE_COMM_GetRequesterStatus
 * address:  0x021586C8
 * packet:   pkt_ov010_021586C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   func_02026478  0x02026478  thumb
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   func_02008500  0x02008500  thumb
 */

typedef unsigned int   u32;
struct Rec44;
struct Sub24;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern u32 func_02026478(void *obj);
extern int INTRUDE_COMM_IsSessionActive(void *);
extern int INTRUDE_COMM_GetRequesterNetId(void *, void *);
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern void func_02008500(void *a, void *b);

int INTRUDE_COMM_GetRequesterStatus(int a, int b)
{
    char *q = (char *)INTRUDE_COMM_GetWorkIfRunning(a);
    int r = func_02026478((void *)a);
    if (q == 0 || INTRUDE_COMM_IsSessionActive(q + 0x1AC) == 0)
        return 0;
    func_02008500(GAME_DATA_GetPlayerStatus((struct Sub24 *)r, INTRUDE_COMM_GetRequesterNetId(q, q + 0x1AC)), (void *)b);
    return 1;
}
