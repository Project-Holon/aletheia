/*
 * file:     unit_0215CD3C_p02.c
 * unit:     yes
 * function: func_0215CE3C, func_0215CE7C, func_0215CE9C
 * address:  0x0215CE3C
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
 *   SOCLi_AllocCommandPacket   0x0215ce14 arm
 *   g_021AA484 0x021AA484 data ov009
 */
struct SOCLSocket;
struct SOCLiCommandPacket {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern struct SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag);
extern void func_02085DBC(void *heap, void *ptr, u32 flags);
struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
void func_0215CE7C(void *ptr);
int func_0215CE9C(const int *p, int b);
extern void *g_021AA484;


struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                     struct SOCLSocket *socket,
                                                     long flag)
{
    struct SOCLiCommandPacket *cp = SOCLi_AllocCommandPacket(flag);

    if (cp != 0) {
        cp->handler = handler;
        cp->socket = socket;
        cp->field8 = 0;
        cp->fieldC = *(signed char *)((char *)socket + 0xaf);
        cp->fieldD = (signed char)flag;
    }
    return cp;
}


void func_0215CE7C(void *ptr)
{
    if (ptr != 0) {
        func_02085DBC(&g_021AA484, ptr, 0);
    }
}

/*
 * Word at +0xa0 of the block, falling back to +0xa4 when it is zero.
 */
int func_0215CE9C(const int *p, int b)
{
    int v = p[0x28];

    if (v == 0)
        v = p[0x29];
    return v;
}
