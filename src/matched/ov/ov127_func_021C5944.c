/*
 * function: func_021C5944
 * address: 0x021C5944
 * packet: pkt_ov127_021C5944
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4280 0x021C4280 thumb ov127
 *   func_021C4270 0x021C4270 thumb ov127
 *   func_021C42A8 0x021C42A8 thumb ov127
 *   func_021C4274 0x021C4274 thumb ov127
 *   d_021C60AC 0x021C60AC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C4280(void *);
typedef unsigned int   u32;
extern u32 func_021C4270(char *p);
struct obj;
extern void func_021C42A8(struct obj *p, int idx, int a);
extern void func_021C4274(char *p, u32 a);
extern u8 d_021C60AC[];
void func_021C5944(u8 *p, int n, int a)
{
    int v = func_021C4280(*(void **)(p+4));
    u16 old = func_021C4270(*(void **)(p+4));
    func_021C42A8(*(void **)(p+4), n, a);
    if (old != n) {
        if (d_021C60AC[n] == 1 && *(u16 *)(p+16) == n)
            func_021C4274(*(void **)(p+4), *(u16 *)(p+14));
        if (d_021C60AC[old] == 1) {
            *(u16 *)(p+16) = old;
            *(u16 *)(p+14) = v;
        }
    }
}
