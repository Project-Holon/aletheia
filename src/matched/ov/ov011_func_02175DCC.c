/*
 * function: INTRUDE_COMM_GetRequestKind
 * address: 0x02175DCC
 * packet: pkt_ov011_02175DCC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x7c]; u32 value:4; u32 rest:28; } Bits;
extern int INTRUDE_COMM_IsSessionActive(u8 *p);
int INTRUDE_COMM_GetRequestKind(void *p)
{
    if (INTRUDE_COMM_IsSessionActive(p) == 0) return 6;
    return ((Bits *)p)->value;
}
