/*
 * function: VS_MULTI_LIST_CreateWindows
 * address:  0x021F6A98
 * packet:   pkt_ov097_021F6A98
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   VS_MULTI_LIST_PrintName  0x021F6B7C  thumb  ov097
 *   VS_MULTI_LIST_PrintLevel  0x021F6CE4  thumb  ov097
 *   VS_MULTI_LIST_PrintHp  0x021F6D70  thumb  ov097
 *   VS_MULTI_LIST_DrawHpDivider  0x021F6EE8  thumb  ov097
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void VS_MULTI_LIST_PrintName(int, int);
extern void VS_MULTI_LIST_PrintLevel(int, int);
extern void VS_MULTI_LIST_PrintHp(char *p, int idx);
extern void VS_MULTI_LIST_DrawHpDivider(unsigned p, unsigned i);

void VS_MULTI_LIST_CreateWindows(int a)
{
    unsigned int i;
    int *p;

    BMP_WIN_Init(0x71);
    for (i = 0; i < 6; i++)
        *(int *)(a + i * 8 + 0x20) = BMP_WIN_Create(0, 0, 0, 0xf, 5, 9, 1);
    for (i = 0; i < 6; i++) {
        p = (int *)(a + i * 8);
        BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)p[8])), 0);
        if (*(int *)(a + i * 4 + 0xf8) != 0) {
            VS_MULTI_LIST_PrintName(a, i);
            VS_MULTI_LIST_PrintLevel(a, i);
            VS_MULTI_LIST_PrintHp((char *)a, i);
            VS_MULTI_LIST_DrawHpDivider(a, i);
        } else {
            BMP_WIN_TransferChars((struct Descriptor *)p[8]);
        }
    }
}
