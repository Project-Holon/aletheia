/*
 * function: ENCEFF_BuildRippleKind36
 * address: 0x021F565C
 * packet: pkt_ov078_021F565C
 * region: ov078
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov021 callee 021CF59C (12-byte thunk, no label) is unresolved. Nothing to change in the source.
 * blocker: ov021 0x021CF59C unlabelled overlay-ID thunk, owned by the integrator.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF59C (no label witness). It is a 12-byte ARM-style thunk inside the ENCEFF_LoadOverlays4B4D extent (ldr r1,[pc]; ldr r3,[pc]; bx r3 with r1 = 0x4B, target ENCEFF_LoadOverlay): veneer-like, not C. Needs a label in layout.
 * symbols:
 *   gRippleBurstCameraPos 0x021F5BBC data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlay4B 0x021CF59C thumb ov021
 *   ENCEFF_StartScreenTexEffect 0x021F529C thumb ov075
 *   ENCEFF_StartRippleBurst 0x021F5AFC thumb ov078
 *   ENCEFF_DrawRipple 0x021F5800 thumb ov078
 */
typedef struct { int x,y,z; } Vec;
extern const Vec gRippleBurstCameraPos;
typedef unsigned int   u32;
struct Res021CF;
struct Vec;
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_LoadOverlay4B(struct Res021CF *r);
extern void *ENCEFF_StartScreenTexEffect(void *a, struct Vec *src, u32 b, u32 c);
extern void *ENCEFF_StartRippleBurst(void *a);
extern void ENCEFF_DrawRipple(void);
void *ENCEFF_BuildRippleKind36(void *p, int b) {
    Vec v = gRippleBurstCameraPos;
    ENCEFF_LoadOverlay4B((void *)FIELDMAP_GetEncEff((unsigned char *)b));
    return ENCEFF_StartScreenTexEffect(p, (struct Vec *)(&v), (u32)ENCEFF_StartRippleBurst, (u32)ENCEFF_DrawRipple);
}
