/*
 * function: func_021D505C
 * address:  0x021D505C
 * packet:   pkt_ov093_021D505C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020181F4  0x020181F4  thumb
 *   func_02017E40  0x02017E40  thumb
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

extern void func_020181F4(void *p, u16 move, u8 slot);
extern void func_02017E40(void *p, u32 id, u32 v);

void func_021D505C(struct A *a)
{
    void *mon = a->f00;
    u32 i;

    for (i = 0; i < 4; i++) {
        func_020181F4(mon, a->e[i].f00, i);
        func_02017E40(mon, 0x3a + i, a->e[i].f02);
        func_02017E40(mon, 0x3e + i, a->e[i].f04);
    }
}
