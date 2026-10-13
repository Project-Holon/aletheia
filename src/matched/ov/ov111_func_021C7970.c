/*
 * function: func_021C7970
 * address:  0x021C7970
 * packet:   pkt_ov111_021C7970
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work;

struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void func_021C7970(Work *p)
{
    void *w;

    PRINTSYS_QUE_Main(p->f14);
    w = p->f14;
    if (p->f10) {
        if (PRINTSYS_QUE_IsExistTarget(w, BMP_WIN_GetBmp(p->fC)) == 0) {
            BMP_WIN_TransferChars(p->fC);
            p->f10 = 0;
        }
    }
}
