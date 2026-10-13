/*
 * function: func_021F777C
 * address: 0x021F777C
 * packet: pkt_ov135_021F777C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02200BAC 0x02200BAC thumb ov135
 *   tbl_02202EC0 0x02202EC0 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u8 pad0[0xD40]; void *win; u8 padD44[0xD90-0xD44]; void *wins[6]; } Work;
extern const u16 tbl_02202EC0[][2];
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 layer);
extern void func_02200BAC(u8 *p, u32 k);
void func_021F777C(Work *p)
{
    void *w;
    int i;
    p->win = (void *)BMP_WIN_Create(0, (u8)2, (u8)21, (u8)27, 2, 13, (u16)1);
    BMP_Clear(func_02045770(p->win), 0);
    w = p->win;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(func_02045730(w));
    for (i = 0; i < 6; i++) {
        p->wins[i] = (void *)BMP_WIN_Create(3, (u8)tbl_02202EC0[i][0], (u8)tbl_02202EC0[i][1], (u8)12, 2, 13, (u16)1);
        BMP_Clear(func_02045770(p->wins[i]), 0);
        w = p->wins[i];
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        func_020409B4(func_02045730(w));
    }
    func_02200BAC((u8 *)p, 3);
}
