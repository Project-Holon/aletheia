/*
 * function: func_02173B4C
 * address: 0x02173B4C
 * packet: pkt_ov012_02173B4C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02008468 0x02008468 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0203D3A8 0x0203D3A8 arm
 * Live r0 return and narrowed third argument observed at send call;
 * matched wrapper copies fourth full-word payload unchanged.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
void func_02173B4C(u8 *p)
{
    u32 link;
    int n;
    link = (u32)func_020399A8();
    n = func_02008468();
    func_0203D3A8((struct Entry *)link, 0x1405, n, (u32)func_02012944(*(void **)(*(u8 **)p + 8)));
}
