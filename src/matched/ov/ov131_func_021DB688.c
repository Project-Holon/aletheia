/*
 * function: func_021DB688
 * address: 0x021DB688
 * packet: pkt_ov131_021DB688
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021D618C 0x021D618C thumb ov131
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021D618C(unsigned char *p, unsigned int a, int b, int c, unsigned short d, unsigned short e);
extern void func_020061E4(u32 a);
void func_021DB688(u8 *a,u8 *b,int c) {
    *(int *)(b+12)=1;
    func_02043B5C(func_02045770(*(void **)(b+140)),0);
    if(c==1) func_021D618C(a,(unsigned int)(*(void **)(b+140)),156,0,0,15424);
    func_020061E4(1367);
}
