/*
 * function: BOX2_SEQ_PrintPrompt
 * address:  0x021EBC58
 * packet:   pkt_ov170_021EBC58
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   func_0201EF14 0x0201EF14 thumb
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb
 *
 * Picks the prompt for a menu kind (kind 1 first names the Pokemon in the
 * current slot) and prints it into window i.  An out-of-range kind prints
 * whatever msg holds; the image does not initialise it.
 */

typedef unsigned int u32;

extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
struct WordSet;
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_PrintPrompt(unsigned char *p, int sel, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x10;
        break;
    case 1:
        msg = 0;
        func_0201EF14(*(void **)(WORK(p) + 0x84), 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], p[0x16]));
        break;
    case 2:
        msg = 5;
        break;
    case 3:
        msg = 0x11;
        break;
    case 4:
        msg = 0xC;
        break;
    case 5:
        msg = 0x1B;
        break;
    }
    BOX2_SEQ_PrintMessageMsg(p, msg, i);
}
