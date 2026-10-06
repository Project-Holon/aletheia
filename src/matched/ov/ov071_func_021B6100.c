/*
 * function: func_021B6100
 * address:  0x021B6100
 * packet:   pkt_ov071_021B6100
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed 2026-10-05 (recoup integrator): func_021B652C and func_021B6540 return int (their matched definitions); with void declarations the 0x30 constant was copied from r4; with the real return type the
 *   bytes are EXACT in c99 and c.
 * checks:   1 every callee's arity from its own ov071 file or a matched caller (func_0203159C/func_02082BCC from ov071_021B730C, func_020056A0 from ov071_021B8EE8, func_0207D63C from ov091_021B6F28, func_0207D534/02043534/020435F4 from ov088_021B98BC); 2 no twin with the 0xF1 byte store or the 0xF8/0xFC/0x100 self-links; ov088_021B98BC gives the register block; 3 o as int, as a Wk struct, 0x30 as an int local, the byte store through s8, 0x12Cu, the 0x12C/0x130 pair as an array: no change; 4 inline setter for the byte (u8 and int parameter) no change; permuter 300 --types found nothing below 2 B; 5 ls docs/idioms re-read, none fits
 * blocker:  ARM9 func_0204363C remains unresolved at THM_CALL +0x74;
 *   no current matched ARM9 source/unit shard witness. Ilias owns this leaf.
 *   Previous 02010F7C blocker is now resolved by src/matched/arm9/func_02010F7C.c
 *   and layout/matched/arm9/pkt_02010F18.json, checked before caller compile.
 * renewed pass: Wave76 R17, one fixed-flag one compile, no sweeps/permuter.
 *   Enum 0x30 local plus inline byte setter retains 336/2, 26/27 relocs.
 *   Stopped immediately on the new owner blocker; no ARM9 leaf compiled
 *   or further caller retries. Baseline retained until that witness exists.
 *
 * 2026-10-05 (wave P7 lane V2): 2 B residue unchanged (336 B, 27/27 relocs). Tried:
 *   0x30 as an int/u8/unsigned local k used for the byte and for both 0x128 and 0x12C
 *   (o + k + 0xF8, o + k + 0xFC); k for 0x128 only; two separate locals (k for byte and
 *   0x128, j for 0x12C); k assigned after the byte store; all copy 0x30 from r4 at +0xF0
 *   ("adds r1,r4,#0") where the original has "movs r1,#0x30". Six per-function pragmas
 *   (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling,
 *   peephole off): all still DIFF. Note the original splits every big offset as a live
 *   or literal base plus an adds (0x13C = 0x61+0xDB, 0x130 = 0x61+0xCF, 0x100 = 0xA+0xF6,
 *   0x128 = r4+0xF8) and only 0x12C re-materialises its base instead of copying r4.
 *   Callee arities checked against matched callers: no mismatch found.
 *
 * recoup 2026-10-05 (lane R2): 2 B residue unchanged (336 B, 27/27 relocs, +0xF0
 *   `adds r1,r4,#0` vs `movs r1,#0x30`). Twin search: no matched ov function has the
 *   0xF1 byte store plus 0x12C/0x130 pair (grep of func_0203159C + func_02031324 +
 *   func_020056A0 in src/matched/ov, same hits as before). Tried, all unchanged: (1) o as a
 *   word array, ((int *)o)[0x4B]/[0x4C]/[0x4A]; (2) a real struct W with fields at 0x30,
 *   0x34, 0xF0, 0xF1, 0xF8, 0xFC, 0x100, 0x128, 0x12C, 0x130 (prototypes take void *);
 *   (3) k = 0x30 set just before the 0x128 call and used as o + k + 0xF8, byte store
 *   literal; (4) 0x12C through a pointer local q = (int *)(o + 0x12C); (5) byte store
 *   through b = o + 0xF1; (6) call results held in a local r and stored from it;
 *   (7) one scratch int n reused: n = 0x13C (alloc and memset size), then n = 0x30 (byte
 *   store), with and without o + n + 0xF8; (8) pragma pairs opt_common_subs+opt_propagation
 *   off and opt_lifetimes+opt_common_subs off. Observation: the 0x30/0x61/0xA bases of the
 *   split offsets are the smallest function constant with an encodable remainder; with the
 *   byte store removed 0x12C becomes 0x61 + 0xCB, so the 0x30 base comes from that
 *   store's constant and the backend copies it from r4 whenever r4 holds it. Idioms read:
 *   a-repeated-small-constant-takes-a-callee-saved-register, a-small-constant-is-
 *   rematerialised-off-a-zero-register-unless-an-argument-shares-it, a-constant-kept-in-a-
 *   register-after-a-switch-is-assigned-in-every-arm, a-width-stored-in-the-handle-temp-it-
 *   replaces-keeps-the-original-colours, a-compound-product-on-a-byte-offset-local-gives-
 *   the-index-the-late-colour (none applies). 13 compiles.
 *
 * DIFF: 2 bytes at +0x00F0. The original builds the 0x12C offset for the
 * first func_02031324 store as `movs r1, #0x30; adds r1, #0xfc`; ours copies
 * the 0x30 already in r4 (from the o[0xF1] = 0x30 store) with `adds r1, r4,
 * #0`. The later 0x128 offset is `adds r4, #0xf8` off that same r4 in both.
 * Everything else, the volatile DISPCNT block included, is byte-exact.
 * runs: 1 + 3 sweeps (4 + 3 + 2) + permuter
 * volatile: 0x021B612E/0x021B6142 (DISPCNT) and 0x021B613C/0x021B614A (DB_DISPCNT) re-read the register after each store
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02031324  0x02031324  arm
 *   func_02028470  0x02028470  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_021B69AC  0x021B69AC  thumb  ov071
 *   func_021B64D0  0x021B64D0  thumb  ov071
 *   func_021B652C  0x021B652C  thumb  ov071
 *   func_021B6540  0x021B6540  thumb  ov071
 *   func_021B65B4  0x021B65B4  thumb  ov071
 *   func_021B6644  0x021B6644  thumb  ov071
 *   func_021B6790  0x021B6790  thumb  ov071
 *   func_021B6844  0x021B6844  thumb  ov071
 *   func_021B68E0  0x021B68E0  thumb  ov071
 *   func_021B699C  0x021B699C  thumb  ov071
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S02021D50;
struct W6844;
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0204363C(u32 a);
extern void func_0203064C(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02010F7C(u32 heap);
extern void *func_02031324(int a0);
extern void func_02028470(u8 *p, u32 v);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021B69AC(u8 *a, u8 *b);
extern void func_021B64D0(void);
extern void func_021B652C(void);
extern unsigned int func_021B6540(int *p);
extern void func_021B65B4(void);
extern void func_021B6644(void *a, void *b);
extern void func_021B6790(int *p);
extern void func_021B6844(struct W6844 *p);
extern void func_021B68E0(int *p);
extern void func_021B699C(void *unused, struct S02021D50 **p);

int func_021B6100(struct Obj0203159C *ctx, int unused, u8 *arg)
{
    u8 *o;

    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0207D63C(0x04000050, 4, 8, 0xF, 0xF);
    func_0207D63C(0x04001050, 4, 8, 0xF, 0xF);
    func_0204363C(1);
    func_0203064C(1, 0x61, 0x70000);
    o = func_0203159C(ctx, 0x13C, 0x61);
    func_02082BCC(o, 0, 0x13C);
    o[0xF1] = 0x30;
    func_021B69AC(o, arg);
    *(int *)(o + 0x30) = (int)func_020490F4(0x27, 0x61);
    func_021B64D0();
    func_021B652C();
    func_021B6540((int *)o);
    func_021B65B4();
    func_021B6644(o, o);
    func_021B6790((int *)o);
    func_021B6844((struct W6844 *)o);
    func_021B68E0((int *)o);
    *(int *)(o + 0x34) = (int)func_02010F7C(0x61);
    *(int *)(o + 0x12C) = (int)func_02031324(0x61);
    *(int *)(o + 0x130) = (int)func_02031324(0x61);
    func_02028470(o + 0x38, 6);
    *(u32 *)(o + 0x128) = func_020056A0((void (*)(void))func_021B699C, o, 0xA);
    func_0203D34C(0, 0x61);
    *(u8 **)(o + 0xF8) = arg;
    *(u8 **)(o + 0xFC) = o;
    *(u8 **)(o + 0x100) = o + 0xF0;
    return 1;
}
