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
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021E8B00 0x021E8B00 data a4
 *   d_021E8B5C 0x021E8B5C data a4
 */
typedef struct { unsigned id; unsigned template[8]; unsigned type; unsigned enable; } Entry;
extern const unsigned d_021E8B00[];
extern const Entry d_021E8B5C[];
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_Create(unsigned short);
extern void BMP_WIN_Init(unsigned short);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void func_021E5568(void *p, unsigned short heap)
{
    unsigned i;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021E8B00);
    for (i = 0; i < 8; i++) {
        const Entry *e = &d_021E8B5C[i];
        unsigned id = e->id;
        BG_SYS_InitBgLayer((unsigned char)id, (const struct BgTemplate *)(&e->template), (unsigned char)e->type);
        BG_SYS_FreeSlot(id);
        func_02040588(id, e->enable);
    }
}
