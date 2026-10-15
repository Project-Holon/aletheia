/*
 * function: BEACON_DETAIL_GRA_InitBgSystem
 * address: 0x021BCA58
 * packet: pkt_ov216_021BCA58
 * region: ov216
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
 *   d_021BDBAC 0x021BDBAC data a4
 *   d_021BDC28 0x021BDC28 data a4
 */
typedef unsigned char u8;
struct Entry { unsigned id; char fields[32]; unsigned a,b; };
extern const unsigned d_021BDBAC[];
extern const struct Entry d_021BDC28[];
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
void BEACON_DETAIL_GRA_InitBgSystem(void *p,int heap)
{
    unsigned i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BDBAC);
    for(i=0;i<8;i++) {
        const struct Entry *e=&d_021BDC28[i];
        unsigned id=e->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        BG_SYS_FreeSlot(id);
        func_02040588(id,e->b);
    }
}
