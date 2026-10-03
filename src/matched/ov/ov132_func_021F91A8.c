/*
 * function: func_021F91A8
 * address: 0x021F91A8
 * packet: pkt_ov132_021F91A8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A380 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void *func_0204A380(u32,u32,u32,u16);
extern void *func_021FAD0C(void *,void *,int,u8);
void func_021F91A8(char *p,u32 n,u8 mask){void *table;table=func_0204A380(*(u32 *)(p+0x18),n+0x4b,0,*(u16 *)p);func_021FAD0C(*(void **)(p+0xb0),table,0,mask);}
