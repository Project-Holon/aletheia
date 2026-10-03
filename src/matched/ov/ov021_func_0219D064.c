/*
 * function: func_0219D064
 * address:  0x0219D064
 * packet:   pkt_ov021_0219D064
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219D3F0  0x0219D3F0  thumb  ov021
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C7B4  0x0219C7B4  thumb  ov021
 *   func_0219C780  0x0219C780  thumb  ov021
 *   func_0216D758  0x0216D758  thumb  ov010
 */

extern unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
extern int func_0219CBD4(int *, unsigned int, unsigned short *, unsigned short *);
extern unsigned short func_0219C7B4(int, unsigned int, unsigned int);
extern unsigned short func_0219C780(int, int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void func_0216D758(int);

void func_0219D064(int *obj, int *rec)
{
    unsigned short x[3];
    unsigned short r;

    x[0] = 0xFFFF;
    *((unsigned char *)rec + 0xd) = 0;
    if (rec[4] != 0) {
        x[2] = func_0219D3F0(obj, *(unsigned short *)(rec + 2), *((unsigned char *)rec + 0xa),
                             *((unsigned char *)rec + 0xb), rec[4], 1);
        rec[4] = 0;
        func_0219CBD4(obj, *(unsigned short *)(rec + 2), &x[0], &x[1]);
    } else {
        func_0219CBD4(obj, *(unsigned short *)(rec + 2), &x[2], &x[1]);
    }
    if (rec[1] != 0) {
        r = func_0219C7B4(rec[1], x[2], x[0]);
    } else {
        r = func_0219C780(obj[4], (int)(rec + 7), *((unsigned char *)rec + 0xa),
                          *((unsigned char *)rec + 0xc), x[2], x[0]);
    }
    *(unsigned short *)rec[0] = r;
    if (rec[5] != 0) {
        ((void (*)(unsigned int, int))rec[5])(*(unsigned short *)rec[0], rec[6]);
    }
    if (rec[1] != 0) {
        func_0216D758(rec[1]);
    }
}
