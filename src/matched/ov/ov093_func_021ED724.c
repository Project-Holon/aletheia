/*
 * function: func_021ED724
 * address:  0x021ED724
 * packet:   pkt_ov093_021ED724
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F7D80  0x021F7D80  thumb  ov094
 *   func_021F7E38  0x021F7E38  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_02031194  0x02031194  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

extern void func_021F7D80(void *a, int b);
extern void func_021F7E38(void *a, int b);
extern int func_021F7EB4(void);
struct TcblNode;
extern void func_02031194(struct TcblNode *n);

void func_021ED724(u32 x, struct S *t)
{
    switch (t->c) {
    case 0:
        if (t->f == 0)
            func_021F7D80(t->v, t->k);
        else
            func_021F7E38(t->v, t->k);
        t->c++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            (*t->cnt)--;
            func_02031194((struct TcblNode *)x);
        }
        break;
    }
}
