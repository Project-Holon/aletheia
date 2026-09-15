/*
 * unit:     no
 * function: func_020411E8
 * address:  0x020411E8
 * packet:   pkt_02040F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_020426A0  0x020426A0  arm
 *   func_020428E8  0x020428E8  arm
 *   func_02042B24  0x02042B24  arm
 *
 * The twin of src/matched/func_020410D0.c, differing only in the trailing
 * constant it appends to the blitter's argument list: 1 here, 0 there.  Fan
 * out on the bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44
 * and forward the whole argument list to one of three blitters.  All three
 * arms are byte-identical in their argument marshalling; only the callee
 * differs.  The pair reads as a "transparent" flag threaded through the two
 * public entry points of the same fill.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/func_02041300.c: `&g_02146A44[index].unk_08` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020411E8.c \
 *       --func func_020411E8 --addr 0x020411E8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8 pad_00[8];
    u8 unk_08[0x14];
    u8 unk_1c;
    u8 pad_1d[0xf];
};

extern struct Entry *g_02146A44;

extern void func_020426A0(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void func_020428E8(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void func_02042B24(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);

void func_020411E8(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6,
                   u8 a7, u8 a8, u8 a9)
{
    u8 kind = g_02146A44[index].unk_1c;

    if (kind == 0) {
        func_020426A0((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 1);
    } else if (kind == 1) {
        func_020428E8((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 1);
    } else {
        func_02042B24((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 1);
    }
}
