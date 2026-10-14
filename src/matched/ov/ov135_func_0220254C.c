/*
 * function: WORLDTRADE_ADAPTER_CreateMail
 * address:  0x0220254C
 * packet:   pkt_0220254C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02019B58  0x02019B58  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_020307B0  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_02019B58(void *mon);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32 func_0202136C(u16 v);
extern void *MAIL_Create(int a0);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern u32 func_020307B0(void *p);
extern void STRBUF_Delete(struct U16Vec *vec);

void WORLDTRADE_ADAPTER_CreateMail(void *mon, u32 heap)
{
    void *bank;
    void *str;
    void *buf;
    u32 id;

    id = (heap & 0x7FFF) | 0x8000;
    bank = func_02045B38(0, 2, 0x51, (u16)id);
    str = func_02045EC0(bank, 0xF);
    MSGDATA_Delete(bank);
    func_02019B58(mon);
    POKE_TOOL_SetPartyValue(mon, 0x8E, (u32)STRBUF_GetChars(str));
    if (func_0202136C((u16)POKE_TOOL_GetPartyValue(mon, 6, 0)) != 0) {
        buf = MAIL_Create((u16)id);
        POKE_TOOL_GetPartyValue(mon, 0xA7, (u32)buf);
        func_02008F88(buf, STRBUF_GetChars(str));
        POKE_TOOL_SetPartyValue(mon, 0xA7, (u32)buf);
        func_020307B0(buf);
    }
    STRBUF_Delete(str);
}
