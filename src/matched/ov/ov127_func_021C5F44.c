/*
 * function: func_021C5F44
 * address: 0x021C5F44
 * packet: pkt_ov127_021C5F44
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021C5F80 0x021C5F80 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 x,y;} Entry;
typedef struct {Entry *data;u32 count;u16 r,w;} S;
extern u32 _u32_div_f(u32,u32);
extern int func_021C5F80(S *,Entry *);
void func_021C5F44(S *p,const Entry *q) {Entry tmp; if((p->w+1u)%p->count==p->r) func_021C5F80(p,&tmp);p->data[p->w]=*q;p->w=(p->w+1u)%p->count;}
