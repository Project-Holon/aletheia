/*
 * function: func_021FF9E0
 * address: 0x021FF9E0
 * packet: pkt_ov135_021FF9E0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_02030EE8 0x02030EE8 arm
 *   func_021FFA3C 0x021FFA3C thumb ov135
 *   func_021FF914 0x021FF914 thumb ov135
 *   str_02203E44 0x02203E44 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int state; int y; u8 *p; } Anim;
extern const char str_02203E44[];
extern void *func_02030734(u32, u32, u32, const char *, u32);
extern void *func_02030DA8(void *, void (*)(void *, Anim *), void *, int);
extern Anim *func_02030EE8(void *);
extern void func_021FFA3C(void *, Anim *);
extern void func_021FF914(Anim *, int);
extern void func_020061E4(int);
void func_021FF9E0(u8 *p)
{
    Anim *a;
    *(void **)(p + 0xF98) = func_02030734(0x48, 12, 0, str_02203E44, 0x150);
    *(void **)(p + 0xE14) = func_02030DA8(*(void **)(p + 0xF94), func_021FFA3C, *(void **)(p + 0xF98), 5);
    a = func_02030EE8(*(void **)(p + 0xE14));
    a->state = 0;
    a->y = 0x8A;
    a->p = p;
    func_021FF914(a, 5);
    func_020061E4(0x55D);
}
