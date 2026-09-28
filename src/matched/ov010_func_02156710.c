/*
 * function: func_02156710
 * address:  0x02156710
 * packet:   pkt_ov010_02156710
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029690  0x02029690  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Seq {
    void *f00;          /* 0x00 */
    u8 pad04[0x10 - 0x04];
    u8 state;           /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    u8 pad18[0x4C - 0x18];
    u8 f4C;             /* 0x4C */
} Seq;

extern void *func_020120F4(void *p);
extern u32 func_02012A30(void *p);
extern void *func_0201210C(void *p);
extern void *func_02012374(void *evt, void *sub);
extern void *func_02029690(void *a, u16 b, u16 c);
extern void *func_020145CC(void *a);
extern void *func_02029CC0(void *a);

int func_02156710(void *evt, Seq *s)
{
    func_02012A30(func_020120F4(s->f00));
    switch (s->state) {
    case 0:
        func_02012374(evt, func_02029690(s->f00, 0, 0x3C));
        s->state++;
        break;
    case 1:
        func_02012374(evt, func_020145CC(s->f00));
        s->state++;
        break;
    case 2:
        s->state++;
        break;
    case 3:
        func_02012374(evt, func_02029CC0(s->f00));
        s->state++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
