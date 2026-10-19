/*
 * function: NO_GEAR_LoadGraphics
 * address:  0x021EFECC
 * packet:   pkt_ov030_021EFECC
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gNoGearPaletteFileIds     0x021F0134  data  ov030  a4
 *   gNoGearCharFileIds     0x021F0140  data  ov030  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern const u32 gNoGearPaletteFileIds[];
extern const u32 gNoGearCharFileIds[];

typedef struct {
    u32 pad0[2];
    u16 heap;
    u16 pad1;
    u32 pad2[2];
    u32 w14;
    void *w18;
} Obj;

void NO_GEAR_LoadGraphics(Obj *p)
{
    void *h;
    int i;

    h = func_020490F4(0x1E, p->heap);
    i = func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(p->w18)));
    func_02049B68(h, gNoGearPaletteFileIds[i], 4, 0, 0, p->heap);
    p->w14 = func_02049740(h, gNoGearCharFileIds[i], 6, 0, 0, p->heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 3, 6, 0, (u16)p->w14, 0, 0, p->heap);
    ARC_TOOL_DeleteHandle(h);
    GFL_NET_RefreshWmIconAtTopRight(0, p->heap);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
