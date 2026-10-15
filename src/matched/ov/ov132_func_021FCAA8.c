/*
 * function: MUS_COMM_FUNC_Update
 * address: 0x021FCAA8
 * packet: pkt_ov132_021FCAA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: state machine on p+0x4c (22-entry jump table; cases 20 and 21 are explicit
 * so the table keeps its size). Players are a 0x30-byte struct array at p+0x64. The final
 * packed-id draw is a 64-bit multiply high (_ull_mul) through an inline helper; the id is
 * added into sum (sum += list[k] << 16) before the call, which fixed the last 2 bytes.
 * Callees 021FD84C, 021FCEA8 and 021FD350 are void in their matched files but the caller
 * tests r0 == 1: their last call (a u32-returning arm9 function) leaves the result in r0,
 * so the originals return it. They are declared with return values here. Callee 021FD14C
 * and 021FD400 have no source yet (symbols resolve as labels).
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   MUS_COMM_FUNC_SendCommandWait 0x021FCEA8 thumb ov132
 *   MUS_COMM_FUNC_SendMyStatus 0x021FD14C thumb ov132
 *   MUS_COMM_FUNC_SendBoxData 0x021FD22C thumb ov132
 *   STA_NET_SendRandomOrder 0x021FD84C thumb ov132
 *   STA_NET_NotifyHostKind4 0x021FD6C8 thumb ov132
 *   STA_NET_SendSlot1Command 0x021FD704 thumb ov132
 *   STA_NET_NotifyHostKind5 0x021FD6DC thumb ov132
 *   STA_NET_NotifyHostKind6 0x021FD6F0 thumb ov132
 *   STA_NET_SendSlot2Command 0x021FD76C thumb ov132
 *   STA_NET_SendSlot3Command 0x021FD7D4 thumb ov132
 *   STA_NET_IsTransferDone 0x021FD6A4 thumb ov132
 *   MUS_COMM_FUNC_SendStatusBlock 0x021FD350 thumb ov132
 *   MUS_COMM_FUNC_SendRecordBlock 0x021FD400 thumb ov132
 *   STA_NET_UpdateTransferState 0x021FD550 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Pl {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 pad[3];
    u32 x;
    u32 e;
    u8 rest[0x18];
};
extern u32 func_0200FB24(void);
extern int GFL_NET_IsSessionNull(void);
extern int GFL_NET_Exit(int a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int GFL_NET_GetNegotiationNum(void);
extern u32 GF_STANDARD_Rand(void);
extern void MUS_COMM_FUNC_SetTimingSync(int a, int b);
extern int MUS_COMM_FUNC_CheckTimingSync(char *, int);
extern u32 MUS_COMM_FUNC_SendCommandWait(int unused, int kind, u32 value, u32 id);
extern int MUS_COMM_FUNC_SendMyStatus(char *);
extern int MUS_COMM_FUNC_SendBoxData(char *);
extern int STA_NET_SendRandomOrder(u8 *p);
extern int STA_NET_NotifyHostKind4(u8 *p);
extern int STA_NET_SendSlot1Command(u8 *p);
extern int STA_NET_NotifyHostKind5(char *);
extern int STA_NET_NotifyHostKind6(char *);
extern int STA_NET_SendSlot2Command(u8 *p);
extern int STA_NET_SendSlot3Command(u8 *p);
extern int STA_NET_IsTransferDone(char *);
extern int MUS_COMM_FUNC_SendStatusBlock(char *p, char *src);
extern int MUS_COMM_FUNC_SendRecordBlock(const char *p);
extern void STA_NET_UpdateTransferState(char *);
static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = GF_STANDARD_Rand();
    return ((u64)draw * n) >> 32;
}
struct G {
    u8 pad[0x64];
    struct Pl pl[4];
};
void MUS_COMM_FUNC_Update(char *p)
{
    u8 i, j, n;
    u8 cnt;
    u8 list[4];
    u32 v;
    u32 ok;
    if (func_0200FB24()) {
        *(int *)(p + 4) = 1;
        if (GFL_NET_IsSessionNull() == 0) GFL_NET_Exit(0);
    }
    if (*(int *)(p + 4) == 1) return;
    switch (*(u32 *)(p + 0x4c)) {
    case 0:
        return;
    case 1:
        GFL_NET_SetLoginOption(1);
        MUS_COMM_FUNC_SetTimingSync((int)p, 0x46);
        *(int *)(p + 0x4c) = 2;
        break;
    case 2:
        if (MUS_COMM_FUNC_CheckTimingSync(p, 0x46) == 1 && MUS_COMM_FUNC_SendMyStatus(p) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 3;
            else *(int *)(p + 0x4c) = 5;
        }
        break;
    case 3:
        if (STA_NET_SendRandomOrder((u8 *)p) == 1) *(int *)(p + 0x4c) = 4;
        break;
    case 4:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct G *)p)->pl[i].b == 1) cnt++;
        if (cnt == GFL_NET_GetNegotiationNum() && MUS_COMM_FUNC_SendBoxData(p) == 1) *(int *)(p + 0x4c) = 5;
        break;
    case 6:
        if (MUS_COMM_FUNC_CheckTimingSync(p, 0x40) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 7;
            else *(int *)(p + 0x4c) = 0xb;
        }
        break;
    case 7:
        if (MUS_COMM_FUNC_SendCommandWait((int)p, 8, *(u32 *)(p + 0x144), 0xff) == 1) *(int *)(p + 0x4c) = 8;
        break;
    case 8:
        if (MUS_COMM_FUNC_SendCommandWait((int)p, 9, *(u32 *)(p + 0x148), 0xff) == 1) *(int *)(p + 0x4c) = 9;
        break;
    case 9:
        if (STA_NET_NotifyHostKind4((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xa;
        break;
    case 10:
        if (*(int *)(p + 0x164) == 1 && STA_NET_SendSlot1Command((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xb;
        break;
    case 12:
        if (MUS_COMM_FUNC_CheckTimingSync(p, 0x42) == 1) {
            if (*(int *)(p + 0x48) == 1) {
                if (STA_NET_NotifyHostKind5(p) == 1) *(int *)(p + 0x4c) = 0xd;
            } else *(int *)(p + 0x4c) = 0x11;
        }
        break;
    case 13:
        if (*(int *)(p + 0x168) == 1 && STA_NET_NotifyHostKind6(p) == 1) *(int *)(p + 0x4c) = 0xe;
        break;
    case 14:
        if (*(int *)(p + 0x16c) == 1 && STA_NET_SendSlot2Command((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xf;
        break;
    case 15:
        if (*(int *)(p + 0x174) == 1 && STA_NET_SendSlot3Command((u8 *)p) == 1) *(int *)(p + 0x4c) = 0x10;
        break;
    case 16:
        *(int *)(p + 0x4c) = 0x11;
        break;
    case 17:
        if (*(int *)(p + 0x178) == 1) STA_NET_IsTransferDone(p);
        break;
    case 18:
        if (MUS_COMM_FUNC_SendStatusBlock(p, (char *)(*(u32 *)(p + 0x120))) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 0x13;
            else *(int *)(p + 0x4c) = 0x15;
        }
        break;
    case 19:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct G *)p)->pl[i].a == 1) cnt++;
        if (cnt == GFL_NET_GetNegotiationNum() && MUS_COMM_FUNC_SendRecordBlock(p) == 1) *(int *)(p + 0x4c) = 0x15;
        break;
    case 20:
    case 21:
        break;
    default:
        break;
    }
    if (*(int *)(p + 0x184) == 1) {
        v = 0;
        v += ((struct G *)p)->pl[0].e;
        v += ((struct G *)p)->pl[1].e << 4;
        v += ((struct G *)p)->pl[2].e << 8;
        v += ((struct G *)p)->pl[3].e << 12;
        if (MUS_COMM_FUNC_SendCommandWait((int)p, 3, v, 0xff) == 1) *(int *)(p + 0x184) = 0;
    }
    {
        u32 sum = 0;
        n = 0;
        for (i = 0; i < 4; i++) {
            if (((struct G *)p)->pl[i].c == 1) {
                list[n] = i;
                n++;
            }
            sum += ((struct G *)p)->pl[i].d << (i * 4);
        }
        if (n != 0) {
            u32 k = random_below(n);
            sum += list[k] << 16;
            if (MUS_COMM_FUNC_SendCommandWait((int)p, 0xb, sum, 0xff) == 1) {
                for (j = 0; j < n; j++) {
                    ((struct G *)p)->pl[list[j]].c = 0;
                    ((struct G *)p)->pl[list[j]].d = 10;
                }
            }
        }
    }
    if (*(int *)(p + 0x188) == 1) {
        ok = 1;
        for (i = 0; i < 8; i++) {
            if (*(u32 *)(p + i * 4 + 0x18c) != 0xFFFF) {
                if (MUS_COMM_FUNC_SendCommandWait((int)p, 0xc, *(u32 *)(p + i * 4 + 0x18c), 0xff) == 1) *(u32 *)(p + i * 4 + 0x18c) = 0xFFFF;
                ok = 0;
            }
        }
        if (ok == 1) *(int *)(p + 0x188) = 0;
    }
    STA_NET_UpdateTransferState(p);
}
