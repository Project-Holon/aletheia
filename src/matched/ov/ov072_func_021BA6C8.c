/*
 * function: TOWNMAP_MapFindTownUnderCursor
 * address:  0x021BA6C8
 * packet:   pkt_ov072_021BA6C8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOWNMAP_CursorGetPos  0x021BA3BC  thumb  ov072
 *   TOWNMAP_TownHitTest  0x021BAA90  thumb  ov072
 */

typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
} W;

extern void TOWNMAP_CursorGetPos(char *p, int *q);
extern int TOWNMAP_TownHitTest(char *a, int *b, int *c);

char *TOWNMAP_MapFindTownUnderCursor(W *p, int a)
{
    int pt[2];
    u32 i;

    TOWNMAP_CursorGetPos((char *)a, pt);
    for (i = 0; i < p->fc; i++) {
        if (TOWNMAP_TownHitTest(p->f8 + i * 0x44, pt, &p->f10) != 0) {
            return p->f8 + i * 0x44;
        }
    }
    return 0;
}
