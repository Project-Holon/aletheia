/*
 * function: MB_UTIL_MSG_CreateWordSet
 * address:  0x021F18D8
 * packet:   pkt_ov107_021F18D8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 */

typedef struct {
    unsigned short f00;
    unsigned char pad02[0x22];
    void *f24;
} Ov107Ctx;

typedef unsigned int   u32;
struct WordSet;
struct WordSet *WORDSET_CreateDefault(u32 heap);

void MB_UTIL_MSG_CreateWordSet(Ov107Ctx *p)
{
    if (p->f24 == 0) {
        p->f24 = WORDSET_CreateDefault(p->f00);
    }
}
