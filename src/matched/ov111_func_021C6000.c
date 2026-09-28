/*
 * function: func_021C6000
 * address:  0x021C6000
 * packet:   pkt_ov111_021C6000
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02040C14  0x02040C14  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201C440  0x0201C440  thumb
 *   d_021C8773  0x021C8773  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *win[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
    u8 pad32D0[4];
    u8 f32D4;
} Work;

extern void func_02045088(int heap);
extern void *func_020450F0(int a, int b, int c, int d, int e, int f, int g);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *p, int v);
extern void func_02040C14(int a, int b, int c, int d);
extern void func_0201F5BC(int a, int b, int c, int d, int heap);
extern void func_02049B40(int a, int b, int c, int d, int e, int heap);
extern void func_02041B6C(int frame);
extern void *func_0201C440(int heap);
extern const u8 d_021C8773[8][6];

void func_021C6000(Work *p)
{
    const u8 (*tbl)[6] = d_021C8773;
    u8 i;

    func_02045088(p->heap);
    for (i = 0; i < 8; i++) {
        p->win[i] = func_020450F0(tbl[i][0], tbl[i][1], tbl[i][2], tbl[i][3], tbl[i][4], tbl[i][5], 1);
        func_02043B5C(func_02045770(p->win[i]), 0);
    }
    func_02040C14(7, 0, 1, 0);
    func_0201F5BC(4, 0x31, 0xD, p->f32D4, p->heap);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, p->heap);
    func_02041B6C(7);
    func_02041B6C(4);
    p->f32CC = func_0201C440(p->heap);
}
