/*
 * function: func_021B9A10
 * address: 0x021B9A10
 * packet: pkt_ov182_021B9A10
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021B9BFC 0x021B9BFC data a4
 *   d_021B9C78 0x021B9C78 data a4
 */
extern void MI_CpuFill8(void *, int, int);
extern void func_0203F8F4(int);
extern void BMP_WIN_Init(int);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
typedef struct { unsigned id; unsigned v[8]; unsigned a, b; } Record;
extern const unsigned d_021B9BFC[];
extern const Record d_021B9C78[];
void func_021B9A10(void *p, int heap)
{
    unsigned i = 0;
    const Record *r;
    unsigned id;
    MI_CpuFill8(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021B9BFC);
    for (; i < 2; i++) {
        r = &d_021B9C78[i];
        id = r->id;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)r->v, (unsigned char)r->a);
        func_020414AC(id);
        func_02040588(id, r->b);
    }
}
