/*
 * function: MUSICAL_SHOT_SYS_CreateScene
 * address:  0x021F3AF0
 * packet:   pkt_ov112_021F3AF0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MUSICAL_MCSS_AllocMon  0x021F67E0  thumb  ov112
 *   MUSICAL_SHOT_SYS_Init3D  0x021F3CA4  thumb  ov112
 *   MUSICAL_SHOT_SYS_InitActors  0x021F3F00  thumb  ov112
 *   MUSICAL_MCSS_DrawLabel  0x021F40F4  thumb  ov112
 *   STA_ACT_LIGHT_AllocElem  0x021F6F24  thumb  ov112
 *   STA_ACT_LIGHT_CreateModel  0x021F6FB0  thumb  ov112
 *   STA_ACT_LIGHT_SetElemFrame  0x021F75DC  thumb  ov112
 *   STA_ACT_LIGHT_SetModelFrame  0x021F7098  thumb  ov112
 *   d_021F8380     0x021F8380  data  ov112  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct F5 { u32 v : 5; };
struct BF { u16 a : 2; u16 c : 1; u16 b : 5; };
extern char d_021F8380[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char *MUSICAL_MCSS_AllocMon(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
extern void MUSICAL_SHOT_SYS_Init3D(char *p);
extern void MUSICAL_SHOT_SYS_InitActors(void *o);
extern void MUSICAL_MCSS_DrawLabel(u8 *p);
extern u8 *STA_ACT_LIGHT_AllocElem(u32 heap, u32 v);
extern void STA_ACT_LIGHT_CreateModel(void *a, u8 b);
extern void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);
extern void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v);
u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap)
{
    u8 i;
    u8 *o;
    u8 j;
    o = func_02030734(heap, 100, 1, d_021F8380, 0x85);
    *(u16 *)o = heap;
    *(u8 **)(o + 4) = src;
    for (i = 0; i < 4; i++) {
        u32 off = i * 0x58;
        u8 *row;
        *(u32 *)(o + i * 4 + 8) = (u32)MUSICAL_MCSS_AllocMon(*(u16 *)(src + off + 4), (u8)((struct BF *)(src + 6 + off))->a, (u8)((struct BF *)(src + 6 + off))->b, (u8)((struct BF *)(src + 6 + off))->c, *(u32 *)(src + off + 8), heap);
        row = (u8 *)((u32)src + off);
        for (j = 0; j < 8; j++) {
            u8 k = row[j * 8 + 0x20];
            if (k != 10) {
                *(u16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x14) = *(u16 *)(row + j * 8 + 0x1c);
                *(s16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x16) = *(s16 *)(row + j * 8 + 0x1e);
                *(u8 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x18) = j;
            }
        }
    }
    MUSICAL_SHOT_SYS_Init3D((char *)o);
    MUSICAL_SHOT_SYS_InitActors(o);
    MUSICAL_MCSS_DrawLabel(o);
    *(void **)(o + 0x28) = STA_ACT_LIGHT_AllocElem(*(u16 *)o, 0);
    STA_ACT_LIGHT_CreateModel(*(void **)(o + 0x28), (u8)((struct F5 *)*(u8 **)(o + 4))->v);
    STA_ACT_LIGHT_SetElemFrame(*(void **)(o + 0x2c), 0x80);
    STA_ACT_LIGHT_SetModelFrame(*(void **)(o + 0x28), 0x80);
    return o;
}
