/*
 * file:     unit_0689B9F4.c
 * function: func_0689B9F4
 * address: 0x0689B9F4
 * packet: pkt_ov095_0689B9F4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: inline Slot-to-Word reinterpretation preserves the extra aggregate home word; passing the aggregate directly differed only at the four frame bytes.
 * symbols:
 *   func_0689BABC 0x0689BABC thumb ov095
 *   func_0689BACC 0x0689BACC thumb ov095
 *   func_0689BADC 0x0689BADC thumb ov095
 *   func_0689BAEC 0x0689BAEC thumb ov095
 *   func_0689BAFC 0x0689BAFC thumb ov095
 *   func_0689BB0C 0x0689BB0C thumb ov095
 *   func_0689BB1C 0x0689BB1C thumb ov095
 *   func_0689BB2C 0x0689BB2C thumb ov095
 *   func_0689BB3C 0x0689BB3C thumb ov095
 *   func_0689BB4C 0x0689BB4C thumb ov095
 *   func_0689BB5C 0x0689BB5C thumb ov095
 *   func_0689BB6C 0x0689BB6C thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union {
    struct { u32 kind:3, pad:6, id:16, rest:7; } a;
    struct { u32 kind:3, pad:12, id:16, rest:1; } b;
} Word;
typedef struct { u32 kind:3, rest:29; } Slot;
typedef struct { u32 flags; u16 hp; u8 c, bits; u16 msg; u8 id, slot; u8 data[1]; } Rec;
extern Slot func_0689BABC(void *, int);
extern u16 func_0689BACC(Word);
extern int func_0689BADC(void *, u8);
extern int func_0689BAEC(void *, u32);
extern int func_0689BAFC(void *, int);
extern Rec *func_0689BB0C(void *, int, int);
extern void func_0689BB1C(void *, int, int);
extern void func_0689BB2C(void *, u32);
extern int func_0689BB3C(void *, int);
extern void func_0689BB4C(void *, void *);
extern Rec *func_0689BB5C(void *, int, int);
extern void func_0689BB6C(void *, void *);
static inline u16 decode(Slot s)
{
    return func_0689BACC(*(Word *)&s);
}
void func_0689B9F4(void *a, void *b, int c)
{
    u8 id;
    int x;
    u16 hp, max;
    Rec *r;
    int msg;
    id = (u8)decode(func_0689BABC(b, 0x12));
    x = func_0689BADC(a, id);
    if (x == 0x1f) return;
    hp = func_0689BAEC(b, 8);
    max = func_0689BAFC(b, 0xd);
    if (hp > max) hp = max;
    r = func_0689BB0C(a, 7, c);
    r->c = c;
    r->hp = hp;
    msg = 0x262;
    func_0689BB1C(r->data, 2, msg);
    func_0689BB2C(r->data, c);
    r->bits |= 2;
    msg += 0x13;
    r->msg = msg;
    r->id = id;
    r->slot = func_0689BB3C(a, c);
    func_0689BB4C(a, r);
    if (x != 0x1f) {
        r = func_0689BB5C(a, 6, c);
        r->flags |= 0x1000000;
        r->c = x;
        r->bits = c;
        r->hp = hp;
        func_0689BB6C(a, r);
    }
}
