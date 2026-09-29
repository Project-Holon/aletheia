/*
 * function: func_021F1A28
 * address:  0x021F1A28
 * packet:   pkt_ov032_021F1A28
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; the only wildcard is the bl to func_02010FA0 (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, Ilias's; it sits
 * in the word run after sub_02010EA0/func_02010EEC). Verified leaf C
 * (EXACT, arm9 0x02010FA0, thumb, `one --thumb` with no --region):
 *   typedef unsigned short u16;
 *   u16 func_02010FA0(unsigned char *rec, int slot)
 *   { return *(u16 *)(rec + slot * 0xc + 2); }
 * `u8 c` and `int flag` with `flag = 0` after the p[0x7f] store are what
 * put the flag's zero store after the argument copies.
 *
 * symbols:
 *   func_021F1A28 0x021F1A28 thumb
 *   func_021F1B94 0x021F1B94 thumb ov032
 *   func_021F1CF0 0x021F1CF0 thumb ov032
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02031288 0x02031288 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201F184 0x0201F184 thumb
 *   func_02010FA0 0x02010FA0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   sub_02010EA0 0x02010EA0 thumb
 *   func_02010EEC 0x02010EEC thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F1B94(void *h, char *t);
extern void func_021F1CF0(void *h, char *t);
extern void func_021F05E8(char *p, int a, int b);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void);
extern void func_02031288(void *h, void *fn);
extern void func_02082BCC(void *p, int v, int n);
extern void func_0201F184(u32 a, u32 b, int c);
extern u16 func_02010FA0(u32 a, int b);
extern u16 func_02007FB8(u32 a, u32 b, u32 c);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u8 sub_02010EA0(int slot, u32 rec);
extern int func_02010EEC(void);

void func_021F1A28(char *p, int b, u8 c, int *r)
{
    void *h;
    int flag;
    u8 *t;

    h = func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1B94, 0x24, 0);
    t = func_02031290();
    func_02082BCC(t, 0, 0x24);
    p[0x7f] = 0x30;
    flag = 0;
    if (c == 0)
        flag = 1;
    p[0x80] = flag;
    *(char **)(t + 0x1c) = p;
    t[2] = 0x5a;
    *(int *)(t + 0xc) = b;
    t[3] = c;
    func_0201F184(*(u32 *)(p + 0x110), 1, b);
    if (t[3] == 0) {
        *(u16 *)(t + 0x12) = func_02010FA0(*(u32 *)(p + 0x24), b);
        *(u16 *)(t + 0x10) = func_02007FB8(*(u32 *)(p + 0x18), 0x23f, *(u16 *)(p + 0x96));
        func_0201EFA4(*(u32 *)(p + 0x110), 2, *(u16 *)(t + 0x12), 3, 0, 1);
        func_0201EFA4(*(u32 *)(p + 0x110), 3, *(u16 *)(t + 0x10), 3, 0, 1);
        if (b == sub_02010EA0(b, *(u32 *)(p + 0x24))) {
            *(u16 *)(t + 0x14) = func_02010EEC();
            if (*(u16 *)(t + 0x14) != 0) {
                *(u16 *)(t + 0x16) = *(u16 *)(t + 0x14) / 60;
                *(u16 *)(t + 0x18) = *(u16 *)(t + 0x14) % 60;
                func_0201EFA4(*(u32 *)(p + 0x110), 4, *(u16 *)(t + 0x16), 3, 0, 1);
                func_0201EFA4(*(u32 *)(p + 0x110), 5, *(u16 *)(t + 0x18), 2, 0, 1);
            }
        }
    }
    if (t[3] != 0)
        func_021F05E8(p, 0, 2);
    func_021F05E8(p, 1, 2);
    func_021F05E8(p, 2, 2);
    func_021F05E8(p, 3, 2);
    if (*(u16 *)(t + 0x14) != 0 || *(u16 *)(t + 0x10) < *(u16 *)(t + 0x12))
        func_02031288(h, (void *)func_021F1CF0);
    *(int **)(t + 0x20) = r;
    (*r)++;
}
