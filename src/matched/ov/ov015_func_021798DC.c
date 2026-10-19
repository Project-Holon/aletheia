/*
 * function: IRCNET_SendPacket
 * address:  0x021798DC
 * packet:   pkt_ov015_021798DC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gIrcNetAssertText     0x0217AAAC  data   ov015  a1
 *   gIrcNetWork     0x0217AAC0  data   ov015  a4
 *   d_0217AAD2     0x0217AAD2  data   ov015  a1
 *   d_0217AAC6     0x0217AAC6  data   ov015  a1
 *   d_0217AAC4     0x0217AAC4  data   ov015  a1
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   IRC_Send  0x0217A148  arm    ov015
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct s_aac0 {
    u8 pad0[4];
    u16 h4;
    u8 b6;
    u8 b7;
};

extern u8 gIrcNetAssertText[];
extern struct s_aac0 gIrcNetWork;
extern u8 d_0217AAD2[];
extern u8 d_0217AAC6[];
extern u8 d_0217AAC4[];

extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern void MI_CpuCopy8(void *dst, void *src, int n);
typedef unsigned int   u32;
extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);
extern void IRC_Send(int a0, int a1, int a2);

void IRCNET_SendPacket(void *dst, int n, u8 a, u8 b)
{
    if ((unsigned)n >= 0xA6)
        func_02034714((const char *)gIrcNetAssertText, 0, (const char *)gIrcNetAssertText);
    gIrcNetWork.b6 = a;
    gIrcNetWork.b7 = b;
    if (dst != 0)
        MI_CpuCopy8(dst, d_0217AAD2, 0xA6);
    gIrcNetWork.h4 = GF_STANDARD_CalcCrc16(d_0217AAC6, n + 12);
    IRC_Send((int)d_0217AAC4, (u8)(n + 14), a);
}
