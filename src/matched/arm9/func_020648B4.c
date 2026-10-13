/*
 * function: NNS_G2dGetMCWorkAreaSize
 * address:  0x020648B4
 * packet:   pkt_0206469C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dGetMCBankNumCellAnimRequired    0x02064648  arm
 *   NNS_G2dGetMCBankNumNodesRequired    0x020648E0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MultiCellBank;
extern u16 NNS_G2dGetMCBankNumCellAnimRequired(struct MultiCellBank *bank);
extern u16 NNS_G2dGetMCBankNumNodesRequired(struct MultiCellBank *bank);

int NNS_G2dGetMCWorkAreaSize(u32 a, u32 b)
{
    u32 v;

    if (b == 1) {
        v = NNS_G2dGetMCBankNumCellAnimRequired((struct MultiCellBank *)a) * 0x5c;
    } else {
        v = NNS_G2dGetMCBankNumNodesRequired((struct MultiCellBank *)a) << 7;
    }
    return v;
}
