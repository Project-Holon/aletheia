/*
 * function: ENCEFF_UpdateRipple
 * address: 0x021F57D4
 * packet: pkt_ov078_021F57D4
 * region: ov078
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ov021 0x021CF51C unlabelled accessor, owned by the integrator.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF51C (no label witness). Filed src/matched/ov/ov021_func_021CF51C.c (EXACT, 4-byte accessor); it needs a manifest shard to count as a witness.
 * symbols:
 *   ENCEFF_GetEffect 0x021CF51C thumb ov021
 *   G3X_SetClearColor 0x0207DD24 arm
 *   ENCEFF_DrawScreenTexEffect 0x021F52D8 thumb ov075
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 ENCEFF_GetEffect(u32 *p);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void ENCEFF_DrawScreenTexEffect(u32 *);
void ENCEFF_UpdateRipple(void *p) {
    u32 h = ENCEFF_GetEffect(p);
    G3X_SetClearColor(0x4210,31,0x7FFF,0,0);
    ENCEFF_DrawScreenTexEffect((u32 *)h);
}
