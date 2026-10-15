/*
 * function: DEMO3D_GRAPHIC_InitG3d
 * address: 0x021BE0F4
 * packet: pkt_ov203_021BE0F4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: twin of ov204_func_021BE03C.c (3D setup, texSize 2, plttSize 4,
 * light set 0x021BFB48); u8 heap parameter.
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   DEMO3D_SetupGx 0x021BDD40 thumb ov203
 *   d_021BFB48 0x021BFB48 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct LightSet; struct LightSlot;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16 heap, void (*setup)(void));
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern void DEMO3D_SetupGx(void);
extern const struct LightSet d_021BFB48;
void DEMO3D_GRAPHIC_InitG3d(char *p, u8 heap)
{
    G3D_SYSTEM_Init(0, 2, 0, 4, 0, heap, DEMO3D_SetupGx);
    *(struct LightSlot **)(p + 4) = G3D_LIGHT_CreateSlots(&d_021BFB48, heap);
    G3D_LIGHT_ApplySlots(*(struct LightSlot **)(p + 4));
}
