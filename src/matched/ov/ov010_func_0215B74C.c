/*
 * function: func_0215B74C
 * address:  0x0215B74C
 * packet:   pkt_ov010_0215B74C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern unsigned int func_02159B10(void *, void *);
struct Stream;
extern u16 func_02011330(struct Stream *s);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_02017E40(void *p, u32 id, u32 v);
int func_0215B74C(int a0, int a1)
{
    int a = func_02159B10((void *)a0, (void *)a1);
    int b = func_02159B10((void *)a0, (void *)a1);
    int mode = func_02011330((struct Stream *)a0);
    int obj = 0;
    u8 v;
    if (func_0215B4AC((void *)a1, a, (void **)(&obj)) == 0) {
        return 0;
    }
    if (func_02017E1C((void *)obj, 0x4C, 0) == 1) {
        return 0;
    }
    v = func_02017E1C((void *)obj, 9, 0);
    switch (mode) {
    case 0:
        if ((u32)b > 0xFF) {
            v = 0xFF;
        } else {
            v = b;
        }
        break;
    case 1:
        if (v + b > 0xFF) {
            v = 0xFF;
        } else {
            v = v + (u8)b;
        }
        break;
    case 2:
        if (v < b) {
            v = 0;
        } else {
            v = v - (u8)b;
        }
        break;
    }
    func_02017E40((void *)obj, 9, v);
    return 0;
}
