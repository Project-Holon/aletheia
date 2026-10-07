/*
 * function: func_021BBF10
 * address:  0x021BBF10
 * packet:   pkt_ov021_021BBF10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
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
typedef unsigned int   u32;
extern u32 func_02050080(u32 *p);
extern int func_020508C4(int a, int b);
extern void func_0204F6B4(u8 *a0, int i, u8 *px);

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
        r6 = func_02050080((u32 *)r4);
        t = func_020508C4(r4, p->h8);
        func_0204F6B4((u8 *)r6, t, &c);
        break;
    }
}
