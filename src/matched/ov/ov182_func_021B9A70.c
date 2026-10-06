/*
 * unit: no
 * function: func_021B9A70
 * address: 0x021B9A70
 * packet: pkt_ov182_021B9A70
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021B9C78 0x021B9C78 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u32 id;u32 v[8];u32 a,b;} Record;
extern const Record d_021B9C78[];
extern void func_020403F4(u32 i);
extern void func_020450C8(void),func_0203F9B4(void),func_02082BCC(void *,int,int);
void func_021B9A70(void *p){u32 i;for(i=0;i<2;i++)func_020403F4((u8)d_021B9C78[i].id);func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
