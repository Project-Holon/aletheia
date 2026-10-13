/*
 * function: func_02156770
 * address:  0x02156770
 * packet:   pkt_ov010_02156770
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020295A4  0x020295A4  thumb
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02029C64  0x02029C64  thumb
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

struct BigObj;
struct Ctx;
struct Evt;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u8 *func_020295A4(u8 *p, u32 a);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *func_02029C64(void *a);

int func_02156770(void *evt, Seq *s)
{
    void *x;

    func_02012A30(func_020120F4(s->f00));
    x = func_0201210C(s->f00);
    switch (s->state) {
    case 0:
        s->state++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020295A4(s->f00, 30));
        s->state++;
        break;
    case 2:
        func_02012374(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)s->f00, (int)x));
        s->state++;
        break;
    case 3:
        func_02012374(evt, func_02029C64(s->f00));
        s->state++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
