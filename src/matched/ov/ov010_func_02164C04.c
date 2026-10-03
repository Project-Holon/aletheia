/*
 * function: func_02164C04
 * address: 0x02164C04
 * packet: pkt_ov010_02164C04
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02010360 0x02010360 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02010360(int idx, void *heap);
void func_02164C04(u8 *p){*(u32 *)(p+4)=1; *(void **)(p+0x80)=func_02010360(4,(void *)0x8005);}
