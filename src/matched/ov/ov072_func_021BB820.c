/*
 * function: TOWNMAP_GRH_InitBgLayers
 * address:  0x021BB820
 * packet:   pkt_ov072_021BB820
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition
 *   tail-returns ARC_UTIL_UploadBgChar). With the void declaration the later register zeros were
 *   copied from the pooled zero web; with the real return type they are fresh movs. EXACT
 *   in c99 and c.
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
 * renewed: Wave75 R29, 3 iteration + 2 check runs. Enum stack-zero72 bytes and enum palette-size74 worse; loop-init after first call flat68. Const BG table CCERR repaired with readonly callee prototype, then flat68. Own arm9 unit_02049B40 and ARC_UTIL_UploadBgCharFromHandle/498F4 re-read (6/7 args, u16 final heap); fresh ov070/071 callers and idioms. Earlier permuter300 remains consumed; best C retained.
 * Graphics init; the seven 0x28-byte BG entries at sTownMapGrhBgTable are the
 * ones TOWNMAP_GRH_ExitBgLayers tears down.
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
 * recoup 2026-10-05 (lane R7): all flat at 328 B / 68 differ: scratch t = 0 then t = 0x1c0 with
 * t as the stack zeros of calls 5..0xf; the same with t in only the (6,5) and 0xf calls, in a
 * block; z in all three zero slots of (6,5) or of 0xf; u32 heap with u32 callee heap (340 B, 200
 * worse). Probe: with the B40 r2 zero and the C14 zeros changed to non-zero values, 0x20 and
 * 0x1c0 land in r7/r6 as in the original, so only two residues are left: (a) at the 0xf call r3
 * is `adds r3,r6,#0` where the original has `movs r3,#0`, (b) the heap store of the (6,5) call
 * comes last instead of first. Every named zero is constant-propagated, so t/z do not make a
 * separate value. Twin search: grep -l func_02049B40 src/matched/ov (ov111 021C72FC, ov209
 * 021BC574, ov210 021BC5DC, ov018 0217D720, ov219 021849A4 share the call forms, none has the
 * 6,5 / 0xf / B40 / C14 run); callees 02049658/020498F4 read in arm9 (no truncation of e, f).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B40  0x02049B40  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   sTownMapGrhDispConfig     0x021BBBCC  data  a4
 *   sTownMapGrhBgTable     0x021BBC28  data  a4
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

extern struct Ent sTownMapGrhBgTable[];
extern char sTownMapGrhDispConfig;

extern void MI_CpuFill8(void *p, int v, int n);
extern void BG_SYS_Create(u16 heap);
extern void BMP_WIN_Init(u16 heap);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void ARC_TOOL_DeleteHandle(void *h);

void TOWNMAP_GRH_InitBgLayers(void *p, u16 heap)
{
    int i;
    u32 id;
    void *h;

    i = 0;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)(&sTownMapGrhDispConfig));
    for (; i < 7; i++) {
        id = sTownMapGrhBgTable[i].id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)(&sTownMapGrhBgTable[i].tmpl), (u8)sTownMapGrhBgTable[i].mode);
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
    BG_SYS_Init((int)1, (int)0, (int)1, (int)0);
    ARC_TOOL_DeleteHandle(h);
}
