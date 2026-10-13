/*
 * unit:     no
 * function: PMS_DRAW_CreateDecoActor
 * address:  0x0202DFEC
 * packet:   pkt_0202DFEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Creates one actor out of the five-word resource record the owner keeps
 * at +0x10 (PMS_DRAW_LoadResources is what fills it), disables it, enables its
 * second flag, and adds the 0x2000 bit only for language 0x1e.
 *
 * The four zero halfwords at sp+0xc must be written as a BRACE
 * INITIALISER, `struct Zero4 z = { 0, 0, 0, 0 };`.  Assigning the four
 * fields as statements -- with or without the address bound to a named
 * pointer local -- swaps r0 and r2 throughout the block (the compiler
 * materialises the zero first and the frame address second, and then
 * re-materialises `add r0, sp, #0xc` for the outgoing slot), which is
 * seventy concrete bytes out and is the whole residue this function had.
 * The permuter (hill and anneal, 3800 compiles, --types) could not reach
 * it from the statement form: no body mutation moves an initialiser's
 * definition order.
 *
 * `one` exists because the original materialises 1 twice, once as the
 * r1 argument to func_0204B92C and once into r4 to survive the
 * func_02035630 call and become `lsls r1, r4, #0xd`; writing the shift
 * as a bare `0x2000` costs a pool word instead.
 *
 * The follower at 0x0202E040 is reached across two bytes of linker fill
 * at 0x0202E03E, which is the 82-against-84 the star records.
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02035630  0x02035630  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_CreateDecoActor.c \
 *       --func PMS_DRAW_CreateDecoActor --addr 0x0202DFEC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Zero4 { u16 a; u16 b; u16 c; u16 d; };

struct Res {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
};

struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, u32 b, u32 c, u32 d,
                                const void *e, u16 f, u16 g);
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u8 func_02035630(void);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);

void *PMS_DRAW_CreateDecoActor(struct Res *r, u16 a)
{
    struct Zero4 z = { 0, 0, 0, 0 };
    void *o;
    u32 one;

    o = CLACT_CreateActor((void *)r->f00, r->f0c, r->f08, r->f10, &z, (u16)r->f04, a);
    func_0204B3DC(o, 0);
    one = 1;
    func_0204B92C(o, 1);
    if (func_02035630() == 0x1e) {
        CLACT_SetActorAutoAnimSpeed(o, one << 0xd);
    }
    return o;
}
