/*
 * unit:     no
 * function: func_0203F3F0
 * address:  0x0203F3F0
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469FC     0x021469FC  data
 *   func_0203F46C  0x0203F46C  arm
 *
 * TU: gf_standard.c.
 *
 * Per-frame tick on the block at 0x021469FC: while +0x04 is clear, count
 * frames in +0x08 and every eleventh one reset the counter and run
 * func_0203F46C.  The `ble` says +0x08 is signed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F3F0.c \
 *       --func func_0203F3F0 --addr 0x0203F3F0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Block {
    u32 unk_00;
    u32 unk_04;
    s32 unk_08;
    u8  pad_0c[0x3c];
};

extern struct Block g_021469FC;

struct RtcRequest;
extern void func_0203F46C(struct RtcRequest *req);

void func_0203F3F0(void)
{
    if (g_021469FC.unk_04 != 0) {
        return;
    }
    g_021469FC.unk_08++;
    if (g_021469FC.unk_08 <= 10) {
        return;
    }
    g_021469FC.unk_08 = 0;
    func_0203F46C((struct RtcRequest *)(&g_021469FC));
}
