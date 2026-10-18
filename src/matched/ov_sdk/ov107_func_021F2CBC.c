/*
 * function: MBi_CommParentSendData
 * address:  0x021F2CBC
 * packet:   pkt_ov107_021F2CBC
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_CommParentSendData (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   MIi_CpuClear16  0x02082A48  arm
 *   MBi_CommParentSendMsg  0x021F276C  arm  ov107
 *   MBi_CommParentSendDLFileInfo  0x021F27A8  arm  ov107
 *   func_021F2A44  0x021F2A44  arm  ov107
 *   g_021F6FA0     0x021F6FA0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct MBiParam {
    u32 sendbuf[0x14e4 / 4];
    u32 p_comm_state[16];
} MBiParam;

struct bitmap {
    u16 connected;
    u16 req;
    u16 kick;
    u16 boot;
    u16 mem_full;
};

extern MBiParam *g_021F6FA0;

extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int MBi_CommParentSendMsg(u8 type, u16 pollbmp);
extern int MBi_CommParentSendDLFileInfo(void);
extern int func_021F2A44(void);

static int MBi_CommParentSendData(void)
{
    int errcode;
    u16 child;
    struct bitmap bmp;

    MIi_CpuClear16(0, &bmp, sizeof(bmp));

    for (child = 1; child <= 15; child++) {
        switch (g_021F6FA0->p_comm_state[child]) {
        case 2:
            bmp.connected |= 1 << child;
            break;
        case 5:
            bmp.req |= 1 << child;
            break;
        case 4:
            bmp.kick |= 1 << child;
            break;
        case 8:
            bmp.boot |= 1 << child;
            break;
        case 11:
            bmp.mem_full |= 1 << child;
            break;
        }
    }

    if (bmp.boot)
        errcode = MBi_CommParentSendMsg(5, bmp.boot);
    else if (bmp.connected)
        errcode = MBi_CommParentSendMsg(1, bmp.connected);
    else if (bmp.mem_full)
        errcode = MBi_CommParentSendMsg(6, bmp.mem_full);
    else if (bmp.kick)
        errcode = MBi_CommParentSendMsg(2, bmp.kick);
    else if (bmp.req)
        errcode = MBi_CommParentSendDLFileInfo();
    else
        errcode = func_021F2A44();

    if (errcode != 0x15)
        return errcode;
    return MBi_CommParentSendMsg(0, 0xffff);
}
