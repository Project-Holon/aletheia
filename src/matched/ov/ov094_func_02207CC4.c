/*
 * function: BTLV_GAUGE_SetSideVisible
 * address:  0x02207CC4
 * packet:   pkt_ov094_02207CC4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: an enum-typed loop counter keeps the entry guard (cmp r4,#8; bge)
 * that a plain int counter rotates away.
 *
 * symbols:
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 */

typedef unsigned int u32;

typedef enum { I0 = 0 } Idx;

typedef struct E {
    char p0[0x44];
    int f44;
    char p48[0x28];
    u32 lo : 3;
    u32 b3 : 1;
    u32 hi : 28;
    char p74[12];
} E;

typedef struct O {
    char pad[0x40];
    E e[8];
} O;

extern void BTLV_GAUGE_SetSlotVisible(O *obj, int a, int idx);

void BTLV_GAUGE_SetSideVisible(O *obj, int a, int c)
{
    Idx i;

    for (i = I0; i < 8; i = (Idx)(i + 1)) {
        if (c == 2 || c == obj->e[i].f44) {
            if (obj->e[i].b3) {
                BTLV_GAUGE_SetSlotVisible(obj, a, (int)i);
            }
        }
    }
}
