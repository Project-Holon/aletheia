/*
 * function: func_021F6890
 * address:  0x021F6890
 * packet:   pkt_ov107_021F6890
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      MBi_MakeParentSendBuffer (libmb.TWL.HYB.a mb_block.o)
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

u8 *func_021F6890(ParentBlockHeader *hdr, u8 *sendbuf)
{
    u8 *ptr;
    u8 type;
    u16 a;
    u16 b;

    type = hdr->type;
    ptr = sendbuf;
    *ptr++ = type;
    switch (type) {
    case 4: {
        a = hdr->a;
        b = hdr->b;
        ptr[0] = a;
        ptr[1] = (a & 0xFF00) >> 8;
        ptr[2] = b;
        ptr[3] = (b & 0xFF00) >> 8;
        ptr += 4;
        break;
    }
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
        break;
    default:
        return 0;
    }
    return ptr;
}
