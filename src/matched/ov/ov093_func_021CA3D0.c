/*
 * function: func_021CA3D0
 * address:  0x021CA3D0
 * packet:   pkt_ov093_021CA3D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021BD43C  0x021BD43C  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021BD4E4  0x021BD4E4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021B8DDC(u8 v);
extern int func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern char *func_021B9AEC(char *p, int i);
extern int func_021B9C98(char *p, u8 *a);
extern void func_021BD43C(u8 *p, int i, u8 a, u8 b, int c);
extern int func_021C99A0(u8 *p, u8 *q);
extern void func_021BD4E4(u8 *p, int i, u8 a, u8 b);

int func_021CA3D0(u8 *p, u8 *q)
{
    int a, b, m1, m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = func_021B8DDC(q[4]);
        b = func_021B8DDC(q[5]);
        if (a == b) {
            m1 = func_021B9934(*(char **)(p + 8), q[4]);
            m2 = func_021B9934(*(char **)(p + 8), q[5]);
            if (!func_021D5B68((void *)m1) && !func_021D5B68((void *)m2)) {
                o = func_021B9AEC(*(char **)(p + 8), a);
                i = func_021B9C98(o, (u8 *)m1);
                j = func_021B9C98(o, (u8 *)m2);
                if (i >= 0 && j >= 0) {
                    func_021BD43C(p, a, i, j, 0);
                    func_021C99A0(p, q + 8);
                    func_021BD4E4(p, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}
