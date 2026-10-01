/*
 * function: func_02184FC8
 * address: 0x02184FC8
 * packet: pkt_ov219_02184FC8
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 20CF8 legacy one parameter; original also visibly sets r1
 * to full-width heap, retained as a second input even though body ignores it.
 * symbols:
 *   func_0201DC80 0x0201DC80 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02184EAC 0x02184EAC thumb ov219
 */
typedef unsigned short u16;
struct Src {unsigned w[13];};
struct Font;struct Obj;struct Descriptor;
extern unsigned func_0201DC80(struct Font *);
extern struct Obj *func_0201FF30(struct Src *,u16,u16,u16);
extern void func_02020CF8(struct Obj *,unsigned),func_0201F73C(void *,int,int,int);
extern void func_02045334(struct Descriptor *),func_02184EAC(int,int,int);
void func_02184FC8(char *p,const struct Src *source,unsigned count)
{
    struct Src cfg;
    *(void **)(p+0xc078)=*(void **)(p+0xc018);p[0xc07c]=0;
    cfg=*source;
    cfg.w[0]=*(unsigned *)(p+0xc050);
    *(u16 *)((char *)&cfg+16)=count;
    cfg.w[3]=*(unsigned *)(p+0xc018);
    cfg.w[1]=(unsigned)func_02184EAC;
    *(u16 *)((char *)&cfg+32)=12;
    *(u16 *)((char *)&cfg+34)=func_0201DC80(*(struct Font **)(p+0xc06c));
    cfg.w[10]=(unsigned)(p+0xc078);
    cfg.w[11]=*(unsigned *)(p+0xc080);
    cfg.w[12]=*(unsigned *)(p+0xc06c);
    *(struct Obj **)(p+0xc04c)=func_0201FF30(&cfg,0,0,(u16)*(unsigned *)p);
    func_02020CF8(*(struct Obj **)(p+0xc04c),*(unsigned *)p);
    func_0201F73C(*(void **)(p+0xc018),0,34,7);
    func_02045334(*(struct Descriptor **)(p+0xc018));
}
