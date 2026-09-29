/*
 * function: func_021BCA50
 * address:  0x021BCA50
 * packet:   pkt_ov093_021BCA50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 a, b, c, d; } E;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

extern u8 func_021D5440(u32 m);

E *func_021BCA50(S *p, E *cur, u32 x)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (&p->e[i] == cur) {
            i++;
            break;
        }
    }
    for (; i < p->n; i++) {
        if (x == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}
