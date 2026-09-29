/*
 * function: func_02200654
 * address:  0x02200654
 * packet:   pkt_ov094_02200654
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FF374  0x021FF374  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 5;    /* 0x4c */
    unsigned int f5 : 1;
    unsigned int mid : 4;
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(Work *w, int key);
extern int func_021FFD9C(Work *w, int key);
extern void func_021FF374(Work *w, int key, int kind);

void func_02200654(Work *w)
{
    Slot i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(w, i)) {
            j = func_022019F4(w, i);
            func_021FF374(w, i, w->e[j].f10);
            w->e[j].f5 = 0;
        }
    }
}
