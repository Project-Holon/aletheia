/*
 * file:     unit_02186664_p01.c
 * unit:     yes
 * function: func_02186664, func_02186788, func_021867C0
 * address:  0x02186664
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_0218FB14  0x0218FB14  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021867E8  0x021867E8  arm  ov009
 *   func_0217F25C  0x0217F25C  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_020946C8  0x020946C8  arm
 *   func_0218B760  0x0218B760  arm  ov009
 *   func_0218D840  0x0218D840  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 */
typedef unsigned int   u32;

typedef struct GPIConnection {
    unsigned char pad[0x5C8];
    void *f5C8;
} GPIConnection;

typedef struct GPIProfile {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
} GPIProfile;

extern void *func_0217EAB0(int size);
extern void *func_020923B0(void *p, int c, u32 n);
extern int   func_0218FB14(void **pp);
extern void  func_0217EAE0(void *p);
extern int   func_021867E8(void **pp);
extern void  func_0217F25C(void);
extern unsigned int func_0217F264(void);
extern void  func_020946C8(void);
extern void func_0218B760(void **connection, int tellServer);
extern void func_0218D840(void **connection);
extern void func_021846B4(void *table);
int func_02186664(void **out, int a1, int a2, int a3);
void func_02186788(void **connection);
int func_021867C0(int unused, GPIProfile *profile);


/*
 * gpiInitialize (gpi_engine?): allocate the 0x638-byte GP connection block,
 * clear it, seed the state words, hand its address to func_0218FB14, clear
 * nine 8-byte pairs, run the two sub-initialisers, then publish the block
 * through *out.  p lives on the stack because &p is taken.
 */
int func_02186664(void **out, int a1, int a2, int a3)
{
    char *p;
    int i;

    *out = 0;
    p = func_0217EAB0(0x638);
    if (p == 0)
        return 1;
    func_020923B0(p, 0, 0x638);
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

    func_0217F25C();
    func_0217F264();
    func_020946C8();
    *out = p;
    return 0;
}


/*
 * sdk:      gpiDestroy (gpi.o)
 */
void func_02186788(void **connection)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    func_0218B760(connection, 1);
    func_0218D840(connection);
    func_021846B4(iconnection->f5C8);
    func_0217EAE0(iconnection);
    *connection = 0;
}


/*
 * sdk:      gpiResetProfile (gpi.o)
 *
 * The object keeps profile in r1 (a leading unused parameter takes r0).
 */
int func_021867C0(int unused, GPIProfile *profile)
{
    profile->f8 = 0;
    profile->fC = 0;
    profile->f14 = 0;
    profile->f18 = 0;
    profile->f1C = 0;
    profile->f20 = 0;
    profile->f28 = 0;
    return 1;
}
