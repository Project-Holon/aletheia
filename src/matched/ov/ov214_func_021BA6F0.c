/*
 * function: func_021BA6F0
 * address: 0x021BA6F0
 * packet: pkt_ov214_021BA6F0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA792 alignment padding (two zero bytes).
 * note: BAD08 accepts the visible obj/p inputs although its stub ignores them.
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BAD08 0x021BAD08 thumb ov214
 */
typedef unsigned char u8;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void func_021BAD08(void*,char*);
void func_021BA6F0(void*obj,char*p)
{
    void*h;
    *(int*)(p+0xac)=0;
    *(int*)(p+0xb0)=0;
    func_0201C6EC((struct PrintSys *)(*(int*)(p+0x14)));
    func_02043B5C(func_02045770(*(void**)(p+0x94)),0);
    h=*(void**)(p+0x94);
    func_02045334(h);func_02045374(h);func_02041B6C(func_02045730(h));
    *(int*)(p+0xa4)=1;
    func_0201C6EC((struct PrintSys *)(*(int*)(p+0x18)));
    func_02043B5C(func_02045770(*(void**)(p+0x98)),0);
    h=*(void**)(p+0x98);
    func_02045334(h);func_02045374(h);func_02041B6C(func_02045730(h));
    *(int*)(p+0xa8)=1;
    if(*(int*)(p+0x3c))func_021BAD08(obj,p);
    *(int*)(p+0xbc)=0;
    *(unsigned short*)(p+0xc0)=0;
}
