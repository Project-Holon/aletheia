/*
 * function: func_021BCAAC
 * address:  0x021BCAAC
 * packet:   pkt_ov093_021BCAAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021D8340  0x021D8340  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

extern u32 func_021D8454(u32 *m);
extern u32 func_021D8340(u32 *m);

E *func_021BCAAC(S *p, u8 x, u32 i)
{
    for (; i < p->n; i++) {
        if (p->e[i].flag == 0 && func_021D8454(&p->e[i].b) == 1 && x == func_021D8340(&p->e[i].b))
            return &p->e[i];
    }
    return 0;
}
