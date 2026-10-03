/*
 * function: func_021781BC
 * address:  0x021781BC
 * packet:   pkt_ov014_021781BC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  ov014  a4
 *   func_0208F644  0x0208F644  arm
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178204  0x02178204  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A8;
int func_0208F644(void *fn);
void func_0217814C(int err);
void func_02178204(u8 *obj);

int func_021781BC(void)
{
    int r;

    if ((u32)(*(int *)(g_021797A8 + 0x1E70) - 4) <= 1)
        return 1;
    r = func_0208F644(func_02178204);
    if (r != 2) {
        func_0217814C(r);
        return 0;
    }
    *(u16 *)(g_021797A8 + 0x1EA8) = 0;
    *(u16 *)(g_021797A8 + 0x1EAA) = 1;
    return 1;
}
