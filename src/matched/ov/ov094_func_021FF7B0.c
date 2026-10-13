/*
 * function: func_021FF7B0
 * address:  0x021FF7B0
 * packet:   pkt_ov094_021FF7B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_021FF374  0x021FF374  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022018A8  0x022018A8  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
 */
typedef struct {
    int x, y, z;
} Vec3;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x44];
    int key;                /* 0x48 */
    unsigned int pad4c : 6; /* 0x4c */
    unsigned int f6 : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(char *p, int key);
extern int func_021FFD9C(char *p, int key);
extern void func_022018A8(Work *w, Vec3 *out, int key);
extern void func_021FF4C0(Work *w, int key, int a, Vec3 *v, int b, int c, int d);
extern int func_021F86B4(void);
extern void BTLV_GAUGE_HideSlot(char *p, int i);
extern void func_021FF374(Work *w, int key, int kind);

void func_021FF7B0(Work *w, int a, int b)
{
    int keys[2];
    int idx[2];
    Vec3 v;
    int i;

    keys[0] = a;
    keys[1] = b;
    for (i = 0; i < 2; i++) {
        idx[i] = func_022019F4((char *)w, keys[i]);
        if (func_021FFD9C((char *)w, keys[i])) {
            func_022018A8(w, &v, keys[i ^ 1]);
            func_021FF4C0(w, keys[i], 0, &v, 0, 0, 0);
            BTLV_GAUGE_HideSlot((char *)func_021F86B4(), keys[i]);
            if (w->e[idx[i]].f6) {
                w->e[idx[i]].f6 = 0;
                func_021FF374(w, keys[i], 0);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (idx[i] != -1)
            w->e[idx[i]].key = keys[i ^ 1];
    }
}
