/*
 * function: func_02178524
 * address:  0x02178524
 * packet:   pkt_ov014_02178524
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * b is const: that is what lets the ldrh of b[1] schedule above the strh of
 * b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217863C  0x0217863C  thumb  ov014
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A8;
void func_02178138(int state);
void func_02082BCC(void *p, u32 v, u32 n);
int func_0217863C(void);

int func_02178524(u32 a, const u16 *b, u32 c)
{
    func_02178138(2);
    if (b != 0) {
        *(u16 *)(g_021797A8 + 0x140E) = b[2];
        *(u16 *)(g_021797A8 + 0x140C) = b[1];
        *(u16 *)(g_021797A8 + 0x140A) = b[0];
    } else {
        func_02082BCC(g_021797A8 + 0x140A, 0xff, 6);
    }
    *(u32 *)(g_021797A8 + 0x1E74) = a;
    *(u32 *)(g_021797A8 + 0x1E94) = 0;
    *(u16 *)(g_021797A8 + 0x1EB2) = c;
    *(u16 *)(g_021797A8 + 0x1406) = 1;
    *(u16 *)(g_021797A8 + 0x1EB4) = 1;
    if (func_0217863C() == 0) {
        func_02178138(9);
        return 0;
    }
    return 1;
}
