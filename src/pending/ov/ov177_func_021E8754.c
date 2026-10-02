/*
 * function: func_021E8754
 * address:  0x021E8754
 * packet:   pkt_ov177_021E8754
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note 2026-10-02: all code matches except the case 2 arm: original ends it with an
 *   explicit `b` onto the immediately following case 0 block (+2 bytes, 238 vs 240).
 *   Fallthrough case 2 -> case 0 emits no such branch. Tried default arm, goto, guarded if.
 *
 * symbols:
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028604  0x02028604  thumb
 *   func_021E8848  0x021E8848  thumb  ov177
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02034714  0x02034714  arm
 *   func_02028470  0x02028470  thumb
 *   func_02028590  0x02028590  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   d_021E8DEC     0x021E8DEC  data
 */

typedef struct {
    int            f0;
    int            f4;
    int            f8;
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad0[3];
    int            f28;
    int            f2c;
    int            f30;
    int            f34;
    char           f38[1];
} S;

extern unsigned char d_021E8DEC[];

extern void func_0201C6EC(int);
extern int  func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_0201CE48(int);
extern void func_02028604(int);
extern void func_021E8848(S *);
extern int  func_020056BC(void);
extern int  func_0202EE30(int, int, int, int, int);
extern void func_0201C6FC(int, int, int, int, int, int);
extern void func_02034714(void *, int, void *);
extern void func_02028470(void *, int);
extern int  func_02028590(int, int, int, int);
extern int  func_02012FFC(void);
extern int  func_0201CCE4(int, int, int, int, int, int, int, int, int, int);

void func_021E8754(S *p, int mode)
{
    int q;

    func_0201C6EC(p->f28);
    func_02043B5C(func_02045770(p->f14), (unsigned char)p->f1c);
    if (p->f8 != 0) {
        func_0201CE48(p->f8);
        p->f8 = 0;
    }
    if (p->f34 != 0) {
        func_02028604(p->f34);
        p->f34 = 0;
    }
    func_021E8848(p);
    switch (mode) {
    case 2:
        p->f10 = func_0202EE30(func_020056BC(), p->f14, (unsigned char)p->f1c, 0x10, p->f1e);
    case 0:
        q = p->f28;
        func_0201C6FC(q, func_02045770(p->f20), 0, 0, p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 1:
        if (p->f34 != 0) {
            func_02034714(d_021E8DEC, 0, d_021E8DEC);
        }
        func_02028470(p->f38, 2);
        p->f34 = func_02028590(p->f1c, 1, 0, p->f1e);
        p->f8 = func_0201CCE4(p->f14, 0, 0, p->f18, p->f4, func_02012FFC(), p->fc, 0, p->f1e, p->f1c);
        p->f2c = 1;
        break;
    }
    p->f30 = 0;
}
