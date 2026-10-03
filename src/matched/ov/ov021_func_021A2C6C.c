/*
 * function: func_021A2C6C
 * address:  0x021A2C6C
 * packet:   pkt_ov021_021A2C6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02028B50  0x02028B50  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C6C;

void func_02028B50(int a, u16 id);
int func_02006148(u32 a0);
void func_020061F8(int h);

void func_021A2C6C(Snd021A2C6C *p, int a)
{
    if (p->state == 1) {
        p->state = 0;
        if (p->flag != 0)
            func_02028B50(a, p->id);
        else
            func_020061F8(func_02006148(p->id));
    }
}
