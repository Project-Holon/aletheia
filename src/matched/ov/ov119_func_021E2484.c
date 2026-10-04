/*
 * function: func_021E2484
 * address: 0x021E2484
 * packet: pkt_ov119_021E2484
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045334 0x02045334 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021E0E4C 0x021E0E4C thumb ov119
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern void func_02045334(struct Descriptor *);
extern void func_020452E8(struct Descriptor *d);
extern void func_021E0E4C(char *p);
extern void func_021E5EF8(void *);
void func_021E2484(char *p,int a)
{
    func_021E0E4C(p+0x8c4);
    func_021E5EF8(p+0x950);
    func_021E5EF8(p+0x964);
    func_021E5EF8(p+0x978);
    if (*(int *)(p+0x6b4)) {
        func_02043B5C(func_02045770((struct Descriptor *)*(int *)(p+0x6b4)),0);
        if(a) {
            func_020456F8((struct Descriptor *)(*(int *)(p+0x6b4)));
            func_02045334((struct Descriptor *)*(int *)(p+0x6b4));
        }
        func_020452E8((struct Descriptor *)(*(int *)(p+0x6b4)));
        *(int *)(p+0x6b4)=0;
    }
}
