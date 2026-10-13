/*
 * function: FLDMMDL_MOVECODE_SwingStepWaitInterval
 * address: 0x0219A7C4
 * packet: pkt_ov021_0219A7C4
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov021/unit_02198D3C.c and filed here.
 */

typedef unsigned char  u8;
int FLDMMDL_MOVECODE_SwingStepWaitInterval(int a, u8 *p);

int FLDMMDL_MOVECODE_SwingStepWaitInterval(int a, u8 *p) { int v = *(int *)(p + 4) + 1; *(int *)(p + 4) = v; if (v < 0x18) return 0; p[2] = 3; return 1; }
