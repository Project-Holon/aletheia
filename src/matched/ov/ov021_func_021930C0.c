/*
 * function: FIELD_MSGBG_CreateWindow
 * address:  0x021930C0
 * packet:   pkt_ov021_021930C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void func_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);

int FIELD_MSGBG_CreateWindow(int a, int unused, int b, int c, u16 d, u16 e, u16 f)
{
    int r;
    int k;

    r = BMP_WIN_Create(a & 0xff, b & 0xff, c & 0xff, d & 0xff, e & 0xff, f & 0xff, 1);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)r)), 0xff);
    BMP_WIN_MakeScreen((struct Cfg *)r);
    BMP_WIN_TransferChars((struct Descriptor *)r);
    func_020409B4((u8)a);
    k = 0xd;
    if (f != 0xe) {
        k = 0xa;
    }
    func_0201F73C((void *)r, 0, 1, k & 0xff);
    return r;
}
