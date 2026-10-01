/*
 * function: func_021BF404
 * address: 0x021BF404
 * packet: pkt_ov203_021BF404
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 */
typedef struct { char *ctx;int pad4[2];int c;int a;int b;void *text;void *window;int pad20[2]; } Work;
extern void func_02082BCC(void *,int,int),func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short),func_02043B5C(void *,unsigned char);
extern void *func_0201F5DC(void *,unsigned,unsigned,unsigned),*func_02045770(void *);
extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
void func_021BF404(char *p,Work *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    func_02082BCC(out,0,0x28);
    out->a=a;out->c=c;out->ctx=p;out->b=b;
    out->text=func_0201F5DC((void *)1,0,1,*(unsigned short *)(p+2));
    func_02049B40(23,5,0,32,32,*(unsigned short *)(p+2));
    out->window=(void *)func_020450F0(1,d,e,f,g,1,0);
    func_02043B5C(func_02045770(out->window),15);
}
