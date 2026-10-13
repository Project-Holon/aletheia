/*
 * function: OPTION_MENU_PrintHelpMessage
 * address:  0x021BAEC4
 * packet:   pkt_ov068_021BAEC4
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *   func_02040588  0x02040588  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   OPTION_MENU_PrintTextFromBank  0x021BA28C  thumb  ov068
 */

typedef unsigned int u32;
typedef signed short s16;

typedef unsigned char  u8;
extern void func_0207D658(u32 addr, int plane, int brightness);
struct MsgBank;
struct Rec;
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void OPTION_MENU_PrintTextFromBank(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4);

void OPTION_MENU_PrintHelpMessage(void *a, u32 b, u32 c)
{
    void *h;

    func_0207D658((u32)((void *)0x04000050), 0x17, 8);
    func_02040588(3, 1);
    h = func_02045B38(0, 3, 0x9e, 0x801C);
    OPTION_MENU_PrintTextFromBank(a, (u32)h, b, c, 1);
    MSGDATA_Delete(h);
}
