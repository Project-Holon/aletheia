/*
 * function: func_021BA650
 * address: 0x021BA650
 * packet: pkt_ov214_021BA650
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA69E alignment padding (two zero bytes).
 * spelling: Add i*4 before the field offset to retain the in-loop base adds.
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
extern void func_0201C6EC(int);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
void func_021BA650(int unused,char*p)
{
    u8 i;
    void*h;
    for(i=0;i<=1;i++){
        func_0201C6EC(*(int*)(p+0x10));
        func_02043B5C(func_02045770(*(void**)(p+i*4+0x8c)),0);
        h=*(void**)(p+i*4+0x8c);
        func_02045334(h);
        func_02045374(h);
        func_02041B6C(func_02045730(h));
        *(int*)(p+i*4+0x9c)=1;
    }
}
