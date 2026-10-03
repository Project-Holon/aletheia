/*
 * function: func_021C9EFC
 * address: 0x021C9EFC
 * packet: pkt_ov128_021C9EFC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * volatile: 021C9F1E rereads loop bound field, also entry021C9F0E.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y,z,pad;u32 value;void *items[8];volatile u32 count[8];} Record;
void func_021C9EFC(Record *p,u32 index) {u8 i;if(p->items[index]){for(i=0;i<p->count[index];i++) {} p->items[index]=0;p->count[index]=0;}}
