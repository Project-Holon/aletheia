/*
 * function: INTRUDE_COMM_SendValueNow
 * address: 0x02176850
 * packet: pkt_ov011_02176850
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: followers 02176870 and 02176880 already filed separately.
 * symbols:
 *   INTRUDE_COMM_SendPageRequest 0x02174854 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 value : 3; } Flag;
typedef struct { u8 value; u8 enabled; } Pair;
extern int INTRUDE_COMM_SendPageRequest(u8 *p, int key, int data);
int INTRUDE_COMM_SendValueNow(u8 *p, u8 value)
{
    Pair pair;
    pair.value = value;
    pair.enabled = 1;
    return INTRUDE_COMM_SendPageRequest(p, (u8)((Flag *)(p + 0x86))->value, (int)&pair);
}
