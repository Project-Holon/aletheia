/*
 * function: func_021743B4
 * address: 0x021743B4
 * packet: pkt_ov011_021743B4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry;
u32 func_02026478(void *obj);
int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
int func_021743B4(char *p)
{
    func_02026478((void *)(((int *)p)[1]));
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x21d, 4, (u32)(p + 0x354));
}
