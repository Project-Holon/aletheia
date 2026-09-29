/*
 * function: func_02161BF8
 * address:  0x02161BF8
 * packet:   pkt_ov010_02161BF8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012144  0x02012144  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_021BFB3C     0x021BFB3C  data  ov203
 *   ov203_id       0x000000CB  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x18];       /* 0x08 */
    u32 f20;            /* 0x20 */
} Obj;

extern u8 d_021BFB3C[];
extern u8 ov203_id[];

extern u32 func_02012144(void *p);
extern void func_0201213C(void *p, u32 v);
extern int func_02026454(void *p);
extern void func_02026400(void *p);
extern void func_020120B4(void *p, void *a, void *b, void *c);
extern int func_020120F0(void *p);

int func_02161BF8(void *a0, int *state, Obj *o)
{
    switch (*state) {
    case 0:
        o->f20 = func_02012144(o->f00);
        func_0201213C(o->f00, 1);
        if (func_02026454(o->f04) == 0) {
            *state = *state + 2;
        } else {
            func_02026400(o->f04);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_02026454(o->f04) == 0)
            *state = *state + 1;
        break;
    case 2:
        func_020120B4(o->f00, ov203_id, d_021BFB3C, o->f08);
        *state = *state + 1;
        break;
    case 3:
        if (func_020120F0(o->f00) == 0) {
            func_0201213C(o->f00, o->f20);
            return 1;
        }
        break;
    }
    return 0;
}
