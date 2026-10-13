/*
 * function: INTRUDE_COMM_GetVisitProgress
 * address: 0x021585E0
 * packet: pkt_ov010_021585E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning 0x02158344 thumb ov010
 *   INTRUDE_COMM_GetRequestState 0x02158630 thumb ov010
 * Callee 02158344 consumes incoming r0; the flag extract reads bit 2.
 */
typedef unsigned char u8;
typedef struct { u8 low:2; u8 flag:1; u8 high:5; } Flag;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_COMM_GetRequestState(int);
int INTRUDE_COMM_GetVisitProgress(int p)
{
    u8 *q = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)p));
    if (q == 0)
        return 0;
    if (((Flag *)(q + 0x93F))->flag == 0) {
        if (INTRUDE_COMM_GetRequestState(p) == 3)
            return 2;
        return 1;
    }
    return 3;
}
