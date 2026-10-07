/*
 * file:     wifibattlematch_view_p17.c
 * unit:     yes
 * function: func_021E777C, func_021E78B0, func_021E7AE0, func_021E7B44, func_021E7B68
 * address:  0x021E777C
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E8CEE 0x021E8CEE data a1
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 */
#include "../../matched/include/Obj06582.h"
#include "../../matched/include/Obj14375.h"
#include "../../matched/include/Obj03873.h"

struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PmsDraw;
struct Strbuf;
struct U16Vec;
struct WordSet;
struct Sub0200852CObj;
struct Obj0202DC98;
struct PrintSys;
typedef struct { short x, y; } Pos;

typedef struct {
    char pad0[0x64];
    void *main;
    void *obj[5];
    char pad7c[0x88 - 0x7c];
    unsigned count;
    unsigned short base;
    unsigned short objBase[5];
} Work_021E777C;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { unsigned char bg, x, y, w; } WinTemplate;

typedef struct { void *win; unsigned char shown; } Entry;

typedef struct {
    int active;
    void *win[8];
    Entry ent[7];
    char pad5c[0x7c - 0x5c];
    void *list;
    char pad80[0x98 - 0x80];
    int mode;
} Work_021E78B0;

typedef struct { char pad0[0x28]; unsigned score; char pad2c[0x34 - 0x2c]; unsigned count; char name[1]; } Record;

typedef unsigned char  u8;

typedef struct { void *pad0; void *res[8]; } Work_021E7B44;

typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;

typedef signed int     s32;

extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern int func_0209C2B0(int, int);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_020061E4(unsigned se);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_020457B0(unsigned capacity, u16 heap);
extern void func_02045808(struct U16Vec *vec);
extern const void *func_020084F4(const void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
extern void func_0202DC48(void *, void *, const void *, unsigned);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0202DBC4(u8 *p);
extern u32 func_0202DC98(struct Obj0202DC98 *o);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0204B294(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned func_0204AC18(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_0204A6C8(void *, unsigned, unsigned, unsigned, unsigned);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
int func_021E777C(Work_021E777C *p);
void func_021E78B0(Work_021E78B0 *p, const Record *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap);
int func_021E7AE0(unsigned char *p, void *mgr);
void func_021E7B44(Work_021E7B44 *p);
void func_021E7B68(char *p, unsigned idx, unsigned owner, unsigned heap);
extern const WinTemplate d_021E8CEE[];
extern const unsigned char d_021E8CBE[];

int func_021E777C(Work_021E777C *p)
{
    int done;
    int shift;
    Pos pos[2];
    int i;
    done = 0;
    if (p->count == 0) {
        if (p->main != 0) {
            func_0204B454(p->main, (struct PtS *)&pos[1], done);
            p->base = pos[1].x;
        }
        for (i = 0; i < 5; i++) {
            if (p->obj[i] != 0) {
                func_0204B454(p->obj[i], (struct PtS *)&pos[1], 0);
                p->objBase[i] = pos[1].x;
            }
        }
        func_020061E4(0x63B);
    }
    shift = func_0209C2B0(p->count << 8, 20) - 0x100;
    if (p->main != 0) {
        func_0204B454(p->main, (struct PtS *)&pos[0], 0);
        pos[0].x = p->base - func_0209C2B0(p->count << 8, 20);
        func_0204B404(p->main, (const struct Vec2 *)(&pos[0]), 0);
    }
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            func_0204B454(p->obj[i], (struct PtS *)&pos[0], 0);
            pos[0].x = p->objBase[i] - func_0209C2B0(p->count << 8, 20);
            func_0204B404(p->obj[i], (const struct Vec2 *)(&pos[0]), 0);
        }
    }
    if (p->count++ >= 20) {
        shift = 0;
        p->count = 0;
        done = 1;
    }
    func_02041EE4(2, 0, shift);
    func_02041EE4(1, 0, shift);
    return done;
}

void func_021E78B0(Work_021E78B0 *p, const Record *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap)
{
    void *str;
    void *buf;
    int j;
    u16 color;
    int draw;
    void *win;
    int i;
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)func_020450F0(1, d_021E8CEE[i].bg, d_021E8CEE[i].x, d_021E8CEE[i].y, d_021E8CEE[i].w, 15, 1);
        func_02043B5C(func_02045770(p->win[i]), 0);
        win = p->win[i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
        if (i != 7) {
            p->ent[i].win = p->win[i];
            p->ent[i].shown = 0;
        }
    }
    buf = func_020457B0(0x80, heap);
    str = func_020457B0(0x80, heap);
    for (j = 0; j < 8; j++) {
        color = alt == 1 ? 0x3C40 : 0x440;
        draw = 1;
        switch (j) {
        case 0:
            func_02045924(str, func_020084F4(data));
            color = 0x3C40;
            break;
        case 1:
            if (p->mode == 3) {
                func_02045CAC(msg, 12, str);
                color = 0x3C40;
            } else if (p->active != 0) {
                func_02045CAC(msg, 8, str);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 2:
            if (p->mode == 3) {
                func_02045CAC(msg, 13, buf);
                func_0201EFA4(fmt, 0, data->score, 5, 1, 1);
                func_0201F250(fmt, str, buf);
                color = 0x3C40;
            } else if (p->active != 0) {
                func_02045CAC(msg, 9, buf);
                func_0201EFA4(fmt, 0, data->count, 4, 1, 1);
                func_0201F250(fmt, str, buf);
                color = 0x3C40;
            } else {
                draw = 0;
            }
            break;
        case 3:
            func_02045CAC(msg, 20, str);
            color = 0x3C40;
            break;
        case 4:
            func_02045CAC(msg, 22, buf);
            func_0201F048(fmt, 0, func_0200856C((const struct Sub0200852CObj *)data));
            func_0201F250(fmt, str, buf);
            break;
        case 5:
            func_02045CAC(msg, 23, buf);
            func_0201F094(fmt, 0, func_0200856C((const struct Sub0200852CObj *)data), func_02008570((const struct Sub0200852CObj *)data));
            func_0201F250(fmt, str, buf);
            break;
        case 6:
            func_02045CAC(msg, 21, str);
            color = 0x3C40;
            break;
        case 7:
            func_0202DE64(p->list, color);
            func_0202DC48(p->list, p->win[j], data->name, 0);
            draw = 0;
            break;
        }
        if (draw) {
            func_0201C724(print, (u32)func_02045770(p->ent[j].win), 0, 0, (u32)str, font, color);
            p->ent[j].shown = 1;
        }
    }
    func_02045808(buf);
    func_02045808(str);
}

static inline int poll_entry(unsigned char *e, void *mgr)
{
    if (e[0x28] != 0) {
        if (func_0201C6C4(mgr, func_02045770(((struct Obj06582 *)e)->f24)) == 0) {
            func_02045334(((struct Obj06582 *)e)->f24);
            e[0x28] = 0;
        }
    }
    return e[0x28] == 0;
}

/*
 * lever: repeat result accumulation in each branch; hoisting through done changes cross-jump and allocation.
 */
int func_021E7AE0(unsigned char *p, void *mgr)
{
    int i;
    unsigned result = 1;
    for (i = 0; i < 8; i++) {
        unsigned done;
        if (i != 7) {
            result &= poll_entry(p + i * 8, mgr);
        } else {
            func_0202DBC4(((struct Obj14375 *)p)->f7C);
            result &= func_0202DC98(((struct Obj14375 *)p)->f7C);
        }
    }
    return result;
}

void func_021E7B44(Work_021E7B44 *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->res[i] != 0) {
            func_020456F8(p->res[i]);
            func_020452E8(p->res[i]);
        }
    }
}

void func_021E7B68(char *p, unsigned idx, unsigned owner, unsigned heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    ((struct Obj03873 *)p)->f80 = func_0204AC18(handle, 0, 0, 0x140, d_021E8CBE[idx], 1, heap);
    ((struct Obj03873 *)p)->f82 = func_0204A6C8(handle, idx + 0x31, 0, 0, heap);
    ((struct Obj03873 *)p)->f84 = func_0204AF28(handle, 0x41, 0x42, heap);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.x = 0x120;
    req.y = 0x2c;
    ((struct Obj03873 *)p)->f64 = func_0204B294(owner, ((struct Obj03873 *)p)->f82, ((struct Obj03873 *)p)->f80, ((struct Obj03873 *)p)->f84, &req, 0, heap);
    func_0204B6F4(((struct Obj03873 *)p)->f64, 0, 1);
}
