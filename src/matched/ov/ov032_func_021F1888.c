/*
 * function: func_021F1888
 * address: 0x021F1888
 * packet: pkt_ov032_021F1888
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02165FCC 0x02165FCC thumb ov010
 *   func_021F0DC0 0x021F0DC0 thumb ov032
 *   func_021F0A98 0x021F0A98 thumb ov032
 *   func_021F18E0 0x021F18E0 thumb ov032
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Rec Rec;
extern void func_02165FCC(Rec *r, void *win, u32 heap);
extern int func_021F0DC0(void *p);
extern void func_021F0A98(char *p, u8 b);
extern void func_021F18E0(char *p, u32 a, int *c);
void func_021F1888(char *p, Rec *r)
{
    func_02165FCC(r, *(void **)(p + 0x110), *(u16 *)(p + 0x96));
    func_021F0A98(p, func_021F0DC0(r));
    func_021F18E0(p, *(u32 *)(p + 0x11c), (int *)(p + 0xa8));
}
