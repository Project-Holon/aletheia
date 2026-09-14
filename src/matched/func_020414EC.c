/*
 * function: func_020414EC
 * address:  0x020414EC
 * packet:   pkt_020414C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   MIi_CpuClear16 0x02082A48  arm
 *   func_020409B4  0x020409B4  arm
 *
 * Clear slot `i` of the 0x2c-byte slot table behind 0x02146A44: if the
 * buffer pointer at +8 is unset there is nothing to do, otherwise zero the
 * buffer over its +0xc length and notify func_020409B4.  Same table and
 * same guard shape as src/matched/sub_020403F4.c, which frees the buffer
 * instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020414EC.c \
 *       --func func_020414EC --addr 0x020414EC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8    pad_00[8];
    void *unk_08;
    u32   unk_0c;
    u8    pad_10[0x1c];
};

extern struct Entry *g_02146A44;

extern void MIi_CpuClear16(u32 data, void *dest, u32 size);
extern void func_020409B4(u32 index);

void func_020414EC(u32 i)
{
    if (g_02146A44[i].unk_08 == 0) {
        return;
    }
    MIi_CpuClear16(0, g_02146A44[i].unk_08, g_02146A44[i].unk_0c);
    func_020409B4(i);
}
