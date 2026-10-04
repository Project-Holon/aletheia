/*
 * function: func_0216BC88
 * address:  0x0216BC88
 * packet:   pkt_ov010_0216BC88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021F3AA0  0x021F3AA0  thumb  ov059
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void func_021F3AA0();

int func_0216BC88(int c, int vm)
{
    void *p;
    int a1;
    int a2;
    int a3;
    int a4;
    int vec[3];

    p = func_0215A5DC((void *)vm);
    a1 = func_02159B10((void *)c, (void *)vm);
    a2 = func_02159B10((void *)c, (void *)vm);
    a3 = func_02159B10((void *)c, (void *)vm);
    a4 = func_02159B10((void *)c, (void *)vm);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    func_021F3AA0(p, a1, vec);
    return 0;
}
