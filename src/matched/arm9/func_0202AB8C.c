/*
 * Graduated from src/pending/; promoted once its blocker became a manifest entry.
 *
 * Previously blocked at MATCH on `label`: ISS_CITY_UNIT_Create has exactly one branch reference
 * image-wide, this function's own call, so no witness exists outside the
 * compared range and no cut helps.  It closes when ISS_CITY_UNIT_Create (pkt_0202AEEC)
 * acquires a manifest entry or a second caller appears.
 *
 * function: ISS_CITY_SYS_LoadUnits
 * address:  0x0202AB8C
 * packet:   pkt_0202AB8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker 0202AEEC is now a manifest entry (matched class)
 * symbols:
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   func_02030734  0x02030734  arm
 *   ISS_CITY_UNIT_Create  0x0202AEEC  thumb
 *   ISS_CITY_SYS_sSourceFileName     0x020A76E8  data
 */
typedef int s32;
typedef unsigned char u8;
typedef unsigned int  u32;

struct A {
    u8  pad0[0x14];
    u32 *unk14;
    u8  unk18;
};

extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *ISS_CITY_UNIT_Create(u32 a, u32 b);
extern const char ISS_CITY_SYS_sSourceFileName[];

void ISS_CITY_SYS_LoadUnits(struct A *a0, void *a1)
{
    s32 n = ARC_TOOL_GetArchiveFileCount(0x84);
    s32 i;

    a0->unk18 = n;
    a0->unk14 = func_02030734((u32)a1, n << 2, 0, ISS_CITY_SYS_sSourceFileName, 0x14d);
    for (i = 0; i < n; i++) {
        a0->unk14[i] = (u32)ISS_CITY_UNIT_Create((u32)a1, i);
    }
}
