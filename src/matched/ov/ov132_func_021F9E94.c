/*
 * function: func_021F9E94
 * address: 0x021F9E94
 * packet: pkt_ov132_021F9E94
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the load uses p+index*0x4848+4, while the outgoing pointer uses p+4+index*0x4848; the latter keeps p+4 hoisted in r6. Using the load's grouping for both gave 49 concrete byte differences.
 * symbols:
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   func_02050ED4 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F9F58(u8 *,u8 *);
extern void func_02050ED4(void);
extern void func_020307B0(void *);
void func_021F9E94(u8 *p) { u8 i; for(i=0;i<8;i++) { if(*(u32 *)(p+i*0x4848+4)==1) func_021F9F58(p,p+4+i*0x4848); } func_02050ED4(); func_020307B0(p); }
