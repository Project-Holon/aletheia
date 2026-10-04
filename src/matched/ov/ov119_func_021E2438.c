/*
 * function: func_021E2438
 * address: 0x021E2438
 * packet: pkt_ov119_021E2438
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021E0E4C 0x021E0E4C thumb ov119
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_021E0E4C(char *p);
void func_021E2438(char *p,int i)
{
    if (*(int *)(p+0x5bc+4*i)) {
        func_02043B5C(func_02045770((struct Descriptor *)*(int *)(p+0x5bc+4*i)),0);
        func_020456F8((struct Descriptor *)(*(int *)(p+0x5bc+4*i)));
        func_020452E8((struct Descriptor *)(*(int *)(p+0x5bc+4*i)));
        func_02041B6C(3);
        *(int *)(p+0x5bc+4*i)=0;
        func_021E0E4C(p+0x8c4+20*(i+1));
    }
}
