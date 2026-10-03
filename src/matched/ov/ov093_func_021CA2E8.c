/*
 * function: func_021CA2E8
 * address: 0x021CA2E8
 * packet: pkt_ov093_021CA2E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 021CA316 are alignment padding.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D67D8(u8 *, u32);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
struct Msg;
extern int func_021C99A0(void *, const struct Msg *);
int func_021CA2E8(u8 *p, const u8 *q)
{
    func_021D67D8(func_021B9934(*(char **)(p + 8), q[4]), *(const u16 *)(q + 6));
    func_021CD4B0(*(void **)(p + 12), 20, q[4], *(const u16 *)(q + 6));
    func_021C99A0(p, (const struct Msg *)(q + 8));
    return 1;
}
