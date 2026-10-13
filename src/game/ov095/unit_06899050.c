/*
 * file:     unit_06899050.c
 * unit:     yes
 * function: func_06899050, func_0689905C
 * address:  0x06899050
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D758 0x0689D758 data a4
 */
typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int);
extern int func_021B9A40(int);
extern int BTL_EVENT_OverwriteVar(int, int);
unsigned int *func_06899050(unsigned int *out);
void func_0689905C(int a0, int a1, int value, int *out);
extern unsigned int d_0689D758;

/*
 * follower: store-return leaf after non-C veneer 0x06899040.
 */
unsigned int *func_06899050(unsigned int *out)
{
    *out = 2;
    return &d_0689D758;
}

void func_0689905C(int a0, int a1, int value, int *out)
{
    u8 v;
    v = BTL_EVENT_GetVar(2);
    if (value == func_021B9A40(v)) {
        if (BTL_EVENT_GetVar(0x20) < 0) {
            if (v != BTL_EVENT_GetVar(3)) {
                *out = BTL_EVENT_OverwriteVar(0x41, 1);
            }
        }
    }
}
