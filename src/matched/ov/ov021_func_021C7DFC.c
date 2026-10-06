/*
 * function: func_021C7DFC
 * address:  0x021C7DFC
 * packet:   pkt_ov021_021C7DFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAAD0  0x021DAAD0  data  ov021  a4
 *   func_020307B0  0x020307B0  arm
 *   func_021C7E90  0x021C7E90  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void (*d_021DAAD0[])(M *m);
extern int func_021C7E90(void *p);
void func_021C7DFC(M *m)
{
    if (m != 0) {
        if (m->f1E != 4) {
            d_021DAAD0[m->f1E](m);
            m->f1E = 4;
        }
        if (m->f1C == 2 && func_021C7E90(m->sub))
            m->f1C = 3;
    }
}
