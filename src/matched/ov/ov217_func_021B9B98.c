/*
 * function: func_021B9B98
 * address: 0x021B9B98
 * packet: pkt_ov217_021B9B98
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021B9C52..021B9C54 zero alignment padding.
 * symbols:
 *   func_021BA67C 0x021BA67C thumb ov217
 *   func_021BA5BC 0x021BA5BC thumb ov217
 *   func_021BA5F8 0x021BA5F8 thumb ov217
 *   func_021BA63C 0x021BA63C thumb ov217
 *   func_021BA560 0x021BA560 thumb ov217
 *   func_021BA698 0x021BA698 thumb ov217
 *   func_021BA768 0x021BA768 thumb ov217
 *   func_021BA7B8 0x021BA7B8 thumb ov217
 *   func_021BA7E0 0x021BA7E0 thumb ov217
 *   func_021BA830 0x021BA830 thumb ov217
 *   func_021BA86C 0x021BA86C thumb ov217
 *   func_021BA910 0x021BA910 thumb ov217
 *   func_021BA978 0x021BA978 thumb ov217
 *   func_021BA9FC 0x021BA9FC thumb ov217
 *   func_021BAA48 0x021BAA48 thumb ov217
 *   func_021BAAD8 0x021BAAD8 thumb ov217
 *   func_021BAB0C 0x021BAB0C thumb ov217
 *   func_021BAB70 0x021BAB70 thumb ov217
 *   func_021BAB58 0x021BAB58 thumb ov217
 *   func_021BA3B4 0x021BA3B4 thumb ov217
 *   func_021BA2FC 0x021BA2FC thumb ov217
 *   func_021BA19C 0x021BA19C thumb ov217
 *   func_021BA144 0x021BA144 thumb ov217
 *   func_021BA284 0x021BA284 thumb ov217
 *   func_021BA3E8 0x021BA3E8 thumb ov217
 *   func_021BA354 0x021BA354 thumb ov217
 *   func_021BA150 0x021BA150 thumb ov217
 * Original reloads p before 7B8/830/BAB58 despite their unused entry r0.
 * BA144 visibly receives classification in r1; retain that argument.
 */
extern void func_021BA67C(unsigned);
extern void func_021BA5BC(unsigned);
extern void func_021BA5F8(void *);
extern void func_021BA63C(void *);
extern void func_021BA560(char *);
extern void func_021BA698(char *);
extern void func_021BA768(char *);
extern unsigned func_021BA7B8(void *);
extern void func_021BA7E0(char *);
extern unsigned func_021BA830(void *);
extern void func_021BA86C(char *);
struct Context;
extern void func_021BA910(struct Context *);
extern void func_021BA978(struct Context *);
extern void func_021BA9FC(void *);
extern void func_021BAA48(char *);
extern void func_021BAAD8(char *);
extern void func_021BAB0C(void *);
extern void func_021BAB70(unsigned);
extern void func_021BAB58(void *);
extern unsigned func_021BA3B4(unsigned,unsigned);
extern unsigned func_021BA2FC(unsigned);
extern unsigned func_021BA19C(unsigned char *);
extern void func_021BA144(unsigned char *,unsigned);
extern unsigned func_021BA284(unsigned);
extern unsigned func_021BA3E8(unsigned,unsigned);
extern void func_021BA354(void);
extern void func_021BA150(void *);
void func_021B9B98(char *p)
{
    unsigned kind;
    func_021BA67C((unsigned)p);func_021BA5BC((unsigned)p);
    func_021BA5F8(p);func_021BA63C(p);func_021BA560(p);
    func_021BA698(p);func_021BA768(p);func_021BA7B8(p);
    func_021BA7E0(p);func_021BA830(p);func_021BA86C(p);
    func_021BA910((struct Context *)p);func_021BA978((struct Context *)p);
    func_021BA9FC(p);func_021BAA48(p);func_021BAAD8(p);
    func_021BAB0C(p);func_021BAB70((unsigned)p);func_021BAB58(p);
    if (func_021BA3B4((unsigned)p,0)==0)func_021BA2FC((unsigned)p);
    kind=func_021BA19C((unsigned char *)p);
    func_021BA144((unsigned char *)p,func_021BA19C((unsigned char *)p));
    if (kind==2) {func_021BA284(*(unsigned *)(p+0x28));func_021BA3E8((unsigned)p,0);}
    func_021BA354();func_021BA150(p);
}
