/*
 * function: func_021C5BE4
 * address: 0x021C5BE4
 * packet: pkt_ov093_021C5BE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5FB8 0x021D5FB8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D5FB8(u8 *);
void func_021C5BE4(u8 *p, u8 *a, int c)
{
    int n;
    func_021D59B4(a, 13);
    n = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(*(void **)(p + 12), 3, n);
    func_021CD4B0(*(void **)(p + 12), 0x43, n, c);
}
