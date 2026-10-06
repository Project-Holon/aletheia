/*
 * function: func_0217DCA8
 * address:  0x0217DCA8
 * packet:   pkt_ov019_0217DCA8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02034714  0x02034714  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217FDC8  0x0217FDC8  thumb  ov019
 *   func_0217FDF8  0x0217FDF8  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02174B40  0x02174B40  thumb  ov012
 *   func_02174BB8  0x02174BB8  thumb  ov012
 *   func_02174C34  0x02174C34  thumb  ov012
 *   func_0217357C  0x0217357C  thumb  ov012
 *   func_02175094  0x02175094  thumb  ov012
 *   d_021807E4     0x021807E4  data  a4
 */
#include "../include/Obj19418.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x20];
    u8 f20[6];
    u8 f26;
    u8 pad27[0x2c - 0x27];
} Ent;

typedef struct {
    u8 pad00[0x18];
    Ent ents[4];
    u8 padc8[0x134 - 0xc8];
    u32 f134[4];
} Work;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Big;
struct Ctx;
struct L0200ED54;
struct Link;
struct Sub0200852CObj;
extern u32 func_0203D1A4(struct Link *p);
extern int func_0203D1B4(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Link;
extern void func_02039C68(struct Link *a, u32 b, u32 c);
extern u32 func_02039CB4(struct Link *a, u32 b, u32 c);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern int func_0217BB20(char *p);
extern void func_0217F074(void *ctx);
extern int func_0217FDC8(u8 *p);
extern int func_0217FDF8(u8 *p);
extern int func_0217B8E4(char *p, char v);
extern void func_02174B40(u32 p);
extern u32 func_02174BB8(u32 a, u32 b);
extern int func_02174C34(u32 v);
extern void func_0217357C(u8 *p, void *a, int b, int c);
extern void func_02175094(Work *w, int v);
extern u8 d_021807E4[];

int func_0217DCA8(void *ctx, u8 *obj, int a2, u8 *state)
{
    Work *w = *(Work * *)&((struct Obj19418 *)ctx)->f355C;
    int me;
    int n;
    int i;
    int a;
    int x;

    me = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (w == 0)
        func_02034714((const char *)d_021807E4, (int)0, (const char *)d_021807E4);

    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    switch (*state) {
    case 0:
        func_02039C68((struct Link *)func_020399A8(), 0xd, 0x14);
        (*state)++;
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xd, 0x14) == 1)
            (*state)++;
        break;
    case 2:
        func_02174B40((u32)ctx);
        func_02039C68((struct Link *)func_020399A8(), 0xe, 0x14);
        (*state)++;
        break;
    case 3:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xe, 0x14) == 1)
            (*state)++;
        break;
    case 4:
        if (func_02174BB8((u32)(&w->ents[me]), 0) == 1)
            (*state)++;
        break;
    case 5:
        if (func_0217FDC8((u8 *)w) == 1) {
            n = func_0203D1B4();
            for (i = 0; i < n; i++) {
                if (w->ents[i].f26 == 1) {
                    a = func_02008554((const struct Sub0200852CObj *)(&w->ents[i]));
                    func_0217357C(obj + 0x14, w->ents[i].f20, a,
                                  (u8)(int)func_02008550((const struct Sub0200852CObj *)(&w->ents[i])));
                }
            }
            (*state)++;
        }
        break;
    case 6:
        func_02039C68((struct Link *)func_020399A8(), 0xf, 0x14);
        (*state)++;
        break;
    case 7:
        if (func_02039CB4((struct Link *)func_020399A8(), 0xf, 0x14) == 1)
            (*state)++;
        break;
    case 8:
        if (func_02174C34(w->f134[me]) == 1)
            (*state)++;
        break;
    case 9:
        if (func_0217FDF8((u8 *)w) == 1)
            (*state)++;
        break;
    case 10:
        x = (int)func_0200ED48(func_02012EBC(func_020120F4((const struct Ctx *)((*(int **)ctx)[3]))));
        n = func_0203D1B4();
        for (i = 0; i < n; i++) {
            if (w->ents[i].f26 == 1 && i != func_0203D1A4((struct Link *)((int)func_020399A8())))
                func_0200ED54((struct L0200ED54 *)x, (int)func_02008530((const struct Sub0200852CObj *)(&w->ents[i])));
        }
        func_02175094(w, 1);
        func_0217B8E4(ctx, 0x2a);
        return 1;
    }
    return 0;
}
