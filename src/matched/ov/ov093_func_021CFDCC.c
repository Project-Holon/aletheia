/*
 * function: func_021CFDCC
 * address: 0x021CFDCC
 * packet: pkt_ov093_021CFDCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: explicit aggregate return local reserves the original eight-byte frame;
 *   named incremented accessor result gives cmp r0,r4.
 * symbols:
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8AFC 0x021E8AFC thumb ov093
 *   func_021D631C 0x021D631C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Slot func_021D6314(void *, int);
extern u8 func_021E8AFC(union Slot);
extern u8 func_021D631C(u8 *p, int i);
int func_021CFDCC(void *p, void *q)
{
    u32 n;
    u32 id = 20;
    u32 m;
    union Slot t;
    if (func_021D62C4(q, id)) {
        t = func_021D6314(q, id);
        n = func_021E8AFC(t);
        m = func_021D631C(q, id) + 1;
        if (m == n) return 1;
    }
    return 0;
}
