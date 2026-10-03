/*
 * function: func_021C2A30
 * address:  0x021C2A30
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatch: after two non-null guards, one of ten handlers is called on the
 * record, chosen by the word at offset 0x18.
 *
 * symbols:
 *   func_021C2AA0  0x021C2AA0  thumb  ov217
 *   func_021C2B10  0x021C2B10  thumb  ov217
 *   func_021C2B80  0x021C2B80  thumb  ov217
 *   func_021C2BF0  0x021C2BF0  thumb  ov217
 *   func_021C2C30  0x021C2C30  thumb  ov217
 *   func_021C2C70  0x021C2C70  thumb  ov217
 *   func_021C2CB0  0x021C2CB0  thumb  ov217
 *   func_021C2CF0  0x021C2CF0  thumb  ov217
 *   func_021C2D28  0x021C2D28  thumb  ov217
 *   func_021C2D68  0x021C2D68  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    u32 kind;
} Rec;

extern void func_021C2AA0(Rec *);
extern void func_021C2B10(Rec *);
extern void func_021C2B80(Rec *);
extern void func_021C2BF0(Rec *);
extern void func_021C2C30(Rec *);
extern void func_021C2C70(Rec *);
extern void func_021C2CB0(Rec *);
extern void func_021C2CF0(void *p);
extern void func_021C2D28(Rec *);
extern void func_021C2D68(void *p);

void func_021C2A30(Rec *p)
{
    if (p->w4 == 0)
        return;
    if (p->w14 == 0)
        return;
    switch (p->kind) {
    case 0:
        func_021C2AA0(p);
        break;
    case 1:
        func_021C2B10(p);
        break;
    case 2:
        func_021C2B80(p);
        break;
    case 3:
        func_021C2BF0(p);
        break;
    case 4:
        func_021C2C30(p);
        break;
    case 5:
        func_021C2C70(p);
        break;
    case 6:
        func_021C2CB0(p);
        break;
    case 7:
        func_021C2CF0(p);
        break;
    case 8:
        func_021C2D28(p);
        break;
    case 9:
        func_021C2D68(p);
        break;
    }
}
