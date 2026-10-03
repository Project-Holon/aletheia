/*
 * function: func_0215B558
 * address:  0x0215B558
 * packet:   pkt_ov010_0215B558
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159B10();
extern int func_0215B4AC();
extern u32 func_02017E1C(void *, u32, u32);
int func_0215B558(int a0, int a1)
{
    u16 *p = func_02159AE8((void *)a0, (void *)a1);
    u16 *q = func_02159AE8((void *)a0, (void *)a1);
    int obj;
    if (func_0215B4AC(a1, func_02159B10(a0, a1), &obj) == 1) {
        *p = func_02017E1C((void *)obj, 0xAE, 0);
        *q = func_02017E1C((void *)obj, 0xAF, 0);
    } else {
        *p = 0;
        *q = 0;
    }
    return 0;
}
