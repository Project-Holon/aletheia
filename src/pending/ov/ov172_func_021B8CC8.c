/*
 * function: func_021B8CC8
 * address: 0x021B8CC8
 * packet: pkt_ov172_021B8CC8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BE010 0x021BE010 thumb ov172
 *   func_021BE018 0x021BE018 thumb ov172
 *   func_021BE024 0x021BE024 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 *
 * note 2026-10-04 (wD1 lane03): DIFF, 487 bytes differ (756 vs 752 compiled). Logic and
 * all callee prototypes are believed right. Residues: (1) the original keeps 15 distinct
 * spill slots sp+0xC..0x44 for the 5 nested-call argument groups
 * f(g(a), h(a,5), h(a,1), h(a,9), &rc, 1, h) and the rect at sp+0x48 (frame 0x50);
 * ours reuses 3 slots (frame 0x40). Tried a static inline helper per call and 15 named
 * temps: both fold to the same code. (2) the original holds &rc in r7 for the whole
 * body (add r7, sp, #0x48), ours rematerialises it in r1. Next idea: rc as a pointer
 * argument to a non-inlined local helper shape, or the five groups as a loop over a table.
 * note 2026-10-04 (wD2 lane18): still DIFF (486 bytes differ). Re-read: the 4 missing frame slots
 * are exactly the first argument temp (func_021BE024 result) of each of the 5 groups: ours keeps it
 * in r7 because &rc is rematerialised per use, the original keeps &rc in r7 (add r7,sp,#0x48 before
 * the first rc store, still used by strh [r7,#4] after the 021BE0B4 call) so the temp must spill.
 * Tried: rc through a pointer local (struct Rect *rp = &rc), no change. Also tried rc stores
 * through a u8 * base local (611 bytes differ, worse). Untried: rc as a field of a larger local struct.
 * note 2026-10-05 (wD4 lane03): DIFF, 417 bytes differ (was 487). Fixed: the 0x15/0x16 store is an
 * if/else (rc.z = 0x15 / rc.z = 0x16), which makes the compiler hold &rc in r7 for the first block and
 * spill group 1's first temp exactly as the listing does.
 * (An array t[15] for the leading call results gives the same code as the nested calls.) Residue: from group 2 on, the original keeps
 * the constant 1 in r7 (movs r7,#1 after the second func_021BE018 call, then str r7,[sp,#4], strh r7
 * rc.z=1, str r7,[sp,#8] for func_020450F0) and spills every group's first temp to its own slot
 * (frame 0x50, rc at sp+0x48); ours keeps groups 2-4 first temp in r7 and later CSEs 0 into r7
 * (frame 0x4c). Tried: rc through a pointer local for the first block (propagated, no change);
 * a constant local one = 1 for the later groups, rc.z and the func_020450F0 argument (propagated,
 * no change); u32 for the u16/u8 parameters that receive the 1 (no change).
 * note 2026-10-05 (wD5 lane07): still DIFF, 417 bytes. Re-read: the original CSEs the constant 1 into r7 from
 *   the second func_021BE018(a, 1) call to the second func_020450F0 call (stack args [sp,#4], [sp,#8], rc.z = 1)
 *   and CSEs 4 into r6 for the func_020450F0 pair; ours instead CSEs 0 into r7 for the 0xA4/0/8 stores and keeps
 *   group 2-4 first temps in r7. So the original 1-vreg won r7 over the group temps. Tried: one static inline
 *   helper for the whole group (mk(a, x, y, z, &rc, h)), same 417 bytes.
 * note 2026-10-05 (wD6 lane05): still DIFF, 417 bytes. Root cause found: mwcc keeps one constant in r7 for the
 *   join block, chosen by use count, and 0 has one use too many against 1. Probes (not fixes): deleting any ONE
 *   zero store (for example p+0x80) makes 1 take r7 and the rest of the function (groups 2-5, all slot
 *   layout, frame 0x50) match exactly; deleting rc.a/rc.b in group 5 also flips it. So the original source has
 *   one fewer constant 0 (or one more constant 1) in the block after the 0x15/0x16 if/else. Tried with no
 *   change: void * (NULL) types for the zero fields, chained zero stores (x = y = 0, same count), u32/u16 types
 *   for the 1 parameters. A compound literal for the group-5 rect flips r7 but copies from a pool (worse).
 *   Next: find which zero store is not a literal in the original (a field set from another value, a store
 *   inside a callee, or a 1 hidden in a call argument).
 * note 2026-10-05 (wD7 lane02): still DIFF, 417 bytes. New probes (not fixes): one extra non-register store of
 *   the constant 1 (for example p+0xAC = 1 after the 0xA8 store) flips r7 to 1 and leaves 156 bytes; changing the
 *   0x38 store from u8 to u32 (drops its adds r1,#0x38 address temp) also flips it and the whole body then matches
 *   up to that store (70 bytes). Register-argument constants do not count (removing the 0 of func_02043B5C or
 *   adding func_020409B4(1) changes nothing). So the score is uses plus address temps, not a plain use count.
 *   Tried with no change: int/void * types for the word zero stores, s8 for the 0x38 byte, chained stores for the
 *   0x80/0x84/0x28 and 0xA4/0/8 groups, a real struct type for p (fields at every offset), short x,y,z in the rect
 *   (as in the matched ov216 caller), u8/int local for the 021B8B68 result, a void * first parameter for 021B8B68.
 *   Worse: rc.a = rc.b = 0 chains (422), func_0204B3DC(p->x = func_0204B294(...), 1) (509).
 *   Next: look for an address temp or store in the tail that the original does not have as a separate IR node.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
struct Rect { u16 x; u16 y; u16 z; u8 a; u8 b; };
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_020409B4(u32 layer);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *buf, u8 value);
extern void func_02045374(void *cfg);
extern void func_02045334(void *d);
extern u16 func_021BE00C(void *p);
extern u32 func_021BE010(void *p);
extern u32 func_021BE018(void *p, int i);
extern u32 func_021BE024(void *p);
extern u32 func_021BE0B4(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021BE210(void *a, u32 b);
extern int func_021BA270(void *p);

void func_021B8CC8(void *a, char *p)
{
    u16 h;
    void *g;
    struct Rect rc;

    h = func_021BE00C(a);
    g = (void *)func_021BE010(a);
    func_02049658(g, 0xB, 6, 0, 0, 0, h);
    func_020498F4(g, 0x11, 6, 0, 0, 0, h);
    func_02049658(g, 0xB, 5, 0, 0x5000, 0, h);
    func_020498F4(g, 0xF, 5, 0, 0, 0, h);
    func_0207D63C((void *)0x04001050, 2, 0x14, 5, 0xF);
    func_020409B4(6);
    func_020409B4(5);
    rc.x = 0x80;
    rc.y = 0x60;
    rc.z = *(u8 *)(p + 0xD) + 0x19;
    rc.a = 0;
    rc.b = 2;
    *(struct Obj **)(p + 0x90) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x90), 1);
    if (func_021BE0B4(a) == 1)
        rc.z = 0x15;
    else
        rc.z = 0x16;
    *(struct Obj **)(p + 0x94) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x94), 1);
    rc.z = 0x14;
    *(struct Obj **)(p + 0x9C) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x9C), 1);
    rc.z = 0x18;
    *(struct Obj **)(p + 0xA0) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0xA0), 1);
    rc.x = 0xE8;
    rc.y = 0xA8;
    rc.z = 1;
    rc.a = 0;
    rc.b = 0;
    *(struct Obj **)(p + 0x98) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 6), func_021BE018(a, 2), func_021BE018(a, 10), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x98), 1);
    func_0204B92C(*(struct Obj **)(p + 0x98), 1);
    *(u32 *)(p + 0xA4) = 0;
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xA8) = 3;
    *(u32 *)(p + 0x2C) = func_020450F0(4, 8, 3, 0x10, 8, 0xA, 1);
    *(u32 *)(p + 0x7C) = func_020450F0(4, 1, 1, 0x1E, 4, 0xA, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x2C)), 0);
    func_02045374(*(void **)(p + 0x2C));
    func_02045334(*(void **)(p + 0x2C));
    *(u32 *)(p + 0x80) = 0;
    *(u32 *)(p + 0x84) = 0;
    *(u32 *)(p + 0x28) = 0;
    func_020409B4(4);
    *(u8 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x8C) = 0;
    *(u8 *)(p + 0xC) = 0;
    {
        u32 r = func_021B8B68((int)a, (char *)func_021BDFE4(a));
        if (r != 0xFF) {
            func_021BE210(a, r);
            *(u32 *)(p + 0xA4) = 2;
        }
    }
    if (func_021BA270(*(void **)(p + 0x10)) == 0)
        *(u32 *)(p + 0xA4) = 2;
}
