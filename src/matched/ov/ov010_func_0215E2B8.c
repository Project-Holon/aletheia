/*
 * function: FIELD_ENCOUNT_ST_LoadEncountData
 * address:  0x0215E2B8
 * packet:   pkt_ov010_0215E2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   ZONEDATA_GetEncountId  0x02013EC0  thumb
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct R {
    u8 pad00[7];
    u8 f7;
};

extern void MI_CpuFill8(void *p, int v, int n);
extern u32 ZONEDATA_GetEncountId(u32 id);
struct ArcFile;
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);

int FIELD_ENCOUNT_ST_LoadEncountData(struct R *r, int a, int b, int n)
{
    u32 q;
    int v;

    MI_CpuFill8(r, 0, 0xe8);
    v = ZONEDATA_GetEncountId(b);
    if (v == 0xffff) {
        return 0;
    }
    q = ARC_TOOL_GetHandleMemberSize((struct ArcFile *)a, v) / 0xe8;
    if (q != 1 && q != 4) {
        return 0;
    }
    if (q == 1) {
        n = 0;
    }
    ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)a, v, n * 0xe8, 0xe8, r);
    r->f7 |= 0x80;
    return 1;
}
