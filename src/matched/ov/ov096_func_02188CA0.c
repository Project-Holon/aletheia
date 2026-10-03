/*
 * function: func_02188CA0
 * address:  0x02188CA0
 * packet:   pkt_ov096_02188CA0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the source order of the switch arms decides which arm holds the
 *   shared tail and which becomes a stub jump; the original order is
 *   1,0,3,2,4,6,5,8,7 (not ascending).
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A378  0x0218A378  thumb  ov096
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021E8D04  0x021E8D04  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xbc - 0x3c];
    u8 *fbc;
    u8 *fc0;
    int fc4;
} Conn;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A378(Conn *, int, int);
typedef signed int     s32;
extern u16 func_021D57FC(void *p);
extern u8 func_021E8CFC(s32 v);
extern unsigned char func_021E8D04(int x);

int func_02188CA0(int a, Conn *b)
{
    u32 k;
    int p;
    int q;

    k = func_0201134C(a);
    p = func_021D57FC(b->fbc);
    q = func_021D57FC(b->fc0);
    switch (k) {
    case 1:
        b->f38 = func_021E8CFC(p);
        break;
    case 0:
        b->f38 = func_021E8CFC(q);
        break;
    case 3:
        b->f38 = func_021E8D04(p);
        break;
    case 2:
        b->f38 = func_021E8D04(q);
        break;
    case 4:
        b->f38 = func_0218A378(b, b->f2, 0);
        break;
    case 6:
        b->f38 = func_021E8CFC(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3))));
        break;
    case 5:
        b->f38 = func_021E8CFC(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 2))));
        break;
    case 8:
        b->f38 = func_021E8D04(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 3))));
        break;
    case 7:
        b->f38 = func_021E8D04(func_021D57FC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, 2))));
        break;
    }
    return b->fc4;
}
