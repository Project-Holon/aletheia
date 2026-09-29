/*
 * function: func_021F4140
 * address:  0x021F4140
 * region:   ov107
 * status:   MATCH (near miss, lane w8_s5, no shard)
 * note:     MBi_SendFixedBeacon, 63 B differ: register coloring only (target mbss=r7 bsendBuff=r8, cur in r4 then reused for attribute; ours mbss=r8 bsendBuff=r7). Size matches at 356 B.
 */
typedef struct {
    unsigned long ggid;
    unsigned char dataAttr : 2;
    unsigned char fileNo : 6;
    unsigned char seqNoFixed;
    unsigned char seqNoVolat;
    unsigned char beaconNo;
    unsigned short checksum;
    unsigned char pad0;
    unsigned char pad1;
    unsigned char length;
} MbBeacon;

typedef struct {
    char pad0[0x1C];
    unsigned char *cur;
    unsigned char *data;
    unsigned char state;
    unsigned char pad1;
    unsigned char seq;
    unsigned char n27;
    unsigned char n28;
    unsigned char beaconNo;
} MbSend;

extern MbSend g_021F6EF4;
extern MbBeacon g_021F6F20;
extern unsigned char g_021F6F2E[];
extern unsigned char g_021F6F28[];

extern void func_02082A48(unsigned short data, void *destp, unsigned long size);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern unsigned short func_021F3CB8(unsigned char *buf, int length);
extern int func_02090CD4(void *callback, void *userGameInfo, unsigned short size,
                         unsigned long ggid, unsigned short tgid, unsigned char attr);

static void func_021F4140(unsigned long ggid, unsigned short tgid, unsigned char attribute)
{
    unsigned long lastAddr;

    lastAddr = (unsigned long)g_021F6EF4.cur + 0x358;
    if ((unsigned long)g_021F6EF4.data + 0x62 <= lastAddr) {
        g_021F6F20.length = 0x62;
    } else {
        lastAddr = lastAddr - (unsigned long)g_021F6EF4.data;
        g_021F6F20.length = (unsigned char)lastAddr;
        func_02082A48(0, g_021F6F2E + (lastAddr & 0xFF), 0x62 - (lastAddr & 0xFF));
    }
    func_02082A60(g_021F6EF4.data, g_021F6F2E, g_021F6F20.length);
    g_021F6F20.pad0 = g_021F6EF4.n27;
    g_021F6F20.pad1 = g_021F6EF4.n28;
    g_021F6F20.dataAttr = g_021F6EF4.cur[0x4B2];
    g_021F6F20.seqNoFixed = g_021F6EF4.cur[0x4B3];
    g_021F6F20.seqNoVolat = g_021F6EF4.seq;
    g_021F6F20.ggid = *(unsigned long *)(g_021F6EF4.cur + 0x4B8);
    g_021F6F20.fileNo = g_021F6EF4.cur[0x4B5];
    g_021F6F20.beaconNo = g_021F6EF4.beaconNo++;
    g_021F6F20.checksum = 0;
    g_021F6F20.checksum = func_021F3CB8(g_021F6F28, 0x68);
    g_021F6EF4.n27 = g_021F6EF4.n27 + 1;
    if (g_021F6EF4.n27 < g_021F6EF4.n28)
        g_021F6EF4.data += 0x62;
    else
        g_021F6EF4.state = 4;
    func_02090CD4(0, &g_021F6F20, 0x70, ggid, tgid, attribute | 3);
}
