/*
 * function: func_021AB7E4
 * address:  0x021AB7E4
 * packet:   pkt_ov021_021AB7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE000  0x021DE000  data  a4
 *   d_021D8EEC  0x021D8EEC  data  a4
 */

typedef struct {
    int pad[2];
    int f8[2];
} S;

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern int func_020490F4(int a, int b);
extern char d_021DE000[];
extern const int d_021D8EEC[];

S *func_021AB7E4(int heap)
{
    S *p = func_02030734(heap, 0x10, 1, d_021DE000, 0x81);
    int i;
    for (i = 0; i < 2; i++) {
        p->f8[i] = func_020490F4(d_021D8EEC[i], heap);
    }
    return p;
}
