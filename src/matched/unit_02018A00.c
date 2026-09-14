/*
 * unit:     yes
 * address:  0x02018A00
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02018A00, func_02018A08
 *
 * The two functions after src/matched/unit_020188B4.c and the three that its
 * header records as a near miss.  func_02018A00 is the eight byte
 * `ldr r3, [pc, #0]; bx r3` tail call that
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes; its callee is the
 * next function in this same range, so the site is the `local` class.
 *
 * symbols:
 *   func_02017E64  0x02017E64  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_02019C7C  0x02019C7C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02017E64(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void *func_02019C54(u16 a, u16 b);
extern u32  func_02019C7C(void *h);
extern u32  func_02019C90(u16 a, u16 b, u32 i);
extern u32  func_0201AE1C(void *h, u32 k);

void func_02018A08(void *p, u32 a, u32 b);

void func_02018A00(void *p, u32 a, u32 b)
{
    func_02018A08(p, a, b);
}

void func_02018A08(void *p, u32 a, u32 b)
{
    void *h;
    u32 t;
    u32 k;
    u32 v;

    v = func_02019C90((u16)a, (u16)b, 0x1C);
    if (v != 0) {
        func_02017E64(p, 0xA, v);
        func_02017E64(p, 0x71, 1);
        return;
    }
    h = func_02019C54((u16)a, (u16)b);
    t = func_02017E88(p, 0, 0);
    k = 0x1A;
    if (func_02019C7C(h) == 2 && (t & (1 << 16))) {
        k = 0x1B;
    }
    func_02017E64(p, 0xA, func_0201AE1C(h, k));
}
