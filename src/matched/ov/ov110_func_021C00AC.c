/*
 * function: func_021C00AC
 * address: 0x021C00AC
 * packet: pkt_ov110_021C00AC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x,y; } Vec2;
extern unsigned func_0204B3F4(void *);
extern void func_0204B3DC(void *, unsigned);
extern void func_0204B404(void *, const Vec2 *, unsigned);
extern void func_0204B878(void *, u16);
void func_021C00AC(u8 *p, unsigned i) {
    Vec2 pos;
    *(unsigned *)(p+0x18)=func_0204B3F4(*(void **)(p+0x14));
    func_0204B3DC(*(void **)(p+0x14),1);
    if (i != -1) {
        pos.x=0x70*(i&1)+0x3e;
        pos.y=0x18*((i>>1)+1);
        func_0204B404(*(void **)(p+0x14),&pos,0);
        func_0204B878(*(void **)(p+0x14),0x1c);
    }
}
