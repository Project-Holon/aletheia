/*
 * function: func_021ED8E8
 * address:  0x021ED8E8
 * packet:   pkt_ov093_021ED8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ED798  0x021ED798  thumb  ov093
 *   func_021ED814  0x021ED814  thumb  ov093
 *   func_02031194  0x02031194  arm
 */

typedef unsigned char u8;

struct Sub {
    u8 pad[0x14];
};

struct Q {
    char *f00;
    int f04;
    u8 *f08;
};

extern void func_021ED798(void *p);
extern int func_021ED814(void *p);
struct TcblNode;
extern void func_02031194(struct TcblNode *n);

void func_021ED8E8(int a,struct Q *q)
{
    switch (q->f04) {
    case 0:
        func_021ED798(q->f00 + 0x154);
        q->f04++;
        break;
    case 1:
        if (func_021ED814(q->f00 + 0x154) != 0) {
            (*q->f08)--;
            func_02031194((struct TcblNode *)a);
        }
        break;
    }
}
