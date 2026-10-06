/*
 * function: func_021BE34C
 * address: 0x021BE34C
 * packet: pkt_ov209_021BE34C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: D934 index is unsigned; original i+16 has no signed CSE spill. Signed halfword coordinates match the caller's ldrsh/truncation and BE29C.
 * symbols:
 *   func_021BD8F4 0x021BD8F4 thumb ov209
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021BD934 0x021BD934 thumb ov209
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 */
typedef unsigned short u16;
extern unsigned int func_021BD8F4(char *p, unsigned int idx);
typedef signed short   s16;
typedef unsigned int   u32;
extern void func_021BD958(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern void func_021BD934(char *p, int idx, short a, short b, unsigned short c);
extern void func_021BD8D8(char *p, u32 idx, u32 value);
void func_021BE34C(char *p, int delta)
{
    unsigned i;
    short pos[2];
    for (i = 10; i < 26; i++) {
        if (func_021BD8F4((char *)p, i) != 0) {
            func_021BD958(p, i, &pos[1], &pos[0], 0);
            func_021BD934(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 0);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200)
                func_021BD8D8(p, i, 0);
        }
    }
    for (i = 26; i < 42; i++) {
        if (func_021BD8F4((char *)p, i) != 0) {
            func_021BD958(p, i, &pos[1], &pos[0], 1);
            func_021BD934(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 1);
            func_021BD934(p, (unsigned)(i + 16), (short)pos[1], (short)(pos[0] + delta), 1);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200) {
                func_021BD8D8(p, i, 0);
                func_021BD8D8(p, i + 16, 0);
            }
        }
    }
}
