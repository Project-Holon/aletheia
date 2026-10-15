/*
 * function: B_PLIST_MAIN_ConfirmSelect
 * address: 0x0220F7C4
 * packet: pkt_ov198_0220F7C4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02045CAC has no witness; owned by the integrator. No overlay leaves filed.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_ClearAndPrintStream 0x0220E13C thumb ov198
 *   B_PLIST_DRAW_FormatRowWord 0x0220E1D4 thumb ov198
 *   B_PLIST_MAIN_ClearSelection 0x02211944 thumb ov198
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 low:7; u8 high:1; } Flag;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_ClearAndPrintStream(u8 *);
extern void B_PLIST_DRAW_FormatRowWord(u8 *);
extern void B_PLIST_MAIN_ClearSelection(u8 **);
extern u32 FILE_UTIL_Get_0FE4(void *,u32,u32);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
int B_PLIST_MAIN_ConfirmSelect(u8 *p)
{
    u8 *q = *(u8 **)p;
    if (((Flag *)(p+B_PLIST_MAIN_GetOrderIndex(p,q[32])*76))[27].high != 0) {
        MSGDATA_ReadString(*(void **)(p+0x1ea0),91,*(void **)(p+0x1ea8));
        B_PLIST_DRAW_ClearAndPrintStream(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        B_PLIST_MAIN_ClearSelection((u8 **)p);
        return 23;
    }
    if ((q+B_PLIST_MAIN_GetOrderIndex(p,q[32]))[56] != 0) {
        B_PLIST_DRAW_FormatRowWord(p);
        B_PLIST_DRAW_ClearAndPrintStream(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        B_PLIST_MAIN_ClearSelection((u8 **)p);
        return 23;
    }
    if (FILE_UTIL_Get_0FE4((void *)*(u16 *)(q+36),39,*(u16 *)(q+16)) != 0 &&
        FILE_UTIL_Get_0FE4((void *)*(u16 *)(q+36),40,*(u16 *)(q+16)) == 0) {
        *(u32 *)(p+0x217c) = 18;
        return 29;
    }
    q[72] = B_PLIST_MAIN_GetOrderIndex(p,q[32]);
    return 31;
}
