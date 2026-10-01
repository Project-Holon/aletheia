/*
 * function: func_021BF624
 * address: 0x021BF624
 * packet: pkt_ov204_021BF624
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Enum zero preserves the clear before the indexed base add.
 * symbols:
 *   defaultPos 0x021C08F0 data ov204
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   func_02015CAC 0x02015CAC thumb
 */

struct Vec { int v[3]; };
extern const struct Vec defaultPos;
extern void *func_020159C8(void *, unsigned int, unsigned int, unsigned int, void *);
extern void func_02015CAC(void *, void *);
extern void func_021BF7F0(void *, void *);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);

void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    struct Vec pos = defaultPos;
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    *(void **)(base + off) = func_020159C8(*(void **)(p + 4), a, b, c, d);
    func_02015CAC(*(void **)(base + off), &pos);
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = 1;
    func_02015F2C(*(void **)(base + off), base + off, func_021BF7F0, 0);
}
