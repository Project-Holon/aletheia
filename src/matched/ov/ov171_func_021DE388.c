/*
 * function: func_021DE388
 * address: 0x021DE388
 * packet: pkt_ov171_021DE388
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave D4 lane08: EXACT. The slot pointer is assigned in each if/else arm (two definitions, so it is not
 *   forwarded to its single use; the shared arm tails merge), and slot is declared before v (slots 0x1c/0x18).
 * symbols:
 *   func_021DE064 0x021DE064 thumb ov171
 *   func_021DE290 0x021DE290 thumb ov171
 *   func_021DE608 0x021DE608 thumb ov171
 *   func_021DE34C 0x021DE34C thumb ov171
 *   func_021DE1F8 0x021DE1F8 thumb ov171
 *   func_021DE218 0x021DE218 thumb ov171
 *   func_021DE238 0x021DE238 thumb ov171
 *   func_021DE684 0x021DE684 thumb ov171
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_02017ED8 0x02017ED8 thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02049238 0x02049238 arm
 *   d_021DEC04 0x021DEC04 data a4
 *   d_021DEC94 0x021DEC94 data a4
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct E { u32 w[6]; };
struct Ent { u32 f0; u32 f4; u32 f8; u32 fc; u16 f10; u8 f12; u8 a : 6; u8 b : 2; };
extern const struct E d_021DEC04[];
extern const struct E d_021DEC94[];
struct PalAnmSlot;
extern void func_021DE064(int *p, int i, int a);
struct Obj;
extern struct Obj *func_021DE290(char *p, const char *q);
extern void func_021DE608(char *, int, int);
extern void func_021DE34C(char *, int);
extern void func_021DE1F8(char *, int);
extern void func_021DE218(char *, int);
extern void func_021DE238(char *, int);
extern void func_021DE684(u8 *p);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32, u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 func_0202D7D8(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_0202D898(u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 func_02017ED8(u32, u32);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02049238(u32);
void func_021DE388(char *p) {
    u32 i;
    u32 h;
    char *rec;
    u32 *slot;
    u32 v;
    struct Ent *r;
    u32 x;
    struct E e;
    for (i = 0; i <= 11; i++) func_021DE064((int *)p, i, 0);
    rec = p + 0xc + (s8)p[0xC5E] * 0xbc;
    h = func_0202D7C8(0x808C);
    {
        for (i = 0; i < *(u16 *)(rec + 0xb8); i++) {
            e = d_021DEC04[i];
            r = (struct Ent *)(rec + i * 0x1c);
            x = func_02017ED8(r->fc, r->f8);
            if (*(u8 *)(p + 0xC60) == 1) {
                e.w[2] += 6;
                e.w[3] += 6;
                e.w[4] += 6;
                v = (u16)(i + 6);
                slot = (u32 *)(p + 0xB74 + v * 4);
            } else {
                v = (u16)i;
                slot = (u32 *)(p + 0xB74 + v * 4);
            }
            *(u32 *)(p + e.w[2] * 4 + 0xBB4) = func_0202D81C(h, r->f10, r->a, r->b, x, 0, 0, r->f8, 0, 0x8c);
            *(u32 *)(p + e.w[3] * 4 + 0xBE8) = func_0202D7D8(h, r->f10, r->a, r->b, x, 0, 0, 0, (u16)(v << 5), 0x8c);
            *(u32 *)(p + e.w[4] * 4 + 0xC1C) = func_0202D898(r->f10, r->a, r->b, x, 0, 0, 2, 0, 0x8c);
            *slot = (u32)func_021DE290(p, (const char *)(&e));
            func_021DE608(p, v, *(u16 *)((char *)d_021DEC94 + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18));
            *(u16 *)(p + i * 2 + 0xB10) = *(u16 *)((char *)d_021DEC94 + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18);
        }
    }
    func_020216D4(*(void **)(p + 0xB30), 2, 0, 0x200);
    func_02049238(h);
    if (*(u8 *)(p + 0xC60) == 1) {
        for (i = 0; i <= 5; i++) func_021DE34C(p, i);
        for (i = 0; i <= 5; i++) func_021DE1F8(p, i);
        for (i = 0; i <= 5; i++) func_021DE218(p, i);
        for (i = 0; i <= 5; i++) func_021DE238(p, i);
    } else {
        for (i = 6; i <= 11; i++) func_021DE34C(p, i);
        for (i = 6; i <= 11; i++) func_021DE1F8(p, i);
        for (i = 6; i <= 11; i++) func_021DE218(p, i);
        for (i = 6; i <= 11; i++) func_021DE238(p, i);
    }
    *(u8 *)(p + 0xC60) ^= 1;
    func_021DE684((u8 *)p);
}
