/*
 * function: func_021BC7FC
 * address:  0x021BC7FC
 * packet:   pkt_ov172_021BC7FC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_TVT_SYS_GetComm  0x021BDFE4  thumb  ov172
 *   CTVT_COMM_IsNetReady  0x021B8108  thumb  ov172
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   NET_WHPIPE_GetEntryBeaconKind  0x02177B80  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   CTVT_COMM_FindPeerName  0x021B85D0  thumb  ov172
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   func_021BD0A4  0x021BD0A4  thumb  ov172
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021BCB88  0x021BCB88  thumb  ov172
 *   func_021BCEF8  0x021BCEF8  thumb  ov172
 *
 * Peer list refresh: marks every active slot as unseen, scans the 16 wireless
 * peers, matches each peer MAC against the 15 slots (kind 0x20 or 3), adds new
 * peers to a free slot and to the first free row, then drops slots that were
 * not seen, compacts the rows, and refreshes the list.
 *
 * pass 2 2026-10-06 P2L03: EXACT. kind is a u8 local (NET_WHPIPE_GetEntryBeaconKind returns u8) and
 * found = 1 is a plain literal after the unseen store. With a u32 kind the found
 * spill store was scheduled above the unseen store (10 bytes) and the found = match
 * stand-in was needed (2 bytes); the narrow kind closes it.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Info {
    u8 pad0[2];
    u8 b2_0 : 1;
    u8 b2_1 : 5;
    u8 b2_6 : 2;
    u8 pad3[8];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32 w4dummy;
};

struct Rec {
    u8 pad0[4];
    u32 f4;
    u8 pad8[3];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32 fC_0 : 17;
    u32 fC_17 : 10;
    u32 fC_27 : 5;
    u8 pad10[0x10];
    u8 f20;
    u8 f21_0 : 1;
    u8 f21_1 : 1;
    u8 f21_2 : 6;
};

struct Bits2 {
    u8 b0 : 1;
    u8 b1 : 5;
    u8 b6 : 2;
};

extern u32 COMM_TVT_SYS_GetComm(void *p);
extern int CTVT_COMM_IsNetReady(void *unused, void *p);
extern u32 GFL_NET_GetScanResult(u32 a);
extern void *GFL_NET_GetScanResultMac(u32 a);
extern u8 NET_WHPIPE_GetEntryBeaconKind(int i);
struct Sub0200852CObj;
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void OS_GetMacAddress(void *p);
extern int CTVT_COMM_FindPeerName(unsigned char *p, unsigned char *q);
extern u32 ZONEDATA_IsZone117(u32 id);
extern u32 ZONEDATA_IsZoneGroup118To120(u32 id);
extern int func_021BD0A4(void *ctx, u32 unused, u32 a, u32 b, u32 c);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void func_021BCB88(void *ctx, char *list);
extern void func_021BCEF8(void *ctx, u8 *list);

struct Slot {
    u32 active;
    u32 unseen;
    u32 f8;
    u8 padC[8];
    u8 *buf;
    u8 kind;
    u8 mac[6];
    u8 pad1f;
    u8 row;
    u8 pad21[3];
};
struct List {
    u8 pad[0x1e4];
    struct Slot slots[15];
};

void func_021BC7FC(void *ctx, u8 *list)
{
    int changed;
    int refresh;
    int found;
    int diff;
    struct Rec *p;
    u8 kind;
    u32 a;
    u32 c;
    int match;
    u8 slot;
    int j;
    int i;
    u8 k;
    u8 m;
    u8 r;
    u8 *e;
    u8 *row;
    u8 *mac;
    u32 mode;
    int ok;
    u32 b;
    u8 buf[8];
    u8 q;

    changed = 0;
    refresh = 0;
    if (!CTVT_COMM_IsNetReady(ctx, (void *)COMM_TVT_SYS_GetComm(ctx)))
        return;
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32 *)(e + 0x1e4) == 1)
            *(u32 *)(e + 0x1e8) = 1;
    }
    mode = *(u32 *)(list + 8);
    if (mode != 7 && mode != 9 && mode != 10 && (int)mode >= 5) {
        for (j = 0; j < 16; j++) {
            found = 0;
            diff = 0;
            p = (struct Rec *)GFL_NET_GetScanResult(j);
            if (p == 0)
                continue;
            slot = 0xff;
            mac = GFL_NET_GetScanResultMac(j);
            kind = NET_WHPIPE_GetEntryBeaconKind(j);
            if (kind == 3 && ((struct Bits2 *)((u8 *)p + 2))->b1 != 2)
                continue;
            ok = 0;
            if (kind == 0x20) {
                a = (u32)func_020084F4(p);
                b = func_02008550((const struct Sub0200852CObj *)p);
                c = func_02008530((const struct Sub0200852CObj *)p);
                OS_GetMacAddress(buf);
                if (p->f21_1 == 0 || CTVT_COMM_FindPeerName((u8 *)p, buf) == 1)
                    ok = func_021BD0A4(ctx, (u32)list, a, c, b);
            } else if (ZONEDATA_IsZone117((u16)p->fC_17) == 0 && ZONEDATA_IsZoneGroup118To120((u16)p->fC_17) == 0) {
                ok = func_021BD0A4(ctx, (u32)list, (u32)((u8 *)p + 0x1a), p->f4, p->bB_7);
            }
            if (ok == 0)
                continue;
            for (k = 0; k < 15; k++) {
                e = list + k * 0x24;
                if (*(u32 *)(e + 0x1e4) == 1) {
                    match = 1;
                    for (m = 0; m < 6; m++) {
                        if (mac[m] != e[m + 0x1fd]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        ((struct List *)list)->slots[k].unseen = 0;
                        found = 1;
                        if (kind != ((struct List *)list)->slots[k].kind) {
                            found = 0;
                            diff = 1;
                            slot = k;
                            for (m = 0; m < 3; m++) {
                                if (k == list[m]) {
                                    list[m] = 0xff;
                                    refresh = 1;
                                }
                            }
                            if (list[3] == k) {
                                list[3] = 0xff;
                                refresh = 1;
                            }
                        }
                        if (kind == 0x20 && (*(u8 **)(e + 0x1f8))[0x20] != p->f20) {
                            found = 0;
                            diff = 1;
                            slot = k;
                        }
                        break;
                    }
                } else if (slot == 0xff) {
                    slot = k;
                }
            }
            if (found != 0 || slot == 0xff)
                continue;
            e = list + slot * 0x24;
            *(u32 *)(e + 0x1e4) = 1;
            *(u32 *)(e + 0x1e8) = 0;
            *(u32 *)(e + 0x1ec) = 0;
            for (m = 0; m < 6; m++)
                e[m + 0x1fd] = mac[m];
            if (kind == 0x20) {
                ((struct List *)list)->slots[slot].kind = 0x20;
                MI_CpuCopy8(p, ((struct List *)list)->slots[slot].buf, 0x34);
            } else {
                ((struct List *)list)->slots[slot].kind = 3;
                MI_CpuCopy8(p, ((struct List *)list)->slots[slot].buf, 0x64);
            }
            if (diff == 0) {
                for (r = 0; r < 15; r++) {
                    row = list + r * 0x1c;
                    if (row[0x58] == 0xff) {
                        row[0x58] = slot;
                        e[0x204] = r;
                        *(u32 *)(row + 0x40) = 1;
                        break;
                    }
                }
            } else {
                *(u32 *)(list + e[0x204] * 0x1c + 0x40) = 1;
            }
            changed = 1;
        }
    }
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32 *)(e + 0x1e4) == 1 && *(u32 *)(e + 0x1e8) == 1) {
            q = e[0x204];
            for (; q < 14; q++) {
                row = list + q * 0x1c;
                if (row[0x74] == 0xff)
                    break;
                row[0x58] = row[0x74];
                list[row[0x58] * 0x24 + 0x204] = q;
                *(u32 *)(row + 0x40) = 1;
            }
            row = list + q * 0x1c;
            row[0x58] = 0xff;
            *(u32 *)(row + 0x40) = 1;
            e[0x204] = 0xff;
            *(u32 *)(e + 0x1e4) = 0;
            for (m = 0; m < 3; m++) {
                if (i == list[m]) {
                    list[m] = 0xff;
                    refresh = 1;
                }
            }
            if (list[3] == i) {
                list[3] = 0xff;
                refresh = 1;
            }
            i--;
            changed = 1;
        }
    }
    if (changed == 1) {
        func_021BCB88(ctx, (char *)list);
        refresh = 1;
        *(u32 *)(list + 0xc) = 1;
    }
    if (refresh == 1 && *(u32 *)(list + 8) == 5)
        func_021BCEF8(ctx, list);
}
