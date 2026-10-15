/*
 * function: DEMO3D_ENGINE_SetupLighting
 * address: 0x021BE63C
 * packet: pkt_ov203_021BE63C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The original reserves 20 bytes for colors at sp+0x2c and 32 for fogtable
 * at sp+0x0c. Keeping cfg mutable moves the colors address before record's
 * parameter copy; const record preserves the later clear-color loads.
 * volatile: 0x04000060, 0x04000340, 0x04000358
 * symbols:
 *   ZONEDATA_GetTimeLightColors 0x0201493C thumb
 *   DEMO3D_GRAPHIC_SetupLightBlock 0x021BDF3C thumb
 *   func_0207DCF8 0x0207DCF8 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetFogTable 0x0207DD10 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3X_SetDisp1DotDepth 0x0207DE88 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef enum { FOG_BLEND_0,FOG_BLEND_1 } GXFogBlend;
typedef enum { FOG_SLOPE_0,FOG_SLOPE_10=10 } GXFogSlope;
struct Record {
    u16 a0,a2,id;
    u16 b0:1,b1:1,blend:1,anti:1,fog:1,edge:1,mode1:1,mode2:1,test:1,ref:5,padbits:2;
    u8 pad08[0x1c];
    int depthoffset;
    u16 clear,alpha;
    u16 polygon:15,polybit:1;
    u16 depth,fogcolor;
    u8 fogalpha,slope;
    u16 offset:15,mode:1;
    u8 fogtable[8];
    u16 edgecolors[8];
};
struct Context { void *owner; u8 pad04[0x70]; struct Record *record; };
struct Config { u8 pad[0xd],hour,minute; u8 second:7,spare:1; };
extern void ZONEDATA_GetTimeLightColors(u32,u32,u32,u32,u32,u16 *,u16);
struct Obj;
extern void DEMO3D_GRAPHIC_SetupLightBlock(struct Obj *obj, unsigned short *a, int a2);
extern void func_0207DCF8(const u16 *);
extern void G3X_SetFog(BOOL,GXFogBlend,GXFogSlope,int);
extern void G3X_SetFogTable(const u32 *);
extern void G3X_SetClearColor(u16,int,int,int,BOOL);
extern void G3X_SetDisp1DotDepth(int);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
#define DISP (*(volatile u16 *)0x04000060)
static inline void Anti(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|16);
    else DISP &= (u16)~0x3010;
}
static inline void Test(BOOL enable,int ref) {
    if(enable) { DISP=(u16)((DISP & ~0x3000)|4); *(volatile u16 *)0x04000340=(u16)ref; }
    else DISP &= (u16)~0x3004;
}
static inline void Blend(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|8);
    else DISP &= (u16)~0x3008;
}
static inline void Edge(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|32);
    else DISP &= (u16)~0x3020;
}
void DEMO3D_ENGINE_SetupLighting(struct Context *ctx,struct Config *cfg,const struct Record *record,u16 heap)
{
    u16 colors[10];
    u32 fogtable[8];
    u32 i;
    ZONEDATA_GetTimeLightColors(record->id,cfg->hour,cfg->minute,0,cfg->second,colors,heap);
    DEMO3D_GRAPHIC_SetupLightBlock(ctx->owner,colors,0);
    Anti(record->anti);
    Test(record->test,ctx->record->ref);
    Blend(record->blend);
    Edge(record->edge);
    if(record->edge) func_0207DCF8(record->edgecolors);
    G3X_SetFog(record->fog,(GXFogBlend)record->mode,(GXFogSlope)record->slope,record->offset);
    if(record->fog) {
        *(volatile u32 *)0x04000358=record->fogcolor|(record->fogalpha<<16);
        for(i=0;i<8;i++) fogtable[i]=record->fogtable[i];
        G3X_SetFogTable(fogtable);
    }
    G3X_SetClearColor(record->clear,record->alpha,record->depth,record->polygon,record->fog);
    G3X_SetDisp1DotDepth(record->depthoffset);
    G3D_SYSTEM_SetSwapBuffersMode(record->mode1,record->mode2);
}
