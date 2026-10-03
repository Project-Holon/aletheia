/*
 * function: func_021DA854
 * address: 0x021DA854
 * packet: pkt_ov121_021DA854
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   d_021DFBA0 0x021DFBA0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DFBA0[];
extern void *func_02030734(u16,u32,int,const char *,u32);
extern void func_02082BCC(void *,int,u32);
extern void func_021DA8B0(void *,void *);
void *func_021DA854(void *a,void *b,u16 heap) { u8 *p; p=func_02030734(heap,20,0,d_021DFBA0,0x61c); func_02082BCC(p,0,20); *(void **)(p+12)=a; func_021DA8B0(p,b); return p; }
