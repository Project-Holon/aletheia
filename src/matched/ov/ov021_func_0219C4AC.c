/*
 * function: FLDMMDL_BLACT_AddVramSlot
 * address:  0x0219C4AC
 * packet:   pkt_ov021_0219C4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Former blocker (now filed in src/matched/arm9): BILLBOARD_ACT_GetBoard (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (the integrator's). Verified C, EXACT under --arm --region arm9:
 *     u32 BILLBOARD_ACT_GetBoard(u32 *p) { return p[1]; }
 * symbols:
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   G3D_SYSTEM_GetTexVramKey  0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey  0x020473B8  arm
 *   BILLBOARD_AddImageFromVramKeys  0x0204F044  arm
 *   BILLBOARD_ACT_AddSlot  0x02050238  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   sBlactCellSize     0x021D75C4  data  a4
 *   sBlactTexFmt     0x021D8064  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u16 sBlactCellSize[][2];
extern u16 sBlactTexFmt[];
struct Board;
struct Layer;
struct Tagged;
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern u32 G3D_SYSTEM_GetTexVramKey(struct Layer *layer);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct Layer *layer);
extern int BILLBOARD_AddImageFromVramKeys(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern u32 BILLBOARD_ACT_AddSlot(void *p, u32 b, u32 c);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

int FLDMMDL_BLACT_AddVramSlot(u32 a, u32 b, u32 c, u32 d)
{
    int r = -1;
    if (G3D_SYSTEM_TransVramTexture((int *)b) == 1) {
        u32 x = BILLBOARD_ACT_GetBoard((u32 *)a);
        u16 *e = sBlactCellSize[c];
        u32 w = G3D_SYSTEM_GetTexVramKey((struct Layer *)b);
        r = BILLBOARD_ACT_AddSlot((void *)a, BILLBOARD_AddImageFromVramKeys((struct Board *)x, w, G3D_SYSTEM_GetPlttVramKey((struct Layer *)b), 0, sBlactTexFmt[d], (u8)e[0], (u8)e[1]), 0);
        G3D_SYSTEM_DeleteResource((struct Tagged *)b);
    }
    return r;
}
