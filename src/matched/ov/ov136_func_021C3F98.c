/*
 * function: func_021C3F98
 * address:  0x021C3F98
 * packet:   pkt_ov136_021C3F98
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C3F98 0x021C3F98 thumb
 *   func_021C4134 0x021C4134 thumb
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0203133C(u32 v);
extern void func_021C4134(void *p);
extern void func_020315D4(u32 v);
extern void func_0203084C(u32 v);
extern void func_020306F0(u32 v);
int func_021C3F98(u32 a, void *b, void *c, u32 *p)
{
    u32 h;
    func_0203133C(p[7]);
    func_021C4134((void *)p[4]);
    h = (u16)p[0];
    func_020315D4(a);
    func_0203084C(h);
    func_020306F0(h);
    return 1;
}
