/*
 * function: sub_0202D214
 * address:  0x0202D214
 * packet:   pkt_0202D1AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stamps the eight character cells of a text/tile object out of the
 * source tilemap hung off the object at +0x14, through a 0x1200 scratch
 * buffer taken from the work allocator.  Four passes: two full rows of
 * eight cells at a 0x180-word source stride, then the two shorter runs
 * of four from +0xc00, interleaving 0x100-byte and 0x80-byte cells.
 *
 * The scratch is requested with the caller's low 15 bits and bit 15
 * forced on -- the id is spelled `(v & 0x7fff) | 0x8000`, and the 0x8000
 * arrives as `0x7fff + 1` because it is not a `movs` immediate.
 *
 * The stride local is written twice, and the second write recomputes off
 * the constant rather than the variable (`s = 0x100; s = 0x100 + 0x80;`),
 * which is the two-store shape of
 * docs/idioms/a-dead-store-to-a-spilled-local-survives-when-the-second-
 * assignment-recomputes.md; the loop addresses are then `base + off`
 * with `off` accumulated by hand, which is why the object base stays in
 * one register and the running pointer in another.
 *
 * symbols:
 *   str_020A77AC    0x020A77AC  data
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   MIi_CpuCopyFast 0x02082B0C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char str_020A77AC[];

extern void *func_02030734(u32 a, u32 b, u32 c, const char *d, u32 e);
extern void  func_020307B0(void *p);
extern void  MIi_CpuCopyFast(void *dst, const void *src, u32 size);

void sub_0202D214(void *p, u32 v)
{
    u8 *base = *(u8 **)((char *)p + 0x14);
    u8 *buf;
    u32 size;
    int i;
    u32 off;

    buf = func_02030734((u16)((v & 0x7fff) | 0x8000), 0x1200, 1, str_020A77AC, 0x100);
    MIi_CpuCopyFast(base, buf, 0x1200);

    size = 0x100;
    size = 0x100 + 0x80;
    off = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + off, base + i * size, 0x100);
        off += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + off, base + (i * 12 + 8) * 32, 0x80);
        off += 0x80;
    }

    size = 0x100;
    size = 0x100 + 0x80;
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + off, base + (i * size + 0xc00), 0x100);
        off += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + off, base + (i * 12 + 0x68) * 32, 0x80);
        off += 0x80;
    }
    func_020307B0(buf);
}
