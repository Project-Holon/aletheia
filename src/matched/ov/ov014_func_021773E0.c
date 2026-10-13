/*
 * function: NET_WHPIPE_StoreScannedEntry
 * address:  0x021773E0
 * packet:   pkt_ov014_021773E0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   NET_WHPIPE_IsBeaconAcceptable  0x0217731C  thumb  ov014
 *   func_0203EFC8  0x0203EFC8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    u8 b0[4];
    u8 mac[6];
    u8 rest[0xC0 - 10];
} Ent;

typedef struct W {
    u8 pad0[8];
    Ent ent[16];
    u8 pad1[0x38];
    u16 age[16];
    u8 pad2[0xAF - 0x20];
    u8 flag;
} W;

extern W *g_pWhPipeWork;
extern void *GFL_NET_GetInitParam(void);
extern int NET_WHPIPE_IsBeaconAcceptable(u8 *p);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void MI_CpuCopy8(void *src, void *dst, int n);

int NET_WHPIPE_StoreScannedEntry(u8 *p)
{
    int i;
    W *base = g_pWhPipeWork;

    GFL_NET_GetInitParam();
    if (NET_WHPIPE_IsBeaconAcceptable(p) == 0)
        return 0;
    for (i = 0; i < 16; i++) {
        if (base->age[i] != 0 && func_0203EFC8(base->ent[i].mac, p + 4, 6) == 0) {
            base->age[i] = 600;
            MI_CpuCopy8(p, &base->ent[i], 0xC0);
            return 1;
        }
    }
    for (i = 0; i < 16; i++) {
        if (base->age[i] == 0)
            break;
    }
    if (i >= 16)
        return 0;
    base->age[i] = 600;
    MI_CpuCopy8(p, &base->ent[i], 0xC0);
    base->flag = 1;
    return 1;
}
