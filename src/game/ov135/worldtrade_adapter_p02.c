/*
 * file:     worldtrade_adapter_p02.c
 * unit:     yes
 * function: func_021FC8CC, func_021FCA8C, func_021FCB54, func_021FCBF0, func_021FCC40, func_021FCE64, func_021FCED4, func_021FCF28, func_021FCFC8
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
 *   func_021FD270  0x021FD270  thumb
 *   func_0207D55C  0x0207D55C  arm
 *   func_021FFFE8  0x021FFFE8  thumb
 *   func_021FCFD8  0x021FCFD8  thumb
 *   func_021FD104  0x021FD104  thumb
 *   func_021FD08C  0x021FD08C  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_021FD760  0x021FD760  thumb
 *   func_021FD790  0x021FD790  thumb
 *   func_021FD5F0  0x021FD5F0  thumb
 *   func_021FFD1C  0x021FFD1C  thumb
 *   func_021FD8BC  0x021FD8BC  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_0202208C  0x0202208C  thumb
 *   tbl_02203D14 0x02203D14 data a4
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   func_021FD0F4 0x021FD0F4 thumb ov135
 *   func_021FD2FC 0x021FD2FC thumb ov135
 *   func_021FD1E0 0x021FD1E0 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   func_020434DC  0x020434DC  arm
 *   g_02203618  0x02203618  data  ov135
 *   g_02203628  0x02203628  data  ov135
 *   g_02203648  0x02203648  data  ov135
 *   sub_020403F4  0x020403F4  arm
 */
#include "../../matched/include/Obj04529.h"
#include "../../matched/include/Obj06515.h"
#include "../../matched/include/Obj03069.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct Obj;
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
} Rec_vC8CC;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

typedef struct {
    u8 pad0[0x14];
    void *data;
} PalFile;

typedef signed int     s32;

typedef volatile unsigned short vu16;

typedef struct {
    u8 pad0[0xEC];
    u8 rec[0x110 - 0xEC];
    u8 name[0x128 - 0x110];
} Entry;

typedef struct {
    u8 pad0[0x20];
    int kind;
    u8 pad24[4];
    u32 f28;
    u8 pad2C[0xD4 - 0x2C];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB68 - 0xB4C];
    void *words;
    void *bank;
    void *names;
    u8 padB74[0xD3C - 0xB74];
    int scroll;
    u8 padD40[0xD50 - 0xD40];
    void *side[2];
    u8 padD58[0xD90 - 0xD58];
    void *win[7];
    void *pane2[2];
    void *title;
    u8 padDB8[0xDC0 - 0xDB8];
    void *pane3[2];
    void *hint;
    u8 padDCC[0xEC0 - 0xDCC];
    void (*vblank)(void *);
    u8 padEC4[0xFA0 - 0xEC4];
    u8 fFA0[4];
    u8 padFA4[0x12E4 - 0xFA4];
    u32 f12E4;
    u8 pad12E8[0x12FC - 0x12E8];
    u32 flag;
} Work_vC8CC;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

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
extern void func_021FD270(Work_vC8CC *p);
extern int func_0207D55C(vu16 *reg);
extern void func_021FFFE8(u8 *p, u32 a, u32 b);
extern void func_021FCFD8(u8 *p);
extern void func_021FD104(Work_vC8CC *p);
extern void func_021FD08C(Work_vC8CC *p);
extern void *func_020185F4(void *mon);
extern void func_021FD760(void *bank, void *pane, u32 index, void *g, u16 color);
extern void func_021FD790(void *bank, void *pane, u32 index, void *g);
extern void func_021FD5F0(Work_vC8CC *p);
extern void func_021FFD1C(Work_vC8CC *p, int i, int dy);
extern void func_021FD8BC(void *p);
extern void func_0203D34C(u32 a, u32 b);
extern int func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021F4EA0(void *, int, int);
extern void func_021F4FF4(unsigned, unsigned, unsigned);
extern void func_021FD0F4(u8 *p);
extern void func_021FD2FC(u8 *p);
extern void func_021FD1E0(u8 *p);
extern void func_022000E4(char *p);
extern void func_021F4EC8(u8 *p);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void sub_020403F4(u32 i);
void func_021FC8CC(void *bank, void *names, void *words, void **win, void *mon, Rec_vC8CC *rec, void *g);
void func_021FCA8C(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g);
void func_021FCB54(void *mon);
void func_021FCBF0(char *p);
int func_021FCC40(Work_vC8CC *p);
int func_021FCE64(char *p);
int func_021FCED4(unsigned char *p);
void func_021FCF28(int y);
void func_021FCFC8(void);
extern const u32 tbl_02202EB0[];
extern struct DispConfig g_02203618;
extern struct BgTemplate g_02203628;
extern struct BgTemplate g_02203648;





