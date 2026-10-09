/*
 * file:     worldtrade_box_p06.c
 * unit:     yes
 * function: func_021F8358, func_021F8498, func_021F84BC, func_021F84EC, func_021F8554, func_021F8668, func_021F86A8, func_021F875C, func_021F87E0
 * address:  0x021F8358
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   tbl_02202EB0  0x02202EB0  data  a4
 *   func_02202670  0x02202670  thumb
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F7F80  0x021F7F80  thumb
 *   func_0204A298  0x0204A298  arm
 *   func_02034714  0x02034714  arm
 *   tbl_0220307C   0x0220307C  data
 *   func_02030734  0x02030734  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_020307B0  0x020307B0  arm
 *   g_02203C00     0x02203C00  data  ov135
 *   func_021F6B34  0x021F6B34  thumb
 *   func_022026A0  0x022026A0  thumb
 *   tbl_02203B84 0x02203B84 data a2
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   d_02202ED8 0x02202ED8 data a4
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 */
#include "../../matched/include/Obj06510.h"
#include "../../matched/include/Obj06511.h"
#include "../../matched/include/Obj06512.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct Blk37;
struct Slot;
struct Obj;
struct Src;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

typedef struct {
    u8 pad0[0x18];
    void *status;
    void *prof;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0xC4 - 4];
    u16 box;
    u16 slot;
    u8 padC8[0xCC - 0xC8];
    void *mon;
} Work_021F8358;

typedef struct { u8 pad[0xEF0]; u16 a[10]; u16 b[10]; } Work_021F86A8;

typedef struct { u32 w[4]; u16 count, rows; u32 rest[8]; } Menu;

