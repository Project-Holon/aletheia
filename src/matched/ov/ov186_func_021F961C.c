/*
 * function: BR_PROC_SYS_SetPendingFlag
 * address: 0x021F961C
 * packet: pkt_ov186_021F961C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov186/br_proc_sys.c and filed here.
 */

typedef unsigned int u32;
void BR_PROC_SYS_SetPendingFlag(u32 *a, u32 *b);

void BR_PROC_SYS_SetPendingFlag(u32 *a, u32 *b) { if (*a == 1) *(u32 *)b[6] = 1; }
