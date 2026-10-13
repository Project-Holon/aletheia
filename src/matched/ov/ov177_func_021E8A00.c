/*
 * function: func_021E8A00
 * address:  0x021E8A00
 * packet:   pkt_ov177_021E8A00
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_MENULIST_Main  0x020200CC  thumb
 */

typedef struct {
    char          pad0[4];
    int           f4;
    int           f8;
    unsigned char fc;
    char          pad1[3];
    int           f10;
    int           f14;
    int           f18;
} S;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern s32 BMP_MENULIST_Main(struct Obj *o);

int func_021E8A00(S *p)
{
    int r4 = p->f4;
    int r;

    if (p->fc != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)r4, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)p->f8))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)p->f8);
            p->fc = 0;
        }
    }
    r = BMP_MENULIST_Main((struct Obj *)p->f10);
    if (r == -2) {
        r = p->f18;
    }
    return r;
}
