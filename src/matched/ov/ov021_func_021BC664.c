/*
 * function: FIELD_PLACE_NAME_LoadPaletteFile
 * address:  0x021BC664
 * packet:   pkt_ov021_021BC664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetHeapId  0x021BD090  thumb  ov021
 *   FIELD_PLACE_NAME_GetArcHandle  0x021BD094  thumb  ov021
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 */

typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct ArcFile;
struct NitroFileHeader;
extern u16 FIELD_PLACE_NAME_GetHeapId(u8 *p);
extern u32 FIELD_PLACE_NAME_GetArcHandle(u8 *p);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);

typedef struct S {
    char pad[0x14c];
    int a;
    int b;
} S;

void FIELD_PLACE_NAME_LoadPaletteFile(S *p)
{
    int r4, r6, h;

    r4 = FIELD_PLACE_NAME_GetHeapId((u8 *)((int)p));
    r6 = FIELD_PLACE_NAME_GetArcHandle((u8 *)((int)p));
    h = (int)func_02030734(r4, ARC_TOOL_GetHandleMemberSize((struct ArcFile *)r6, 1), 0, (const char *)0x021DE354, 0x2c8);
    p->a = h;
    ARC_TOOL_ReadHandleMember((struct ArcFile *)r6, 1, (void *)h);
    NNS_G2dGetUnpackedPaletteData((struct NitroFileHeader *)p->a, (void **)((int)&p->b));
}
