/*
 * function: func_021DBB00
 * address: 0x021DBB00
 * packet: pkt_ov175_021DBB00
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F028 0x0203F028 arm
 *   d_021E2F70 0x021E2F70 data a4
 */
#include "../include/Obj14343.h"
extern int func_0203F028(const char *, const char *);
extern const char d_021E2F70[];
void func_021DBB00(int count, char **rows, int *out, int width)
{
    int i, j;
    char *record;
    for (i = 0; i < count; i++) {
        for (j = 0; j < width; j++) {
            record = rows[i] + j * 16;
            if (func_0203F028(*(char * *)&((struct Obj14343 *)record)->f0, d_021E2F70) == 0)
                *out = ((struct Obj14343 *)record)->f8;
        }
    }
}
