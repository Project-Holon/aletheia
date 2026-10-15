/*
 * function: func_02186664
 * address:  0x02186664
 * packet:   pkt_02186664
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiInitialize (gpi_engine?): allocate the 0x638-byte GP connection block,
 * clear it, seed the state words, hand its address to func_0218FB14, clear
 * nine 8-byte pairs, run the two sub-initialisers, then publish the block
 * through *out.  p lives on the stack because &p is taken.
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_0218FB14  0x0218FB14  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021867E8  0x021867E8  arm  ov009
 *   func_02186788  0x02186788  arm  ov009
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   srand  0x020946C8  arm
 */

extern void *func_0217EAB0(int size);
typedef unsigned int   u32;
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
extern int   func_0218FB14(void **pp);
extern void  func_0217EAE0(void *p);
extern int   func_021867E8(void **pp);
extern void  func_02186788(void **pp);
extern void  SocketStartUp(void);
extern unsigned int current_time(void);
extern void  srand(void);

int func_02186664(void **out, int a1, int a2, int a3)
{
    char *p;
    int i;

    *out = 0;
    p = func_0217EAB0(0x638);
    if (p == 0)
        return 1;
    MSL_C_LIB_MemsetPtr(p, 0, 0x638);
    p[0] = 0;
    *(int *)(p + 0x5b8) = 0;
    *(int *)(p + 0x100) = 1;
    *(int *)(p + 0x104) = 0;
    *(int *)(p + 0x108) = 0;
    *(int *)(p + 0x10c) = 0;
    *(int *)(p + 0x60c) = a1;
    *(int *)(p + 0x610) = a2;
    *(int *)(p + 0x1a4) = a3;

    if (func_0218FB14((void **)&p) == 0) {
        func_0217EAE0(p);
        return 1;
    }

    *(int *)(p + 0x5c0) = 0;
    for (i = 0; i < 9; i++) {
        *(int *)(p + i * 8 + 0x1a8) = 0;
        *(int *)(p + i * 8 + 0x1ac) = 0;
    }

    i = func_021867E8((void **)&p);
    if (i != 0) {
        func_02186788((void **)&p);
        return i;
    }

    SocketStartUp();
    current_time();
    srand();
    *out = p;
    return 0;
}
