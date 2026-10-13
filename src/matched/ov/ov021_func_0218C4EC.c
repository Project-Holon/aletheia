/*
 * function: FIELD_BUILDMODEL_RemoveEntriesByObject
 * address:  0x0218C4EC
 * packet:   pkt_ov021_0218C4EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_FreeEntry  0x0218C518  thumb  ov021
 */

typedef struct {
    void *key;
    int a;
    int b;
    int c;
} Ent;

void FIELD_BUILDMODEL_FreeEntry(void *p, Ent *e);

void FIELD_BUILDMODEL_RemoveEntriesByObject(unsigned char *p, void *key)
{
    Ent *e = (Ent *)(p + 0x1F8);
    int i;
    for (i = 0; i < 0x120; i++) {
        if (e[i].key == key)
            FIELD_BUILDMODEL_FreeEntry(p, &e[i]);
    }
}
