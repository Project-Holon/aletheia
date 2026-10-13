/*
 * function: func_021E5568
 * address: 0x021E5568
 * packet: pkt_ov177_021E5568
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021E8B00 0x021E8B00 data a4
 *   d_021E8B5C 0x021E8B5C data a4
 */
typedef struct { unsigned id; unsigned template[8]; unsigned type; unsigned enable; } Entry;
extern const unsigned d_021E8B00[];
extern const Entry d_021E8B5C[];
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_0203F8F4(unsigned short);
extern void BMP_WIN_Init(unsigned short);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void func_021E5568(void *p, unsigned short heap)
{
    unsigned i;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021E8B00);
    for (i = 0; i < 8; i++) {
        const Entry *e = &d_021E8B5C[i];
        unsigned id = e->id;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)(&e->template), (unsigned char)e->type);
        func_020414AC(id);
        func_02040588(id, e->enable);
    }
}
