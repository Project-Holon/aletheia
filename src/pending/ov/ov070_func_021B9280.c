/*
 * function: func_021B9280
 * address:  0x021B9280
 * packet:   pkt_ov070_021B9280
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-05 (wave D8 lane03): still DIFF 2 bytes (+0x15A `movs r2,#0` vs our `adds r2,r4,#0`).
 *   New probes: in ours the arg zeros turn from movs into copies of r4 right after func_02049238(h)
 *   (moving 0204B100 before 02049B40 makes 0204B100's zero the first copy); in the image the switch is one
 *   call later, after 02049B40. It is not plain register pressure: after the 0x53 open (r4-r7 all busy) the
 *   image still copies. Tried without change: an enum palette-location parameter for 02049B40 (PAL_MAIN_BG);
 *   a `z = 0` variable for the zero arguments after 02049B40; `w = 0x20` for the 0x20 stack arguments;
 *   `w = 0x60` with `w *= 4` / `w <<= 2` / `w = w * 4` for 0x180 (mwcc folds all); inline helpers
 *   [02049B40..0x53 close] and [02049B40..020434DC]. Next: find which value the image keeps live until
 *   02049B40 returns.
 * note (2026-10-04, wave D3 lane 08): DIFF, complete draft (1276 vs 1240 bytes).
 *   Logic is checked against the listing (every call, constant and pool word). Residue
 *   is register choice: after the func_02008550 if, the target keeps the 0x544 heap
 *   offset in r7 and the 0x7FC base in a spill slot [sp,#0x18] (0x7FC+4/+8/+0xC derived
 *   from it); ours keeps 0x7FC in r7 and reloads 0x544 from the pool at every use (that
 *   is most of the 36 extra bytes). Later the target also keeps 0x69C in [sp,#0x1C] and
 *   hoists the loop offsets (0x5E8, 0x5E0, 0x5E4, 0x6C0, 0x6CC) into stack slots.
 *   The 0x53 file id is a variable: the target computes k + 0xED = 0x140 at run time
 *   and stores it back. Data d_021BBBE0/d_021BBA8C/d_021BBAB0 have no witness outside
 *   this function (unresolved relocations). Next: try struct-field accesses for the
 *   0x7FC..0x808 group (an array p->a[4]) and for the heap field.
 *
 * note 2026-10-05 (wave D4 lane 10): still DIFF (1037 bytes, 1276 vs 1240). Constant-in-local lever
 *   tried: `o = 0x7FC` with p+o, o+4, o+8, o+0xC and `hp = 0x544` for every heap read (from the top and
 *   from after the 02008550 if): output identical, mwcc propagates both. The listing shows the 0x544 value
 *   and 0x7FC/0x69C/0x53 bases stored back after `adds` (o += 8 at the 0x804 store, k += 0xED, 0x69C-0xB4
 *   stored back as the loop base), which looks like compiler induction on spilled values, not source.
 * note 2026-10-05 (wave D5 lane 15): still DIFF (1276 vs 1240, 1037 bytes). Tried the stored-back
 *   shape as source variables: `o = 0x7FC` with o, o+4, o+0xC then `o += 8` for 0x804, and
 *   `q = 0x69C` with q-0xBC, q-0xB8, `q -= 0xB4` as the 0x5E8 loop base: output identical to
 *   the literal form (mwcc folds them). Reading: the target splits the 0x544 and zero CSE temps
 *   at the 02008550 join (0 r7->r4, 0x544 r4->r7) and spills the 0x7FC derivation chain to
 *   [sp,#0x18]; ours keeps 0x7FC in r7 and rematerialises 0x544 at each use. A spill-priority
 *   residue; the source shape that changes it is not found.
 * note 2026-10-05 (wave D6 lane 14): still DIFF (1037 bytes). New reading: the original keeps the
 *   0x544 CSE in r7 from 0xA4 to the end (it also derives 0x55C/0x564/0x570 from it) and spills the second
 *   handle `a` to [sp,#0x10]; ours gives r7 to the 0x7FC chain and then to `a`, and reloads 0x544 at each
 *   use. Tried without change: `a` declared last, a temp for the 020275E4 id, a struct array field for
 *   0x7FC..0x808, a struct field for the heap id (all 1037 bytes, identical output).
 * note 2026-10-05 (wave D7 lane 12): still DIFF, but 2 bytes from EXACT (1240 vs 1240 bytes, was 1037).
 *   Fixes: (1) rects declared in use order (r2, r1, r0) give the image slots 0x5C/0x54/0x4C; (2) the
 *   third-file block (open by func_020275E4, the 0x5E0/0x5E4 calls, both loops, close) is a static inline
 *   helper LoadIcons(p). Probes showed the `a` use in the 17-entry loop was what made `a` take r7 and
 *   pushed the 0x544 CSE out; the inline parameter/local split makes `a` spill to [sp,#0x10] and 0x544
 *   stay in r7, as in the image. Whole body then matches. Residue: +0x15A, the third argument (0) of
 *   func_02049B40 is `movs r2,#0` in the image and `adds r2,r4,#0` (copy of the kept zero) in ours.
 *   Probe: keeping `h` live across that call (close after it) turns it into movs, so the image has one
 *   more live value there. Tried without change: 02049B40 third param as u16, int, void *, unprototyped;
 *   0204B100 as (int, u8, u32); `k = 0x53` moved before the call; `w = 0x60` with `w * 4` for 0x180;
 *   a `z` zero variable for 0204B100; separate handle variable for the 0x53 file; inline helpers around
 *   02049B40 alone, [first open..02049B40], [first open..0204B100], [02049B40..020434DC], and one per file.
 * symbols:
 *   func_021B8F98  0x021B8F98  thumb  ov070
 *   func_021B9178  0x021B9178  thumb  ov070
 *   func_021B91FC  0x021B91FC  thumb  ov070
 *   func_021BA6F4  0x021BA6F4  thumb  ov070
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 *   d_021BBBE0  0x021BBBE0  data  ov070
 *   d_021BBA8C  0x021BBA8C  data  ov070
 *   d_021BBAB0  0x021BBAB0  data  ov070
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u16 x, y, z; u8 a, b; } Rect;
typedef struct { u32 w[4]; } Tbl16;
extern u8 d_021BBBE0[];
extern u8 d_021BBA8C[];
extern const Tbl16 d_021BBAB0;
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(void *);
extern void func_0204A48C(void *, void *, u16);
extern void func_0203FC28(Tbl16 *);
extern void func_02043534(int);
extern void func_020435F4(int);
extern void func_021B8F98(void);
extern void func_0201DD68(void);
extern u32 func_0201F5DC(int, int, int, u16);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_02008550(u32);
extern void func_02049BDC(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_021B9178(u8 *, void *);
extern void func_021B91FC(u8 *, void *);
extern void func_02049238(void *);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0204B100(u32, u32, u16);
extern void func_02043598(int, int);
extern void func_020434DC(int, int);
extern void func_020409B4(int);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_021BA6F4(u8 *);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275FC(int);
extern u32 func_02027600(int);
extern u32 func_02027610(u8);
extern u32 func_020275F8(u8);
extern u32 func_02027604(u8);
extern u32 func_020275EC(u8);
extern u32 func_0204B294(u32, u32, u32, u32, const void *, u16, u16);
extern void func_0204B6F4(u32, u32, u32);
extern void func_0204B3DC(u32, u32);
extern void func_0204B92C(u32, u32);
extern void func_021BB5A4(u8 *);

static inline void LoadIcons(u8 *p)
{
    void *a;
    u32 m;
    u32 i;
    u32 z;

    a = func_020490F4(func_020275E4(), *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x5E0) = func_0204AC18(a, func_020275E8(), 1, 0x80, 0, 3, *(u16 *)(p + 0x544));
    m = func_020275FC(2);
    *(u32 *)(p + 0x5E4) = func_0204AF28(a, m, func_02027600(2), *(u16 *)(p + 0x544));
    z = 0;
    for (i = 0; i < 3; i++)
        *(u32 *)(p + i * 4 + 0x5E8) = func_0204A6C8(a, func_02027610((u8)i), z, 1, *(u16 *)(p + 0x544));
    for (i = 0; i < 17; i++)
        *(u32 *)(p + i * 4 + 0x59C) = func_0204A6C8(a, func_020275F8((u8)i), 0, 1, *(u16 *)(p + 0x544));
    func_02049238(a);
}

void func_021B9280(u8 *p)
{
    Tbl16 t;
    Rect r2;
    Rect r1;
    Rect r0;
    void *h;
    u32 v;
    u32 k;
    u32 i;

    *(volatile u16 *)0x04000050 = 0;
    func_0203F8F4(*(u16 *)(p + 0x544));
    func_02045088(*(u16 *)(p + 0x544));
    func_0201DD60();
    func_020433E0(d_021BBBE0);
    func_0204A48C(d_021BBA8C, d_021BBBE0, *(u16 *)(p + 0x544));
    t = d_021BBAB0;
    func_0203FC28(&t);
    func_02043534(0);
    func_020435F4(0);
    func_021B8F98();
    func_0201DD68();
    *(u32 *)(p + 0x838) = func_0201F5DC(3, 13, 0, *(u16 *)(p + 0x544));
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    func_02049B68(h, 8, 4, 0, 0, *(u16 *)(p + 0x544));
    if (func_02008550(*(u32 *)(p + 8)) == 0)
        func_02049BDC(h, 8, 4, 0x20, 0, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 6, 4, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x7FC) = v;
    func_02049990(h, 7, 4, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    func_021B9178(p, h);
    v = func_02049740(h, 0x11, 5, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x800) = v;
    func_02049990(h, 0x17, 5, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    func_021B91FC(p, h);
    *(u32 *)(p + 0x808) = func_02049740(h, 0x21, 3, 0, 0, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x22, 0, 0x60, 0x20, *(u16 *)(p + 0x544));
    func_02049238(h);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x69C) = func_0204B100(0x34, 0, *(u16 *)(p + 0x544));
    func_02043598(0x10, 1);
    func_020434DC(0x10, 1);
    k = 0x53;
    h = func_020490F4(k, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x1B, 0, 0x100, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 0x1C, 1, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x804) = v;
    func_02049990(h, 0x1D, 1, 0, (u16)v + 0x8000, 0, 0, *(u16 *)(p + 0x544));
    func_020409B4(1);
    k += 0xED;
    *(u32 *)(p + 0x55C) = func_0204AC18(h, 0x13, 0, k, 0, 3, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x564) = func_0204A6C8(h, 0x14, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x570) = func_0204AF28(h, 0x17, 0x1A, *(u16 *)(p + 0x544));
    func_02049238(h);
    func_021BA6F4(p);
    LoadIcons(p);
    r2.x = 0x50;
    r2.y = 0xB8;
    r2.a = 1;
    r2.b = 1;
    r2.z = 0;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + i * 4 + 0x6C0) = func_0204B294(*(u32 *)(p + 0x69C), *(u32 *)(p + i * 4 + 0x5E8), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r2, 1, *(u16 *)(p + 0x544));
        func_0204B6F4(*(u32 *)(p + i * 4 + 0x6C0), func_02027604((u8)i), 1);
        func_0204B3DC(*(u32 *)(p + i * 4 + 0x6C0), 0);
    }
    r1.x = 0x52;
    r1.y = 0xA5;
    r1.a = 1;
    r1.b = 1;
    r1.z = 0;
    for (i = 0; i < 17; i++) {
        *(u32 *)(p + i * 4 + 0x6CC) = func_0204B294(*(u32 *)(p + 0x69C), *(u32 *)(p + i * 4 + 0x59C), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r1, 1, *(u16 *)(p + 0x544));
        func_0204B6F4(*(u32 *)(p + i * 4 + 0x6CC), func_020275EC((u8)i), 1);
        func_0204B3DC(*(u32 *)(p + i * 4 + 0x6CC), 0);
    }
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x580) = func_0204AC18(h, 0x27, 0, 0x80, 0, 2, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x584) = func_0204A6C8(h, 0x26, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x58C) = func_0204AF28(h, 0x25, 0x24, *(u16 *)(p + 0x544));
    func_02049238(h);
    r0.a = 10;
    r0.b = 1;
    r0.x = 0x92;
    r0.y = 0xB0;
    r0.z = 0;
    *(u32 *)(p + 0x72C) = func_0204B294(*(u32 *)(p + 0x69C), *(u32 *)(p + 0x584), *(u32 *)(p + 0x580), *(u32 *)(p + 0x58C), &r0, 0, *(u16 *)(p + 0x544));
    func_0204B92C(*(u32 *)(p + 0x72C), 1);
    func_0204B3DC(*(u32 *)(p + 0x72C), 1);
    func_021BB5A4(p);
}
