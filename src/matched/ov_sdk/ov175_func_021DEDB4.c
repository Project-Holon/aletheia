/*
 * function: sakeiGetRandomRecordProcessSoapResponse
 * address:  0x021DEDB4
 * packet:   pkt_021DEDB4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiReadOutputRecords  0x021DE2E0  arm
 *   (none)
 *
 * Slot lookup: the object's +8 table supplies the two keys and a 5th word that
 * goes on the stack; when the probe finds nothing the destination is either
 * the found record's word or zero, and the found pointer is released.
 */

typedef unsigned int u32;

extern int  sakeiReadOutputRecords(void *p, int **pa, int *nb, int c, int d);
extern void func_0217EAE0(int *pa);

int sakeiGetRandomRecordProcessSoapResponse(int **p)
{
    int *t = (int *)p[2];
    int *out = (int *)p[3];
    int *pa;
    int nb;
    int h = sakeiReadOutputRecords(p, &pa, &nb, t[2], t[1]);

    if (h == 0) {
        if (pa != 0 && nb > 0)
            *out = *pa;
        else
            *out = 0;
    }
    func_0217EAE0(pa);
    return h;
}
