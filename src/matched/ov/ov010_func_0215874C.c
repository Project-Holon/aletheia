/*
 * function: INTRUDE_COMM_ClearHoldMode
 * address: 0x0215874C
 * packet: pkt_ov010_0215874C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning 0x02158344 thumb ov010
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
typedef unsigned char u8;
typedef struct { u8 low:2; u8 flag:2; u8 high:4; } Flag;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
void INTRUDE_COMM_ClearHoldMode(void *p)
{
    u8 *q = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)p);
    if (q != 0)
        ((Flag *)(q + 0x904))->flag = 0;
}
