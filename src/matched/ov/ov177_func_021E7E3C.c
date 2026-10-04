/*
 * function: func_021E7E3C
 * address: 0x021E7E3C
 * packet: pkt_ov177_021E7E3C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021E8DBC 0x021E8DBC data a1
 *
 * The temporary heap id is formed twice: once through an inline that
 * rewrites its own parameter (the image copies heap before the and), held
 * in r7 for the first block; then as a plain expression, which the
 * compiler CSEs into a temporary slot below the loop pointers. One shared
 * expression or one shared local CSEs both blocks together.
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x, y; } Pos;
typedef struct { short x, y; u16 id; u8 a, flag; } Request;
typedef struct { void *win; u8 shown; } Entry;
typedef struct {
    void *pal;
    void *chr[7];
    void *cell;
    void *chrB;
    void *palB;
    void *cellB;
    void *spr[14];
    void *win[6];
    Entry ent[6];
    unsigned count;
    short base[14];
} Work;
static inline unsigned HeapTemp(unsigned heap)
{
    heap &= 0x7FFF;
    heap |= 0x8000;
    return heap;
}
extern const char d_021E8DBC[];
extern void *func_02030734(unsigned heap, unsigned size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0200BAF4(void *, u16);
extern void func_0204989C(int, int, int, int, int, int, u16);
extern void *func_020490F4(unsigned int id, unsigned heap);
extern unsigned func_0201BC3C(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern unsigned func_0201BC40(void);
extern unsigned func_0201BCB4(void);
extern void *func_0204AF28(void *, unsigned, unsigned, u16);
extern unsigned func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern void *func_020185F4(void *);
extern unsigned func_0201BA68(void *);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *);
extern unsigned func_020275E4(void);
extern unsigned func_02027694(void);
extern unsigned func_0202769C(int);
extern unsigned func_020276A0(int);
extern unsigned func_02027698(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void *func_0204B294(void *, void *, void *, void *, const Request *, unsigned short, unsigned);
extern unsigned func_0201BBE8(void *);
extern void func_0204B6F4(void *, unsigned, unsigned);
extern void *func_0201EC64(u16);
extern void *func_020457B0(unsigned capacity, u16 heap);
extern void *func_02045EC0(void *msg, unsigned idx);
extern void *func_020450F0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
struct Descriptor;
extern void func_02045334(struct Descriptor *);
extern void func_02045374(void *);
extern unsigned char func_02045730(void *win);
extern void func_020409B4(int v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *win);
extern void func_0201C724(unsigned print, void *bmp, short x, short y, void *str, unsigned font, u16 color);
extern void func_0201EFA4(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_0201F250(void *, void *, void *);
extern unsigned func_0201D304(void *, unsigned, unsigned);
extern void func_02045808(void *);
extern void func_0201ED04(void *);
struct Actor; struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern void func_0204B404(void *, Pos *, int);
extern void func_02040618(int, int, int);
extern void func_020307B0(void *);
extern void func_0207D63C(int, int, int, int, int);
Work *func_021E7E3C(void *src, void *owner, int unused, unsigned font, unsigned print, void *msg, unsigned heap)
{
    Work *work;
    void *party;
    void *handle;
    void *mon;
    u8 x;
    void *fmt;
    void *buf;
    void *sLevel;
    void *sMale;
    void *sFemale;
    void *win;
    u8 level;
    int i;
    unsigned h;
    Request req;
    Request req2;
    Pos pos;
    work = func_02030734(heap, sizeof(Work), 0, d_021E8DBC, 0xC8A);
    func_02082BCC(work, 0, sizeof(Work));
    h = HeapTemp(heap);
    party = func_0200BAF4(src, h);
    func_0204989C(0x85, 7, 2, 0, 0, 0, h);
    handle = func_020490F4(7, heap);
    work->pal = (void *)func_0204ACEC(handle, func_0201BC3C(), 0, 0xA0, h);
    work->cell = func_0204AF28(handle, func_0201BC40(), func_0201BCB4(), h);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            work->chr[i] = (void *)func_0204A6C8(handle, func_0201BA68(func_020185F4(mon)), 0, 0, h);
        }
    }
    func_02049238(handle);
    handle = func_020490F4(func_020275E4(), heap);
    work->chrB = (void *)func_0204AC18(handle, func_02027694(), 0, 0x100, 0, 1, (heap & 0x7FFF) | 0x8000);
    work->cellB = func_0204AF28(handle, func_0202769C(2), func_020276A0(2), (heap & 0x7FFF) | 0x8000);
    work->palB = (void *)func_0204A6C8(handle, func_02027698(), 0, 0, (heap & 0x7FFF) | 0x8000);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.x = 0x18;
    req.y = 0x2C;
    req.id = 1;
    req.a = 1;
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            req.x = i * 0x28 + 0x18;
            work->spr[i] = func_0204B294(owner, work->chr[i], work->pal, work->cell, &req, 0, heap);
            func_0204B6F4(work->spr[i], func_0201BBE8(func_020185F4(mon)), 0);
            if (func_02017E1C(mon, 6, 0) != 0) {
                req2 = req;
                req2.x += 12;
                req2.y += 8;
                req2.a = 0;
                req2.id = 0;
                work->spr[i + 7] = func_0204B294(owner, work->palB, work->chrB, work->cellB, &req2, 0, heap);
            }
        }
    }
    fmt = func_0201EC64((heap & 0x7FFF) | 0x8000);
    buf = func_020457B0(0x80, (heap & 0x7FFF) | 0x8000);
    sLevel = func_02045EC0(msg, 0x63);
    sMale = func_02045EC0(msg, 0x64);
    sFemale = func_02045EC0(msg, 0x65);
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            work->win[i] = func_020450F0(1, i * 5 + 1, 4, 5, 6, 15, 1);
            win = work->win[i];
            func_02045334(win);
            func_02045374(win);
            func_020409B4(func_02045730(win));
            work->ent[i].win = work->win[i];
            work->ent[i].shown = 0;
            if (func_02017E1C(mon, 0x6E, 0) == 0) {
                func_0201C724(print, func_02045770(work->ent[i].win), 0x20, 0, sMale, font, 0x14C0);
                work->ent[i].shown = 1;
            } else if (func_02017E1C(mon, 0x6E, 0) == 1) {
                func_0201C724(print, func_02045770(work->ent[i].win), 0x20, 0, sFemale, font, 0xC80);
                work->ent[i].shown = 1;
            }
            level = func_02017E1C(mon, 0x9E, 0);
            func_0201EFA4(fmt, 0, level, 3, 1, 1);
            func_0201F250(fmt, buf, sLevel);
            x = 20 - func_0201D304(buf, font, 0) / 2;
            func_0201C724(print, func_02045770(work->ent[i].win), x, 0x24, buf, font, 0x440);
            work->ent[i].shown = 1;
        }
    }
    func_02045808(sFemale);
    func_02045808(sMale);
    func_02045808(sLevel);
    func_02045808(buf);
    func_0201ED04(fmt);
    for (i = 0; i < 14; i++) {
        if (work->spr[i] != 0) {
            func_0204B454(work->spr[i], (struct PtS *)&pos, 0);
            pos.x += 0x100;
            func_0204B404(work->spr[i], &pos, 0);
        }
    }
    func_02040618(2, 0, -0x100);
    func_02040618(1, 0, -0x100);
    func_020307B0(party);
    func_0207D63C(0x04000050, 4, 8, 15, 3);
    return work;
}
