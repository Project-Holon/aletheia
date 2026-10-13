/*
 * unit:     no
 * function: func_0203F9B4
 * address:  0x0203F9B4
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_020403F4  0x020403F4  arm
 *   AREAMAN_Delete  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * TU: bg_sys.c.
 *
 * Teardown of the background system: free the eight layers one at a time,
 * release the two buffers at +0x168 and +0x16c, free the block itself and
 * null the global.  The counter is a u8, which is what turns `i++` into the
 * `add`/`and #0xff` pair; r4 is recycled from the counter to the global's
 * address once the loop is over, and the global is re-read through it after
 * every call because the callees may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F9B4.c \
 *       --func func_0203F9B4 --addr 0x0203F9B4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int  u32;

struct BgSys {
    u16   heapId;
    u8    pad_02[2];
    u16   unk_04;
    u16   unk_06;
    u8    pad_08[0x160];
    void *unk_168;
    void *unk_16c;
    u32   unk_170[8];
    u32   unk_190[8];
    u32   unk_1b0[8];
};

extern struct BgSys *g_02146A44;

extern void func_020403F4(u32 layer);
extern u32 AREAMAN_Delete(void *a);
extern u32 func_020307B0(void *p);

void func_0203F9B4(void)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        func_020403F4(i);
    }
    AREAMAN_Delete(g_02146A44->unk_168);
    AREAMAN_Delete(g_02146A44->unk_16c);
    func_020307B0(g_02146A44);
    g_02146A44 = 0;
}
