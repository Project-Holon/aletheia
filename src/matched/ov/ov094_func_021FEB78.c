/*
 * function: func_021FEB78
 * address:  0x021FEB78
 * packet:   pkt_ov094_021FEB78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_021FF0F8  0x021FF0F8  thumb  ov094
 *   func_02014BA8  0x02014BA8  thumb
 *   func_020307B0  0x020307B0  arm
 */
typedef enum { KEY_0 } Key;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_021FFD9C(Work *w, int key);
extern void func_021FF0F8(Work *w, int key);
typedef unsigned char  u8;
extern void func_02014BA8(u8 *a0);
extern void func_020307B0(void *p);

void func_021FEB78(Work *w)
{
    Key i;

    for (i = 0; i < 14; i++) {
        if (func_021FFD9C(w, i))
            func_021FF0F8(w, i);
    }
    func_02014BA8(w->obj);
    func_020307B0(w);
}
