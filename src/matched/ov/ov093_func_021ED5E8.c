/*
 * function: func_021ED5E8
 * address:  0x021ED5E8
 * packet:   pkt_ov093_021ED5E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021F7D80  0x021F7D80  thumb  ov094
 *   func_021F7E38  0x021F7E38  thumb  ov094
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F803C  0x021F803C  thumb  ov094
 *   func_02031194  0x02031194  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *w; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

extern int func_021B98AC(char *const *q, u8 b);
extern u32 func_021D5844(u32 *p);
extern int func_021F7D80(int a, int b);
extern void func_021F7E38(int a, int b);
extern void func_021F80E4(u32 a);
extern int func_021F7EB4(void);
extern void func_021F803C(u32 a, u32 b, u32 c);
extern void func_02031194(u32 a);

void func_021ED5E8(u32 x, struct S *t)
{
    u32 r;

    switch (t->c) {
    case 0:
        r = func_021D5844((u32 *)func_021B98AC(*(char *const **)(t->w + 0x138), t->k));
        if (t->a == 0)
            func_021F7D80(r, t->v);
        else
            func_021F7E38(r, t->v);
        func_021F80E4(t->v);
        t->c++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021F803C(*(u32 *)(t->w + 0x134),
                          func_021B98AC(*(char *const **)(t->w + 0x138), t->k), t->v);
            (*t->cnt)--;
            func_02031194(x);
        }
        break;
    }
}
