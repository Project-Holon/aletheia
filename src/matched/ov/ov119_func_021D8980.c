/*
 * function: func_021D8980
 * address: 0x021D8980
 * packet: pkt_ov119_021D8980
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status:   EXACT*
 * 2026-10-02: the first call's target 021B65B4 (thumb, ov067 window) was an
 *  unlabelled tail-call stub; seeded in layout/function_starts.txt and matched
 *  as src/matched/ov/ov067_func_021B65B4.c, so every call now resolves.
 * symbols:
 *   func_021B65B4 0x021B65B4 thumb ov067
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 */
typedef unsigned int u32;
extern void func_021B65B4(u32 *p, u32 a1);
extern void func_021B6558(u32 *p, u32 a1, u32 a2);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
void func_021D8980(char *p)
{
    func_021B65B4(*(u32 **)(p + 0x9c0), 1);
    func_021B6558(*(u32 **)(p + 0x9c0), 1, 1);
    func_021B6548((unsigned char *)(*(u32 **)(p + 0x9c0)), 1, 1);
}
