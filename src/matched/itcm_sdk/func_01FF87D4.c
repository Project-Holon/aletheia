/*
 * function: SCFGi_SwitchCpuSpeed
 * address:  0x01FF87D4
 * packet:   pkt_01FF87D4
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      SCFGi_SwitchCpuSpeed, sdk/TwlSDK/lib/ARM9-TS/Rom/libscfg.TWL.HYB.a
 *           member scfg_proc.o (48 bytes, .itcm), declared
 *           `asm void SCFGi_SwitchCpuSpeed(SCFGCpuSpeed cpuSpeed)` at
 *           sdk/TwlSDK/build/libraries/scfg/ARM9.TWL/src/scfg_proc.c:74 -- the
 *           original is inline assembly, so this is too, and the constants
 *           below are the SDK's own (REG_CLK_ADDR and
 *           REG_SCFG_CLK_CPUSPD_MASK are 0x04004004 and 1, the pair crt0.FLX.c
 *           also drives with ldrh/strh).  DWARF agrees: no locals at all, the
 *           sole formal `cpuSpeed` is a 4-byte enum (SCFG_CPU_SPEED_1X=0,
 *           SCFG_CPU_SPEED_2X=1) at fbreg+0, and the four decoded line rows
 *           cover exactly the four code words 0x00..0x0C of scfg_proc.c:77..83,
 *           none of the literal word at 0x2C.  A C body cannot reach these
 *           bytes: mwccarm 1.1p1 -O4,p deletes an empty delay loop outright
 *           (measured: `u32 wait = (cpuSpeed ? 20 : 10); while (wait >= 4)
 *           wait -= 4;` compiles to 32 bytes with the loop gone, and -O2 keeps
 *           it but as `sub; cmp r0, #4; bcs`, three instructions where the
 *           image has the folded two).
 */

typedef unsigned int u32;

typedef enum
{
    SCFG_CPU_SPEED_1X = 0,
    SCFG_CPU_SPEED_2X = 1
} SCFGCpuSpeed;

#define REG_CLK_ADDR                 0x04004004
#define REG_SCFG_CLK_CPUSPD_MASK     1

#define SCFGi_SWITCH_CPU_WAIT        10
#define SCFGi_SWITCH_CPU_WAIT2       (SCFGi_SWITCH_CPU_WAIT * 2)

/* hand-written in the original: SDK SCFGi_SwitchCpuSpeed is declared asm in scfg_proc.c; the empty delay loop is deleted by mwccarm */
asm void SCFGi_SwitchCpuSpeed(SCFGCpuSpeed cpuSpeed)
{
    ldr     r2, =REG_CLK_ADDR
    ldrh    r1, [r2]

    bic     r1, r1, #REG_SCFG_CLK_CPUSPD_MASK
    orr     r1, r0, r1
    strh    r1, [r2]

    cmp     r0, #SCFG_CPU_SPEED_1X
    moveq   r0, #SCFGi_SWITCH_CPU_WAIT
    movne   r0, #SCFGi_SWITCH_CPU_WAIT2

@switch_cpu_wait:
    subs    r0, r0, #4
    bcs     @switch_cpu_wait
    bx      lr
}
