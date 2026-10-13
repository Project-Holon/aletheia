/*
 * function: func_021DD68C
 * address:  0x021DD68C
 * packet:   pkt_ov119_021DD68C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E7704     0x021E7704  data  a4
 *   func_020275E4  0x020275E4  thumb
 *   func_02049B40  0x02049B40  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj00384.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct {
    int a;
    int b;
} Pair;

extern const Pair d_021E7704;
extern u32 func_020275E4(void);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
struct Cfg;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);

void func_021DD68C(char *p)
{
    Pair t;
    Pair u;
    void *h;
    int q;
    void *h2;
    int i;
    int k;
    int m;
    int x;

    t = d_021E7704;
    u.a = ((struct Obj00384 *)p)->f830;
    u.b = ((struct Obj00384 *)p)->f834;
    func_02049B40(func_020275E4(), 0x1F, 0, 0x1A0, 0x20, ((struct Obj00384 *)p)->f5F4);
    if (((struct Obj00384 *)p)->f5D4 != 0) {
        BMP_WIN_Delete(((struct Obj00384 *)p)->f5D4);
        BMP_WIN_Delete(((struct Obj00384 *)p)->f5D8);
    }
    h = (void *)BMP_WIN_Create(3, 0, 0, 0x20, 2, 13, 0);
    ((struct Obj00384 *)p)->f5D4 = h;
    GF_FONT_SetTextColor(14, 15, 0);
    if (((struct Obj00384 *)p)->f118C == 3 && ((struct Obj00384 *)p)->f1050 != -1) {
        func_02045CAC(((struct Obj00384 *)p)->f720, 0x85, ((struct Obj00384 *)p)->f730);
        PRINTSYS_Print(BMP_WIN_GetBmp(h), 8, 2, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
        func_02045CAC(((struct Obj00384 *)p)->f720, ((struct Obj00384 *)p)->f1050 + 0x7B, ((struct Obj00384 *)p)->f730);
        PRINTSYS_Print(BMP_WIN_GetBmp(h), 0x88, 2, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
    }
    BMP_WIN_TransferChars(h);
    BMP_WIN_MakeScreen(h);
    i = 0;
    h2 = (void *)BMP_WIN_Create(3, 0, 3, 0x20, 8, 5, 0);
    ((struct Obj00384 *)p)->f5D8 = h2;
    for (i = 0; i < 2; i++) {
        k = i * 4;
        q = *(int *)((char *)&u + k);
        if (q != 0) {
            if (((struct Obj00384 *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                m = 0x75;
            } else {
                m = 0x80;
            }
            GF_FONT_SetTextColor(1, 2, 0);
            func_02045CAC(((struct Obj00384 *)p)->f720, m, ((struct Obj00384 *)p)->f734);
            func_0201F02C(((struct Obj00384 *)p)->f724, 0, (void *)q);
            func_0201F250(((struct Obj00384 *)p)->f724, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f734);
            x = *(int *)((char *)&t + k) * 8;
            PRINTSYS_Print(BMP_WIN_GetBmp(h2), x, 2, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
            if (((struct Obj00384 *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                GF_FONT_SetTextColor(3, 4, 0);
                func_02045CAC(((struct Obj00384 *)p)->f720, *(int *)(p + k + 0x1048) + 0x76, ((struct Obj00384 *)p)->f730);
                PRINTSYS_Print(BMP_WIN_GetBmp(h2), x + 4, 0x22, ((struct Obj00384 *)p)->f730, ((struct Obj00384 *)p)->f728);
            }
        }
    }
    BMP_WIN_TransferChars(h2);
    BMP_WIN_MakeScreen(h2);
    func_02041B6C(3);
}
