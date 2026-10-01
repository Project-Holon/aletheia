/*
 * function: func_02201B44
 * address: 0x02201B44
 * packet: pkt_ov135_02201B44
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 local joins species branches; byte flags use explicit masked RMW.
 * symbols:
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_021F72C4 0x021F72C4 thumb ov135
 *   func_02009EC8 0x02009EC8 thumb
 *   func_02009DE8 0x02009DE8 thumb
 *   func_020307B0 0x020307B0 arm
 *   memset 0x02082BCC arm
 *   func_02008494 0x02008494 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202EB7C 0x0202EB7C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 raw[0x20];
    u16 old_species;
    u16 new_species;
    u8 x;
    u8 y;
    u8 flags;
    u8 tail;
} Record;
extern void func_02008DF0(void *, u32);
extern void *func_0200ED48(void *);
extern void func_0200ED54(void *, u32);
extern void *func_021F72C4(void *);
extern void *func_02009EC8(void *);
extern void func_02009DE8(void *, void *);
extern void func_020307B0(void *);
extern void *memset(void *, int, u32);
extern void func_02008494(void *, Record *);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_0202EB7C(void *, Record *);
void func_02201B44(u8 *p, void *mon, u8 *r, void *old)
{
    void *copy;
    Record rec;
    u16 species;
    func_02008DF0(*(void **)(*(u8 **)p + 0x24), 0x10);
    func_0200ED54(func_0200ED48(*(void **)(*(u8 **)p + 0x3c)), *(u32 *)(r + 0x10c));
    copy = func_021F72C4(r);
    func_02009DE8(func_02009EC8(*(void **)(*(u8 **)p + 0x3c)), copy);
    func_020307B0(copy);
    copy = func_021F72C4(r);
    memset(&rec, 0, sizeof(rec));
    func_02008494(copy, &rec);
    if (old != 0) species = func_02017E1C(old, 5, 0);
    else species = *(u16 *)(r + 0xec);
    rec.old_species = species;
    rec.new_species = func_02017E1C(mon, 5, 0);
    rec.x = *(u8 *)(r + 0x126);
    rec.flags = (rec.flags & ~7) | (*(u8 *)(r + 0xf7) & 7);
    rec.y = *(u8 *)(r + 0x127);
    func_0202EB7C(*(void **)(*(u8 **)p + 0x18), &rec);
    func_020307B0(copy);
}
