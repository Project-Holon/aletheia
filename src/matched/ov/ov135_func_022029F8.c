/*
 * function: func_022029F8
 * address:  0x022029F8
 * packet:   pkt_022029F8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
} Ent;

typedef struct {
    u8 pad0[4];
    void *queue;
    u8 pad8[0x10 - 8];
    Ent ent[8];
    void *active[8];
} Printer;

struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C4E4(struct PrintSys *ps);

void func_022029F8(Printer *q)
{
    int i;
    void *queue;

    for (i = 0; i < 8; i++) {
        if (q->active[i] != 0) {
            queue = q->queue;
            if (q->ent[i].busy != 0 && func_0201C6C4(queue, func_02045770(q->ent[i].win)) == 0) {
                func_02045334(q->ent[i].win);
                q->ent[i].busy = 0;
            }
            if (q->ent[i].busy == 0) {
                q->active[i] = 0;
            }
        }
    }
    func_0201C4E4(q->queue);
}
