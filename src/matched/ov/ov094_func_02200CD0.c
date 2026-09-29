/*
 * function: func_02200CD0
 * address:  0x02200CD0
 * packet:   pkt_ov094_02200CD0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021FF260  0x021FF260  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *
 * Task callback.
 */
typedef unsigned char u8;

typedef struct {
    char pad000[0x588];
    u8 tag[1];              /* 0x588 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x3c];
    int wait;               /* 0x44 */
    int reload;             /* 0x48 */
    int count;              /* 0x4c */
    int tag;                /* 0x50 */
} Ctx;

extern void func_021F89BC(void *h);
extern int func_021FFD9C(Work *w, int key);
extern void func_021FF260(Work *w, int key, int kind);

void func_02200CD0(void *h, Ctx *c)
{
    Work *w = c->w;

    if (func_021FFD9C(w, c->key) == 0 || c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    if (c->wait == 0) {
        c->wait = c->reload;
        func_021FF260(c->w, c->key, 2);
        if (--c->count == 0) {
            func_021FF260(c->w, c->key, 0);
            func_021F89BC(h);
        }
    } else {
        c->wait--;
    }
}
