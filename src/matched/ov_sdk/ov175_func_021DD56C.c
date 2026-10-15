/*
 * function: sakeiInitRequest
 * address:  0x021DD56C
 * packet:   pkt_021DD56C
 * region:   ov175
 * status:   EXACT
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 */
typedef unsigned int u32;

void *func_0217EAB0(int size);
void MSL_C_LIB_MemsetPtr(void *dst, int c, int n);

int *sakeiInitRequest(int *ctx, int a1, int a2, int a3, int a4)
{
    int *p;

    ctx[0x12] = 0;
    if (a2 == 0) {
        ctx[0x12] = 3;
        return 0;
    }
    if (ctx[0] == 0 || ctx[9] == 0) {
        ctx[0x12] = 1;
        return 0;
    }
    p = (int *)func_0217EAB0(0x24);
    if (p == 0) {
        ctx[0x12] = 2;
        return 0;
    }
    MSL_C_LIB_MemsetPtr(p, 0, 0x24);
    p[0] = (int)ctx;
    p[1] = a1;
    p[2] = a2;
    p[4] = a3;
    p[5] = a4;
    return p;
}
