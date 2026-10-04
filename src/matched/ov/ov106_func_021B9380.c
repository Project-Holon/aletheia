/*
 * function: func_021B9380
 * address: 0x021B9380
 * packet: pkt_ov106_021B9380
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding after the return.
 * symbols:
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021B9414 0x021B9414 thumb ov106
 *   func_0201C724 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B9414(void *,int,int *);
extern void func_0201C724(void *,void *,short,short,void *,int,u16);
void func_021B9380(u8 *p,void *a,void *b,int c) {
 int xy[2];
 func_02043B5C(*(void **)p,*(u16 *)(p+4)&31);
 func_02045CAC(a,(u32)b,*(void **)(p+24));
 func_021B9414(p,c,xy);
 func_0201C724(*(void **)(p+32),*(void **)p,(short)xy[0],(short)xy[1],*(void **)(p+24),c,*(u16 *)(p+4));
 *(int *)(p+8)=1;
}
