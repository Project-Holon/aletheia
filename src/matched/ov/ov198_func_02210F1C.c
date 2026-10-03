/*
 * function: func_02210F1C
 * address: 0x02210F1C
 * packet: pkt_ov198_02210F1C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Group the unsigned address sum as base plus row, then column, then offset.
 * symbols:
 *   func_0202F72C 0x0202F72C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0202F72C(void *,u16,u16);
u32 func_02210F1C(u8 *p) { u8 *q;unsigned long i;int row;q=*(u8 **)p;i=q[75];if(i==4)return 0;row=(u32)p+q[32]*76;return func_0202F72C(*(void **)q,*(u16 *)(row+i*8+48),*(u16 *)(q+16)); }
