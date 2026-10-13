/*
 * function: VCT_SESSION_ReadChannel
 * address:  0x021B0904
 * packet:   pkt_ov013_021B0904
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Take one queued packet for slot idx (0x94-byte slots at 0x021B3CBC).
 * Compares the packet's u64 time at +0x46C against the tick count: more
 * than 0x34 ahead falls back to the slot's held packet at +0x3C, more
 * than 0x8B4C behind is released and the loop retries; otherwise it
 * counts sequence gaps (+0x14), updates +0x28/+0x2C/+0 from the tick
 * difference to +0x464, copies +0x474 to dst and sets bit (+0x10) in
 * *mask.
 * VCT_AUDIO_SetLastPacket is void in its own file, but this caller loops on the
 * r0 it leaves behind (mov r4, r0 after each call), so it is declared
 * int here.
 *
 * symbols:
 *   d_021B3CBC     0x021B3CBC  data  ov013  a4
 *   VCT_AUDIO_GetReadyCount  0x021B19AC  arm  ov013
 *   func_020870D0  0x020870D0  arm
 *   VCT_AUDIO_PeekReadyPacket  0x021B190C  arm  ov013
 *   func_02082B0C  0x02082B0C  arm
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   VCT_AUDIO_SetLastPacket  0x021B1A74  arm  ov013
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Pkt {
    u8 pad0[0x10];
    u8 f10;
    u8 pad11[7];
    u32 f18;
    u8 pad1C[0x45C - 0x1C];
    int f45C;
    u8 pad460[4];
    u64 f464;
    u64 f46C;
    void *f474;
} Pkt;

typedef struct Slot {
    u32 f0;
    u8 pad4[4];
    int f8;
    u8 padC[8];
    int f14;
    u8 pad18[8];
    int f20;
    u8 pad24[4];
    u32 f28;
    u32 f2C;
    u8 pad30[0xC];
    Pkt *f3C;
    u8 pad40[0x18];
    u32 f58;
    u8 pad5C[0x14];
    int f70;
    u8 pad74[0x20];
} Slot;

extern Slot d_021B3CBC[3];

extern int VCT_AUDIO_GetReadyCount(u32 idx);
extern u64 func_020870D0(void);
extern void *VCT_AUDIO_PeekReadyPacket(unsigned int i);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern void VCT_POOL_FreeFrame(Pkt *p);
extern int VCT_AUDIO_SetLastPacket(Slot *s, Pkt *p);

int VCT_SESSION_ReadChannel(void *dst, u32 size, u32 idx, u32 *mask)
{
    int n;
    Pkt *pkt;
    Slot *slot;
    int first;
    u64 now;
    u32 d;
    u32 diff;

    slot = &d_021B3CBC[idx];
    first = 1;
    n = VCT_AUDIO_GetReadyCount(idx);
    while (n != 0) {
        now = func_020870D0();
        pkt = VCT_AUDIO_PeekReadyPacket(idx);
        if (pkt != 0) {
            if (pkt->f46C > now + 0x34) {
                if (pkt->f45C == 0 && slot->f3C != 0) {
                    slot->f20++;
                    func_02082B0C(slot->f3C->f474, dst, size);
                    VCT_POOL_FreeFrame(slot->f3C);
                    slot->f3C = 0;
                    if (mask != 0) {
                        *mask |= 1 << pkt->f10;
                    }
                    return 1;
                }
                return 0;
            }
            if (now > pkt->f46C + 0x8B4C) {
                slot->f58 = pkt->f18;
                n = VCT_AUDIO_SetLastPacket(slot, pkt);
                VCT_AUDIO_PeekReadyPacket(idx);
                first = 0;
                continue;
            }
            if (slot->f58 + 1 != pkt->f18 && slot->f58 != 0 && slot->f58 <= pkt->f18) {
                if (pkt->f45C == 0) {
                    slot->f14++;
                }
            }
            slot->f58 = pkt->f18;
            if (first != 0 && slot->f70 != 0) {
                n = VCT_AUDIO_SetLastPacket(slot, pkt);
                VCT_AUDIO_PeekReadyPacket(idx);
                slot->f70--;
                continue;
            }
            d = (u32)(now - pkt->f464);
            diff = d - slot->f28;
            slot->f28 = d;
            slot->f2C = slot->f28 + ((diff - slot->f28) >> 4);
            slot->f0 = slot->f2C;
            func_02082B0C(pkt->f474, dst, size);
            VCT_AUDIO_SetLastPacket(slot, pkt);
            if (mask != 0) {
                *mask |= 1 << pkt->f10;
            }
            return 1;
        } else {
            slot->f8 = n;
            return 0;
        }
    }
    if (slot->f3C != 0) {
        VCT_POOL_FreeFrame(slot->f3C);
        slot->f3C = 0;
    }
    return 0;
}
