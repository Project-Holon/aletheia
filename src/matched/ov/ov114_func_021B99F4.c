/*
 * function: NHTTP_RAP_RecordList_GetValue
 * address: 0x021B99F4
 * packet: pkt_ov114_021B99F4
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Integer base q=p+1 puts q in r4 and the record address in r5;
 * the pointer-typed base swaps that pair (six concrete bytes differ).
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a,b,c,d; } Record;
u32 NHTTP_RAP_RecordList_GetValue(u32 p,u32 i) { u32 q=p+1; return (((Record *)q)[i].a<<24)|(((Record *)q)[i].b<<16)|(((Record *)q)[i].c<<8)|((Record *)q)[i].d; }
