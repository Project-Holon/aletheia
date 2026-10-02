/*
 * function: func_021A96B8
 * address:  0x021A96B8
 * packet:   pkt_ov021_021A96B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_021A9CAC  0x021A9CAC  thumb
 *   func_021A9D30  0x021A9D30  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef unsigned long long u64;

struct Unit {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x11];
    u8 f1D;
    u8 pad1E[2];
    u32 f20;
    void *f24;
    u32 b0 : 9;
    u32 b9 : 1;
    u32 b10 : 1;
};
struct Slot14 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 f07; };

extern void *func_0201ADE4(u16 a, u16 b, u16 c);
extern u32 func_021A9D30(const struct Unit *u, void *src, struct Slot14 *s);
extern void func_02017588(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_02018A00(void *mon, u16 species, u8 form);
extern void func_021A9CAC(void *mon, void *src, int a, int b);
extern u32 func_02008550(void *p);
extern u32 func_020084F4(void *p);
extern void func_020185C4(void *p);
extern void func_0201AE14(void *p);

void func_021A96B8(void *mon, const struct Unit *u, struct Slot14 *s)
{
    void *pd = func_0201ADE4(s->f00, s->f05, 4);
    u32 pid = func_021A9D30(u, pd, s);

    func_02017588(mon, s->f00, s->f04, u->f20, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, s->f05);
    if (s->f07)
        func_02018A00(mon, s->f00, s->f05);
    if (s->f02 <= 0x272) {
        if (s->f02 != 0)
            func_02017E40(mon, 6, s->f02);
        else
            func_021A9CAC(mon, pd, u->b9, u->f08 == 1);
    }
    func_02017E40(mon, 0x9A, func_02008550(u->f24));
    func_02017E40(mon, 0x8E, func_020084F4(u->f24));
    if (u->b10)
        func_02017E40(mon, 0x70, u->f1D);
    func_020185C4(mon);
    func_0201AE14(pd);
}
