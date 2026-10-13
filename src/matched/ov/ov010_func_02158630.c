/*
 * function: INTRUDE_COMM_GetRequestState
 * address:  0x02158630
 * packet:   pkt_ov010_02158630
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb
 *   INTRUDE_COMM_IsRequestFromSelf  0x02176258  thumb
 *   func_02026478  0x02026478  thumb
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb
 */

extern int INTRUDE_COMM_GetWorkIfRunning(int);
extern int INTRUDE_COMM_IsSessionActive(int);
extern int INTRUDE_COMM_IsRequestFromSelf(int);
typedef unsigned int   u32;
extern u32 func_02026478(void *obj);
extern int INTRUDE_COMM_HasUnlockFlags(void *p);

int INTRUDE_COMM_GetRequestState(int a)
{
    int q = INTRUDE_COMM_GetWorkIfRunning(a);
    if (q == 0)
        return 0;
    if (INTRUDE_COMM_IsSessionActive(q + 0x1AC) == 1) {
        if (INTRUDE_COMM_IsRequestFromSelf(q) == 1)
            return 2;
        if (INTRUDE_COMM_HasUnlockFlags((void *)func_02026478((void *)a)) == 0)
            return 1;
        return 3;
    }
    return 1;
}
