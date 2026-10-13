/*
 * function: FIELD_BUILDMODEL_Delete
 * address:  0x0218B7F8
 * packet:   pkt_ov021_0218B7F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb
 *   FIELD_BUILDMODEL_DeleteAnimSets  0x0218BE84  thumb
 *   FIELD_BUILDMODEL_DeleteModels  0x0218BD94  thumb
 *   FIELD_BUILDMODEL_FreeModelArchive  0x0218BB64  thumb
 *   FIELD_BUILDMODEL_DeleteG3dResources  0x0218BC6C  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

extern void FIELD_BUILDMODEL_DeleteNode(void *p);
typedef unsigned char  u8;
extern void FIELD_BUILDMODEL_DeleteAnimSets(u8 *s, u8 *e);
extern void FIELD_BUILDMODEL_DeleteModels(u8 *s);
extern int FIELD_BUILDMODEL_FreeModelArchive(char *a);
extern void FIELD_BUILDMODEL_DeleteG3dResources(unsigned char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void FIELD_BUILDMODEL_Delete(char *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (*(void **)(p + 0x1DC + i * 4) != 0)
            FIELD_BUILDMODEL_DeleteNode(*(void **)(p + 0x1DC + i * 4));
    }
    FIELD_BUILDMODEL_DeleteAnimSets((u8 *)p, (u8 *)(p + 0x1B0));
    FIELD_BUILDMODEL_DeleteModels((u8 *)p);
    FIELD_BUILDMODEL_FreeModelArchive(p);
    FIELD_BUILDMODEL_DeleteG3dResources((unsigned char *)p);
    func_020307B0(p);
}
