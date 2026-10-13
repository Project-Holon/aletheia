/*
 * function: FIELD_EVENT_CHECK_CheckWildEncount
 * address:  0x0218B208
 * packet:   pkt_ov021_0218B208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When bit 3 of the flag word is set, runs the object's interaction:
 * FIELD_ENCOUNT_CheckWfbcEncount with the map value when ZONEDATA_IsZoneInTableDFC0 accepts field 0x10,
 * else FIELD_ENCOUNT_CheckWildEncount(obj, 0).
 *
 * is an unlabelled Thumb veneer (ldr r1, [pc, #4]; ldr r3, [pc, #8]; movs r2,
 * #4; bx r3) with no witness; it closes once arm9 0x02013DD0 is labelled.
 *
 * symbols:
 *   FIELDMAP_GetEncount  0x02188CE8  thumb
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb
 *   FIELD_ENCOUNT_CheckWfbcEncount  0x021AA248  thumb
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

extern u32 FIELDMAP_GetEncount(u8 *p);
struct Ctx;
extern int ZONEDATA_IsZoneInTableDFC0(int a0);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
extern int FIELD_ENCOUNT_CheckWfbcEncount(struct Ctx *ctx, void *b);
extern int FIELD_ENCOUNT_CheckWildEncount(struct Ctx *ctx, int mode);

int FIELD_EVENT_CHECK_CheckWildEncount(struct FieldCtx *p, void *unused, u8 *pos)
{
    void *obj = (void *)FIELDMAP_GetEncount(pos);

    if (!p->b3)
        return 0;
    if (ZONEDATA_IsZoneInTableDFC0(p->f10))
        return FIELD_ENCOUNT_CheckWfbcEncount(obj, FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper(pos)));
    return FIELD_ENCOUNT_CheckWildEncount(obj, 0);
}
