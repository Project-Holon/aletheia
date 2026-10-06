/*
 * function: func_021B7970
 * address: 0x021B7970
 * packet: pkt_ov103_021B7970
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: drop contested ov103 hints on the 927C/9298 tables after checking
 * pool slots 7AD8/7AE0; data a4 resolves both as sole-ref, same exact bytes.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_021B9060 0x021B9060 thumb ov103
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B924C 0x021B924C data ov103 a4
 *   d_021B927C 0x021B927C data a4
 *   d_021B9298 0x021B9298 data a4
 *   d_021B9310 0x021B9310 data ov103 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 d_021B924C[], d_021B927C[], d_021B9298[];
extern const u32 d_021B9310[][8];
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_021B9060(int, u16);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_0207D63C(int, int, int, int, int);
void func_021B7970(u32 *p, u16 heap)
{
    int i;
    u32 layer;
    void *arc;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021B924C);
    for (i = 0; i < 7; i++) {
        layer = d_021B927C[i];
        func_0203FCA0((u8)layer, (const struct BgTemplate *)d_021B9310[i], (u8)d_021B9298[i]);
        func_020414AC(layer);
        func_02040588(layer, 1);
    }
    arc = func_020490F4(94, heap);
    func_02049B68(arc, 1, 0, 0, 0, heap);
    func_02049B68(arc, 1, 4, 0, 0, heap);
    func_02049B68(arc, 6, 0, 0x120, 0, heap);
    func_02049658(arc, 2, 3, 0, 0, 0, heap);
    func_02049658(arc, 0, 6, 0, 0, 0, heap);
    func_02049658(arc, 48, 4, 0, 0, 0, heap);
    func_02049658(arc, 5, 2, 0, 0, 0, heap);
    func_020498F4(arc, 3, 3, 0, 0, 0, heap);
    func_020498F4(arc, 4, 6, 0, 0, 0, heap);
    func_020498F4(arc, 45, 4, 0, 0, 0, heap);
    func_020498F4(arc, 7, 2, 0, 0, 0, heap);
    func_021B9060(1, heap);
    func_02040C14(5, 0, 1, 0);
    p[0] = func_02049740(arc, 49, 5, 0, 0, heap);
    func_02049238(arc);
    func_0207D63C(0x04000050, 5, 12, 13, 8);
}
