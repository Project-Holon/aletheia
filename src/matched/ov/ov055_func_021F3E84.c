/*
 * function: func_021F3E84
 * address:  0x021F3E84
 * packet:   pkt_ov055_021F3E84
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S {
    char pad[0x32];
    short cnt[2];
    int f38;
    u32 f3c;
} S;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int *func_02049250(void *, int, u16);
extern u32 func_020493D4(void *, int);
extern void func_0204944C(void *, int, int, int, void *);
extern void func_020307B0(void *);
extern void func_02049238(void *);

void func_021F3E84(S *o, int b, int key, u16 c)
{
    void *h;
    int *tbl;
    u32 n, i;
    u32 m;
    int j;

    m = (c & 0x7fff) | 0x8000;
    h = func_020490F4(0xba, m);
    tbl = func_02049250(h, 5, m);
    n = func_020493D4(h, 5) >> 2;
    for (i = 0; i < n; i++) {
        if (key == tbl[i])
            break;
    }
    func_0204944C(h, i, 0, 0x32, o);
    func_020307B0(tbl);
    n = func_020493D4(h, 6);
    o->f38 = (int)func_02049250(h, 6, c);
    o->f3c = n >> 4;
    func_02049238(h);
    for (j = 0; j < 2; j++)
        o->cnt[j] = 0;
}
