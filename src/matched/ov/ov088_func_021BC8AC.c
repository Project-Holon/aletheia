/*
 * function: func_021BC8AC
 * address:  0x021BC8AC
 * packet:   pkt_ov088_021BC8AC
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_021BC870  0x021BC870  thumb  ov088
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C08  0x02035C08  arm
 *   d_021BD83C     0x021BD83C  data  a1
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct C12 {
    char c[12];
} C12;

extern C12 d_021BD83C;

extern u32 func_020362DC(void);
extern void func_021BC870(u8 *);
extern void func_020061E4(u32);
extern int func_02035C08(const void *p);

int func_021BC8AC(u8 *p)
{
    int r;
    u32 k;
    int t;
    C12 s;

    if ((func_020362DC() & 0x40) || (func_020362DC() & 0x80)) {
        if (p[0] == 0)
            p[0] = 1;
        else
            p[0] = 0;
        func_021BC870(p);
        func_020061E4(0x548);
    }
    k = func_020362DC();
    r = 1;
    if (k & r) {
        func_020061E4(0x54C);
        if (p[0] != 0)
            r = 2;
        return r;
    }
    s = d_021BD83C;
    t = func_02035C08(&s);
    if (t != -1) {
        func_020061E4(0x54C);
        return t == 0 ? 1 : 2;
    }
    return 0;
}
