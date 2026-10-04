/*
 * function: func_021BCC68
 * address: 0x021BCC68
 * packet: pkt_ov217_021BCC68
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_021C0EF4 0x021C0EF4 thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C33C8 0x021C33C8 data a4
 *   d_021C3520 0x021C3520 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 idx;
    u32 arg;
    u32 w;
};
struct Loc {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 w;
};
struct S { char pad0[8]; u16 h8; char pad1[2]; u32 f0c; u32 arr[0x28]; };
extern const struct Ent d_021C33C8[];
extern const struct Ent d_021C3520[];
extern int func_021BC6DC(struct S *p);
struct Config;
struct Record;
extern struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
extern u32 func_021C0F5C(u32 a0, u32 a1);

void func_021BCC68(struct S *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        const struct Ent *e = &d_021C33C8[i];
        struct Loc l1;
        l1.b0 = e->b0;
        l1.b1 = e->b1;
        l1.b2 = e->b2;
        l1.b3 = e->b3;
        l1.b4 = e->b4;
        l1.b5 = e->b5;
        l1.b6 = e->b6;
        l1.b7 = e->b7;
        l1.b8 = e->b8;
        l1.b9 = e->b9;
        l1.b10 = e->b10;
        l1.w = e->w;
        p->arr[0xdc / 4 - 4 + i] = (u32)func_021C0EF4((const struct Config *)(&l1), p->f0c, p->arr[e->idx], p->h8);
        func_021C0F5C(p->arr[0xdc / 4 - 4 + i], e->arg);
    }
    for (i = 0; i < func_021BC6DC(p); i++) {
        const struct Ent *e = &d_021C3520[i];
        struct Loc l2;
        l2.b0 = e->b0;
        l2.b1 = e->b1;
        l2.b2 = e->b2;
        l2.b3 = e->b3;
        l2.b4 = e->b4;
        l2.b5 = e->b5;
        l2.b6 = e->b6;
        l2.b7 = e->b7;
        l2.b8 = e->b8;
        l2.b9 = e->b9;
        l2.b10 = e->b10;
        l2.w = e->w;
        p->arr[0xb4 / 4 - 4 + i] = (u32)func_021C0EF4((const struct Config *)(&l2), p->f0c, p->arr[e->idx], p->h8);
        func_021C0F5C(p->arr[0xb4 / 4 - 4 + i], e->arg);
    }
}
