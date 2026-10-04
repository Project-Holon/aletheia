/*
 * function: func_021C4290
 * address:  0x021C4290
 * packet:   pkt_ov136_021C4290
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4290 0x021C4290 thumb
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203F9B4(void *a);
extern void func_02031140(u32 v);
extern void func_0201D83C(u32 v);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_0203084C(u16 v);
extern void func_020306F0(u32 v);
int func_021C4290(void *a, void *b, void *c, u32 *p)
{
    u32 h;
    func_0203F9B4(a);
    func_02031140(p[0x40]);
    func_0201D83C(p[9]);
    h = p[0];
    func_020315D4(a);
    func_0203084C(h);
    func_020306F0((u16)h);
    return 1;
}
