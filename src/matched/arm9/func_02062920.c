/*
 * function: NNS_G2dGetUnpackedMultiCellBank
 * address:  0x02062920
 * packet:   pkt_02062884
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dFindBinaryBlock    0x02062B64  arm
 *   NNSi_G2dUnpackMultiCellBank    0x0206296C  arm

 * Blocking class: label.  Same shape as src/pending/NNS_G2dGetUnpackedAnimBank.c one tag over:
 * every concrete byte is right, the only unresolved site is the tail
 * `bl NNSi_G2dUnpackMultiCellBank` at 0x02062934, and this call is the only branch to
 * 0x0206296C in the image.  The `bl NNS_G2dFindBinaryBlock` site resolves (`label x40`).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MultiCellBank;
struct NitroFileHeader;
extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void NNSi_G2dUnpackMultiCellBank(volatile struct MultiCellBank *bank);

int NNS_G2dGetUnpackedMultiCellBank(u32 a, u32 *out)
{
    u32 r = (u32)NNS_G2dFindBinaryBlock((struct NitroFileHeader *)a, 0x4D43424B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    NNSi_G2dUnpackMultiCellBank((volatile struct MultiCellBank *)(r + 8));
    *out = r + 8;
    return 1;
}
