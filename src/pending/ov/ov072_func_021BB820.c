/*
 * function: func_021BB820
 * address:  0x021BB820
 * packet:   pkt_ov072_021BB820
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * checks: 1 own 0203F8F4/45088 one, 3FC28 one, 3FCA0 three, 40588 two, 490F4 two, 49B68 six, 49658/498F4 seven, 49B40 six, 40C14 four; SDK82BCC three and49238 one confirmed by matched ov0729E38 caller; 2 same-region/sibling graphics callers refreshed; 3 enum register-zero prototype variants and unsigned-long u32 each compile328/68 flat; 4 enum-zero and sub-word parameter idioms read, no fresh improving lever; 5 full idiom directory and matched neighbours refreshed. Prior permuter300 remains spent. Next hypothesis: genuine palette request storage type for the tail zero web.
 * retry: Wave76 R18 final retry, three fixed one runs; original best328/68 retained, all22 relocations resolved.
 *
 * Residual (328/328 bytes, 35 lines, all relocations resolve): from the
 * sixth handle call on (func_02049658(h, 6, 5, 0, 0, 0, heap)) the original
 * ends the callee-saved zero (r6, which feeds only the stack-argument zeros)
 * at the [sp+4] store of func_020498F4(h, 0xf, ...), then puts 0x1C0 in r6
 * and 0x20 in r7 for both func_02049B40 calls and materialises every later
 * register-argument zero with movs. Ours keeps the zero web in r6 to the
 * end (r3 of the 0xf call, r2 of the first B40, r1/r3 of C14 are copies of
 * r6), so 0x20 is rematerialised per call and the heap store of the (6,5)
 * call is scheduled last instead of first. Everything before +0xE2 is
 * byte-identical. Next thing to try: a spelling that ends the zero's live
 * range at the (0xf,5) call (the stack zeros of the last three handle calls
 * as a separate value), which no type change above reached.
 *
 * renewed: Wave75 R29, 3 iteration + 2 check runs. Enum stack-zero72 bytes and enum palette-size74 worse; loop-init after first call flat68. Const BG table CCERR repaired with readonly callee prototype, then flat68. Own arm9 unit_02049B40 and sub_02049658/498F4 re-read (6/7 args, u16 final heap); fresh ov070/071 callers and idioms. Earlier permuter300 remains consumed; best C retained.
 * Graphics init; the seven 0x28-byte BG entries at d_021BBC28 are the
 * ones func_021BB968 tears down.
 *
 * note 2026-10-05 (wave P7 lane V1): no matched twin exists (ov021 02192FA4, ov218 021B9964,
 * ov173 021B66BC, ov091 021B71E4 share only the 02049B40/02049658 call forms). Prototypes now
 * follow the matched house forms (void *h, u16 heap, u16 final argument): still 328 B, 68 differ,
 * same residue (zero web in r6 copied into r3/r2/r1 for the 0xf, B40 and C14 calls; 0x1c0/0x20
 * land in r7/rematerialised). Tried, all flat at 68: each of opt_lifetimes, opt_propagation
 * (288), opt_common_subs (269), opt_dead_assignments, scheduling, peephole off; e parameter u16;
 * e parameter void *; d parameter void * on 0xf call; zero as local z; heap param u16 with u16
 * callees; tail pair and C14 in a static inline. Residue: the original treats the stack zeros
 * and the register zeros as different values, no human source form found.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02049238  0x02049238  arm
 *   d_021BBBCC     0x021BBBCC  data  a4
 *   d_021BBC28     0x021BBC28  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[8]; } BgTemplate;

struct Ent {
    u32 id;
    BgTemplate tmpl;
    u32 mode;
};

extern struct Ent d_021BBC28[];
extern char d_021BBBCC;

extern void func_02082BCC(void *p, int v, int n);
extern void func_0203F8F4(u16 heap);
extern void func_02045088(u16 heap);
extern void func_0203FC28(void *p);
extern void func_0203FCA0(u8 bg, void *tmpl, u8 mode);
extern void func_02040588(u8 bg, int on);
extern void *func_020490F4(u32 id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040C14(int, int, int, int);
extern void func_02049238(void *h);

void func_021BB820(void *p, u16 heap)
{
    int i;
    u32 id;
    void *h;

    i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&d_021BBBCC);
    for (; i < 7; i++) {
        id = d_021BBC28[i].id;
        func_0203FCA0(id, &d_021BBC28[i].tmpl, d_021BBC28[i].mode);
        func_02040588(id, 1);
    }
    h = func_020490F4(0x55, heap);
    func_02049B68(h, 0, 2, 0x6000, 0x2000, heap);
    func_02049B68(h, 0, 2, 0x4000, 0x2000, heap);
    func_02049658(h, 5, 2, 0, 0x10000, 0, heap);
    func_02049658(h, 7, 3, 0, 0x10000, 0, heap);
    func_020498F4(h, 0x11, 2, 0, 0x800, 0, heap);
    func_020498F4(h, 0x10, 3, 0, 0x800, 0, heap);
    func_02049B68(h, 1, 4, 0, 0, heap);
    func_02049658(h, 6, 5, 0, 0, 0, heap);
    func_020498F4(h, 0xf, 5, 0, 0, 0, heap);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, heap);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, heap);
    func_02040C14(1, 0, 1, 0);
    func_02049238(h);
}
