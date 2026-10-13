/*
 * function: BTL_NET_FreeRecvBuffers
 * address:  0x021D4A6C
 * packet:   pkt_ov093_021D4A6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x3ae4];
    void *tblA[4];
    void *tblB[4];
    void *tblC[4];
    void *f3b14;
    void *f3b18;
};

extern struct S *gBtlNet;
extern u32 func_020307B0(void *p);

void BTL_NET_FreeRecvBuffers(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (gBtlNet->tblA[i] != 0) {
            func_020307B0(gBtlNet->tblA[i]);
            gBtlNet->tblA[i] = 0;
            gBtlNet->tblB[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (gBtlNet->tblC[i] != 0) {
            func_020307B0(gBtlNet->tblC[i]);
            gBtlNet->tblC[i] = 0;
        }
    }
    if (gBtlNet->f3b14 != 0) {
        func_020307B0(gBtlNet->f3b14);
        gBtlNet->f3b14 = 0;
        gBtlNet->f3b18 = 0;
    }
}
