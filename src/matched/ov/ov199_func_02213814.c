/*
 * function: func_02213814
 * address: 0x02213814
 * packet: pkt_ov199_02213814
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_02005E30 0x02005E30 thumb
 */
struct Obj0203159C;
extern void func_0203064C(void *,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02031324(int);
extern void func_02005E30(unsigned);
int func_02213814(struct Obj0203159C *p,int unused,char *q){void *r;func_0203064C((void *)1,88,336);r=func_0203159C(p,16,88);func_02082BCC(r,0,16);*(int *)(q+12)=0;*(void **)r=func_02031324(88);func_02005E30(16);return 1;}
