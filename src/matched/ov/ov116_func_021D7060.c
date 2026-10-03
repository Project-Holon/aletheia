/*
 * function: func_021D7060
 * address: 0x021D7060
 * packet: pkt_ov116_021D7060
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes after the epilogue.
 * symbols:
 *   func_021C9530 0x021C9530 arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 *   func_0200DE94 0x0200DE94 thumb
 *   func_0200DEA0 0x0200DEA0 thumb
 */
typedef unsigned char u8;
struct Blk1AC;
struct RecSlot;
extern u8 func_0200DE94(struct RecSlot *p);
extern u8 func_0200DEA0(struct RecSlot *p);
extern u8 func_0200DCFC(struct Blk1AC *p);
extern void func_021C9530(u8,u8,u8,void *,void *,int);
extern void func_021D70E4(u8 *);
void func_021D7060(u8 *p, u8 *q) {
    int a, b, c;
    a = func_0200DE94(*(void **)(p + 0x160));
    b = func_0200DEA0(*(void **)(p + 0x160));
    c = func_0200DCFC(*(void **)(p + 0x164));
    func_021C9530(a,b,c,p+0x70,p+0x16e,0x80);
    func_021D70E4(q);
}
