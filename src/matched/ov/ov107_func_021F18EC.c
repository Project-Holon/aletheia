/*
 * function: MB_UTIL_MSG_DeleteWordSet
 * address:  0x021F18EC
 * packet:   pkt_ov107_021F18EC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WORDSET_Delete  0x0201ED04  thumb
 */

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx;

struct WordSet;
typedef unsigned int   u32;
u32 WORDSET_Delete(struct WordSet *p);

void MB_UTIL_MSG_DeleteWordSet(Ov107Ctx *p)
{
    if (p->f24 != 0) {
        WORDSET_Delete(p->f24);
        p->f24 = 0;
    }
}
