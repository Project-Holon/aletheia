/*
 * function: func_021C8904
 * address: 0x021C8904
 * packet: pkt_ov128_021C8904
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   func_021C8A80 0x021C8A80 thumb ov128
 *   func_021C8B90 0x021C8B90 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201283C(const void *);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021C8A50(void *,void *);
extern void func_021C8A80(void *,void *,void *,int,int,void *,int,u16);
extern void func_021C8B90(char *p, char *q, int unused, int i, u16 h);
void func_021C8904(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {
 int i;int offset;void *base;int found;char *row;void *v;
 base=func_0201283C(*(void **)(q+4));
 v=func_02045770(**(void ***)(p+8));
 found=0;
 func_02043B5C(v,0);
 func_021C8A50(p,r);
 offset=page*8;i=0;row=table+offset;
 for(;i<8;i++) {
  if(*(u32 *)table > offset+i) {
   func_021C8A80(p,s,r,t,i,base,(u8)row[i+8],heap);found=1;
  } else func_021C8B90(p,r,t,i,heap);
 }
 if(!found)func_02045334(**(void ***)(p+8));
}
