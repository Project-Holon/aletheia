/*
 * function: TOWNMAP_GRH_Create
 * address:  0x021BB6E8
 * packet:   pkt_ov072_021BB6E8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   TOWNMAP_GRH_ResetDisplay  0x021BB7BC  thumb  ov072
 *   TOWNMAP_GRH_InitBgLayers  0x021BB820  thumb  ov072
 *   TOWNMAP_GRH_InitSprites  0x021BB9B8  thumb  ov072
 *   func_020056A0  0x020056A0  thumb
 *   sTownMapGrhFileName     0x021BBD6C  data  ov072  a1
 *   sTownMapGrhVramBanks     0x021BBBDC  data  ov072
 *   TOWNMAP_GRH_UpdateTask  0x021BB80C  thumb  ov072
 */
typedef unsigned int u32;

extern char sTownMapGrhFileName[];
extern char sTownMapGrhVramBanks[];
extern void TOWNMAP_GRH_UpdateTask(int unused, char *p);

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern void TOWNMAP_GRH_ResetDisplay(void);
extern void TOWNMAP_GRH_InitBgLayers(u32 *p, u32 a);
extern void TOWNMAP_GRH_InitSprites(u32 *p, char *s, u32 a);
extern u32  func_020056A0(void (*cb)(void), void *arg, int pri);

u32 *TOWNMAP_GRH_Create(u32 heap)
{
    u32 *p;

    p = func_02030734(heap, 0x2C, 0, sTownMapGrhFileName, 0xEC);
    func_02082BCC(p, 0, 0x2C);
    TOWNMAP_GRH_ResetDisplay();
    TOWNMAP_GRH_InitBgLayers(p, heap);
    TOWNMAP_GRH_InitSprites(p + 1, sTownMapGrhVramBanks, heap);
    p[10] = func_020056A0((void (*)(void))TOWNMAP_GRH_UpdateTask, p, 1);
    return p;
}
