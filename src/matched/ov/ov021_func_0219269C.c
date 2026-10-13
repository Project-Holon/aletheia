/*
 * function: FIELD_MSGBG_SpWinPrintStr
 * address:  0x0219269C
 * packet:   pkt_ov021_0219269C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020409B4  0x020409B4  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   FIELD_MSGBG_PrintLines  0x021924F0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u32 f08;
} Fx;

typedef struct T {
    u32 f00;
    u32 f04;
    Fx *f08;
} T;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void FIELD_MSGBG_PrintLines(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void func_020409B4(u32 a);

void FIELD_MSGBG_SpWinPrintStr(T *t, u16 b, u16 c, u32 d)
{
    Fx *x = t->f08;

    FIELD_MSGBG_PrintLines(b, c, (u32)func_02045770((struct Descriptor *)t->f00), x->f08, d, x->f00);
    BMP_WIN_TransferChars((struct Descriptor *)t->f00);
    func_020409B4((u8)t->f08->f02);
}
