/*
 * function: func_021C89C4
 * address: 0x021C89C4
 * packet: pkt_ov128_021C89C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding at 0x021C8A4E; next label 0x021C8A50.
 * symbols:
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C8A50(void *,void *);
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32,int,u8,u8,u8,u8,u8);
static inline int ab(int v) {return v<0?-v:v;}
void func_021C89C4(char *p,void *q) {
 void *v;
 func_021C8A50(p,q);
 v=**(void ***)(p+8);func_020456F8(v);func_02041B6C(func_02045730(v));
 func_02041300(2,0,ab(*(s16 *)p),ab(*(s16 *)(p+2)),p[4],p[5],0);
 func_02041B6C(2);
 func_02041300(3,0,ab(*(s16 *)p),ab(*(s16 *)(p+2)),p[4],p[5],0);
 func_02041B6C(3);
}
