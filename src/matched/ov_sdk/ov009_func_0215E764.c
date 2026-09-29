/*
 * function: func_0215E764
 * address:  0x0215E764
 * packet:   pkt_ov009_0215E764
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ShutdownCallBack (libsoc.TWL.HYB.a(socl_shutdown.o))
 *
 * symbols:
 *   func_0215AD00  0x0215AD00  arm  ov009
 */

typedef struct {
    unsigned char pad0[0xAF];
    signed char mode;
} Socket;

typedef struct {
    unsigned long pad0;
    Socket *socket;
} Cmd;

extern void func_0215AD00(void);

static inline int IsTcp(int mode)
{
    int r = 1;

    if (mode != 0 && mode != 4)
        r = 0;
    return r;
}

int func_0215E764(void *arg)
{
    Socket *socket = ((Cmd *)arg)->socket;

    if (IsTcp(socket->mode))
        func_0215AD00();
    return 0;
}
