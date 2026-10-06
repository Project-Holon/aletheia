/*
 * function: func_021C446C
 * address: 0x021C446C
 * packet: pkt_ov093_021C446C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: unlabelled thunk 021C4B8C and veneers 021C45E4, 021C45F4,
 * 021C4604 have no attested targets. The thunk loads target 0x06898D54;
 * the veneers load 0x0689CC84, 0x0689CC8C, 0x0689CC8C respectively,
 * outside every image region. Its 376 compiled bytes are concrete-correct.
 * Trailing extent holds Thumb linker veneers 021C45E4, 021C45F4, 021C4604.
 * 2026-10-05 (D9 lane 02): 021C4B8C is `adds r1,r0,#0; ldr r0,[pc]; ldr r3,[pc]; bx r3` with pool words 0x021C4B9D and 0x06898D55: a linker thunk to a function outside the image, not C
 *   (a C call through the constant gives push/blx/pop, 14 bytes differ). The veneers are the same kind. Stays MATCH*.
 * 2026-10-05 (D9r lane16): 021C4B8C is NOT a linker thunk. It is C: a Thumb
 *   tail call `func_06898D54(func_021C4B9C, p)` into the matched ov095 walker
 *   (ov095 lives in VRAM at 0x0689xxxx). func_021C4B9C (new EXACT witness,
 *   src/matched/ov/ov093_func_021C4B9C.c) is the callback that swaps args and
 *   tail calls func_021C4BAC. func_021C4B8C itself verifies MATCH (pending
 *   file) only because the ABS32 to 021C4B9C needs a manifest witness; it is
 *   EXACT once the integrator writes the 021C4B9C shard. 021C45E4, 021C45F4,
 *   021C4604 are real linker veneers (bx pc; nop; ldr ip,[pc]; bx ip) to the
 *   matched ov095 functions 0x0689CC84 / 0x0689CC8C / 0x0689CC8C; the harness
 *   already attests them (veneer class). After the shards land, the only
 *   residue here should be the 4B8C call. Concrete bytes unchanged.
 * symbols:
 *  func_021C43F0 0x021C43F0 thumb ov093
 *  func_021C4744 0x021C4744 thumb ov093
 *  func_021CD4B0 0x021CD4B0 thumb ov093
 *  func_021C4D1C 0x021C4D1C thumb ov093
 *  func_021BC2B0 0x021BC2B0 thumb ov093
 *  func_021C4838 0x021C4838 thumb ov093
 *  func_021C493C 0x021C493C thumb ov093
 *  func_021C4B8C 0x021C4B8C thumb ov093
 *  func_021C4C24 0x021C4C24 thumb ov093
 *  func_021C45E4 0x021C45E4 thumb ov093
 *  func_021C45F4 0x021C45F4 thumb ov093
 *  func_021C4604 0x021C4604 thumb ov093
 *  func_021D6408 0x021D6408 thumb ov093
 *  func_021D6E88 0x021D6E88 thumb ov093
 *  func_021D5440 0x021D5440 thumb ov093
 *  func_021C4614 0x021C4614 thumb ov093
 *  func_021D701C 0x021D701C thumb ov093
  * note 2026-10-05 (D8 lane16): re-verified MATCH*. Callee 0x021C4B8C is a Thumb thunk to 0x06898D54 (veneer-like, outside every image region) and 021C45E4/F4/604 are veneers; not C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C43F0(u8 *, u8 *);
extern void func_021C4744(u8 *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C4D1C(u8 *p, void *it);
extern int func_021BC2B0(u8 *);
extern int func_021C4838(u8 *, u8 *, u8 *);
extern int func_021C493C(u8 *, u8 *);
extern void func_021C4B8C(u8 *);
extern void func_021C4C24(u8 *);
extern void func_021C45E4(u8 *);
extern u8 *func_021C45F4(u8 *);
extern u8 *func_021C4604(u8 *);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
extern u8 func_021D5440(u8 *);
extern void func_021C4614(u8 *);
extern void func_021D701C(void);
int func_021C446C(u8 *p)
{
    u8 *a;
    u8 *q;
    int result = 0;
    a = *(u8 **)(p + 0x854);
    if (p[0x77e] == 0) {
        func_021C43F0(p, a);
        p[0x77e] = 1;
        func_021C4744(p);
    }
    switch (p[0x77e]) {
    case 0: break;
    case 1:
        p[0x77e]++;
        func_021CD4B0(*(void **)(p + 12), 0x56, 0);
        result = 0;
        if (func_021C4D1C(p, a)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 2:
        p[0x77e]++;
        if (func_021C4838(p, a, (u8 *)0x76)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 3:
        p[0x77e]++;
        if (func_021C493C(p, a)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 4:
        p[0x77e]++;
        func_021C4B8C(p);
        func_021C4C24(p);
    case 5:
        p[0x77e]++;
        if (func_021C4838(p, a, (u8 *)0x77)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 6:
        func_021C4838(p, a, (u8 *)0x78);
        p[0x77e]++;
        func_021C45E4(a);
        q = func_021C45F4(a);
        while (q) {
            func_021D6408(q);
            func_021D6E88(q);
            func_021CD4B0(*(void **)(p + 12), 0x2e, func_021D5440(q));
            q = func_021C4604(a);
        }
        func_021C4614(p);
        func_021D701C();
        if (*(u32 *)(p + 16) < 9999) (*(u32 *)(p + 16))++;
        p[0x77e] = 0;
        *(u32 *)(p + 0x774) = 0;
        return 0;
    default: break;
    }
    return result;
}
