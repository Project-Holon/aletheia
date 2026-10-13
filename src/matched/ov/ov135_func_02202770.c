/*
 * function: func_02202770
 * address:  0x02202770
 * packet:   pkt_02202770
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   TCBL_Main  0x020310C4  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    void *win;
    u8 busy;
    void *active;
} Ent;

typedef struct {
    u8 pad0[4];
    void *heap;
    u8 pad8[0xC - 8];
    void *queue;
    void *yesno;
    void *yesnoArg;
    Ent ent[24];
    void *bg;
} Printer;

struct Ctx;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct Tcbl;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_020061E4(u32 se);
extern void func_0201CE38(void *menu);
extern void func_0201CE48(struct Rec3 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);

void func_02202770(Printer *p)
{
    int i;
    Ent *e;
    void *queue;

    for (i = 0; i < 24; i++) {
        e = &p->ent[i];
        if (e->active != 0) {
            queue = p->queue;
            if (e->busy != 0 && func_0201C6C4(queue, func_02045770(e->win)) == 0) {
                BMP_WIN_TransferChars(e->win);
                e->busy = 0;
            }
            if (e->busy == 0) {
                e->active = 0;
            }
        }
    }
    if (p->yesno != 0) {
        APP_KEYCURSOR_Update(p->bg, p->yesno, p->yesnoArg);
        switch (func_0201CE30(p->yesno)) {
        case 0:
            if ((func_020362DC() & 3) || TOUCHPANEL_GetTrg() != 0) {
                func_0201CE5C(p->yesno, 0);
            }
            break;
        case 1:
            if ((func_020362DC() & 3) || TOUCHPANEL_GetTrg() != 0) {
                func_020061E4(0x547);
                func_0201CE38(p->yesno);
            }
            break;
        case 2:
            func_0201CE48(p->yesno);
            p->yesno = 0;
            p->yesnoArg = 0;
            break;
        }
    }
    PRINTSYS_QUE_Main(p->queue);
    TCBL_Main(p->heap);
}
