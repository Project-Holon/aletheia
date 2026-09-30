/*
 * function: func_021B6DD0
 * address: 0x021B6DD0
 * packet: pkt_ov093_021B6DD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the boolean passed narrow is an int local; t declared after desc puts t at sp+0x1c.
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B8B78 0x021B8B78 thumb ov093
 *   func_021B9E38 0x021B9E38 thumb ov093
 *   func_021B9E7C 0x021B9E7C thumb ov093
 *   func_021B6954 0x021B6954 thumb ov093
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021B6848 0x021B6848 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021B69FC 0x021B69FC thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021B6A3C 0x021B6A3C thumb ov093
 *   func_021B6A70 0x021B6A70 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAB40 0x021BAB40 thumb ov093
 *   func_021B83F4 0x021B83F4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B6818(int *);
struct T;
extern void func_021B6848(u8 *, struct T *);
extern void func_021B93E0(char *, u32, u32);
extern void func_021B9460(void *, void *, u8);
extern int func_021BA9C8(void *, void *, void *, int, u16);
extern void func_021B69FC(int, char *);
extern int func_021CD6F0(void *, void *, int, int, u16, u8, u8, int, u8, void *, u16);
extern void func_021B6A3C(void *, void *);
extern void func_021B6A70(void *, void *, int);
extern int func_021CD978(int);
extern void func_021BAA94(int, int, u8, u8);
extern void func_021BAB40(int);
extern int func_021B83F4(u8 *, int *);
extern int func_021B8B9C(void *, u8);
extern int func_021B8B78(void *, u8);
extern void func_021B9E38(int, int, int);
extern void func_021B9E7C(int, int);
extern void func_021B6954(int, u8);
extern void func_021EE644(void *, int, int);
extern void func_021CD938(int, void *);
int func_021B6DD0(int unused, u8 *p)
{
    u8 *q;
    int i;
    u8 k;
    int b;
    u8 *desc;
    u8 *table;
    int t;
    q = *(u8 **)p;
    t = func_021B6818((int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x42a] = 0;
    p[0x429] = 1;
    p[0x42b] = 1;
    switch (q[0x22]) {
    case 0: break;
    case 1: case 2: case 3:
        p[0x42a] = 2;
        p[0x42b] = 3;
        p[0x46b] = 4;
        break;
    case 4:
        p[0x42b] = 3;
        p[0x46b] = 3;
        break;
    }
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            func_021B9460(p + 0xc8, p, i);
            func_021B9460(p + 0x1b0, p, i);
        }
    }
    if (!q[0x23]) {
        func_021B9E38((int)(p + 0x20), *(u16 *)(p + 0x468), *(int *)(p + 0xc0));
        func_021B9E7C((int)(p + 0x48), *(int *)(q + 0x4c));
        if (func_021B8B9C(p, 2)) func_021B9E7C((int)(p + 0x70), *(int *)(q + 0x50));
        if (func_021B8B9C(p, 3)) func_021B9E7C((int)(p + 0x98), *(int *)(q + 0x54));
    } else {
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021B6954((int)p, i);
        }
    }
    *(int *)(p + 8) = func_021BA9C8(p, p + 0x3f0, p + 0x1b0, t, *(u16 *)(p + 0x468));
    p[0x46e] = 1;
    table = p + 0x3f0;
    desc = p;
    desc = p + 0xc8;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, i);
            b = 0;
            if (i != 0) b = 1;
            *(int *)(p + i * 4 + 0x10) = func_021CD6F0(p, desc, 0, *(int *)(q + 0x1c), i, k, b, t, q[0x23], table, *(u16 *)(p + 0x468));
        }
    }
    if (q[0x23]) {
        func_021EE644(p + 0x2c8, *(int *)(q + 0x94), *(int *)(q + 0x98));
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021CD938(*(int *)(p + i * 4 + 0x10), p + 0x2c8);
        }
    }
    func_021B6A70(p, q, t);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, i);
            func_021BAA94(*(int *)(p + 8), func_021CD978(*(int *)(p + i * 4 + 0x10)), i, k);
        }
    }
    func_021BAB40(*(int *)(p + 8));
    *(u32 *)(p + 0x464) = (u32)func_021B83F4;
    return 1;
}
