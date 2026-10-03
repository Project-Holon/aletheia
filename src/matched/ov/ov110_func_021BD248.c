/*
 * function: func_021BD248
 * address: 0x021BD248
 * packet: pkt_ov110_021BD248
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BD248(u8 *p)
{
    func_0204B3DC(*(void **)(p+0x28),1);
    func_0204B878(*(void **)(p+0x28),1);
    *(int *)(p+0x2c)=0;
}
