/*
 * Calibration target: a known SDK function, reimplemented from the
 * disassembly alone.  Used to pin the harness (tools/match.py) against a
 * compiler we already know built this code: the SDK libraries carry
 * "Metrowerks C/C++ for ARM 4.0.0.1024" in .comment, which is dsi/1.1p1.
 *
 * function: CARD_GetResultCode
 * address:  0x02075DD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Original:
 *   ldr r0, [pc, #8]   ; &cardi_common
 *   ldr r0, [r0]       ; cardi_common.cmd
 *   ldr r0, [r0]       ; cmd->result
 *   bx  lr
 *   .word <cardi_common>
 *
 * Two chained loads off a file-scope object, so the object holds a pointer
 * whose first word is the value returned.  The literal is an ABS32
 * relocation in the object and is wildcarded by the harness.
 */

struct CARDiCommand {
    int result;
};

struct CARDiCommon {
    struct CARDiCommand *cmd;
};

extern struct CARDiCommon cardi_common;

int CARD_GetResultCode(void)
{
    return cardi_common.cmd->result;
}
