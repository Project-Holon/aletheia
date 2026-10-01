/*
 * function: func_021FFD6C
 * address:  0x021FFD6C
 * packet:   pkt_ov094_021FFD6C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_021FFCB0  0x021FFCB0  thumb  ov094
 */
typedef enum { KEY_0 } Key;

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
} Work;

extern int func_021FFD9C(Work *w, int key);
extern int func_021FFCB0(Work *w, int key);

int func_021FFD6C(Work *w)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(w, i) && func_021FFCB0(w, i))
            return 1;
    }
    return 0;
}
