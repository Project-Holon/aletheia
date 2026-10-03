/*
 * function: func_021E6F20
 * address: 0x021E6F20
 * packet: pkt_ov177_021E6F20
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200B214 0x0200B214 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y; u16 id; u8 a, flag; } Request;
typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    void *chr[6];        /* 0x1c4 */
    char pad1dc[4];
    void *cell;          /* 0x1e0 */
    void *pal;           /* 0x1e4 */
    char pad1e8[0x1f4 - 0x1e8];
    void *pal2;          /* 0x1f4 */
    void *chr2;          /* 0x1f8 */
    void *cell2;         /* 0x1fc */
    char pad200[0x232 - 0x200];
    u8 palSlot;          /* 0x232 */
    u8 pad233;
    u32 layer;           /* 0x234 */
} Work;
extern void *func_020490F4(u32 id, u16 heap);
struct Obj;
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void *func_0204ACEC(void *, u32, u32, u16, u16);
extern void *func_0204AF28(void *, u32, u32, u32);
extern u32 func_0200B214(void *, int, u8);
extern u32 func_0201BABC(u16, u32, u32, u32);
extern void *func_0204A6C8(void *, u32, u32, u32, u16);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern void *func_0204AC18(void *, u32, u32, u16, u32, u32, u16);
extern void func_02082BCC(void *, u32, u32);
extern void *func_0204B294(void *, void *, void *, void *, const Request *, u16, u32);
extern u32 func_0201BB5C(u32, u32, u32, u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021E6F20(Work *w, void *owner, void *rec, u16 heap)
{
    u8 form;
    u8 shown;
    void *h;
    u16 species;
    u8 gender;
    int i;
    Request req, sub;
    h = func_020490F4(7, heap);
    w->pal = func_0204ACEC(h, func_0201BC3C(), w->layer, w->palSlot << 5, (heap & 0x7fff) | 0x8000);
    w->cell = func_0204AF28(h, func_0201BC40(), func_0201BCB4(), heap);
    for (i = 0; i < 6; i++) {
        species = func_0200B214(rec, 0, i);
        form = func_0200B214(rec, 1, i);
        gender = func_0200B214(rec, 3, i);
        w->chr[i] = func_0204A6C8(h, func_0201BABC(species != 0 ? species : 1, form, gender, 0), 0, w->layer, (heap & 0x7fff) | 0x8000);
    }
    func_02049238(h);
    h = func_020490F4(func_020275E4(), heap);
    w->pal2 = func_0204AC18(h, func_02027694(), w->layer, (w->palSlot + 3) << 5, 0, 1, (heap & 0x7fff) | 0x8000);
    w->chr2 = func_0204A6C8(h, func_02027698(), 0, w->layer, (heap & 0x7fff) | 0x8000);
    w->cell2 = func_0204AF28(h, func_0202769C(2), func_020276A0(2), heap);
    func_02049238(h);
    func_02082BCC(&req, 0, 8);
    req.y = 0xa8;
    req.id = 1;
    req.flag = 1;
    req.a = 1;
    for (i = 0; i < 6; i++) {
        species = func_0200B214(rec, 0, i);
        form = func_0200B214(rec, 1, i);
        gender = func_0200B214(rec, 3, i);
        shown = func_0200B214(rec, 2, i);
        if (species != 0) {
            req.x = (i << 5) + 0x120;
            w->objs[i] = func_0204B294(owner, w->chr[i], w->pal, w->cell, &req, w->layer, heap);
            func_0204B6F4(w->objs[i], func_0201BB5C(species, form, gender, 0), 0);
            if (shown != 0) {
                sub = req;
                sub.x += 12;
                sub.y += 8;
                sub.a = 0;
                sub.id = 0;
                w->objs[i + 15] = func_0204B294(owner, w->chr2, w->pal2, w->cell2, &sub, w->layer, heap);
            } else {
                w->objs[i + 15] = 0;
            }
        } else {
            w->objs[i] = 0;
            w->objs[i + 15] = 0;
        }
    }
}
