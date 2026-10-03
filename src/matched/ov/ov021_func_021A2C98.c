/*
 * function: func_021A2C98
 * address:  0x021A2C98
 * packet:   pkt_ov021_021A2C98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C98;

int func_02005C64(void);
void func_02028A7C(int a, u16 id);
void func_020061E4(u32 a);

void func_021A2C98(Snd021A2C98 *p, int a)
{
    if (p->state == 2 && func_02005C64() == 0) {
        p->state = 1;
        if (p->flag != 0)
            func_02028A7C(a, p->id);
        else
            func_020061E4(p->id);
    }
}
