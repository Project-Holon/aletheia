/*
 * function: func_021AE4E0
 * address:  0x021AE4E0
 * packet:   pkt_ov021_021AE4E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 */

typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(void *a0);
typedef unsigned short u16;
extern u16 func_0216D5A0(void *p);

int func_021AE4E0(Task *p)
{
    if (func_0216D454(func_021A3074(p->f34)) == 0)
        return 0;
    p->state = 3;
    switch (func_0216D5A0(p->f08)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        p->state = 7;
        break;
    }
    return 1;
}
