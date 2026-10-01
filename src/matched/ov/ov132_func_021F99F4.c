/*
 * function: func_021F99F4
 * address: 0x021F99F4
 * packet: pkt_ov132_021F99F4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9E0C 0x021F9E0C thumb ov132
 *   func_021F5140 0x021F5140 thumb ov112
 *   func_02157394 0x02157394 thumb ov010
 *   func_021F95F0 0x021F95F0 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021F9E0C(char *);
extern int func_021F5140(void *, u16);
extern u16 func_02157394(void *, u8);
extern void func_021F95F0(u8 *);
int func_021F99F4(char *p, unsigned i, unsigned j)
{
    u16 v;
    u8 old;
    v = func_02157394(*(void **)(*(char **)(p + 0x30) + 0x14), func_021F5140(func_021F9E0C(p), *(u16 *)(*(char **)(*(char **)(p + 0x30) + i * 4 + 4) + j * 6 + 0x14)));
    old = *(u8 *)(p + 0xf7 + i);
    *(u8 *)(p + 0xf7 + i) = old + v;
    func_021F95F0((u8 *)p);
    return (unsigned)v >= 7 ? 1579 : 1580;
}
