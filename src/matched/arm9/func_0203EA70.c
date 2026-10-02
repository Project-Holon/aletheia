/*
 * function: func_0203EA70
 * address:  0x0203EA70
 * packet:   pkt_0203EA70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F4      0x021469F4  data
 */

typedef unsigned char u8;
typedef struct { u8 pad[0x10]; u8 flag : 1; } Obj;
extern int *g_021469F4;
int func_0203EA70(unsigned int idx)
{
    Obj *p;
    if (g_021469F4 == 0 || (p = (Obj *)g_021469F4[idx]) == 0)
        return 0;
    return p->flag;
}
