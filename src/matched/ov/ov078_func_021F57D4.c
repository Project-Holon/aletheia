/*
 * function: func_021F57D4
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
 *   func_021CF51C 0x021CF51C thumb ov021
 *   func_0207DD24 0x0207DD24 arm
 *   func_021F52D8 0x021F52D8 thumb ov075
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_021CF51C(u32 *p);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_021F52D8(u32 *);
void func_021F57D4(void *p) {
    u32 h = func_021CF51C(p);
    func_0207DD24(0x4210,31,0x7FFF,0,0);
    func_021F52D8((u32 *)h);
}
