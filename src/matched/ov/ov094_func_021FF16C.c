/*
 * function: func_021FF16C
 * address:  0x021FF16C
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02015BF0   0x02015BF0  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_022006B4  0x022006B4  thumb  ov094
 */
typedef unsigned int u32;
typedef int fx32;
typedef long long s64;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work;

extern void sub_02015BF0(void *obj);
extern int func_022019F4(char *p, int key);
extern void func_022006B4(Work *w, int i);

void func_021FF16C(Work *w)
{
    int i;
    int idx;

    sub_02015BF0(w->obj);
    w->active = 1;
    for (i = 0; i < 14; i++) {
        idx = func_022019F4((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 1;
            func_022006B4(w, i);
        }
    }
}
