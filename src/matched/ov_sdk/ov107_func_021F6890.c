/*
 * function: MBi_MakeParentSendBuffer
 * address:  0x021F6890
 * packet:   pkt_ov107_021F6890
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_MakeParentSendBuffer (libmb.TWL.HYB.a mb_block.o)
 *
 * notes:    a const header lets both halfwords load before the stores; with
 *           a plain pointer (or u16 locals) r1 and r2 swap.
 *
 * symbols:

 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 type;
    u8 pad;
    u16 a;
    u16 b;
} ParentBlockHeader;

u8 *MBi_MakeParentSendBuffer(const ParentBlockHeader *hdr, u8 *sendbuf)
{
    u8 *ptr = sendbuf;

    *ptr++ = hdr->type;
    switch (hdr->type) {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        *ptr++ = (u8)(0x00FF & hdr->a);
        *ptr++ = (u8)((0xFF00 & hdr->a) >> 8);
        *ptr++ = (u8)(0x00FF & hdr->b);
        *ptr++ = (u8)((0xFF00 & hdr->b) >> 8);
        break;
    case 5:
    case 6:
        break;
    default:
        return 0;
    }
    return ptr;
}
