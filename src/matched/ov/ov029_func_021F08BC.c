/*
 * function: func_021F08BC
 * address:  0x021F08BC
 * packet:   pkt_ov029_021F08BC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F08BC  0x021F08BC  thumb  ov029
 *   func_020215BC  0x020215BC  thumb
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct PalAnmSlot;
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern const u8 d_021F31A8[];

struct W {
    u8 pad0[0x210];
    int unk_210;
    u8 pad1[0x1c];
    u16 unk_230[3][5];
    u16 unk_24E[3][5];
    u16 unk_26C[3];
    u16 unk_272[1][5];
};

void func_021F08BC(struct W *p, int i, int j, int k)
{
    int n;
    int m;
    int a;
    int b;

    for (n = 0; n < 5; n++) {
        p->unk_24E[i][n] = 0;
        for (m = 0; m < 3; m++) {
            a = (p->unk_230[i][n] >> (m * 5)) & 0x1f;
            b = ((p->unk_272[p->unk_26C[i]][n] >> (m * 5)) & 0x1f) - a;
            p->unk_24E[i][n] |= ((a + b * j / k) & 0x1f) << (m * 5);
        }
        func_020215BC((struct PalAnmSlot *)p->unk_210, &p->unk_24E[i][n], 1, (u16)(d_021F31A8[i] + (n + 1) * 16), 2);
    }
}
