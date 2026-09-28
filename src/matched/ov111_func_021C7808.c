/*
 * function: func_021C7808
 * address:  0x021C7808
 * packet:   pkt_ov111_021C7808
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048AC4  0x02048AC4  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02047E54  0x02047E54  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work;

extern void func_02048AC4(void *p);
extern void func_020480E4(void *p, u16 v);
extern void func_02047E54(void *p);

void func_021C7808(Work *p)
{
    func_02048AC4(p->f104);
    func_020480E4(p->fF8, p->fFC);
    func_02047E54(p->fF8);
}
