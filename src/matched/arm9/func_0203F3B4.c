/*
 * unit:     no
 * function: func_0203F3B4
 * address:  0x0203F3B4
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
 *   func_02088788  0x02088788  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F46C  0x0203F46C  arm
 *
 * Reset of the 0x48-byte block at 0x021469FC: zero it wholesale, then write
 * its first three words explicitly (the redundant stores are in the source;
 * the memset has already cleared them) and hand it to func_0203F46C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F3B4.c \
 *       --func func_0203F3B4 --addr 0x0203F3B4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Block {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8  pad_0c[0x3c];
};

extern struct Block g_021469FC;

extern void func_02088788(void);
extern void func_02082BCC(void *dst, u32 value, u32 size);
struct RtcRequest;
extern void func_0203F46C(struct RtcRequest *req);

void func_0203F3B4(void)
{
    func_02088788();
    func_02082BCC(&g_021469FC, 0, 0x48);
    g_021469FC.unk_00 = 0;
    g_021469FC.unk_04 = 0;
    g_021469FC.unk_08 = 0;
    func_0203F46C((struct RtcRequest *)(&g_021469FC));
}
