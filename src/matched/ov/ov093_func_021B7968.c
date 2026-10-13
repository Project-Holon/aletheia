/*
 * function: BTL_MAIN_SeqExchangePlayers
 * address: 0x021B7968
 * packet: pkt_ov093_021B7968
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the bank string object is its own inner-block local declared
 *   before the copy index (void *str; int j;); reusing the outer s or
 *   declaring str after j swapped r4/r5 (17 bytes).
 * leaves: ov093 021D49B0 (+0x1E4) and 021D49CC (+0x1EC) resolve through
 *   their own shards pkt_ov093_021D49B0/pkt_ov093_021D49CC (W82 R11).
 * symbols:
 *   BTL_NET_HasCommError 0x021D4270 thumb ov093
 *   BTL_NET_BeginSync 0x021D4AF4 thumb ov093
 *   BTL_NET_PollSync 0x021D4B18 thumb ov093
 *   BTL_NET_SendPlayerInfo 0x021D4808 thumb ov093
 *   BTL_NET_IsPlayerInfoReceived 0x021D4898 thumb ov093
 *   BTL_NET_GetPlayerInfo 0x021D48CC thumb ov093
 *   BTL_NET_SendRelayedPlayerInfo 0x021D4908 thumb ov093
 *   BTL_NET_IsRelayedPlayerInfoReceived 0x021D49B0 thumb ov093
 *   BTL_NET_GetRelayedPlayerInfo 0x021D49CC thumb ov093
 *   BTL_NET_FreeRelayedPlayerInfo 0x021D49E0 thumb ov093
 *   BTL_NET_FreeAfterPlayerInfoUse 0x021D4A04 thumb ov093
 *   BTL_TRAINER_SLOT_InitPlayer 0x021B9E38 thumb ov093
 *   BTL_TRAINER_SLOT_InitFromPacket 0x021B9EF0 thumb ov093
 *   BTL_MAIN_CopyClientPlayerStatus 0x021BA670 thumb ov093
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020084D4 0x020084D4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { START, END = 15 } Index;
typedef struct { u8 a:1; u8 b:1; u8 c:1; } Bits;
extern int BTL_NET_HasCommError(void);
struct A;
struct B;
extern void BTL_NET_BeginSync(int a);
extern int BTL_NET_PollSync(int a);
extern int BTL_NET_SendPlayerInfo(u32 a);
extern int BTL_NET_IsPlayerInfoReceived(void);
extern void *BTL_NET_GetPlayerInfo(u8);
extern u32 BTL_NET_SendRelayedPlayerInfo(void *);
extern int BTL_NET_IsRelayedPlayerInfoReceived(void);
extern void *BTL_NET_GetRelayedPlayerInfo(void);
extern void BTL_NET_FreeRelayedPlayerInfo(void);
extern void BTL_NET_FreeAfterPlayerInfoUse(void);
extern void BTL_TRAINER_SLOT_InitPlayer(char *p, int a, int b);
extern void BTL_TRAINER_SLOT_InitFromPacket(struct A *p, const struct B *src);
extern void BTL_MAIN_CopyClientPlayerStatus(char *p, u8 k, void *dst);
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
int BTL_MAIN_SeqExchangePlayers(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    u32 offset;
    void *bank;
    void *s;
    void *s2;
    u16 *src;
    u16 *dst;
    u16 buf[16];
    int k;
    q = *(u8 **)p;
    if (BTL_NET_HasCommError()) {
        ((Bits *)(p + 0x473))->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        BTL_NET_BeginSync((u8)4);
        ++*state;
        break;
    case 1:
        if (BTL_NET_PollSync((u8)4)) ++*state;
        break;
    case 2:
        if (BTL_NET_SendPlayerInfo((u32)(*(void **)(p + 0xc0)))) ++*state;
        break;
    case 3:
        if (BTL_NET_IsPlayerInfoReceived()) {
            for (i = 0; i < p[0x46b]; ++i) {
                s = BTL_NET_GetPlayerInfo(i);
                if (s) {
                    offset = i * 0x28;
                    BTL_TRAINER_SLOT_InitPlayer((char *)(p + 0x20 + offset),*(u16 *)(p + 0x468),(int)s);
                    if (i != p[0x46c] && ((Bits *)(q + 0xc1))->c) {
                        void *str;
                        int j;
                        bank = func_02045B38(0,2,0x51,*(u16 *)(p + 0x468));
                        str = func_02045EC0(bank,15);
                        MSGDATA_Delete(bank);
                        src = STRBUF_GetChars(str);
                        for (j = START; j < END && (u32)j < STRBUF_GetLength(str); ++j) buf[j] = src[j];
                        dst = buf;
                        dst[j] = STRBUF_GetEosChar();
                        STRBUF_Delete(str);
                        func_020084D4((u32)(*(void **)(p + offset + 0x20)),dst);
                        STRBUF_Delete(*(void **)(p + offset + 0x24));
                        bank = func_02045B38(0,2,0x51,*(u16 *)(p + 0x468));
                        s2 = func_02045EC0(bank,15);
                        MSGDATA_Delete(bank);
                        *(void **)(p + offset + 0x24) = s2;
                    }
                    BTL_MAIN_CopyClientPlayerStatus((char *)p,i,*(void **)(p + offset + 0x20));
                }
            }
            ++*state;
        }
        break;
    case 4:
        if (!p[0x471]) *state = 10;
        else { p[0x470] = 0; ++*state; }
        break;
    case 5:
        BTL_NET_BeginSync((u8)(p[0x470] + 8));
        ++*state;
        break;
    case 6:
        if (BTL_NET_PollSync((u8)(p[0x470] + 8))) ++*state;
        break;
    case 7:
        k = 1;
        if (p[0x470]) k = 3;
        p[0x472] = k;
        if (p[0x46e] && !BTL_NET_SendRelayedPlayerInfo(*(void **)(q + p[0x472] * 4 + 0x48))) break;
        ++*state;
    case 8:
        if (BTL_NET_IsRelayedPlayerInfoReceived()) {
            BTL_TRAINER_SLOT_InitFromPacket((struct A *)(p + 0x20 + p[0x472] * 0x28),BTL_NET_GetRelayedPlayerInfo());
            BTL_NET_FreeRelayedPlayerInfo();
            ++p[0x470];
            if (p[0x470] >= p[0x471]) *state = 10;
            else *state = 5;
        }
        break;
    case 10:
        BTL_NET_FreeAfterPlayerInfoUse();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}
