/*
 * function: UNION_COMM_GetBeacon
 * address: 0x02173248
 * packet: pkt_ov012_02173248
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_COMM_BuildBeacon 0x0217325C thumb ov012
 */
typedef unsigned char u8;
typedef struct Rec { u8 b[0x64]; } Rec;
extern void UNION_COMM_BuildBeacon(u8 *self, Rec *out);
Rec *UNION_COMM_GetBeacon(u8 *p) { UNION_COMM_BuildBeacon(p, (Rec *)(p + 0x28ac)); return (Rec *)(p + 0x28ac); }
