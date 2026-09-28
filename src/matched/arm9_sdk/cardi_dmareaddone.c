/*
 * function: CARDi_DmaReadDone
 * address:  0x02077084
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02076CD0   0x02076CD0  arm
 *   func_02077518   0x02077518  arm
 *   func_02076DA0   0x02076DA0  arm
 *   func_020762A8   0x020762A8  arm
 *   cardi_common    0x02150200  data  a4
 *
 * Original (48 bytes):
 *   push {r3, lr}
 *   bl   #0x02076CD0
 *   bl   #0x02077518
 *   mov  r0, #8
 *   bl   #0x02076DA0
 *   ldr  r0, [pc, #0x10]   ; &cardi_common
 *   mov  r2, #0
 *   ldr  r1, [r0]
 *   str  r2, [r1]
 *   bl   #0x020762A8
 *   pop  {r3, pc}
 */

typedef unsigned int u32;

typedef struct
{
    u32 *cmd;
} CARDiCommon;

extern void func_02076CD0(void);
extern void func_02077518(void);
extern void func_02076DA0(int mode);
extern void func_020762A8(void);
extern CARDiCommon cardi_common;

void CARDi_DmaReadDone(void)
{
    func_02076CD0();
    func_02077518();
    func_02076DA0(8);
    *cardi_common.cmd = 0;
    func_020762A8();
}
