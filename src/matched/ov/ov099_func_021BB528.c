/*
 * function: func_021BB528
 * address: 0x021BB528
 * packet: pkt_ov099_021BB528
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring mon before kind and form restores their original spill-slot order.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02009864 0x02009864 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021C2370 0x021C2370 thumb ov099
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BB918 0x021BB918 thumb ov099
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_021C285C 0x021C285C thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_021BB374 0x021BB374 thumb ov099
 *   func_021BB460 0x021BB460 thumb ov099
 *   func_02043598 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201DD68(void);
typedef signed short   s16;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Sub020097BCObj;
struct WordSet;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021C2370(char *,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void * func_021C23B8(int);
extern unsigned func_021BDD48(char *,void *);
extern unsigned func_021BDD54(char *,void *);
extern int func_021BB918(unsigned,unsigned,int *);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void func_021BE4BC(char *p, int a, int b, int c, int d, unsigned int e, int f);
extern int func_021C285C(void *);
extern void func_021BE3CC(char *,int,int,int,int,int);
extern void func_021BB374(char *,int,int);
extern void func_021BB460(char *,int);
extern void func_02043598(u32 mask, u32 enable);
#define PTR(off) (*(void **)(p+(off)))
void func_021BB528(char *p,int v)
{
    int index;
    void *mon;
    unsigned kind,form;
    int unused;
    int message;
    func_0201DD68();
    index=*(u8 *)(p+0x8ed)-1;
    func_02009864(PTR(4),index,9);
    func_0201DD78(15,2,0);
    func_021C2370(p,index);
    func_02045CAC(PTR(0xe0),33,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7A4(func_02045770(PTR(0x958)),25,0,PTR(0xf8),PTR(0xe8));
    mon=func_021C23B8(index);
    kind=func_021BDD48(p,mon);
    form=func_021BDD54(p,mon);
    message=func_021BB918(kind,form,&unused);
    if(message>=141 && message<=144)message-=81;
    func_02045CAC(PTR(0xe0),message,PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x958)),96,0,PTR(0xf0),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),35,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),104,0,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,2),4,1,1);
    func_02045CAC(PTR(0xe0),36,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),176,24,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,3),4,1,1);
    func_02045CAC(PTR(0xe0),37,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),176,40,PTR(0xf8),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),38,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),104,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,4),4,1,1);
    func_02045CAC(PTR(0xe0),39,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),188,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),42,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),8,96,PTR(0xf8),PTR(0xe8),0x3c40);
    message=func_02009864(PTR(4),index,7);
    if(message){
        func_0201EFA4(PTR(0x8b0),2,message,2,0,1);
        func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,5),4,1,1);
        func_0201EFA4(PTR(0x8b0),1,func_02009864(PTR(4),index,6),2,0,1);
        func_02045CAC(PTR(0xe0),44,PTR(0xf0));
        func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
        func_0201C7D0(func_02045770(PTR(0x95c)),152,96,PTR(0xf8),PTR(0xe8),0x3c40);
    }
    func_02045374(PTR(0x95c));
    func_02045334(PTR(0x95c));
    func_02045374(PTR(0x958));
    func_02045334(PTR(0x958));
    func_02041B6C(7);
    func_021BE4BC(p+0x898,6,2,1,kind,form,32);
    func_021BE3CC(p+0x898,6,28,1,func_021C285C(mon)?47:43,0);
    func_021BB374(p,index,v);
    func_021BB460(p,(u16)v);
    func_02043598(16,1);
}
