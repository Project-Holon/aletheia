/*
 * file:     btl_net_p15.c
 * unit:     yes
 * function: func_021D505C, func_021D50B4, func_021D5150
 * address:  0x021D505C
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
 *   func_020181F4  0x020181F4  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_021D5244  0x021D5244  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct E {
    u16 f00;
    u8 f02;
    u8 pad03;
    u8 f04;
    u8 pad05[9];
};

struct A {
    void *f00;
    u8 pad04[0x100];
    struct E e[4];
};

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Ent {
    u16 h[6];
    u8 fC;
    u8 fD;
};

struct Work_021D50B4 {
    void *h;
    u8 pad4[0x100];
    struct Ent e[4];
    u8 pad13C[4];
    u8 n140;
};

struct Work_021D5150 {
    u8 pad0[0x104];
    struct Ent e[4];
    u8 pad13C[4];
    u8 n140;
};

extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_02017E40(void *p, u32 id, u32 v);
extern int func_021D5244(struct Ent *e, void *h, u8 k);
void func_021D505C(struct A *a);
void func_021D50B4(struct Work_021D50B4 *p);
void func_021D5150(struct Work_021D5150 *p);


void func_021D505C(struct A *a)
{
    void *mon = a->f00;
    u32 i;

    for (i = 0; i < 4; i++) {
        func_020181F4(mon, a->e[i].f00, (u8)i);
        func_02017E40(mon, 0x3a + i, a->e[i].f02);
        func_02017E40(mon, 0x3e + i, a->e[i].f04);
    }
}


void func_021D50B4(struct Work_021D50B4 *p)
{
    void *h = p->h;
    u32 i;
    p->n140 = 0;
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&p->e[i], h, i)) p->n140++;
        if (p->e[i].fC != 0) {
            p->e[i].h[3] = p->e[i].h[0];
            p->e[i].h[4] = p->e[i].h[1];
            p->e[i].h[5] = p->e[i].h[2];
        }
    }
}


void func_021D5150(struct Work_021D5150 *p)
{
    u32 i;
    p->n140 = 0;
    for (i = 0; i < 4; i++) {
        p->e[i].h[3] = p->e[i].h[0];
        p->e[i].h[4] = p->e[i].h[1];
        p->e[i].h[5] = p->e[i].h[2];
        if (p->e[i].h[3] != 0) p->n140++;
        p->e[i].fC = 1;
    }
}
