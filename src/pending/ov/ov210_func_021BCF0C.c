/*
 * function: func_021BCF0C
 * address:  0x021BCF0C
 * packet:   pkt_ov210_021BCF0C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD4 lane16): also tried a do/while with u32 counter declared after the pointer, and a u8 counter with break: both worse (17 and 27 bytes). Residue unchanged (rec=r4/counter=r2 in image).
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (8 bytes): image rec=r4, counter=r2; ours rec=r2, counter=r4. Colouring looks priority ordered (counter gets the callee-saved register in ours); no source form found that lowers the pointer's priority.
 *
 * 2026-10-02: 44 bytes, size exact, one relocation resolved.  Only the colours
 * differ: the image keeps the record pointer in r4 and the loop counter in r2;
 * the compile swaps them (counter r4, pointer r2).  Tried: counter declared
 * first, int counter, do/while, break form, u32 value local, early return.
 *
 * symbols:
 *   d_021C0720  0x021C0720  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 d_021C0720[];

void func_021BCF0C(u8 *p)
{
    u8 *r0 = *(u8 **)p;
    u8 *r4 = *(u8 **)(r0 + 8);
    u8 r3 = r4[6];

    if (r3 != 0xff) {
        u32 i;
        for (i = 0; i < 14; i++) {
            if (r3 == d_021C0720[i]) {
                r4[6] = i;
                return;
            }
        }
    }
}
