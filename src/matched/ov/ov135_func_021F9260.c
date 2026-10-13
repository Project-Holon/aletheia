/*
 * function: ov135_func_021F9260
 * address:  0x021F9260
 * packet:   pkt_ov135_021F9260
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040C14  0x02040C14  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   data_02203200  0x02203200  data
 *   data_02203206  0x02203206  data
 *   data_0220322A  0x0220322A  data
 *   data_02203242  0x02203242  data
 *   data_022032AE  0x022032AE  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32  BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern const u8 data_02203200[3][2];
extern const u8 data_02203206[4][2];
extern const u8 data_0220322A[4][3];
extern const u8 data_02203242[5][2];
extern const u8 data_022032AE[9][2];

struct Ov135Menu {
    u32 *win;
    u8 pad4[0x4c];
    u32 layer;
};

void ov135_func_021F9260(struct Ov135Menu *p, u32 mode)
{
    int i;

    func_02040C14(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 9; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 5:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        p->win[0] = BMP_WIN_Create((u8)p->layer, 2, 2, 3, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[0])), 7);
        for (i = 1; i < 4; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 0:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 4; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        p->win[4] = BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[4])), 8);
        break;
    case 6:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 9; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        p->win[15] = BMP_WIN_Create((u8)p->layer, 1, 2, 9, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[15])), 10);
        break;
    case 3:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 24, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 5; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        p->win[5] = BMP_WIN_Create((u8)p->layer, 14, 16, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[5])), 10);
        break;
    case 1:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 3; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 2:
        p->win[14] = BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 4; i++) {
            p->win[i] = BMP_WIN_Create((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 10);
        }
        p->win[4] = BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[4])), 8);
        break;
    }
}
