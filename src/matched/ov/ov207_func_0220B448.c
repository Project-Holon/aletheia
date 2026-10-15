/*
 * function: ZUKAN_TOROKU_GRAPHIC_InitBg
 * address: 0x0220B448
 * packet: pkt_ov207_0220B448
 * region: ov207
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
 *   d_0220BABC 0x0220BABC data a4
 *   d_0220BB18 0x0220BB18 data a4
 */
typedef unsigned char u8;
struct Entry { unsigned id; char fields[32]; unsigned a,b; };
extern const unsigned d_0220BABC[];
extern const struct Entry d_0220BB18[];
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
void ZUKAN_TOROKU_GRAPHIC_InitBg(void *p,int heap)
{
    unsigned i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_0220BABC);
    for(i=0;i<4;i++) {
        const struct Entry *e=&d_0220BB18[i];
        unsigned id=e->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        BG_SYS_FreeSlot(id);
        func_02040588(id,e->b);
    }
}
