/*
 * function: func_021FF088
 * address:  0x021FF088
 * packet:   pkt_ov094_021FF088
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020159C8  0x020159C8  thumb
 *   func_022006A0  0x022006A0  thumb  ov094
 *   func_022006B4  0x022006B4  thumb  ov094
 *   func_022018A8  0x022018A8  thumb  ov094
 */
typedef unsigned int u32;
typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;
typedef struct {
    int pad00;
    void *obj;
    Entry e[14];
} Work;
typedef struct { u32 x, y, z; } Vec;

struct Obj;
struct Rec;
struct Sub150;
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_022006A0(void *p, void *out, int key);
extern void func_022006B4(Work *w, int key);
extern void func_022018A8(void *obj, void *out, int idx);

void func_021FF088(Work *w, void *src, int key)
{
    int i;
    char buf[0x24];
    Vec v;

    for (i = 0; i < 14; i++) {
        if (w->e[i].h == 0)
            break;
    }
    if (key < 14 && i < 14) {
        w->e[i].flip = 1;
        w->e[i].k48 = key;
        func_022006A0(src, buf, key);
        func_022018A8(w, &v, key);
        w->e[i].h = func_020159C8(w->obj, v.x, v.y, v.z, (const struct Sub150 *)buf);
        func_022006B4(w, key);
    }
}
