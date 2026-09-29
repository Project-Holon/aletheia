/*
 * function: func_021B6250
 * address:  0x021B6250
 * packet:   pkt_ov071_021B6250
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Main proc of the ov071 triple (work allocated by func_021B6100): fade in,
 * wait on the link state, start the two sound handles (+0x12C/+0x130) off the
 * d_021BA774 pair table, fade out. The link-wait cases are
 * `if (r == 0 || FB24() != 0) seq++; else if (X() == 1) seq++;`: one ||
 * chain of all three conditions lays the branches out 2 B short.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0202208C  0x0202208C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0217440C  0x0217440C  thumb  ov011
 *   func_0217446C  0x0217446C  thumb  ov011
 *   func_020221A4  0x020221A4  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02031348  0x02031348  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02031330  0x02031330  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   d_021BA774     0x021BA774  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
} Pair;

extern Pair d_021BA774[];

extern void *func_02012138(void *);
extern u8 *func_02158344(void);
extern void func_0202208C(int, int, int, int, int, int, int);
extern int func_0200FB24(void);
extern int func_0217440C(void);
extern int func_0217446C(void);
extern int func_020221A4(void);
extern int func_0202648C(void *);
extern int func_02026454(void *);
extern void func_02031348(int h, int id, int a, void *b);
extern void func_0201DD78(u32, u32, u32);
extern int func_02031330(int h);
extern void func_020310C4(void *);
extern void func_0201C4E4(int);
extern void func_0204A600(void);

int func_021B6250(int a, int *seq, void **pwk, u8 *mywk)
{
    void *h;
    u8 *r;
    int s1;
    int s2;
    u8 k;

    h = func_02012138(*pwk);
    r = func_02158344();
    switch (*seq) {
    case 0:
        func_0202208C(0, 1, 1, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 1:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (func_0217440C() == 1)
            (*seq)++;
        break;
    case 2:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0200FB24() != 0 || (r == 0 && func_0202648C(h) != 0) || (r == 0 && func_02026454(h) == 2))
            mywk[0x126] = 1;
        if (mywk[0x126] == 0) {
            if (mywk[0x135] == 0) {
                func_02031348(*(int *)(mywk + 0x12C), -1, d_021BA774[mywk[0x134]].a, mywk + 0xF8);
                mywk[0x135] = 1;
            }
            if (mywk[0x136] == 0) {
                func_0201DD78(0xF, 2, 0);
                func_02031348(*(int *)(mywk + 0x130), -1, d_021BA774[mywk[0x134]].b, mywk + 0xF8);
                mywk[0x136] = 1;
            }
        }
        s2 = func_02031330(*(int *)(mywk + 0x130));
        k = mywk[0x124];
        if (k == 4 || (s2 != 1 && mywk[0x126] == 1)) {
            mywk[0x125] = 1;
        } else if (mywk[0x134] != k && d_021BA774[mywk[0x134]].a != d_021BA774[k].a) {
            mywk[0x125] = 1;
        }
        s1 = func_02031330(*(int *)(mywk + 0x12C));
        if (s1 == 1 && s2 == 1)
            break;
        if (mywk[0x126] == 1 || mywk[0x124] == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            mywk[0x134] = mywk[0x124];
            if (s1 != 1) {
                mywk[0x135] = 0;
                mywk[0x125] = 0;
            }
            if (s2 != 1)
                mywk[0x136] = 0;
        }
        break;
    case 4:
        func_0202208C(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (func_0217446C() == 1)
            (*seq)++;
        break;
    case 6:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    func_020310C4(*(void **)(mywk + 0x18));
    func_0201C4E4(*(int *)(mywk + 8));
    func_0204A600();
    return 0;
}
