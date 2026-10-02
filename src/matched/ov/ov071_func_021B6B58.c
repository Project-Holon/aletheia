/*
 * function: func_021B6B58
 * address: 0x021B6B58
 * packet: pkt_ov071_021B6B58
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021B6B6E.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02025774 0x02025774 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *, u32);
extern void func_02025774(u8 *, u32);
void func_021B6B58(void **p, u32 v)
{
    func_0204B3DC(p[0], v);
    func_02025774(p[1], v);
}
