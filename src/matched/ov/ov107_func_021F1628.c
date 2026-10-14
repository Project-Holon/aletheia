/*
 * function: MB_UTIL_MSG_SetWindowLayout
 * address:  0x021F1628
 * packet:   pkt_ov107_021F1628
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
} Ov107Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
u32 BMP_WIN_Delete(struct Descriptor *d);
u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void *BMP_WIN_GetBmp(struct Descriptor *p);
void BMP_Clear(struct CharBuf *buf, u8 value);
void BMP_WIN_TransferChars(struct Descriptor *d);
void BMP_WIN_MakeScreen(struct Cfg *cfg);
void func_020409B4(u32 index);

void MB_UTIL_MSG_SetWindowLayout(Ov107Ctx *p, int mode)
{
    if (p->f04 != mode) {
        if (p->f10 != 0) {
            BMP_WIN_Delete(p->f10);
            p->f10 = 0;
        }
        switch (mode) {
        case 0:
            break;
        case 1:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 3, 8, 0x1A, 8, 0xE, 1);
            break;
        case 2:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 3, 2, 0x1A, 0x12, 0xE, 1);
            break;
        case 3:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 3, 2, 0x1A, 0x14, 0xE, 1);
            break;
        case 4:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 1, 0x15, 0x1E, 2, 0xE, 1);
            break;
        case 5:
        case 8:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 1, 0x13, 0x1E, 4, 0xE, 1);
            break;
        case 6:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 1, 0x11, 0x1E, 6, 0xE, 1);
            break;
        case 7:
            p->f10 = (void *)BMP_WIN_Create(p->f02, 1, 1, 0x1E, 4, 0xE, 1);
            break;
        }
        p->f04 = mode;
    }
    BMP_Clear(BMP_WIN_GetBmp(p->f10), 0);
    BMP_WIN_TransferChars(p->f10);
    BMP_WIN_MakeScreen(p->f10);
    func_020409B4(p->f02);
}
