/*
 * function: BOX2_SEQ_PrintPromptB
 * address:  0x021EBCB4
 * packet:   pkt_ov170_021EBCB4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb
 *
 * Item-menu prompt for a kind; kinds 1 to 3 name the held item first.  An
 * out-of-range kind prints whatever msg holds; the image does not initialise it.
 */

typedef unsigned int u32;

struct WordSet;
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_PrintPromptB(unsigned char *p, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x1A;
        break;
    case 1:
        msg = 0x17;
        WORDSET_Callback_EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 2:
        msg = 0x18;
        WORDSET_Callback_EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 3:
        msg = 0x19;
        WORDSET_Callback_EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 4:
        msg = 0x16;
        break;
    case 5:
        msg = 0x1F;
        break;
    case 6:
        msg = 0xD;
        break;
    case 7:
        msg = 0x2F;
        break;
    }
    BOX2_SEQ_PrintMessageMsg(p, msg, i);
}
