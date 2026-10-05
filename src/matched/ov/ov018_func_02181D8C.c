/*
 * function: func_02181D8C
 * address:  0x02181D8C
 * packet:   pkt_ov018_02181D8C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  two unlabelled arm9 thumb leaves (Ilias's), no witness outside the range:
 *   0x02008494 (unresolved site +0034), 0x0202E82C (site +002E). Verified EXACT in scratch:
 *     void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }   (func_02082D44 arm)
 *     typedef struct { int f00; int f04; } S;
 *     void *func_0202E82C(S *p) { if (p->f04 != 0) return (char *)p + 0x2C; return (char *)p + 0xC; }
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0200846C  0x0200846C  thumb
 *   func_0202E82C  0x0202E82C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0217F2B4  0x0217F2B4  thumb
 *   func_02181DD4  0x02181DD4  thumb  ov018
 */

typedef unsigned char u8;

void *func_020120F4(void *);
void *func_02012F20(void *);
void *func_020122C0(void *, int, int (*)(), int);
u8 *func_020124E8(void *);
void *func_0200846C(void *);
void *func_0202E82C(void *);
void func_02008494(void *, void *);
void func_0217F2B4(void *, void *);
int func_02181DD4();

void *func_02181D8C(void *a, void *b)
{
    void *w;
    void *r;
    u8 *t;

    w = func_02012F20(func_020120F4(a));
    r = func_020122C0(a, 0, func_02181DD4, 0x34);
    t = func_020124E8(r);
    *(void **)(t + 0x30) = func_0200846C(b);
    func_02008494(func_0202E82C(w), *(void **)(t + 0x30));
    func_0217F2B4(t, a);
    return r;
}
