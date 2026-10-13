/*
 * function: func_021E8870
 * address:  0x021E8870
 * packet:   pkt_021E8870
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef struct {
    char           pad0[0x14];
    int            f14;
    char           pad1[4];
    unsigned short f1c;
} S;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned char  u8;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);

void func_021E8870(S *p)
{
    int r = (int)BMP_WIN_GetBmp((struct Descriptor *)p->f14);

    BMP_Clear((struct CharBuf *)r, (unsigned char)p->f1c);
    BMP_WIN_TransferChars((struct Descriptor *)p->f14);
}
