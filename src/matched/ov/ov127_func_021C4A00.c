/*
 * function: func_021C4A00
 * address:  0x021C4A00
 * packet:   pkt_021C4A00
 * region:   ov127
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021C4A00(void *p, int i, int v)
{
    switch (i)
    {
    case 0:
        *(u16 *)((char *)p + 4) = (u16)v;
        break;
    case 1:
        *(u16 *)((char *)p + 6) = (u16)v;
        break;
    case 2:
        *(u16 *)((char *)p + 8) = (u16)v;
        break;
    case 3:
        *(u16 *)((char *)p + 0xa) = (u16)v;
        break;
    case 4:
        *(u16 *)((char *)p + 0xc) = (u16)v;
        break;
    case 5:
        *(u8 *)((char *)p + 0x15) = (u8)v;
        break;
    case 6:
        *(u8 *)((char *)p + 0x14) = (u8)v;
        break;
    case 7:
        *(u16 *)((char *)p + 0xe) = (u16)v;
        break;
    case 8:
        *(u16 *)((char *)p + 0x10) = (u16)v;
        break;
    case 9:
        *(u16 *)((char *)p + 0x12) = (u16)v;
        break;
    case 10:
        *(u16 *)((char *)p + 0x16) = (u16)v;
        break;
    default:
        break;
    }
}
