/*
 * function: func_021C3678
 * address: 0x021C3678
 * packet: pkt_ov208_021C3678
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_021C3A24 0x021C3A24 thumb ov208
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor; struct CharBuf; struct Bmp;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *p, u8 v);
extern void func_02043AF4(struct Bmp *p,u32 a,u32 b,u32 c,u32 d,u32 e);
extern void func_021C3A24(u16 *heap,u8 *p,int key);
void func_021C3678(u16 *heap,u8 *p,int key)
{
    struct Bmp *bmp;
    p[0x24] = 0;
    *(u16 *)(p+0x18) = 0;
    *(u16 *)(p+0x1a) = 0;
    *(u16 *)(p+0x26) = 0;
    *(u16 *)(p+0x28) = 0;
    *(u16 *)(p+0x30) = 0;
    *(u16 *)(p+0x32) = *(s16 *)(p+0x30);
    *(u32 *)(p+0x38) = 0;
    bmp = func_02045770(*(struct Descriptor **)(p+0x20));
    func_02043B5C((struct CharBuf *)bmp,0);
    func_02043AF4(bmp,0,0x37,0xee,1,0xf);
    func_021C3A24(heap,p,key);
}
