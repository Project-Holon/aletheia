/*
 * function: func_021C94DC
 * address: 0x021C94DC
 * packet: pkt_ov128_021C94DC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   d_021CA576 0x021CA576 data a1
 *   func_021C93C0 0x021C93C0 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_02035C08(const void *);
extern const u8 d_021CA576[];
extern int func_021C93C0(void *,void *,void *,int);
int func_021C94DC(void *p,void *q,void *r,int *flag) {
 int v=func_02035C08(d_021CA576);
 if(v==-1)return 2;
 *flag=1;
 if(v==0)return func_021C93C0(p,q,r,3);
 if(v==1)return func_021C93C0(p,q,r,2);
 if(v==2)return func_021C93C0(p,q,r,0);
 return func_021C93C0(p,q,r,1);
}
