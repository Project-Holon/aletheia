/*
 * function: func_02200608
 * address:  0x02200608
 * packet:   pkt_ov094_02200608
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FF348  0x021FF348  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 10;   /* 0x4c */
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(char *p, int key);
extern int func_021FFD9C(char *p, int key);
extern int func_021FF348(Work *w, int key);

void func_02200608(Work *w)
{
    Slot i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            w->e[j].f10 = func_021FF348(w, i);
        }
    }
}
