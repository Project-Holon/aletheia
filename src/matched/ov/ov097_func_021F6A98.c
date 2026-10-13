/*
 * function: func_021F6A98
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
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_021F6B7C  0x021F6B7C  thumb  ov097
 *   func_021F6CE4  0x021F6CE4  thumb  ov097
 *   func_021F6D70  0x021F6D70  thumb  ov097
 *   func_021F6EE8  0x021F6EE8  thumb  ov097
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void func_021F6B7C(int, int);
extern void func_021F6CE4(int, int);
extern void func_021F6D70(char *p, int idx);
extern void func_021F6EE8(unsigned p, unsigned i);

void func_021F6A98(int a)
{
    unsigned int i;
    int *p;

    BMP_WIN_Init(0x71);
    for (i = 0; i < 6; i++)
        *(int *)(a + i * 8 + 0x20) = BMP_WIN_Create(0, 0, 0, 0xf, 5, 9, 1);
    for (i = 0; i < 6; i++) {
        p = (int *)(a + i * 8);
        BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[8])), 0);
        if (*(int *)(a + i * 4 + 0xf8) != 0) {
            func_021F6B7C(a, i);
            func_021F6CE4(a, i);
            func_021F6D70((char *)a, i);
            func_021F6EE8(a, i);
        } else {
            BMP_WIN_TransferChars((struct Descriptor *)p[8]);
        }
    }
}
