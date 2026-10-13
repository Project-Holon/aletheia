/*
 * function: func_021BBEB4
 * address:  0x021BBEB4
 * packet:   pkt_ov099_021BBEB4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   POKE_REGULATION_CreateText 0x0201A4D4 thumb
 *   func_0200AE3C 0x0200AE3C thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern int func_021BA8BC(void *);
struct Reg;
struct U16Vec;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_0201F73C(void *,int,int,int);
extern void GF_FONT_SetDefaultTextColor(void);
extern u8 *POKE_REGULATION_CreateText(u8 *a0, u32 a1, u16 a2, u32 a3);
extern void *func_0200AE3C(struct Reg *p, u32 heap);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void PRINTSYS_PrintColor(void *,int,s16,void *,void *,u32);
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct O {
    u8 p0[0xdc];
    void *fdc, *fe0, *fe4, *fe8, *fec, *ff0, *ff4;
    u8 pf8[0x19c - 0xf8];
    void *f19c;
    u8 p1a0[0x1334 - 0x1a0];
    u32 f1334;
    u8 p1338[0x1344 - 0x1338];
    void **f1344;
    void **f1348;
};
void func_021BBEB4(struct O *p, int mask, u32 a, int mode)
{
    int base;
    int i;
    u32 flags;
    void *t;
    u32 w;
    base = 4;
    a = (a == 1) ? 1 : 0;
    p->f19c = (void *)func_021BA8BC(p->f19c);

    if (mode == 1) p->f19c = (void *)BMP_WIN_Create(2, 2, 5, 26, 12, 15, 1); else p->f19c = (void *)BMP_WIN_Create(2, 2, 5, 26, 16, 15, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->f19c), 255);
    BMP_WIN_ClearScreen(p->f19c);
    BMP_WIN_MakeScreen(p->f19c);
    func_0201F73C(p->f19c, 1, (u16)p->f1334, 14);
    GF_FONT_SetDefaultTextColor();
    p->f1344 = (void **)POKE_REGULATION_CreateText((u8 *)p->f1348, (u32)p->fdc, 33, a);
    if (mode == 0) {
        t = func_0200AE3C((struct Reg *)p->f1348, 33);
        PRINTSYS_Print(BMP_WIN_GetBmp(p->f19c), 0, 0, t, p->fe8);
        STRBUF_Delete(t);
    } else if (mode != 1) {
        MSGDATA_ReadString(p->fe0, (mode == 2) ? 0x66 : 0x67, p->ff0);
        PRINTSYS_Print(BMP_WIN_GetBmp(p->f19c), 0, 0, p->ff0, p->fe8);
    }
    if (mode == 1) base = 0;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) flags = 0x41; else flags = 0x11;
        flags <<= 6;
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f19c), 0, (s16)((base + i * 2) * 8), p->f1344[i + 1], p->fe8, flags);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f19c), 0x70, (s16)((base + i * 2) * 8), p->f1344[i + 7], p->fe8, flags);
    }
    BMP_WIN_TransferChars(p->f19c);
}
