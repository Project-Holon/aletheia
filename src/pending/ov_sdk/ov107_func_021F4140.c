typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u32 ggid;
    u8 dataAttr:2;
    u8 fileNo:6;
    u8 seqNoFixed;
    u8 seqNoVolat;
    u8 beaconNo;
    u16 checksum;
    u8 seqNo;
    u8 seqLen;
    u8 size;
    u8 pad;
    u8 data[0x62];
} MbBeacon;

typedef struct {
    char pad0[0x4b2];
    u8 dataAttr;
    u8 seqNoFixed;
    u8 pad4b4;
    u8 fileNo;
    char pad4b6[2];
    u32 ggid;
} Gi;

typedef struct {
    char pad0[0x1c];
    Gi *gi;
    u8 *cur;
    u8 state;
    u8 pad25;
    u8 seqNoVolat;
    u8 seq;
    u8 seqLen;
    u8 beaconNo;
} Mbss;

extern Mbss g_021F6EF4;
extern MbBeacon g_021F6F20;

extern void func_02082A48(u16 data, void *destp, u32 size);
extern void func_02082A60(void *srcp, void *destp, u32 size);
extern u16 func_021F3CB8(u16 *buf, int length);
extern int func_02090CD4(void *cb, void *info, u16 size, u32 ggid, u16 tgid, u8 attr);

void func_021F4140(u32 ggid, u16 tgid, u8 attribute)
{
    u32 lastAddr;
    u8 *cur;
    Gi *gi;

    gi = g_021F6EF4.gi;
    cur = g_021F6EF4.cur;
    lastAddr = (u32)gi + 0x358;
    if ((u32)cur + 0x62 > lastAddr) {
        g_021F6F20.size = lastAddr - (u32)cur;
        func_02082A48(0, g_021F6F20.data + g_021F6F20.size, 0x62 - g_021F6F20.size);
    } else {
        g_021F6F20.size = 0x62;
    }
    func_02082A60(g_021F6EF4.cur, g_021F6F20.data, g_021F6F20.size);
    g_021F6F20.seqNo = g_021F6EF4.seq;
    g_021F6F20.seqLen = g_021F6EF4.seqLen;
    g_021F6F20.dataAttr = g_021F6EF4.gi->dataAttr;
    g_021F6F20.seqNoFixed = g_021F6EF4.gi->seqNoFixed;
    g_021F6F20.seqNoVolat = g_021F6EF4.seqNoVolat;
    g_021F6F20.ggid = g_021F6EF4.gi->ggid;
    g_021F6F20.fileNo = g_021F6EF4.gi->fileNo;
    g_021F6F20.beaconNo = g_021F6EF4.beaconNo++;
    g_021F6F20.checksum = 0;
    g_021F6F20.checksum = func_021F3CB8(&g_021F6F20.checksum, 0x68);
    if (++g_021F6EF4.seq < g_021F6EF4.seqLen) {
        g_021F6EF4.cur += 0x62;
    } else {
        g_021F6EF4.state = 4;
    }
    func_02090CD4(0, &g_021F6F20, 0x70, ggid, tgid, attribute | 3);
}
