/*
 * function: func_021C7DE0
 * address:  0x021C7DE0
 * packet:   pkt_ov021_021C7DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021C7E64  0x021C7E64  thumb  ov021
 *   func_021C8054  0x021C8054  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern void func_020307B0(void *p);
extern void func_021C7E64(u32 a);
extern int func_021C8054(u32 a);
void func_021C7DE0(M *m)
{
    if (m != 0) {
        func_021C7E64((u32)m->sub);
        func_021C8054(m->f0);
        func_020307B0(m);
    }
}
