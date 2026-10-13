/*
 * function: DWCi_MOV_MBP_GetPlayerNo
 * address:  0x021D28E4
 * packet:   pkt_ov016_021D28E4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_GetPlayerNo (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   gDwcMovMbpWork                       0x021DE65C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x16];
    u8 mac[6];
    u16 playerNo;
} Child;

typedef struct {
    u16 pad0;
    u16 bmp;
    u8 pad1[10];
    Child child[1];
} Wb;

extern Wb *gDwcMovMbpWork;

static inline int cmpmac(u8 *a, u8 *b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]
        && a[4] == b[4] && a[5] == b[5];
}

u16 DWCi_MOV_MBP_GetPlayerNo(u8 *macAddress)
{
    u16 i;
    for (i = 1; i < 2; i++) {
        if ((gDwcMovMbpWork->bmp & (1 << i)) && cmpmac(macAddress, gDwcMovMbpWork->child[i - 1].mac))
            return gDwcMovMbpWork->child[i - 1].playerNo;
    }
    return 0;
}
