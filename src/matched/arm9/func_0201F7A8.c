/*
 * function: func_0201F7A8
 * address:  0x0201F7A8
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The sibling of func_0201F73C: the same five ARM byte accessors on the same
 * descriptor, but the four geometry bytes are adjusted before the call, the
 * two extents shrunk by one and the two origins grown by two, and the worker
 * is func_02041300 with a zero second argument and a zero trailing one.
 * The four `lsls #24 / lsrs #24` pairs are the u8 truncation of each adjusted
 * value, not bitfield extraction: they are equal-amount pairs on values that
 * already left the accessors as bytes, so they only survive because the
 * arithmetic promoted to int in between.
 *
 * symbols:
 *   func_02045730  0x02045730  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041300  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F7A8.c \
 *       --func func_0201F7A8 --addr 0x0201F7A8 --cc 1.1p1 --thumb
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5,
                          u8 a6);

void func_0201F7A8(void *desc, u32 kind)
{
    u8 id;
    u8 a;
    u8 b;
    u8 c;
    u8 d;

    id = func_02045730(desc);
    a = func_02045758(desc);
    b = func_02045760(desc);
    c = func_02045748(desc);
    d = func_02045750(desc);
    func_02041300(id, 0, (u8)(a - 1), (u8)(b - 1), (u8)(c + 2), (u8)(d + 2), 0);
    if (kind == 0) {
        func_020409B4(id);
        return;
    }
    if (kind == 1) {
        func_02041B6C(id);
    }
}
