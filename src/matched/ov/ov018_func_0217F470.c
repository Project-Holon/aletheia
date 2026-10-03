/*
 * function: func_0217F470
 * address: 0x0217F470
 * packet: pkt_ov018_0217F470
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02190758 0x02190758 thumb ov021
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190758(void *, u16, u16, void *);
void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b)
{
    func_02045CAC(bank, index, p[2]);
    func_0201F250(p[0], p[1], p[2]);
    func_02190758(handle, a, b, p[1]);
}
