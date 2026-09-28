/*
 * function: func_02068FF0
 * address:  0x02068FF0
 * packet:   pkt_02068E78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02068E78  0x02068E78  arm
 *   g_020A18F4     0x020A18F4  data
 *   g_020A18E8     0x020A18E8  data
 *
 * NitroSystem g2d_CharCanvas.c, the OBJ-1D canvas initialiser: derive the
 * log2 of each area dimension saturated at 3 (MATH_ILog2 over the SDK's
 * inline-asm MATH_CountLeadingZeros, which is how the image's predicated
 * clz/rsb #0x1f pairs arise), look the OBJ shift pair up in g_020A18F4
 * [shiftH][shiftW], and hand everything to the common initialiser
 * func_02068E78 with the vtable-like object g_020A18E8.
 *
 * Two readings closed it.  (1) The word the image reads uninitialised from
 * [sp, #0xc], edits in bytes 0 and 1 and stores to both [sp, #0xc] and
 * [sp, #8] is a 4-byte BITFIELD STRUCT local passed BY VALUE as the seventh
 * argument, not an eighth argument: its home is [sp, #0xc] and the by-value
 * copy is the argument slot.  (2) The pair is read through a pointer local
 * `const u8 *p = g_020A18F4[shiftH][shiftW];`; subscripting the table twice
 * leaves shiftW/shiftH in swapped registers (10 bytes).  1.1p1 compiles 132 bytes;
 * the pin is ../2.0/sp2.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02068FF0.c \
 *       --func func_02068FF0 --addr 0x02068FF0 --arm --cc ../2.0/sp2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

static inline u32 MATH_CountLeadingZeros(u32 x)
{
    asm { clz x, x }
    return x;
}

inline static int MATH_ILog2(u32 x)
{
    return (int)(31 - MATH_CountLeadingZeros(x));
}

inline static int SizeToShift(int size)
{
    return (size >= 8) ? 3 : MATH_ILog2((u32)size);
}

typedef struct {
    u32 w    : 8;
    u32 h    : 8;
    u32 rest : 16;
} Param;

extern const u8 g_020A18F4[4][4][2];
extern const u8 g_020A18E8[];
extern void func_02068E78(void *pCC, void *charBase, int areaWidth, int areaHeight,
                          int colorMode, const void *vtable, Param param);

void func_02068FF0(void *pCC, void *charBase, int areaWidth, int areaHeight, int colorMode)
{
    Param param;
    const int shiftW = SizeToShift(areaWidth);
    const int shiftH = SizeToShift(areaHeight);
    const u8 *p = g_020A18F4[shiftH][shiftW];

    param.w = p[0];
    param.h = p[1];
    func_02068E78(pCC, charBase, areaWidth, areaHeight, colorMode, g_020A18E8, param);
}
