/*
 * function: func_021FC644
 * address: 0x021FC644
 * packet: pkt_ov132_021FC644
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021FDE5C 0x021FDE5C data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020263D8(void *, u32, void *);
extern const char d_021FDE5C[];
void func_021FC644(int a, void *b, void *c, int d)
{
    char *p;
    p = func_02030734(4, 0x1ac, 1, d_021FDE5C, 0x14c);
    *(int *)(p + 0xc) = d;
    *(void **)(p + 0x54) = b;
    *(void **)(p + 0x58) = func_020120F4(b);
    *(void **)(p + 0x50) = c;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    func_020263D8(c, 4, p);
}
