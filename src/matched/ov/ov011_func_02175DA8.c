/*
 * function: func_02175DA8
 * address: 0x02175DA8
 * packet: pkt_ov011_02175DA8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef struct { u8 pad[0x1a5]; u8 flag:1; u8 rest:7; } Bits;
typedef struct { u8 pad[0x2c]; u8 value; } Rec;
int func_02175DA8(u8 *p)
{
    Rec *r;
    r = (Rec *)(p + 0xac);
    if (((Bits *)p)->flag == 1 && r->value != 4) return 1;
    return 0;
}
