/*
 * function: func_021FE520
 * address:  0x021FE520
 * packet:   pkt_ov094_021FE520
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
 *   func_021FF470  0x021FF470  thumb  ov094
 */
typedef enum { KEY_0 } Key;

extern void *func_021F8694(void);
extern int func_021FFD9C(char *p, int key);
typedef unsigned char u8;

extern void func_021FF470(char *p, int key, void *v);

void func_021FE520(void)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(func_021F8694(), i) == 1)
            func_021FF470(func_021F8694(), i, 0);
    }
}
