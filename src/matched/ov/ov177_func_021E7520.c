/*
 * function: func_021E7520
 * address: 0x021E7520
 * packet: pkt_ov177_021E7520
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   func_021E78B0 0x021E78B0 thumb ov177
 *   func_021E7B68 0x021E7B68 thumb ov177
 *   func_021E7C3C 0x021E7C3C thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 owner;           /* 0x00 */
    char pad4[0x7c - 4];
    void *menu;          /* 0x7c */
    char pad80[0x98 - 0x80];
    u32 mode;            /* 0x98 */
} Work;
typedef struct {
    char pad0[0x28];
    u32 f28;
    u32 f2c;
    void *f30;
} Record;
extern const char d_021E8DBC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, int, u32);
struct PmsDraw;
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
struct PmsDraw;
extern void func_0202DE68(struct PmsDraw *p, u32 v);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern u32 func_021E7CF0(void *, u32, u32);
extern void func_021E78B0(Work *, const Record *, void *, void *, void *, void *, int, u16);
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_021E7B68(char *p, unsigned idx, unsigned owner, unsigned heap);
extern void func_021E7C3C(char *p, char *q, void *x, void *data, unsigned heap);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_020413B0(u32, u8, u8, u8, u8, u8);
extern u32 func_0204162C(int);
extern void func_020410D0(u32, u32, u32, u32, u8, u32, u8, u8, u8, u8);
extern void func_020409B4(u32);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D63C(void *, int, int, int, int);
Work *func_021E7520(const Record *rec, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, u32 mode, u32 owner, int style, u16 heap)
{
    Work *w;
    u32 kind;
    int alt;
    w = func_02030734(heap, 0x9c, 0, d_021E8DBC, 0x952);
    func_02082BCC(w, 0, 0x9c);
    w->owner = owner;
    w->mode = mode;
    w->menu = func_0202DB0C((u32)a1, 0, (u32)a4, (u32)a3, 5, 1, heap);
    func_0202DE68(w->menu, 1);
    func_0202DE5C(w->menu, 0);
    kind = func_021E7CF0(rec->f30, rec->f28, rec->f2c);
    alt = 0;
    if (mode - 2 <= 1)
        alt = kind == 5;
    func_021E78B0(w, rec, a3, a4, a5, a6, alt, heap);
    func_021E7B68((char *)w, func_02008554((const struct Sub0200852CObj *)rec), (unsigned int)a1, heap);
    func_0204989C(0x85, 9, 2, 0, 0, 0, (heap & 0x7fff) | 0x8000);
    switch (mode) {
    case 2:
    case 3:
        func_021E7C3C((char *)w, (char *)rec, a1, a2, heap);
        func_020413B0(2, 0, 0, 0x20, 2, 1);
        func_020413B0(2, 0, 3, 0x20, 0x20, kind + 3);
        func_020413B0(2, 0, 3, 1, 2, 1);
        func_020413B0(2, 0x1f, 3, 1, 2, 1);
        break;
    case 0:
    case 1:
        func_020410D0(2, 0, 0, 0x20, 2, func_0204162C(2), 0, 0x18, 0x20, 0x20);
        switch (style) {
        case 0:
            func_020413B0(2, 0, 0, 0x20, 2, 1);
            func_020413B0(2, 0, 3, 0x20, 0x20, 3);
            func_020413B0(2, 0, 3, 1, 2, 1);
            func_020413B0(2, 0x1f, 3, 1, 2, 1);
            break;
        case 1:
            func_020413B0(2, 0, 0, 0x20, 2, 1);
            func_020413B0(2, 0, 3, 0x20, 0x20, 7);
            func_020413B0(2, 0, 3, 1, 2, 1);
            func_020413B0(2, 0x1f, 3, 1, 2, 1);
            break;
        }
        break;
    }
    func_020409B4(2);
    func_02040618(2, 0, ~0xff);
    func_02040618(1, 0, ~0xff);
    func_0207D63C((void *)0x04000050, 4, 8, 0xf, 3);
    return w;
}
