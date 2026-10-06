/*
 * function: func_021BBF78
 * address:  0x021BBF78
 * packet:   pkt_ov021_021BBF78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE320     0x021DE320  data  a4
 *   func_021BBFB0  0x021BBFB0  thumb  ov021
 */

typedef struct {
    int f0;
} Obj;

extern int d_021DE320;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_021BBFB0(void);

Obj *func_021BBF78(int a, int b)
{
    Obj *q = func_02030734(b, 4, 1, (const char *)&d_021DE320, 0x78);

    q->f0 = a;
    func_021BBFB0();
    return q;
}
