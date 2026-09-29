/*
 * function: func_021BBF10
 * address:  0x021BBF10
 * packet:   pkt_ov021_021BBF10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_02050080 and func_020508C4 are unlabelled arm9 leaves
 * (Ilias's; no witness outside this range).  Verified EXACT arm:
 *   int func_02050080(A *p) { return p->a4; }   // A {int a0, a4;}
 *   int func_020508C4(B *p, int i) { return p->tab[i].e0; }
 *   // B {char pad[0x18]; E *tab;}  E {int e0; short e4; char pad[0x20];} (size 0x28)
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_020508C4  0x020508C4  arm
 *   func_0204F6B4  0x0204F6B4  arm
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned char u8;

typedef struct Head {
    int h0;
    int h4;
} Head;

typedef struct Obj {
    Head *head;
    int pad4;
    u16 h8;
    u16 hA;
    u16 padC;
    s16 h0e;
    int i10;
} Obj;

extern void func_021AC154(int a);
extern int func_02050080(int a);
extern int func_020508C4(int a, int b);
extern void func_0204F6B4(int a, u16 b, u8 *c);

void func_021BBF10(int a0, Obj *p)
{
    u8 c;
    int r4, r6;
    u16 t;

    switch (p->hA) {
    case 0:
        p->i10 = p->i10 + 1;
        if (p->i10 >= 0x10) {
            p->hA = p->hA + 1;
        }
        break;
    case 1:
        p->h0e = p->h0e - 2;
        if (p->h0e < 0) {
            func_021AC154(a0);
            return;
        }
        c = p->h0e;
        r4 = p->head->h4;
        r6 = func_02050080(r4);
        t = func_020508C4(r4, p->h8);
        func_0204F6B4(r6, t, &c);
        break;
    }
}
