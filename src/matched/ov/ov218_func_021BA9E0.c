/*
 * function: func_021BA9E0
 * address: 0x021BA9E0
 * packet: pkt_ov218_021BA9E0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 020403F4 argument is explicitly narrowed by lsls/lsrs at 021BA9F0/021BA9F2, so extern uses u8 instead of legacy u32.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021BAF28 0x021BAF28 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
extern const u32 d_021BAF28[];extern void func_020403F4(u8);extern void func_020450C8(void);extern void func_0203F9B4(void);extern void func_02082BCC(void *,int,int);
void func_021BA9E0(void *p){u32 base=(u32)d_021BAF28;u32 i;for(i=0;i<7;i++)func_020403F4(*(const u32 *)(base+i*44));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
