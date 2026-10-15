/*
 * function: BOX2_SEQ_ClearTextWin
 * address:  0x021EB324
 * packet:   pkt_ov170_021EB324
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_ClearScreen 0x021EABB8 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BOX2_SEQ_SetDirtyBit 0x021EAAE4 thumb
 */

typedef struct {
    void *obj;
    int pad;
} Item;

typedef struct {
    unsigned char pad[0x94];
    Item items[14];
} Work;

extern void BOX2_SEQ_ClearScreen(void **p);
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BOX2_SEQ_SetDirtyBit(unsigned char *p, unsigned i);

void BOX2_SEQ_ClearTextWin(Work *w)
{
    unsigned i;
    for (i = 1; i <= 9; i++) {
        BOX2_SEQ_ClearScreen((void **)(&w->items[i]));
        BMP_Clear(BMP_WIN_GetBmp(w->items[i].obj), 0);
        BOX2_SEQ_SetDirtyBit((unsigned char *)w, i);
    }
    BOX2_SEQ_ClearScreen((void **)(&w->items[10]));
    BOX2_SEQ_ClearScreen((void **)(&w->items[11]));
    BOX2_SEQ_ClearScreen((void **)(&w->items[12]));
    BOX2_SEQ_ClearScreen((void **)(&w->items[13]));
}
