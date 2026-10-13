/*
 * function: WaitResult
 * address:  0x0270738C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735AAC  0x02735AAC  data twl a2
 */

typedef unsigned int u32;

extern u32 data_02735AAC[];
extern u32 OS_ReceiveMessage(u32 *q, u32 *msg, u32 flags);

u32 WaitResult(void) {
    u32 msg;
    OS_ReceiveMessage(data_02735AAC, &msg, 1);
    return msg;
}
