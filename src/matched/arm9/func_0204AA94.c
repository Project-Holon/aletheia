/*
 * function: CLACT_TransferCharacterPart
 * address:  0x0204AA94
 * packet:   pkt_0204A9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   lbl_02146A74    0x02146A74  data
 *   NNSi_G2dIsVramHandleSet   0x020637BC  arm
 *   NNSi_G2dGetVramHandleValue   0x020637B4  arm
 *   DC_FlushRange   0x020862F0  arm
 *   func_0207E780   0x0207E780  arm
 *   func_0207E804   0x0207E804  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj02146A74 {
    u8 pad[0x10c];
    u32 f10C;
};

extern struct Obj02146A74 *lbl_02146A74;
extern int NNSi_G2dIsVramHandleSet(const u32 *p, u32 i);
extern int NNSi_G2dGetVramHandleValue(int *p, int i);
extern void DC_FlushRange(void *a, u32 b);
extern void func_0207E780(void *a, void *b, u32 c);
extern void func_0207E804(void *a, void *b, u32 c);

void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e)
{
    if (e == 0 || e == 2) {
        if (NNSi_G2dIsVramHandleSet((const u32 *)(lbl_02146A74->f10C + (a << 6)), 1) != 0) {
            void *p = (void *)NNSi_G2dGetVramHandleValue((int *)(lbl_02146A74->f10C + (a << 6)), 1);
            DC_FlushRange(b, c);
            func_0207E780(b, (char *)p + d, c);
        }
    }
    if (e == 1 || e == 2) {
        if (NNSi_G2dIsVramHandleSet((const u32 *)(lbl_02146A74->f10C + (a << 6)), 2) == 0)
            return;
        {
            void *p = (void *)NNSi_G2dGetVramHandleValue((int *)(lbl_02146A74->f10C + (a << 6)), 2);
            DC_FlushRange(b, c);
            func_0207E804(b, (char *)p + d, c);
        }
    }
}
