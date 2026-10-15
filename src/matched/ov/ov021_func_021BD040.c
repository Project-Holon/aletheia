/*
 * function: FIELD_PLACE_NAME_DeleteWordSet
 * address:  0x021BD040
 * packet:   pkt_ov021_021BD040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 */

typedef struct {
    char pad[8];
    void *f8;
} Obj;

struct WordSet;
typedef unsigned int   u32;
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

void FIELD_PLACE_NAME_DeleteWordSet(Obj *p)
{
    if (p->f8 != 0) {
        WORDSET_DeleteStrbufED04(p->f8);
        p->f8 = 0;
    }
}
