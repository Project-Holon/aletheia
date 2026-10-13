/*
 * function: INTRUDE_COMM_SetResultRecord
 * address: 0x02175D7C
 * packet: pkt_ov011_02175D7C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 words[15]; } Rec;
typedef struct { u8 pad[0x1a5]; u8 flag:1; u8 rest:7; } Bits;
void INTRUDE_COMM_SetResultRecord(void *unused, u8 *p, Rec *q)
{
    *(Rec *)(p + 0xac) = *q;
    ((Bits *)p)->flag = 1;
}
