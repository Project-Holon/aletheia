/*
 * function: func_021D3B88
 * address: 0x021D3B88
 * packet: pkt_ov093_021D3B88
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021EFAD8 0x021EFAD8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;
extern int func_021EFAD8(char *, u32, u8);
int func_021D3B88(u32 *a, int *b, u32 *c)
{
    func_021EFAD8((char *)a[13], c[0], c[1]);
    return 1;
}
