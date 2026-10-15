/*
 * function: TH_AWARD_UploadWindows
 * address:  0x021BA01C
 * packet:   pkt_ov220_021BA01C
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef struct Obj {
    unsigned char pad00[0x10];
    void *f10;
    unsigned char pad14[0x60 - 0x14];
    void *ptr[4];
    int done[4];
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);

void TH_AWARD_UploadWindows(Obj *o)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (o->done[i] == 0) {
            if (PRINTSYS_QUE_IsExistTarget(o->f10, BMP_WIN_GetBmp(o->ptr[i])) == 0) {
                void *p = o->ptr[i];
                BMP_WIN_TransferChars(p);
                BMP_WIN_MakeScreen(p);
                func_02041B6C(BMP_WIN_GetBgLayer(p));
                o->done[i] = 1;
            }
        }
    }
}
