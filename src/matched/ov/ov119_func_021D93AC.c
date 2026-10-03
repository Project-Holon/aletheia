/*
 * function: func_021D93AC
 * address: 0x021D93AC
 * packet: pkt_ov119_021D93AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_021DF8A0 0x021DF8A0 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern void func_021DF8A0(void *, int, int);
void func_021D93AC(u32 a, u32 b, u8 *src, void *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_02039338())
            func_021DF8A0(base, *src, 1);
    }
}
