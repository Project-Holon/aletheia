/*
 * function: BTLV_INPUT_InitBgLayers
 * address:  0x0220255C
 * packet:   pkt_ov094_0220255C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_INPUT_StartBgScrollOffsetTask  0x02204960  thumb  ov094
 *   d_0220A8BC  0x0220A8BC  data  a4
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm  arm9
 *   BG_SYS_ClearLayer  0x0204152C  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Ent { char pad[0x20]; int f20; } Ent;
typedef unsigned short u16;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearLayer(int channel, u16 val);
struct Main;
extern void BTLV_INPUT_StartBgScrollOffsetTask(struct Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern const Ent d_0220A8BC[];

void BTLV_INPUT_InitBgLayers(void *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        BG_SYS_InitBgLayer((u8)(i + 4), (const struct BgTemplate *)(&d_0220A8BC[i]), (u8)d_0220A8BC[i].f20);
        BG_SYS_ClearLayer((u8)(i + 4), (int)0x3ff);
        BTLV_INPUT_StartBgScrollOffsetTask(p, i + 4, 0, 0, 2, 2, 2, 2);
    }
}
