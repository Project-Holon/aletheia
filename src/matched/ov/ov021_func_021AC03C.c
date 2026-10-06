/*
 * function: func_021AC03C
 * address:  0x021AC03C
 * packet:   pkt_ov021_021AC03C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

typedef struct {
    int f0;
    char pad[0xd0];
} E;

typedef struct {
    u32 f0;
    int f4;
    E *f8;
} U;

extern void func_021AC154(E *e);
extern u32 func_020307B0(void *p);

void func_021AC03C(U *u)
{
    u32 i;
    for (i = 0; i < u->f0; i++) {
        if (u->f8[i].f0 != 0) {
            func_021AC154(&u->f8[i]);
        }
    }
    func_020307B0(u->f8);
    func_020307B0(u);
}
