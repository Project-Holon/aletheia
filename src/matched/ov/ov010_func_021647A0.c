/*
 * function: func_021647A0
 * address: 0x021647A0
 * packet: pkt_ov010_021647A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021729B0 0x021729B0 data ov010 a1
 *   func_021647F0 0x021647F0 thumb ov010
 *   func_021647FC 0x021647FC thumb ov010
 *   func_02164890 0x02164890 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02030734(u32,u32,int,const char *,u32);
extern const char d_021729B0[];
extern void func_021647F0(u8 *);
extern void func_021647FC(u8 *);
extern void func_02164890(u8 *);
u8 *func_021647A0(void *a,u32 b){u8 *p=func_02030734(b,0x11c,0,d_021729B0,0x53);func_021647F0(p);*(u16 *)p=b;*(void **)(p+4)=a;func_021647FC(p);func_02164890(p);return p;}
