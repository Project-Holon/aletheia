/*
 * file:     unit_021E0DC4.c
 * unit:     yes
 * function: func_021E0DC4, func_021E0DF4, func_021E0E00, func_021E0E28, func_021E0F44
 * address:  0x021E0DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   d_021F28D8     0x021F28D8  data   ov093  a4
 *   d_021F24D4     0x021F24D4  data   ov093  a4
 */
struct S;
typedef unsigned int   u32;

typedef unsigned char u8;

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
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D80A8(void *p);
extern int func_021D76BC(int key, u32 val);
extern int func_021D5814(void *m, int k);
extern int func_021D59B4(u8 *p, int k);
extern Word func_021E89C0(void);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C83DC(char *p, int x);
void func_021E0DC4(int a, void *q, int id);
int *func_021E0DF4(int *p);
void func_021E0E00(int a, int b, int c);
void func_021E0E28(int a, void *q, int id);
int *func_021E0F44(int *p);
extern int d_021F28D8[];
extern int d_021F24D4[];


void func_021E0DC4(int a, void *q, int id)
{
    unsigned char *r;

    if (id != func_021D775C(3))
        return;
    r = (unsigned char *)func_021C88A4(q, 4, id);
    func_021C8838(r + 4, 1, 102);
    func_021C88C8(q, r);
}


int *func_021E0DF4(int *p)
{
    *p = 2;
    return d_021F28D8;
}


void func_021E0E00(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(27, func_021D80A8(func_021C7CF4((int *)b, c)));
}



/*
 * func_021E89C0 returns a one-word struct (Word): the by-value struct return
 * reserves a 4-byte stack temporary, which is the second slot of the original's
 * `sub sp,#8` frame. An int return keeps m in the push's r3 slot with no sub sp.
 */
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
                func_021C8860((struct S *)((u8 *)r + 0x14), id);
                func_021C8860((struct S *)((u8 *)r + 0x14), k);
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


int *func_021E0F44(int *p)
{
    *p = 1;
    return d_021F24D4;
}
