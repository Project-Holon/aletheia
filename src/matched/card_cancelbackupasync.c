/*
 * function: CARD_CancelBackupAsync
 * address:  0x02076B98
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988   0x02087988  arm
 *   func_0208799C   0x0208799C  arm
 *   cardi_common    0x02150200  data  a4
 *
 * Original (36 bytes):
 *   push {r3, lr}
 *   bl   #0x02087988
 *   ldr  r1, [pc, #0x10]   ; &cardi_common
 *   ldr  r2, [r1, #4]
 *   orr  r2, r2, #0x40
 *   str  r2, [r1, #4]
 *   bl   #0x0208799C
 *   pop  {r3, pc}
 */

typedef unsigned int u32;

typedef struct
{
    void *cmd;
    u32 flags;
} CARDiCommon;

extern int func_02087988(void);
extern void func_0208799C(int state);
extern CARDiCommon cardi_common;

void CARD_CancelBackupAsync(void)
{
    int state = func_02087988();
    cardi_common.flags |= 0x40;
    func_0208799C(state);
}
