/*
 * function: func_021B6BA4
 * address: 0x021B6BA4
 * packet: pkt_ov133_021B6BA4
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF. All calls, argument values, stores and the 0x1858.. object array match
 *   in content; one residue: ours hoists constant 4 into r7 at the first use (movs r7,#4, later
 *   adds r2,r7,#0) while the original issues a fresh movs r2,#4 per call and uses r7 only for
 *   0xd (and -128 as r7-0x8d, modelled as v - 0x8d). The shifted bytes make the rest differ.
 *   Tried: u16/u8/s16/int parameter types on the 02049xxx callees, last arg u16 (as ov021
 *   prototypes), casts on the three r2=4 uses, dropping the first 4. Hoist stays.
 *   2026-10-04 (D2): the whole residue is one hoist. Ours emits movs r7,#4 before the first call and uses it
 *   once (the r2=4 of the 0x10 call at +00A2, third r2=4 use); that then turns every later movs rN,#0 into
 *   adds rN,r6,#0. The original never hoists 4 (every use is a fresh movs) and only loads r7=0xd just before
 *   the 0xd call. Untried here: nothing new; hoist threshold seems to follow the count of equal constants.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged (619 bytes from the hoisted 4 in r7). Tried:
 *   static inline wrappers for the 0x020498F4 / 0x02049658 / 0x02049B68 calls (zero args and H inside the
 *   helper): the 4 hoist goes away but the shared zero in r6 is lost too (521 bytes, worse). So the hoist
 *   and the r6 zero share one CSE region in the original; the 4 uses must be split from it some other way.
 * 2026-10-05 (wave D5 lane 04): DIFF, residue unchanged. New finding: the switch from fresh `movs rN,#0`
 *   to `adds rN,r6,#0` copies starts at the 0x10 call even when that call's 4 is changed to 5 (then the 4
 *   hoist goes away but the zero copies stay). So the 4 hoist is a symptom; the cause is that the CSE'd
 *   constants (0 in r6, 4 in r7) stop being rematerialised from the 8th 02049xxx call on. Tried: literal
 *   0xd and -128 instead of v (hoist stays), int types for the register zero params, int types for the
 *   stack zero params (no change, so the zero CSE is not split by parameter type). Untried: a source shape
 *   that keeps r7 busy (a value live from the start to the 0xd call) so the 4 cannot take a register.
 * 2026-10-05 (wave D6 lane 09): DIFF, residue unchanged (movs r7,#4 hoist, then adds rN,r6 zero copies).
 *   New finding: the switch from fresh movs to register copies is a call count, not a position: with
 *   calls 2..4 deleted the copies still start at the 8th 02049xxx call, and with H replaced by a
 *   constant or the tail after 02041EE4 deleted they also start at the 8th call. Tried: void * type for
 *   the r3 zero parameter of the three loaders, every loader call wrapped in do { } while (0), one
 *   static inline helper holding calls 2..12 (all no change). The original never copies a constant into
 *   an argument register over about 25 calls, so its zeros for r2/r3 are not one value with the r6 zero.
 * 2026-10-05 (wave D7 lane 04): DIFF, residue unchanged (619 bytes). New finding: the switch from fresh
 *   movs #0 to adds rN,r6,#0 copies at the 8th loader call is real compiler behaviour, not a draft error:
 *   the ORIGINAL of ov131 func_021D4964 (same loader sequence, EXACT* there) starts its adds r3,r4,#0
 *   copies at its 8th loader call. So this original differs in source structure: its register zeros are
 *   never in one class with the r6 zero. Tried: a plain `u32 z = 0` local for the stack zeros (fully
 *   propagated, no change); static inline loaders that hold only the r3 zero and take the stack zeros as
 *   parameters (transparent, no change); an enum-typed compressed-flag parameter with an enum constant
 *   argument (no change). The note copy in docs/notes reaches 32 bytes only with an
 *   enum-typed zero local (a stand-in by the D7 rules); even there the copies start at call 9.
 *   Next: a source shape where the stack/struct zeros (r6) are not the int constant 0.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {s16 x,y,index;u8 a,b;} Params;
struct Obj;
extern void *func_020490F4(u32, u32);
extern void func_02049B68(void *,u32,u32,u32,u32,u32);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u32);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u32);
extern void func_02041EE4(u32,u32,u32);
extern struct Obj *func_0204ABF0(void *,u32,u32,u32,u32);
extern struct Obj *func_0204A6C8(void *,u32,u32,u32,u32);
extern struct Obj *func_0204AF28(void *,u32,u32,u32);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
extern void func_020409B4(u32);
#define H (*(u16 *)p)
#define W(o) (*(u32 *)(p + (o)))
void func_021B6BA4(u8 *p)
{
    Params cfg;
    u32 v = 0xd;
    void *g = func_020490F4(0x2e, H);
    func_02049B68(g, 4, 0, 0, 0, H);
    func_02049658(g, 7, 3, 0, 0, 0, H);
    func_020498F4(g, 0xc, 3, 0, 0, 0, H);
    func_020498F4(g, 0xb, 2, 0, 0, 0, H);
    func_02049B68(g, 3, 4, 0, 0, H);
    func_02049658(g, 0xa, 4, 0, 0, 0, H);
    func_02049658(g, 9, 7, 0, 0, 0, H);
    func_020498F4(g, 0x10, 4, 0, 0, 0, H);
    func_020498F4(g, 0xf, 6, 0, 0, 0, H);
    func_020498F4(g, 0xe, 5, 0, 0, 0, H);
    func_020498F4(g, v, 7, 0, 0, 0, H);
    func_02041EE4(6, 0, 128);
    func_02041EE4(5, 0, v - 0x8d);
    *(struct Obj **)(p + 0x1858) = func_0204ABF0(g, 2, 0, 0, H);
    *(struct Obj **)(p + 0x1864) = func_0204A6C8(g, 8, 0, 0, H);
    *(struct Obj **)(p + 0x1870) = func_0204AF28(g, 0x14, 0x18, H);
    *(struct Obj **)(p + 0x1860) = func_0204ABF0(g, 1, 1, 0, H);
    *(struct Obj **)(p + 0x186c) = func_0204A6C8(g, 6, 0, 1, H);
    *(struct Obj **)(p + 0x1878) = func_0204AF28(g, 0x13, 0x17, H);
    *(struct Obj **)(p + 0x185c) = func_0204ABF0(g, 0, 0, 0x40, H);
    *(struct Obj **)(p + 0x1868) = func_0204A6C8(g, 5, 0, 0, H);
    *(struct Obj **)(p + 0x1874) = func_0204AF28(g, 0x11, 0x15, H);
    cfg.x = 32; cfg.y = 224; cfg.index = 0; cfg.a = 0; cfg.b = 2;
    *(struct Obj **)(p + 0x184c) = func_0204B294((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 224; cfg.y = 224; cfg.index = 1;
    *(struct Obj **)(p + 0x1850) = func_0204B294((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 128; cfg.y = 96; cfg.index = 2; cfg.a = 0; cfg.b = 0;
    *(struct Obj **)(p + 0x1854) = func_0204B294((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    func_0204B3DC(*(struct Obj **)(p + 0x184c), 1);
    func_0204B3DC(*(struct Obj **)(p + 0x1850), 1);
    func_0204B3DC(*(struct Obj **)(p + 0x1854), 0);
    func_02049238(g);
    func_020409B4(3);
    func_020409B4(2);
    func_020409B4(7);
}
