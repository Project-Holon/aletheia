/*
 * file:     union_comm_p03.c
 * unit:     yes
 * function: func_02172EDC, func_02172EEC, func_02172FF0, func_0217303C, func_021730C8
 * address:  0x02172EDC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_021739CC  0x021739CC  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02173D88  0x02173D88  thumb  ov012
 *   func_02173DBC  0x02173DBC  thumb  ov012
 *   func_02173840  0x02173840  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_02167590  0x02167590  thumb  ov010
 *   func_0216786C  0x0216786C  thumb  ov010
 *   func_02174C90  0x02174C90  thumb  ov012
 *   func_0217FF78  0x0217FF78  thumb  ov019
 *   func_02175110  0x02175110  thumb  ov012
 *   func_02175144  0x02175144  thumb  ov012
 *   func_0203CF10 0x0203CF10 arm
 *   func_0203CF3C 0x0203CF3C arm
 *   func_021730F8 0x021730F8 thumb ov012
 *   func_02177BF4 0x02177BF4 thumb ov014
 */
struct Report;
struct Work_1;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x5E];
    u8 f5E;
    u8 step : 7;
    u8 active : 1;
} Sub_0;

typedef struct {
    u8 pad[0x2830];
    Sub_0 sub;
} Work_0;

typedef unsigned int   u32;

typedef struct {
    u8 flag : 1;
} Sub_1;

typedef struct {
    int f0;
    u8 pad[0xC4];
    u8 flag : 1;
    u8 pad2[0x16F - 0xC9];
    u8 f16F;
} Q;

typedef struct {
    struct { int pad[3]; int f0c; } *head;
    u8 pad[0x355C - 4];
    Q *q;
} Work_1;

typedef struct Entry { u8 b[0x64]; } Entry;

extern u32 func_0200FB24(void);
extern int func_021739CC(void);
extern int func_02080D24(u8 a);
extern int func_0203D1B4(void);
extern void func_0203D7BC(u8 a0);
extern u32 func_0203D378(void);
extern void func_02172D38(u8 *p);
extern int func_02173D88(u32 a);
extern int func_02173DBC(int a);
extern int func_02173840(u8 *w);
extern int func_02174268(u8 *p);
extern void func_02167590(void *a, struct Work_1 *w);
extern int func_0216786C(struct Work_1 *w, struct Report *out);
extern u32 func_02174C90(u32 a);
extern void func_0217FF78(u32 *p);
extern void func_02175110(u8 *p);
extern void func_02175144(u8 *p);
extern u32 func_0203CF10(u32 a);
extern void *func_0203CF3C(u32 a);
extern int func_021730F8(u8 *self, Entry *info, const u8 *mac);
extern void func_02177BF4(u32 idx);
void func_02172EDC(u8 *p);
void func_02172EEC(Work_0 *w);
void func_02172FF0(u8 *w);
/* * Lever: func_02173840 reads the entry Work_1 pointer still live in r0; * the guard uses r1 only when that input is explicitly forwarded. */ void func_0217303C(Work_1 *w);
/* * interface: caller tests r0 after 0203CF3C; retains index r0 through ov014 thunk to 02177BAC. */ void func_021730C8(u8 *self);


void func_02172EDC(u8 *p) { p[0x288f] |= 0x80; }



void func_02172EEC(Work_0 *w)
{
    Sub_0 *s = &w->sub;

    if (s->active == 0) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    switch (s->step) {
    case 0:
        if (func_021739CC() == 1) {
            s->step++;
        }
        break;
    case 1:
        if (func_02080D24(s->f5E) >= func_0203D1B4()) {
            func_0203D7BC(0);
            s->step++;
        }
        break;
    case 2:
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1) {
                func_02172D38((u8 *)w);
                s->step++;
            }
        } else {
            func_02172D38((u8 *)w);
            s->step++;
        }
        break;
    }
}



void func_02172FF0(u8 *w)
{
    if (func_0203D1B4() > 1) {
        if (w[0x282D] != 0 && func_02173D88(w[0x282D]) == 1) {
            w[0x282D] = 0;
        }
        if (w[0x282C] != 0 && func_02173DBC(w[0x282C]) == 1) {
            w[0x282C] = 0;
        }
    } else {
        w[0x282D] = 0;
        w[0x282C] = 0;
    }
}



/*
 * Lever: func_02173840 reads the entry Work_1 pointer still live in r0;
 * the guard uses r1 only when that input is explicitly forwarded.
 */
/*
 * Lever: func_02173840 reads the entry Work pointer still live in r0;
 * the guard uses r1 only when that input is explicitly forwarded.
 */
void func_0217303C(Work_1 *w)
{
    if (w->q != 0 && ((Sub_1 *)((u8 *)w->q + 0xC8))->flag) {
    if (func_02173840((u8 *)w) == 1) {
        if (func_02174268((u8 *)w) == 0) {
            func_02167590((void *)w->head->f0c, (struct Work_1 *)w->q->f0);
            if (w->q->f16F == 0) {
                if (func_0216786C((struct Work_1 *)w->q->f0, (struct Report *)((u8 *)w->q + 4)) == 1) {
                    w->q->f16F = 1;
                }
            }
            if (w->q->f16F == 1) {
                if (func_02174C90((u32)((u8 *)w->q + 4)) == 1) {
                    w->q->f16F = 0;
                }
            }
        }
        func_0217FF78((u32 *)w->q);
    }
    func_02175110((u8 *)w->q);
    func_02175144((u8 *)w->q);
    }
}


/*
 * interface: caller tests r0 after 0203CF3C; retains index r0 through ov014 thunk to 02177BAC.
 */
void func_021730C8(u8 *self) { int i; Entry *p; const u8 *mac; for (i=0;i<10;i++) { p=(Entry *)func_0203CF10(i); if(p) { mac=(const u8 *)func_0203CF3C(i); if(mac) func_021730F8(self,p,mac); func_02177BF4(i); } } }
