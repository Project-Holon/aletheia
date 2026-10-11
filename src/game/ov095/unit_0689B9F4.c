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
 *   func_021C7D44  0x021C7D44  thumb
 *   func_021C8010  0x021C8010  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   func_021D6314  0x021D6314  thumb
 *   func_021D7B74  0x021D7B74  thumb
 *   func_021E8B80  0x021E8B80  thumb
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
extern Slot func_021D6314(void *, int);
extern u16 func_021E8B80(Word);
extern int func_021C7D44(void *, u8);
extern int func_021D7B74(void *, u32);
extern int func_021D59B4(void *, int);
extern Rec *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern int func_021C8010(void *, int);
extern void func_021C88C8(void *, void *);
static inline u16 decode(Slot s)
{
    return func_021E8B80(*(Word *)&s);
}
void func_0689B9F4(void *a, void *b, int c)
{
    u8 id;
    int x;
    u16 hp, max;
    Rec *r;
    int msg;
    id = (u8)decode(func_021D6314(b, 0x12));
    x = func_021C7D44(a, id);
    if (x == 0x1f) return;
    hp = func_021D7B74(b, 8);
    max = func_021D59B4(b, 0xd);
    if (hp > max) hp = max;
    r = func_021C88A4(a, 7, c);
    r->c = c;
    r->hp = hp;
    msg = 0x262;
    func_021C8838(r->data, 2, msg);
    func_021C8860(r->data, c);
    r->bits |= 2;
    msg += 0x13;
    r->msg = msg;
    r->id = id;
    r->slot = func_021C8010(a, c);
    func_021C88C8(a, r);
    if (x != 0x1f) {
        r = func_021C88A4(a, 6, c);
        r->flags |= 0x1000000;
        r->c = x;
        r->bits = c;
        r->hp = hp;
        func_021C88C8(a, r);
    }
}
