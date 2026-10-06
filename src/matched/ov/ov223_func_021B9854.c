/*
 * function: func_021B9854
 * address: 0x021B9854
 * packet: pkt_ov223_021B9854
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047E88 0x02047E88 arm
 *   func_021B95B0 0x021B95B0 thumb ov223
 *   func_020489F4 0x020489F4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   func_02011510 0x02011510 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 *   d_021BC7AC 0x021BC7AC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021BC7AC[];
extern u16 func_02047E88(void *, const void *);
struct G3dSys;
struct Record;
extern struct Record *func_021B95B0(u32 heap, u32 count);
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void *func_02011510(u32 heap, u32 b, u32 c, u32 d);
extern unsigned func_021BC52C(u8 *p);
extern void func_02011B8C(void *, void *);
void func_021B9854(u8 *p)
{
    u16 i;
    u32 n;
    u16 j;
    u8 *rec;
    u32 r;
    void *h;
    *(u16 *)(p + 0x2C) = func_02047E88(*(void **)(p + 0x28), d_021BC7AC);
    *(u16 *)(p + 0x3A) = 1;
    *(void **)(p + 0x3C) = func_021B95B0(*(u16 *)p, *(u16 *)(p + 0x3A));
    r = func_020489F4(*(void **)(p + 0x28), *(u16 *)(p + 0x2C));
    *(u16 *)(p + 0x30) = 0;
    rec = *(u8 **)(p + 0x3C);
    *(u16 *)rec = r;
    *(u32 *)(rec + 0x40) = 1;
    for (i = 0; i < *(u16 *)(p + 0x3A); i++) {
        h = (void *)func_02048A18(*(void **)(p + 0x28), *(u16 *)(*(u8 **)(p + 0x3C) + i * 0x44));
        n = func_0204779C(h);
        for (j = 0; j < n; j++) {
            func_020477A4(h, j);
        }
    }
    *(void **)(p + 0x40) = func_02011510(*(u16 *)p, 0xCD, 0x21, 0xA);
    func_02011B8C((void *)func_021BC52C(*(u8 **)(p + 0x14)), *(void **)(p + 0x40));
    *(u32 *)(p + 0x50) = 0;
}
