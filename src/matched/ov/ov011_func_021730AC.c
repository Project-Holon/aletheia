/*
 * function: func_021730AC
 * address:  0x021730AC
 * packet:   pkt_ov011_021730AC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_021736EC  0x021736EC  thumb  ov011
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02173580  0x02173580  thumb  ov011
 */

typedef unsigned char  u8;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct Param {
    u32   field00;
    void *field04;
} Param;

typedef struct Work {
    u8  pad000[0x8f8];
    u8  field8f8;       /* 0x8F8 */
    u8  pad8f9[4];
    u8  field8fd;       /* 0x8FD */
    u8  pad8fe[0x10];
    s16 timer;          /* 0x90E */
    u8  pad910[0x2f];
    u8  bit0 : 1;       /* 0x93F */
    u8  bit1 : 1;
} Work;

extern u32 func_02026478(void *obj);
extern u8 func_02012E40(const u8 *o);
extern u32 func_0200FB24(void);
extern void  func_0203CEAC(void (*cb)(Work *));
extern int   func_0203D1B4(void);
extern int   func_021736EC(Work *w);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *p, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *p, u32 a, u32 b);
extern void  func_0203D7BC(int a);
extern u32 func_0203D378(void);
extern void  func_02173580(Work *w);

int func_021730AC(int *state, Param *p, Work *w)
{
    if (func_02012E40((const u8 *)func_02026478(p->field04)) == 1) {
        return 0;
    }
    if (w->bit1 == 1 || func_0200FB24() != 0) {
        w->field8f8 |= 0x40;
        func_0203CEAC(func_02173580);
        return 1;
    }
    switch (*state) {
    case 0:
        w->field8fd = 9;
        if (func_0203D1B4() <= 1) {
            *state = 4;
        } else if (func_021736EC(w) == 1) {
            (*state)++;
        }
        break;
    case 1:
        w->timer = 0;
        func_02039C68((struct Link *)func_020399A8(), 0x14, 2);
        (*state)++;
        break;
    case 2:
        w->timer++;
        if (func_02039CB4((struct Link *)func_020399A8(), 0x14, 2) == 1 || w->timer > 300) {
            func_0203D7BC(0);
            (*state)++;
        }
        break;
    case 3:
        w->timer++;
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1 || w->timer > 300) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        w->field8f8 |= 0x40;
        func_0203CEAC(func_02173580);
        return 1;
    }
    return 0;
}
