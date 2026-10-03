/*
 * function: func_021FD974
 * address: 0x021FD974
 * packet: pkt_ov132_021FD974
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* A byte parameter keeps the store input live without an entry truncation. */
void func_021FD974(char *p,u32 key,u8 value) {u8 i;for(i=0;i<4;i++){if(key==*(u8 *)((u32)p+i*0x30+0x72)){*(int *)((u32)p+i*0x30+0x6c)=1;*(u8 *)((u32)p+i*0x30+0x70)=value;}}}
