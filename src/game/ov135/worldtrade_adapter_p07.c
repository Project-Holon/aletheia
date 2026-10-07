/*
 * file:     worldtrade_adapter_p07.c
 * unit:     yes
 * function: func_021FC8CC, func_021FCA8C, func_021FCB54, func_021FCBF0
 * address:  0x021FC8CC
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
 *   func_020457B0  0x020457B0  arm
 *   func_02017E88  0x02017E88  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02202670  0x02202670  thumb
 *   func_02020F84  0x02020F84  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021FC8A8  0x021FC8A8  thumb
 *   func_02045808  0x02045808  arm
 *   tbl_02202EB0   0x02202EB0  data
 *   func_02045924  0x02045924  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0202D6F4  0x0202D6F4  thumb
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F8290 0x021F8290 thumb ov135
 */
#include "../../matched/include/Obj04529.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Strbuf;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

typedef struct {
    u8 pad0[0x14];
    void *data;
} PalFile;

typedef signed int     s32;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern void func_02020F84(void *dst, u32 entry, u32 heap);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern u16 func_021FC8A8(int mode);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void *func_020185F0(void);
extern u32 func_0202D6F4(void *a0, void *mon, u32 a2, u32 a3);
extern void func_020862F0(void *p, u32 n);
extern void func_0207E780(void *src, u32 dst, u32 n);
extern u32 func_020307B0(void *p);
extern int func_0202D060(void);
extern u32 func_02017EAC(void *mon);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_021F886C(int key, int val, int which);
extern void func_021F8290(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
void func_021FC8CC(void *bank, void *names, void *words, void **win, void *mon, Rec *rec, void *g);
void func_021FCA8C(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g);
void func_021FCB54(void *mon);
void func_021FCBF0(char *p);
extern const u32 tbl_02202EB0[];


void func_021FC8CC(void *bank, void *names, void *words, void **win, void *mon, Rec *rec, void *g)
{
    u32 lv;
    void *sname;
    void *smode;
    void *s70;
    void *s71;
    void *s4f;
    void *s41;
    void *nick;
    void *ot;
    int mode;
    int name;
    u32 flag;
    int key;
    int i;

    nick = func_020457B0(0x1a, 0x48);
    ot = func_020457B0(0x26, 0x48);
    func_02017E88(mon, 0x73, (u32)nick);
    name = rec->name;
    mode = rec->mode;
    key = rec->key;
    lv = func_02017E88(mon, 6, 0);
    flag = func_02017E88(mon, 0xAD, 0);
    s4f = func_02045EC0(bank, 0x4F);
    smode = func_02045EC0(bank, tbl_02202EB0[mode]);
    s70 = func_02045EC0(bank, 0x70);
    func_0201EFA4(words, 3, key, 3, 0, 1);
    s71 = (void *)func_02202670((u32)words, (u32)bank, 0x71, 0x48);
    sname = func_02045EC0(names, name);
    func_02020F84(ot, (u16)lv, 0x48);
    s41 = func_02045EC0(bank, 0x41);
    for (i = 0; i < 6; i++) {
        func_02043B5C(func_02045770(win[i]), 0);
    }
    func_021F91A0(win[0], nick, 0, 0, 0, 0x440, g);
    if (mode != 3 && flag != 0) {
        func_021F91A0(win[0], smode, 0x40, 0, 0, func_021FC8A8(mode), g);
    }
    func_021F91A0(win[1], sname, 1, 0, 0, 0x440, g);
    func_021F91A0(win[2], s70, 0, 0, 0, 0x440, g);
    func_021F91A0(win[3], s71, 0, 0, 0, 0x440, g);
    func_021F91A0(win[4], s4f, 0, 0, 0, 0x3C40, g);
    func_021F91A0(win[5], ot, 1, 0, 0, 0x440, g);
    func_021F91A0(win[6], s41, 0, 0, 0, 0x3C40, g);
    func_02045808(s4f);
    func_02045808(ot);
    func_02045808(s70);
    func_02045808(s71);
    func_02045808(smode);
    func_02045808(nick);
    func_02045808(sname);
    func_02045808(s41);
}


void func_021FCA8C(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g)
{
    void *s0;
    void *s1;
    void *t0;
    void *t1;

    s0 = func_020457B0(0x22, 0x48);
    s1 = func_020457B0(0x22, 0x48);
    t0 = func_02045EC0(bank, 0x37);
    func_02045924(s0, name);
    t1 = func_02045EC0(bank, 0xC2);
    func_02017E1C(mon, 0x8D, (u32)s1);
    func_021F91A0(pane->win0, t0, 0, 0, 0, 0x3C40, g);
    func_021F91A0(pane->win1, s0, 0, 0, 0, 0x440, g);
    func_021F91A0(pane2->win0, t1, 0, 0, 0, 0x3C40, g);
    func_021F91A0(pane2->win1, s1, 1, 0, 0, 0x440, g);
    func_02045808(t0);
    func_02045808(s0);
    func_02045808(t1);
    func_02045808(s1);
}


void func_021FCB54(void *mon)
{
    PalFile *pal;
    void *h;
    u32 arc;
    u32 species;
    u32 form;
    u32 shiny;
    u32 id;

    h = (void *)func_0202D6F4(&pal, func_020185F0(), 0, 0x48);
    func_020862F0(pal->data, 0x1200);
    func_0207E780(pal->data, 0x3F80, 0x1200);
    func_020307B0(h);
    arc = func_0202D060();
    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    shiny = func_02017E1C(mon, 0x6E, 0);
    id = func_0202D0D4(arc, species, form, shiny, func_02017EAC(mon), 0, 0);
    func_02049B40(func_0202D060(), id, 1, 0x1A0, 0x20, 0x48);
}

void func_021FCBF0(char *p)
{
    int n;
    n = func_021F886C(p[0x1d7], p[0x1d8], 0);
    func_021F8290(((struct Obj04529 *)p)->fB6C, ((struct Obj04529 *)p)->fB70, (int)(((struct Obj04529 *)p)->fB68), (u8 *)(p + 0xdb4), ((struct Obj04529 *)p)->f1D4, p[0x1d6], n, p + 0xfa0);
}
