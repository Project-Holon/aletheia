/*
 * function: func_021D79A8
 * address: 0x021D79A8
 * packet: pkt_ov131_021D79A8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ll_mul 0x0209C054 arm
 *   d_021DC1EC 0x021DC1EC data a4
 *   d_020A5078 0x020A5078 data a2
 *   func_021D7A1C 0x021D7A1C thumb ov131
 */
typedef struct {int x,y,z;} Vec;
extern const Vec d_021DC1EC;
extern const short d_020A5078[];
extern void func_021D7A1C(void *,void *,Vec *);
static inline int mul(int a,int b) {return (int)(((long long)a*b+0x800LL)>>12);}
void func_021D79A8(void *p,unsigned char *q,int radius) {
 Vec v=d_021DC1EC;
 *(int *)(q+76)=mul(d_020A5078[10],radius);
 *(int *)(q+80)=mul(d_020A5078[11],radius);
 *(int *)(q+84)=0;
 func_021D7A1C(p,q,&v);
}
