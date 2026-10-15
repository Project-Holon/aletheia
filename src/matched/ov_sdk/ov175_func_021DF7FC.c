/*
 * function: sciInterfaceCreate
 * address:  0x021DF7FC
 * packet:   pkt_021DF7FC
 * region:   ov175
 * status:   EXACT
 * symbols:
 *   d_021ACEF8     0x021ACEF8  data  a4
 *   d_021ACEFC     0x021ACEFC  data  a4
 *   d_021E52B4     0x021E52B4  data  a1
 *   d_021E412C     0x021E412C  data  a4
 *   OS_SNPrintf  0x02084F80  arm
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 */
typedef unsigned int u32;

extern int d_021ACEF8;
extern int d_021ACEFC;
extern signed char d_021E52B4;
extern int d_021E412C;

void OS_SNPrintf(void *p, int a, void *b, void *c);
void *func_0217EAB0(int size);
void MSL_C_LIB_MemsetPtr(void *dst, int c, int n);

int sciInterfaceCreate(void **out)
{
    void *p;

    if (d_021ACEF8 == 1) {
        if (d_021E52B4 == 0)
            OS_SNPrintf(&d_021E52B4, 0x80, &d_021E412C, &d_021ACEFC);
    } else {
        return 1;
    }
    p = func_0217EAB0(0xac);
    *out = p;
    if (p == 0)
        return 5;
    MSL_C_LIB_MemsetPtr(p, 0, 0xac);
    return 0;
}
