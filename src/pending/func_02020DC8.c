/*
 * unit:     no
 * address:  0x02020DC8
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_02020DC8
 *
 * symbols:
 *   g_0209E8CC     0x0209E8CC  data
 *   func_020436FC  0x020436FC  arm
 *
 * The fifth, stack-passed argument is `(u16)v`, an explicit truncation of a
 * `u32` parameter: that is the `lsls #0x10` / `lsrs #0x10` pair in front of
 * the `str r0, [sp]`.  Declaring the parameter itself `u16` does not produce
 * it, because this compiler treats an incoming `u16` parameter as already
 * narrowed by the caller and stores it straight to the outgoing slot.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * 0x0209E8CC has exactly one pool word in the whole image, this function's
 * own at 0x02020DE8 (`grep -rn 0209E8CC asm/` finds that one and nothing
 * else), so the `literal` class has no witness outside the compared range and
 * no other class reaches a plain data address.  It closes the day anything
 * else in the image names the table.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02020DC8.c \
 *       --func func_02020DC8 --addr 0x02020DC8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8    pad[8];
    void *unk08;
};

extern const u8 g_0209E8CC[];
extern void *func_020436FC(const u8 *desc, u32 a, u32 b, u32 c, u32 d);

void func_02020DC8(struct Obj *p, u32 v)
{
    p->unk08 = func_020436FC(g_0209E8CC, 1, 1, 0x20, (u16)v);
}
