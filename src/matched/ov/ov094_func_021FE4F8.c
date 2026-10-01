/*
 * function: func_021FE4F8
 * address:  0x021FE4F8
 * packet:   pkt_ov094_021FE4F8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022004BC  0x022004BC  thumb  ov094
 */
typedef enum { KEY_0 } Key;

extern void *func_021F8694(void);
extern int func_021FFD9C(void *w, int key);
extern void func_022004BC(void *w, int key);
void func_021FE4F8(void)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(func_021F8694(), i) == 1)
            func_022004BC(func_021F8694(), i);
    }
}
