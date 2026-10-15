/*
 * function: Wf2dmapFriend_ShowEntryFriendCode
 * address: 0x021C84E8
 * packet: pkt_ov128_021C84E8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_GetEntryFriendKey 0x021C8388 thumb ov128
 *   Wf2dmapFriend_GetEntryIndex 0x021C87A0 thumb ov128
 *   Wf2dmapFriend_PrintMyStatus 0x021C6BCC thumb ov128
 *   Wf2dmapFriend_SetFriendCode 0x021C6B50 thumb ov128
 *   Wf2dmapFriend_PrintEntryMessage 0x021C867C thumb ov128
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long long u64;
extern unsigned long long Wf2dmapFriend_GetEntryFriendKey(s16 *p, u8 *q);
extern int Wf2dmapFriend_GetEntryIndex(s16 *);
extern void Wf2dmapFriend_PrintMyStatus(u8 *p, u8 *q, int idx, unsigned heap);
extern void Wf2dmapFriend_SetFriendCode(void **p, unsigned long long value);
extern void Wf2dmapFriend_PrintEntryMessage(u8 *, u8 *, int, int);
int Wf2dmapFriend_ShowEntryFriendCode(u8 *p, u8 *a, u8 *b, int c)
{
    u64 value = Wf2dmapFriend_GetEntryFriendKey((s16 *)p, a);
    Wf2dmapFriend_PrintMyStatus(b, a, (a + Wf2dmapFriend_GetEntryIndex((s16 *)p))[0x18], c);
    if (value != 0) {
        Wf2dmapFriend_SetFriendCode((void **)b, value);
        Wf2dmapFriend_PrintEntryMessage(p, b, 0x3c, c);
    } else {
        Wf2dmapFriend_PrintEntryMessage(p, b, 0x44, c);
    }
    return 1;
}
