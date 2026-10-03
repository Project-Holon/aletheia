/*
 * function: func_021C6360
 * address: 0x021C6360
 * packet: pkt_ov128_021C6360
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C658C 0x021C658C thumb ov128
 *   func_021C6354 0x021C6354 thumb ov128
 *   func_020056A0 0x020056A0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C658C(char *,void *,int);
extern void func_021C6354(void *,char *);
extern void *func_020056A0(void *,void *,int);
void func_021C6360(char *p,int heap) {func_021C658C(p+4,p+0x190,heap); if(!*(void **)(p+0x5a8)) *(void **)(p+0x5a8)=func_020056A0(func_021C6354,p,16);}
