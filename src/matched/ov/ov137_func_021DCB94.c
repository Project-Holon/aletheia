/*
 * function: func_021DCB94
 * address: 0x021DCB94
 * packet: pkt_ov137_021DCB94
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate q=(u8 *)((u32)p+4) keeps the updated buffer base;
 *   assigning p+=4 or retaining an integer parameter gave 50 bytes/DIFF.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020399A8(void);
extern void func_02082D44(const void *,void *,u32);
extern int func_0203D3A8(void *,u16,u16,u32);
void func_021DCB94(u8 *p,u32 id,const void *data,u32 size) {u8 *q;void *v;v=func_020399A8();q=(u8 *)((u32)p+4);func_02082D44(data,q+4,size);func_0203D3A8(v,id,size+4,(u32)q+4);}
