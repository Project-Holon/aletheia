/*
 * function: FIELD_BUILDMODEL_LoadArea
 * address:  0x0218B8AC
 * packet:   pkt_ov021_0218B8AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   FIELD_BUILDMODEL_GetArchiveMemberIndex  0x0218BC1C  thumb
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   FIELD_BUILDMODEL_LoadModelArchive  0x0218BB0C  thumb
 *   FIELD_BUILDMODEL_CreateG3dResources  0x0218BC40  thumb
 *   FIELD_BUILDMODEL_BuildTableIndex  0x0218BB78  thumb
 *   FIELD_BUILDMODEL_CreateModels  0x0218BD28  thumb
 *   FIELD_BUILDMODEL_CreateAnimSets  0x0218BDD8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub020140BCObj;
extern u32 ZONEDATA_GetAreaId(u32 id);
extern unsigned short FIELD_BUILDMODEL_GetArchiveMemberIndex(int x);
extern u8 ZONEDATA_GetAreaInnerOuter(struct Sub020140BCObj *p);
extern void FIELD_BUILDMODEL_LoadModelArchive(u8 *s, u16 a, u32 n);
extern void FIELD_BUILDMODEL_CreateG3dResources(unsigned char *p, int a, int b, int c);
extern void FIELD_BUILDMODEL_BuildTableIndex(u8 *s, int k);
extern void FIELD_BUILDMODEL_CreateModels(char *p, int c);
extern void FIELD_BUILDMODEL_CreateAnimSets(u8 *s, u32 *out);

void FIELD_BUILDMODEL_LoadArea(char *p, int a, int b, int c)
{
    void *s;
    int k1;
    int k2;
    int k3;

    s = (void *)FIELD_BUILDMODEL_GetArchiveMemberIndex(ZONEDATA_GetAreaId(a));
    if (ZONEDATA_GetAreaInnerOuter((struct Sub020140BCObj *)b)) {
        k1 = 0xE5;
        k2 = 0xB0;
        k3 = 0x15;
    } else {
        k1 = 0xE6;
        k2 = 0xB1;
        k3 = 0x14;
    }
    FIELD_BUILDMODEL_LoadModelArchive((u8 *)p, k1, (u32)s);
    FIELD_BUILDMODEL_CreateG3dResources((unsigned char *)p, (u16)k2, (int)s, c);
    FIELD_BUILDMODEL_BuildTableIndex((u8 *)p, k3);
    FIELD_BUILDMODEL_CreateModels(p, c);
    FIELD_BUILDMODEL_CreateAnimSets((u8 *)p, (u32 *)(p + 0x1B0));
}
