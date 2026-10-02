/*
 * function: func_0216B81C
 * address:  0x0216B81C
 * packet:   pkt_ov010_0216B81C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216B8B8  0x0216B8B8  thumb  ov010
 *   func_0216B91C  0x0216B91C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0E8(void *sys);
extern int func_02159B10();
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0200C32C();
extern int func_0216B8B8(void *a0, unsigned short *a1);
extern int func_0216B91C(void *a0, int a1, unsigned short *a2);

int func_0216B81C(int c, int vm)
{
    void *r6;
    void *t;
    int r5;
    u16 *r4;

    r6 = func_02012EBC((struct Big *)func_0215A5E4((void *)vm));
    t = func_0200C0E8(r6);
    r5 = (u8)func_02159B10(c, vm);
    r4 = func_02159AE8((void *)c, (void *)vm);
    if (r5 == func_0200C32C(t)) {
        func_0216B8B8(r6, r4);
    } else {
        func_0216B91C(r6, r5, r4);
    }
    return 0;
}