typedef struct { u32 id; int coords; } Entry;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02018438(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021F91A0(void *win, void *str, u32 c, u32 d, u32 e, u16 f, void *g);
extern u16 func_021F7F80(int mode);
extern void func_02045808(struct U16Vec *vec);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern int func_021F6B34(int v);
extern u32 func_02017988(void *p, u32 a);
extern u32 func_020173EC(void);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern int func_020179B8(int a0, int a1);
extern void func_022026A0(u8 *p, u32 k);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern u8 func_02009584(const struct Sub02009470Obj *obj);
extern u8 func_0200960C(const struct Sub02009470Obj *obj);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_0201F73C(void *win, int a, int b, int c);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
void func_021F8358(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g);
u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
void func_021F84BC(u32 i, int *start, int *end);
u8 *func_021F84EC(u32 id);
void func_021F8554(u8 *dst, Work_021F8358 *p);
void func_021F8668(u8 *dst, u8 *p);
int func_021F86A8(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag);
void *func_021F875C(Work_021F86A8 *p, void **menu, void *win, void *endmsg, void *msg, u8 *cfg, void *bag);
int func_021F87E0(void **menu, void *msg, int kind);
extern const u32 tbl_02202EB0[];
extern const int tbl_0220307C[];
extern u8 g_02203C00[];
extern const u16 tbl_02203B84[];
extern const Menu d_02202ED8;
extern const Entry tbl_0220301C[], tbl_02202FC4[];







void func_021F8358(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g)
{
    int i;
    int form;
    void *title;
    void *place;
    void *name;
    void *tmp;
    u32 has;
    u32 gender;

    name = func_020457B0(0xB, 0x48);
    tmp = func_020457B0(0xB, 0x48);
    func_02017E88(mon, 0x73, (u32)name);
    form = func_02017E88(mon, 0x6E, 0) + 1;
    gender = func_02018438(mon);
    has = func_02017E88(mon, 0xAD, 0);
    title = func_02045EC0(bank, 0x6E);
    func_0201EFA4(ws, 3, gender, 3, 0, 1);
    place = (void *)func_02202670((u32)ws, (u32)bank, 0x72, 0x48);
    if (form != 3) {
        func_02045CAC(bank, tbl_02202EB0[form], tmp);
    }
    for (i = 0; i < 3; i++) {
        func_02043B5C(func_02045770(win[i]), 0);
    }
    func_021F91A0(win[0], title, 1, 0, 0, 0x3C40, g);
    func_021F91A0(win[1], name, 0, 0, 0, 0x3C40, g);
    func_021F91A0(win[2], place, 0, 0, 2, 0x3C40, g);
    if (form != 3 && has != 0) {
        func_021F91A0(win[1], tmp, 0x46, 0, 0, func_021F7F80(form - 1), g);
    }
    out->species = func_02017E88(mon, 5, 0);
    out->form = form;
    out->gender = gender;
    func_02045808(place);
    func_02045808(tmp);
    func_02045808(name);
    func_02045808(title);
}








u16 *func_021F8498(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = (u16 *)func_0204A298(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}








void func_021F84BC(u32 i, int *start, int *end)
{
    if (i >= 0x1B) {
        func_02034714((void *)0x02203C18, 0, (void *)0x02203C18);
    }
    *start = tbl_0220307C[i];
    *end = tbl_0220307C[i + 1];
}






u8 *func_021F84EC(u32 id)
{
    u32 size;
    u32 i;
    u8 *buf;
    u16 *tbl;
    u32 n;

    buf = func_02030734(0x48, 0x28A, 0, (const char *)g_02203C00, 0x796);
    func_02082AC0(0, buf, 0x28A);
    tbl = (u16 *)func_0204A298(0x62, 4, 0, (u16)id, &size);
    n = size / 2;
    for (i = 0; i < n; i++) {
        if (tbl[i] < 0x28A) {
            buf[tbl[i]] = 1;
        }
    }
    func_020307B0(tbl);
    return buf;
}





void func_021F8554(u8 *dst, Work_021F8358 *p)
{
    u32 species;

    if (func_021F6B34(p->box) != 0) {
        species = func_02017E88(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            func_02017988(p->mon, 0);
        }
        func_02082B0C(p->mon, dst, func_020173EC());
    } else {
        species = func_02017E88(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            func_020179B8((int)p->mon, 0);
        }
        func_022026A0(p->mon, (u32)dst);
    }
    func_0201F41C(func_020084F4(p->ctx->prof), (u16 *)(dst + 0x110), 8);
    *(u32 *)(dst + 0x10C) = func_02008530(p->ctx->prof);
    dst[0x120] = func_0200856C(p->ctx->prof);
    dst[0x121] = func_02008570(p->ctx->prof);
    dst[0x122] = func_02008554(p->ctx->prof);
    dst[0xF6] = func_02008550(p->ctx->prof);
    dst[0x124] = 0x15;
    dst[0x125] = 2;
    dst[0x126] = func_02009628(p->ctx->status);
    dst[0x127] = func_02009584(p->ctx->status);
    dst[0xF7] = func_0200960C(p->ctx->status);
}



void func_021F8668(u8 *dst, u8 *p)
{
    func_021F8554(dst, (Work_021F8358 *)p);
    ((struct Obj06510 *)dst)->fEC = ((struct Obj06511 *)p)->fB4C;
    ((struct Obj06510 *)dst)->fEE = ((struct Obj06511 *)p)->fB4E;
    ((struct Obj06510 *)dst)->fF0 = ((struct Obj06511 *)p)->fB50;
    ((struct Obj06510 *)dst)->fF2 = ((struct Obj06511 *)p)->fB52;
    ((struct Obj06510 *)dst)->fF4 = ((struct Obj06511 *)p)->fB54;
}



int func_021F86A8(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag)
{
    int i;
    int size;
    int count;
    int start;
    count = 0;
    start = tbl_02203B84[kind];
    size = tbl_02203B84[kind + 1] - start;
    for (i = 0; i < size; i++) {
        if (func_0200D064(bag, list[start + i]) != 0) count++;
    }
    *menu = func_0201F81C(count + 1, 0x48);
    for (i = 0; i < size; i++) {
        if (func_0200D064(bag, list[start + i]) != 0) {
            func_0201F878(*menu, (u32)msg, list[start + i], list[start + i], 0x48);
        }
    }
    func_0201F878(*menu, (u32)endmsg, 0x85, -2, 0x48);
    return count + 1;
}



/*
 * lever: u16 arrays at 0xEF0 and 0xF04 preserve base/index load scheduling; raw offset casts differ by 8 bytes.
 */
void *func_021F875C(Work_021F86A8 *p, void **menu, void *win, void *endmsg, void *msg, u8 *cfg, void *bag)
{
    int kind;
    int count;
    Menu src;
    func_02043B5C(func_02045770(win), 15);
    kind = ((struct Obj06512 *)cfg)->f6 + ((struct Obj06512 *)cfg)->f4;
    count = func_021F86A8(menu, msg, endmsg, *(u16 * *)&((struct Obj06512 *)cfg)->f18, ((struct Obj06512 *)cfg)->f14, ((struct Obj06512 *)cfg)->f1C, kind, bag);
    src = d_02202ED8;
    src.count = count;
    src.w[0] = (u32)*menu;
    src.w[3] = (u32)win;
    func_0201F73C(win, 0, 31, 11);
    return func_0201FF30((struct Src *)(&src), p->a[kind], p->b[kind], 0x48);
}

int func_021F87E0(void **menu, void *msg, int kind)
{
    const Entry *table;
    int i;
    int count;
    if (kind == 0) { table = tbl_0220301C; count = 12; }
    else { table = tbl_02202FC4; count = 11; }
    *menu = func_0201F81C(count, 0x48);
    for (i = 0; i < count; i++) {
        func_0201F878(*menu, (u32)msg, table[i].id, i, 0x48);
    }
    return count;
}
