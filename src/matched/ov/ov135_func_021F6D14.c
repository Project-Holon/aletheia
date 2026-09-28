/*
 * function: func_021F6D14
 * address:  0x021F6D14
 * packet:   pkt_021F6D14
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
  *
  *
 * symbols:
 *   func_021F8554  0x021F8554  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

typedef struct {
    u16 species;
    u8 form;
    u8 b3;
    u8 b4;
} WantTag;

typedef struct {
    u8 pad0[0xCC];
    void *mon;
    u8 padD0[0xD4 - 0xD0];
    int sel;
    u8 padD8[0x20C - 0xD8];
    u8 list[1][0x128];
} Work;

typedef struct {
    u8 pad0[0xEC];
    MonTag have;
    WantTag want;
} Deposit;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02018438(void *p);
extern void func_021F8554(Deposit *dst, Work *p);
extern void *func_020185F4(void *a);

void func_021F6D14(Deposit *dst, Work *p)
{
    MonTag m;
    WantTag w;
    void *e;

    m.species = func_02017E88(p->mon, 5, 0);
    m.form = func_02017E88(p->mon, 0x6E, 0) + 1;
    m.gender = func_02018438(p->mon);
    dst->have = m;
    func_021F8554(dst, p);
    e = func_020185F4(p->list[p->sel]);
    w.species = func_02017E88(e, 5, 0);
    w.form = func_02017E88(e, 0x6E, 0) + 1;
    w.b3 = 0;
    w.b4 = 0;
    dst->want = w;
}
