/*
 * function: func_02037680
 * address:  0x02037680
 * packet:   pkt_02037478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A34   0x020A7A34  data
 *   g_021469D0     0x021469D0  data
 *   func_02034714  0x02034714  arm
 *   func_0203640C  0x0203640C  arm
 *   func_02037234  0x02037234  arm
 *
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: func_0203640C here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride f1E0 passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { f10 + i * f1E0, f1E0 }.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Net {
    u8 pad00[0x10];
    u8 *f10;
    u8 pad14[0x4c - 0x14];
    u8 f4C[0x11c - 0x4c];
    u8 f11C[0x1b4 - 0x11c];
    u32 f1B4[8];
    u8 pad1D4[0x1d7 - 0x1d4];
    u8 f1D7[8];
    u8 pad1DF[0x1e0 - 0x1df];
    u32 f1E0;
};

extern const u8 str_020A7A24[];
extern const u8 str_020A7A34[];
extern struct Net *g_021469D0;
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern void func_0203640C(u8 *dst, u8 *src, u32 n);
extern void func_02037234(u8 *p);

void func_02037680(int i)
{
    if (i >= 8) {
        func_02034714(str_020A7A24, 0x155, str_020A7A34);
    }
    g_021469D0->f1B4[i] = 0;
    func_0203640C(g_021469D0->f4C + i * 16, g_021469D0->f10 + i * g_021469D0->f1E0, g_021469D0->f1E0);
    g_021469D0->f1D7[i] = 0;
    func_02037234(g_021469D0->f11C + i * 16);
}
