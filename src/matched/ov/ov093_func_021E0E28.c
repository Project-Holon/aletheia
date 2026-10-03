/*
 * function: func_021E0E28
 * address:  0x021E0E28
 * packet:   pkt_ov093_021E0E28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * func_021E89C0 returns a one-word struct (Word): the by-value struct return
 * reserves a 4-byte stack temporary, which is the second slot of the original's
 * `sub sp,#8` frame. An int return keeps m in the push's r3 slot with no sub sp.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Word { unsigned int v; } Word;

typedef struct RecA {
    int pad00;
    int f04;
    Word f08;
    signed char f0c;
    u8 pad0d[2];
    u8 f0f;
    u8 f10;
} RecA;

typedef struct RecB {
    u32 f00;
    u8 f04;
    u8 pad05[2];
    u8 f07;
    u8 pad08[8];
    int f10;
} RecB;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5814(void *m, int k);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(void *a, int k, int b);
extern Word func_021E89C0(void);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C83DC(void *p, int x);

void func_021E0E28(int a, void *q, int id)
{
    void *m;
    int flag;
    u8 k;
    RecA *r;
    RecB *s;

    if (id != func_021D775C(3))
        return;
    m = func_021C7CF4(q, id);
    flag = 0;
    if (func_021D5814(m, 7)) {
        if (func_021D59B4(m, 13) > 0) {
            k = func_021D775C(6);
            if (k != 31) {
                r = (RecA *)func_021C88A4(q, 12, id);
                r->f0f = k;
                r->f04 = 10;
                r->f08 = func_021E89C0();
                func_021C8838((u8 *)r + 0x14, 2, 1064);
                func_021C8860((u8 *)r + 0x14, id);
                func_021C8860((u8 *)r + 0x14, k);
                func_021C88C8(q, r);
                s = (RecB *)func_021C88A4(q, 8, id);
                s->f07 = id;
                s->f10 = -func_021D7B74(m, 2);
                s->f04 = 1;
                s->f00 |= 0x1000000;
                func_021C88C8(q, s);
            }
        }
        flag = 1;
    } else {
        r = (RecA *)func_021C88A4(q, 14, id);
        r->f0f = 1;
        r->f10 = id;
        r->f04 = 5;
        r->f0c = -1;
        func_021C88C8(q, r);
        r = (RecA *)func_021C88A4(q, 14, id);
        r->f0f = 1;
        r->f10 = id;
        r->f04 = 1;
        r->f0c = 1;
        func_021C88C8(q, r);
        r = (RecA *)func_021C88A4(q, 14, id);
        r->f0f = 1;
        r->f10 = id;
        r->f04 = 2;
        r->f0c = 1;
        func_021C88C8(q, r);
    }
    func_021C83DC(q, flag);
}
