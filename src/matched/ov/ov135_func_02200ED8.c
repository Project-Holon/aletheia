/*
 * function: func_02200ED8
 * address:  0x02200ED8
 * packet:   pkt_02200ED8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   func_021F90A0  0x021F90A0  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_021F4FA4  0x021F4FA4  thumb
 *   str_02203F58  0x02203F58  data  a1
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x14];
    u32 x14;
    u8 pad18[0x20 - 0x18];
    int mode;
    u8 pad24[0x28 - 0x24];
    u32 state;
    u8 pad2C[0xB6C - 0x2C];
    void *msg;
    u8 padB70[0xE10 - 0xB70];
    u32 next;
    u8 padE14[0xEB4 - 0xE14];
    u32 xEB4;
    u8 padEB8[0x1328 - 0xEB8];
    u32 x1328;
} Work;

extern void func_021F90A0(Work *p, void *msg, u32 c, u32 d, u16 e);
extern void func_021F4E98(Work *p, u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F4FA4(Work *p);
extern const char str_02203F58[];

int func_02200ED8(Work *p)
{
    switch (p->mode) {
    case 7:
        func_021F90A0(p, p->msg, 0x18, 1, 0xF0F);
        func_021F4E98(p, 0x29, 2);
        p->x1328 = 0;
        p->next = 6;
        break;
    case 8:
        func_021F90A0(p, p->msg, 0x18, 1, 0xF0F);
        func_021F4E98(p, 0x29, 0xB);
        break;
    case 9:
        func_021F90A0(p, p->msg, 0x18, 1, 0xF0F);
        func_021F4E98(p, 0x29, 2);
        p->x1328 = 0;
        p->next = 0x10;
        break;
    case 10:
        func_021F90A0(p, p->msg, 0x18, 1, 0xF0F);
        func_021F4E98(p, 0x29, 0x16);
        p->xEB4 = 1;
        break;
    case 11:
        func_021F90A0(p, p->msg, 0x18, 1, 0xF0F);
        func_021F4E98(p, 0x29, 0x1C);
        break;
    case 12:
        func_021F90A0(p, p->msg, 0x9A, 1, 0xF0F);
        p->state = 0x21;
        p->x14 = 1;
        func_0203D34C(1, 0x48);
        break;
    default:
        func_02034714(str_02203F58, 0, str_02203F58);
        break;
    }
    func_021F4FA4(p);
    return 2;
}
