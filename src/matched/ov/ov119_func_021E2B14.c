/*
 * function: POKETRADE_SAVE_Init3DProjection
 * address: 0x021E2B14
 * packet: pkt_ov119_021E2B14
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   gLightSet 0x021E799C data a4
 *   gLightSetHandle 0x021F4560 data a4
 *   gProjectionConfig 0x021E7B1C data a4
 *   gProjectionParams 0x020A1DF8 data a2
 */
typedef struct {int a,b,c,d,e,f,g,h;} Config;
extern const Config gProjectionConfig;
extern char gLightSet[];
extern void *gLightSetHandle;
extern short gProjectionParams[];
typedef unsigned int   u32;
struct LightSet;
struct LightSlot;
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
struct LightSlot;
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
void POKETRADE_SAVE_Init3DProjection(int a) {
    Config c;
    gLightSetHandle=G3D_LIGHT_CreateSlots((const struct LightSet *)gLightSet,a);
    G3D_LIGHT_ApplySlots(gLightSetHandle);
    c=gProjectionConfig;
    c.b=gProjectionParams[12]; c.c=gProjectionParams[13];
    G3D_SYSTEM_SetProjection((const u32 *)(&c));
}
