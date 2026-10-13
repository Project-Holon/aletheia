/*
 * function: func_021F23F8
 * address: 0x021F23F8
 * packet: pkt_ov032_021F23F8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov032/beacon_view.c and filed here.
 *
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 */

struct PrintSys;
typedef unsigned int   u32;
extern u32 func_0201C4E4(struct PrintSys *ps);
u32 func_021F23F8(char *p);

/*
 * Byte-correct; the only wildcards are the bls to two unlabelled arm9
 * leaves, the integrator's (blocker: no witness outside the range). Verified leaf C
 * (both EXACT, thumb, `one --thumb` with no --region):
 *   0x020275B8 (12 bytes incl. pool word 0x0B0E):
 *     typedef unsigned char u8;
 *     void func_020275B8(char *p, u8 v) { p[0xb0e] = v; }
 *   0x020275D0 (12 bytes incl. pool word 0x0B0C):
 *     void *func_020275D0(char *p) { return p + 0xb0c; }
 * 0x53 is ov083's id (func_021F5260/func_021F5368 are ov083 children).
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/func_020275A8,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 */
u32 func_021F23F8(char *p)
{
    return func_0201C4E4(*(struct PrintSys **)(p + 0xB4));
}
