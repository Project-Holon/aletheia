/*
 * function: IRC_RESULT_InitBackgrounds
 * address: 0x021B78F4
 * packet: pkt_ov105_021B78F4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: contested89B8 hint dropped after original7A30 word confirmed.
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   sResultDisplayConfig 0x021B8964 data ov105 a4
 *   sResultBackgroundLayers 0x021B89B8 data a4
 *   sResultBackgroundTemplates 0x021B8A08 data ov105 a4
 *   sResultBackgroundTypes 0x021B8998 data ov105 a4
 */
typedef unsigned char u8;
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void BG_SYS_FreeSlot(u8);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,int,int,int,int,int);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_020498F4(void *,int,int,int,int,int,int);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void *func_02049740(void *,int,int,int,int,int);
extern void ARC_TOOL_DeleteHandle(void *);
extern const u8 sResultDisplayConfig[],sResultBackgroundTemplates[];
extern const int sResultBackgroundLayers[],sResultBackgroundTypes[];
void IRC_RESULT_InitBackgrounds(void **p,int heap)
{
    int i,id;
    void *archive;
    BG_SYS_Create(heap); BMP_WIN_Init(heap); BG_SYS_SetGraphicsMode((struct DispConfig *)sResultDisplayConfig);
    for(i=0;i<8;++i) {
        id=sResultBackgroundLayers[i];
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)(sResultBackgroundTemplates+i*32),(u8)sResultBackgroundTypes[i]);
        BG_SYS_FreeSlot((u8)id); func_02040588((u8)id,1);
    }
    archive=func_020490F4(0x5e,heap);
    func_02049B68(archive,16,0,0,0,heap);
    func_02049B68(archive,16,4,0,0,heap);
    func_02049658(archive,0,2,0,0,0,heap);
    func_02049658(archive,0,6,0,0,0,heap);
    func_02049658(archive,48,4,0,0,0,heap);
    func_02049658(archive,13,1,0,0,0,heap);
    func_020498F4(archive,4,2,0,0,0,heap);
    func_020498F4(archive,4,6,0,0,0,heap);
    func_020498F4(archive,46,4,0,0,0,heap);
    func_020498F4(archive,14,1,0,0,0,heap);
    BG_SYS_Init(5,0,1,0);
    *p=func_02049740(archive,49,5,0,0,heap);
    ARC_TOOL_DeleteHandle(archive);
}
