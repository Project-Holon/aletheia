/*
 * function: func_021F565C
 * address: 0x021F565C
 * packet: pkt_ov078_021F565C
 * region: ov078
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov021 callee 021CF59C (12-byte thunk, no label) is unresolved. Nothing to change in the source.
 * blocker: ov021 0x021CF59C unlabelled overlay-ID thunk, owned by Ilias.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF59C (no label witness). It is a 12-byte ARM-style thunk inside the ov021_func_021CF580 extent (ldr r1,[pc]; ldr r3,[pc]; bx r3 with r1 = 0x4B, target func_021CF564): veneer-like, not C. Needs a label in layout.
 * symbols:
 *   d_021F5BBC 0x021F5BBC data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF59C 0x021CF59C thumb ov021
 *   func_021F529C 0x021F529C thumb ov075
 *   func_021F5AFC 0x021F5AFC thumb ov078
 *   func_021F5800 0x021F5800 thumb ov078
 */
typedef struct { int x,y,z; } Vec;
extern const Vec d_021F5BBC;
extern int func_02189A08(int);
extern void func_021CF59C(void *);
extern void *func_021F529C(void *, const Vec *, void (*)(void), void (*)(void));
extern void func_021F5AFC(void);
extern void func_021F5800(void);
void *func_021F565C(void *p, int b) {
    Vec v = d_021F5BBC;
    func_021CF59C((void *)func_02189A08(b));
    return func_021F529C(p, &v, func_021F5AFC, func_021F5800);
}
