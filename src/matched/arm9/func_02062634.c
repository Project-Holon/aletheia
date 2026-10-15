/*
 * function: NNS_G2dGetUnpackedAnimBank
 * address:  0x02062634
 * packet:   pkt_02062474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dFindBinaryBlock    0x02062B64  arm
 *   NNSi_G2dUnpackAnimBank    0x02062688  arm

 * Blocking class: label.  Every concrete byte is right; the only unresolved site
 * is the tail `bl NNSi_G2dUnpackAnimBank` at 0x02062648, and 0x02062688 -- the packet's own
 * 336-byte function -- has no witness outside this file's range, because this is
 * its only caller.  The `bl NNS_G2dFindBinaryBlock` site resolves (`label x40`), so the
 * file closes on its own as soon as 0x02062688 is matched, which makes the site
 * `matched` instead of `label`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct AnimBank;
struct NitroFileHeader;
extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void NNSi_G2dUnpackAnimBank(volatile struct AnimBank *bank);

int NNS_G2dGetUnpackedAnimBank(u32 a, u32 *out)
{
    u32 r = (u32)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x41424E4B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    NNSi_G2dUnpackAnimBank((volatile struct AnimBank *)(r + 8));
    *out = r + 8;
    return 1;
}
