/*
 * function: func_021A2C30
 * address:  0x021A2C30
 * packet:   pkt_ov021_021A2C30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A2C6C  0x021A2C6C  thumb  ov021
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
} Snd021A2C30;

void func_021A2C6C(Snd021A2C30 *p, int a);
int func_02005C64(void);
void func_02028A7C(int a, u16 id);
void func_020061E4(u16 id);

void func_021A2C30(Snd021A2C30 *p, int a, u16 id)
{
    func_021A2C6C(p, a);
    if (func_02005C64() == 0) {
        p->state = 1;
        p->id = id;
        if (p->flag != 0)
            func_02028A7C(a, p->id);
        else
            func_020061E4(p->id);
    } else {
        p->state = 2;
        p->id = id;
    }
}
