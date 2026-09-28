/*
 * function: func_021F1898
 * address:  0x021F1898
 * packet:   pkt_ov107_021F1898
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02194A34  0x02194A34  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_0202F038  0x0202F038  thumb
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
    unsigned char pad14[0x40];
    void *f54;
    unsigned char pad58[4];
    void *f5C;
} Ov107Ctx;

void *func_02045770(void *);
void func_02043B5C(void *, int);
int func_02194A34(void *, void *);
void func_020409B4(int);
void func_0201F7A8(void *, int);
void func_0202F038(void *);

void func_021F1898(Ov107Ctx *p)
{
    func_02043B5C(func_02045770(p->f10), 0);
    if (p->f04 == 8) {
        func_02194A34(p->f54, p->f10);
        func_020409B4(p->f02);
    } else {
        func_0201F7A8(p->f10, 1);
    }
    if (p->f5C != 0) {
        func_0202F038(p->f5C);
        p->f5C = 0;
    }
}
