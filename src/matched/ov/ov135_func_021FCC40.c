/*
 * function: func_021FCC40
 * address:  0x021FCC40
 * packet:   pkt_021FCC40
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD270  0x021FD270  thumb
 *   func_021FCF28  0x021FCF28  thumb
 *   func_0207D55C  0x0207D55C  arm
 *   func_021FFFE8  0x021FFFE8  thumb
 *   func_021FCFD8  0x021FCFD8  thumb
 *   func_021FD104  0x021FD104  thumb
 *   func_021FD08C  0x021FD08C  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_021FC8CC  0x021FC8CC  thumb
 *   func_021FCA8C  0x021FCA8C  thumb
 *   func_021FCB54  0x021FCB54  thumb
 *   func_021FD760  0x021FD760  thumb
 *   func_021FD790  0x021FD790  thumb
 *   func_021FD5F0  0x021FD5F0  thumb
 *   func_021FFD1C  0x021FFD1C  thumb
 *   func_021FD8BC  0x021FD8BC  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_0202208C  0x0202208C  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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
} Work;

extern void func_021FD270(Work *p);
extern void func_021FCF28(int y);
extern int func_0207D55C(vu16 *reg);
extern void func_021FFFE8(u8 *p, u32 a, u32 b);
extern void func_021FCFD8(u8 *p);
extern void func_021FD104(Work *p);
extern void func_021FD08C(Work *p);
extern void *POKE_TOOL_GetBoxParam(void *mon);
extern void func_021FC8CC(void *bank, void *names, void *words, void **win, void *mon, void *rec, void *g);
extern void func_021FCA8C(void *bank, void *pane, void *name, void *mon, void *pane2, void *g);
extern void func_021FCB54(void *mon);
extern void func_021FD760(void *bank, void *pane, u32 index, void *g, u16 color);
extern void func_021FD790(void *bank, void *pane, u32 index, void *g);
extern void func_021FD5F0(Work *p);
extern void func_021FFD1C(Work *p, int i, int dy);
extern void func_021FD8BC(void *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_021FCC40(Work *p)
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
    func_021FC8CC(p->bank, p->names, p->words, p->win, POKE_TOOL_GetBoxParam(&p->arr[p->cur]), p->arr[p->cur].rec, p->fFA0);
    func_021FCA8C(p->bank, &p->win[7], p->arr[p->cur].name, &p->arr[p->cur], p->pane3, p->fFA0);
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
