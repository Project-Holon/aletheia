/*
 * function: UNION_MSG_GetNoReplyMsg
 * address: 0x0217EC04
 * packet: pkt_ov019_0217EC04
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02008550 0x02008550 thumb
 *   d_0218031C 0x0218031C data a2
 * Followers EC1C, EC28 and EC34 are already filed separately.
 */
typedef unsigned short u16;
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern const u16 d_0218031C[];
u16 UNION_MSG_GetNoReplyMsg(void ***ctx)
{
    return d_0218031C[func_02008550(**ctx)];
}
