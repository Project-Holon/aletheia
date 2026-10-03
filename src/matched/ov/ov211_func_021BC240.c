/*
 * function: func_021BC240
 * address: 0x021BC240
 * packet: pkt_ov211_021BC240
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: caller consumes r0 from legacy void 0203159C allocation wrapper.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 */
struct Obj0203159C;extern void func_0203064C(void *,unsigned,unsigned);extern void *func_0203159C(struct Obj0203159C *,unsigned,unsigned);extern void func_02082BCC(void *,int,int);
int func_021BC240(struct Obj0203159C *obj,int unused,unsigned value){unsigned char *p;func_0203064C((void *)1,126,0x60000);p=func_0203159C(obj,16,126);func_02082BCC(p,0,16);*(unsigned *)p=value;return 1;}
