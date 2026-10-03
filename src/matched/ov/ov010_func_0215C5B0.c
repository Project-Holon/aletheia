/*
 * function: func_0215C5B0
 * address: 0x0215C5B0
 * packet: pkt_ov010_0215C5B0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_020127A4 0x020127A4 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C274 0x0200C274 thumb
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *a0, void *a1);
typedef unsigned int   u32;
struct Blk34;
struct SaveBlock;
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_020127A4(struct SaveBlock *p);
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);

int func_0215C5B0(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    unsigned int v = func_02159B10(a, b);
    void *q = func_0215A5E4(b);
    func_020127A4(q);
    *p = v <= func_0200C274(func_02012F08(q)) ? 1 : 0;
    return 0;
}