void func_021FC8CC(void *bank, void *names, void *words, void **win, void *mon, Rec_vC8CC *rec, void *g)
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




int func_021FCC40(Work_vC8CC *p)
{
    func_021FD270(p);
    func_021FCF28(-32 - p->scroll);
    if (func_0207D55C((vu16 *)0x0400106C) == 0) {
        func_021FFFE8((u8 *)p, -32 - p->scroll, 1);
    } else {
        func_021FFFE8((u8 *)p, -32 - p->scroll, 0);
    }
    func_021FCFD8((u8 *)p);
    func_021FD104(p);
    func_021FD08C(p);
    func_021FC8CC(p->bank, p->names, p->words, p->win, func_020185F4(&p->arr[p->cur]), (Rec_vC8CC *)(p->arr[p->cur].rec), p->fFA0);
    func_021FCA8C(p->bank, (Pane2 *)(&p->win[7]), p->arr[p->cur].name, &p->arr[p->cur], (Pane2 *)p->pane3, p->fFA0);
    func_021FCB54(&p->arr[p->cur]);
    func_021FD760(p->bank, &p->pane3[2], 0x53, p->fFA0, 0x440);
    func_021FD760(p->bank, &p->title, 0x57, p->fFA0, 0x3C40);
    if (p->flag == 0) {
        func_021FD790(p->bank, &p->side[0], 0x5E, p->fFA0);
        func_021FD790(p->bank, &p->side[1], 0x73, p->fFA0);
    }
    func_021FD5F0(p);
    func_021FFD1C(p, p->cur, -p->scroll);
    p->vblank = func_021FD8BC;
    *(vu16 *)0x04000304 |= 0x8000;
    func_0203D34C(1, 0x48);
    if (p->kind == 0x11) {
        if (func_0207D55C((vu16 *)0x0400006C) == -16 && func_0207D55C((vu16 *)0x0400106C) != -16) {
            func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
        } else if (func_0207D55C((vu16 *)0x0400006C) != -16 && func_0207D55C((vu16 *)0x0400106C) == -16) {
            func_0202208C((void *)4, 1, 1, 0, 6, 1, 0x48);
        } else {
            func_0202208C(0, 1, 1, 0, 6, 1, 0x48);
        }
    }
    p->f28 = 0;
    p->f12E4 = 0;
    p->flag = 0;
    return 1;
}


extern int (*const tbl_02203D14[])(void *);


int func_021FCE64(char *p)
{
    int r;
    int i;
    r = tbl_02203D14[*(int *)(p + 0x28)](p);
    for (i = 0; i < 8; i++) {
        func_021F4EA0(*(void **)(p + i * 4 + 0xd0c), *(s16 *)(p + i * 4 + 0xec4), *(s16 *)(p + i * 4 + 0xec6) + ((struct Obj06515 *)p)->fD3C + 0x20);
    }
    func_021F4FF4(((struct Obj06515 *)p)->fD08, 0xd0, 0x3a - ((struct Obj06515 *)p)->fD3C);
    func_021FFD1C((Work_vC8CC *)p, ((struct Obj06515 *)p)->fD4, ((struct Obj06515 *)p)->fD3C);
    return r;
}


int func_021FCED4(unsigned char *p)
{
    ((struct Obj03069 *)p)->fEC0 = 0;
    func_021FD0F4(p);
    func_021FD2FC(p);
    func_021FD1E0(p);
    func_021FCFC8();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)((struct Obj03069 *)p)->fD38, 0);
    func_021F4EC8(p);
    if (*(int *)&((struct Obj03069 *)p)->f12FC == 0)
        func_0203D34C(0, 0x48);
    return 0;
}



/*
 * Three-layer bring-up: the saved display config, layers 2 and 1 enabled
 * (only 2 020414EC'd) and layer 2's 0x20x0x48 tilemap cleared.
 */
void func_021FCF28(int y)
{
    struct DispConfig c = g_02203618;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203628;

        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02203648;

        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_020434DC(8, 0);
}



/*
 * Poke channel 1 then channel 2.
 */
void func_021FCFC8(void)
{
    sub_020403F4(1);
    sub_020403F4(2);
}
