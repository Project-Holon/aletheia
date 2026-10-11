/*
 * function: func_06898D54
 * address:  0x06898D54
 * packet:   pkt_ov095_06898D54
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D7040  0x021D7040  thumb
 *   g_0689E7E0     0x0689E7E0  data
 */

#include "../../matched/include/G_Row.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *p;
    u32 type : 3;
    u32 lim : 6;
    u32 rest : 23;
    u32 n;
    u32 en;
} E;

typedef struct {
    E e[14];
} Row;

extern struct Row g_0689E7E0[2];
extern void func_021D7040(void *p);

void func_06898D54(void (*cb)(u8, u32, u32), u32 arg)
{
    u32 j;
    u32 i;

    for (j = 0; j < 2; j++) {
        Row *row;

        i = 0;
        row = &((Row *)g_0689E7E0)[j];

        for (; i < 14; i++) {
            E *e = &row->e[i];

            if (e->en != 0 && e->type == 2) {
                e->n++;
                if (e->n >= e->lim) {
                    e->en = 0;
                    e->type = 0;
                    func_021D7040(e->p);
                    e->p = 0;
                    cb(j, i, arg);
                }
            }
        }
    }
}
