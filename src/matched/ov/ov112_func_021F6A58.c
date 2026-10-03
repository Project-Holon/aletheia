/*
 * function: func_021F6A58
 * address: 0x021F6A58
 * packet: pkt_ov112_021F6A58
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Load adds the index before offset eight; the call adds offset eight before the index.
 * symbols:
 *   func_021F6A80 0x021F6A80 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F6A80(char *,u32 *);
void func_021F6A58(char *p) {int i;for(i=0;i<5;i++)if(*(u32 *)(p+i*28+8)==1)func_021F6A80(p,(u32 *)(p+8+i*28));}
