/*
 * function: CARDi_InitResourceLock
 * address:  0x0207608C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   cardi_common    0x02150200  data  a4
 *
 * Original (40 bytes):
 *   ldr r2, [pc, #0x1c]   ; &cardi_common
 *   mov r0, #0
 *   mvn r1, #2
 *   str r1, [r2, #0x14]
 *   str r0, [r2, #0x18]
 *   str r0, [r2, #0x24]
 *   str r0, [r2, #0x20]
 *   str r0, [r2, #0x1c]
 *   bx  lr
 */

typedef unsigned int u32;

typedef struct
{
    void *cmd;        /* +0x00 */
    u32 flags;        /* +0x04 */
    char pad8[0x14 - 8];
    u32 f14;          /* +0x14 */
    u32 f18;          /* +0x18 */
    u32 f1c;          /* +0x1c */
    u32 f20;          /* +0x20 */
    u32 f24;          /* +0x24 */
} CARDiCommon;

extern CARDiCommon cardi_common;

void CARDi_InitResourceLock(void)
{
    cardi_common.f14 = ~2u;
    cardi_common.f18 = 0;
    cardi_common.f24 = 0;
    cardi_common.f20 = 0;
    cardi_common.f1c = 0;
}
