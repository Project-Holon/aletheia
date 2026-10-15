/*
 * function: BR_BTN_CreateFromMessage
 * address: 0x021FB378
 * packet: pkt_ov186_021FB378
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB3BA..021FB3BC is two zero alignment bytes.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BR_BTN_CreateObject 0x021FB3BC thumb ov186
 */
typedef unsigned int   u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BR_BTN_CreateObject(void *, void *, int, int, int, int, int, void *, unsigned short);
void *BR_BTN_CreateFromMessage(void *ctx, int file, int a, int b, int c, int d, int e, int archive, void *config, unsigned short heap)
{
    void *data;
    void *result;
    data = func_02045EC0((struct MsgBank *)archive, file);
    result = BR_BTN_CreateObject(ctx, data, a, b, c, d, e, config, heap);
    STRBUF_Delete(data);
    return result;
}
