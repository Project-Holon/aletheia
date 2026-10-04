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

void func_021B9280(u8 *p)
{
    Tbl16 t;
    Rect r0;
    Rect r1;
    Rect r2;
    void *h;
    void *a;
    u32 v;
    u32 k;
    u32 m;
    u32 i;
    u32 z;

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
