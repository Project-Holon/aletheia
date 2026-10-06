/*
 * function: func_021B8A28
 * address: 0x021B8A28
 * packet: pkt_ov106_021B8A28
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return, before 0x021B8A6C.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_021B9298 0x021B9298 thumb ov106
 *   func_021B8B5C 0x021B8B5C thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct Bmp;
extern void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h);
extern void func_021B8B5C(u8 *,u32,int,u8);
void func_021B8A28(u32 *p,u32 a,u32 b,u16 c) {
    func_021B9298((const struct Bmp *)p[1],(const struct Bmp *)((u32)func_02045770((struct Descriptor *)a)),0,0,0,c,32,3);
    func_021B8B5C((u8 *)p[7],b,c,(*(u32 *)(p[0]+4)<<7)>>24);
}
