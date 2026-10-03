/*
 * function: func_021BCB14
 * address:  0x021BCB14
 * packet:   pkt_ov093_021BCB14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BCAAC  0x021BCAAC  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021BCB68  0x021BCB68  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 *a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

extern E *func_021BCAAC(S *p, u8 x, u32 i);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021D5B68(void *m);
extern int func_021BCB68(S *p, E *cur);

E *func_021BCB14(S *p, u8 x, u32 y)
{
    E *e = func_021BCAAC(p, x, 0);
    while (e) {
        if (func_021B9A24(y, func_021D5440(e->a)) && func_021D5B68(e->a) == 0)
            return e;
        e = func_021BCAAC(p, x, (u8)(func_021BCB68(p, e) + 1));
    }
    return 0;
}
