/*
 * function: func_021BD348
 * address:  0x021BD348
 * packet:   pkt_ov110_021BD348
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: codegen scheduling only.  Same family as the parked
 *          src/pending/func_021BF664.c.  Compiled size is exactly 256
 *          (byte size is right) and both relocations resolve, but mwccarm
 *          colours the loop differently: it spills i*2 to [sp,#8] and keeps
 *          the high-channel result in r7, where the original keeps i*2 in r7
 *          and the high result in [sp,#8]; every following instruction is
 *          then transposed.  Typing A/B as unsigned int (so the 0x3e0/0x1f
 *          masks use `lsr`) cut the mismatch from 217 to 128 bytes but did
 *          not change the allocation.
 *
 * symbols:
 *   tbl_020A1B38  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    char pad0[0x98];
    unsigned short srcA[5];
    unsigned short srcB[5];
    unsigned short dst[5];
    char padb6[0xb8 - 0xb6];
    int f108;
} Ent;

extern short tbl_020A1B38[];
extern void func_02061CA4(int, int, int, int);

void func_021BD348(Ent *e)
{
    if (e->f108 + 0x400 >= 0x10000)
        e->f108 = e->f108 - 0xfc00;
    else
        e->f108 = e->f108 + 0x400;

    {
        unsigned char i;
        int t = e->f108;
        short ratio;

        t = ((t >> 4) << 1) + 1;
        ratio = (tbl_020A1B38[t] + 0x1000) / 2;

        for (i = 0; i < 5; i++) {
            unsigned int A = e->srcA[i];
            unsigned int B = e->srcB[i];
            int g = (unsigned char)((A & 0x3e0) >> 5);
            int r = (unsigned char)(A & 0x1f);
            int b = (unsigned char)((A & 0x7c00) >> 10);

            b = (unsigned char)(b + ((ratio * ((unsigned char)((B & 0x7c00) >> 10) - b)) >> 12));
            r = (unsigned char)(r + ((ratio * ((unsigned char)(B & 0x1f) - r)) >> 12));
            g = (unsigned char)(g + ((ratio * ((unsigned char)((B & 0x3e0) >> 5) - g)) >> 12));

            e->dst[i] = (unsigned short)((b << 10) | (g << 5) | r);
        }

        func_02061CA4(0xe, 0x56, (int)e->dst, 0xa);
    }
}
