/*
 * function: func_021E94AC
 * address: 0x021E94AC
 * packet: pkt_ov170_021E94AC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CF8C 0x0202CF8C thumb
 */
typedef struct {
 unsigned char pad[0x1A6];
 unsigned char flag:1;
 unsigned char rest:7;
 unsigned char lo:4;
 unsigned char hi:4;
 unsigned char a,b,d,c,f,g;
} Work;
typedef struct {
 unsigned char pad[0x28];
 int value;
 Work *work;
} Obj;
extern unsigned char func_0202CF8C(int,unsigned);
int func_021E94AC(Obj *p,int a,int b) {
 p->work->flag=1;
 p->work->rest=func_0202CF8C(*(int *)((char *)p->work+0x74),7);
 p->work->lo=13;
 p->work->hi=12;
 p->work->a=0;
 p->work->b=0;
 if(a==0) p->work->c=14;
 else p->work->c=17;
 p->work->d=21;
 p->work->f=11;
 p->work->g=3;
 p->value=b;
 return 8;
}
