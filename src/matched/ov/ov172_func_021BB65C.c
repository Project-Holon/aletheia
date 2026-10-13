/*
 * function: func_021BB65C
 * address:  0x021BB65C
 * packet:   pkt_ov172_021BB65C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj00836.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_021BE034(void *p);
extern u32 func_021BE03C(void *p);
extern u32 func_021BE044(void *p);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void func_021BB65C(void *ctx, u8 *p, int k)
{
    void *last;
    void *w8;
    void *w7;
    void *w6;
    void *w5;
    void *w4;
    void *w3;
    void *w2;
    void *w1;
    void *w0;
    void *old;
    void *h3c;
    void *h44;
    u32 h34;

    h34 = func_021BE034(ctx);
    h3c = (void *)func_021BE03C(ctx);
    h44 = (void *)func_021BE044(ctx);
    old = ((struct Obj00836 *)p)->f48;
    if (old != 0) {
        PRINTSYS_QUE_Clear(h44);
        func_0201F7A8(((struct Obj00836 *)p)->f48, 2);
        BMP_WIN_ClearScreen(((struct Obj00836 *)p)->f48);
    }
    ((struct Obj00836 *)p)->f3C = k;
    if (k == 1) {
        ((struct Obj00836 *)p)->f48 = (void *)BMP_WIN_Create(4, 2, 8, 0x1c, 0xd, 0xa, 1);
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0xf);
        BMP_WIN_TransferChars(((struct Obj00836 *)p)->f48);
        w0 = func_02045EC0(h3c, 6);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x4, (u32)w0, h34, 0x440);
        STRBUF_Delete(w0);
        w1 = func_02045EC0(h3c, 7);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x18, (u32)w1, h34, 0x440);
        STRBUF_Delete(w1);
        w2 = func_02045EC0(h3c, 8);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x2c, (u32)w2, h34, 0x440);
        STRBUF_Delete(w2);
        w3 = func_02045EC0(h3c, 10);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x40, (u32)w3, h34, 0x440);
        STRBUF_Delete(w3);
        last = func_02045EC0(h3c, 9);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x40, 0x54, (u32)last, h34, 0x440);
        STRBUF_Delete(last);
    } else {
        ((struct Obj00836 *)p)->f48 = (void *)BMP_WIN_Create(4, 2, 0x10, 0x1c, 6, 0xa, 1);
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0xf);
        BMP_WIN_TransferChars(((struct Obj00836 *)p)->f48);
        w4 = func_02045EC0(h3c, 0);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x8, 0x0, (u32)w4, h34, 0x440);
        STRBUF_Delete(w4);
        w5 = func_02045EC0(h3c, 1);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x8, 0x10, (u32)w5, h34, 0x440);
        STRBUF_Delete(w5);
        w6 = func_02045EC0(h3c, 2);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x8, 0x20, (u32)w6, h34, 0x440);
        STRBUF_Delete(w6);
        w7 = func_02045EC0(h3c, 3);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x50, 0x0, (u32)w7, h34, 0x440);
        STRBUF_Delete(w7);
        w8 = func_02045EC0(h3c, 4);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x50, 0x10, (u32)w8, h34, 0x440);
        STRBUF_Delete(w8);
        last = func_02045EC0(h3c, 5);
        PRINTSYS_PrintQueColor(h44, (u32)BMP_WIN_GetBmp(((struct Obj00836 *)p)->f48), 0x50, 0x20, (u32)last, h34, 0x440);
        STRBUF_Delete(last);
    }
    ((struct Obj00836 *)p)->f38 = 1;
    if (old != 0) {
        BMP_WIN_Delete(old);
    }
}
