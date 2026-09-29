/*
 * function: func_021E4754
 * address:  0x021E4754
 * packet:   pkt_ov093_021E4754
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7D78  0x021D7D78  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C7CF4(u8 *s, int k);
extern int func_021D62C4(u8 *p, int i);
extern int func_021D5BB0(u8 *q, u32 n);
extern u8 *func_021C88A4(u8 *p, int a, int b);
typedef struct Word { u32 v; } Word;
typedef enum { K_0 } KType;
struct Rec { u32 f0; u32 f4; Word f8; u8 fc; u8 fd; u8 fe; u8 ff; };

extern Word func_021D7D78(int c);
extern void func_021C88C8(u8 *a, u8 *b);

void func_021E4754(int a0, u8 *s, int k)
{
    KType c = 3;
    u8 v;
    u8 *q;
    struct Rec *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4(s, v);
        if (func_021D62C4(q, 0xb) == 0) {
            if (func_021D5BB0(q, 1) != 0)
                c = (u8)(c + 1);
            e = (struct Rec *)func_021C88A4(s, 12, k);
            e->f4 = 0xb;
            e->f8 = func_021D7D78(c);
            e->ff = v;
            func_021C88C8(s, (u8 *)e);
        }
    }
}
