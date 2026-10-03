/*
 * function: func_021DC8D0
 * address: 0x021DC8D0
 * packet: pkt_ov137_021DC8D0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCB04 0x021DCB04 thumb ov137
 *   d_021E2260 0x021E2260 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern u32 *func_021DCB04(u32,int);
extern const u8 d_021E2260[];
void *func_021DC8D0(void *q,int heap) {u8 *p;p=func_02030734((u16)heap,36,0,(const char *)d_021E2260,171);func_02082BCC(p,0,36);*(void **)(p+20)=q;*(void **)(p+24)=func_021DCB04((u32)p,heap);return p;}
