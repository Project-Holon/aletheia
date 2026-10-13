/*
 * function: BTL_SERVER_CMD_PushVariable
 * address:  0x021CD64C
 * packet:   pkt_ov093_021CD64C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_WriteU16  0x021CCAE0  thumb  ov093
 *   BTL_SERVER_CMD_WriteU32  0x021CCB98  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

extern void BTL_SERVER_CMD_WriteU16(void *w, u16 v);
extern void BTL_SERVER_CMD_WriteU32(void *w, s32 v);

void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...)
{
    va_list ap;
    u16 v;
    s32 x;

    va_start(ap, id);
    v = va_arg(ap, s32);
    BTL_SERVER_CMD_WriteU16(w, id);
    BTL_SERVER_CMD_WriteU16(w, v);
    if (id == 0x5C) {
        BTL_SERVER_CMD_WriteU16(w, va_arg(ap, s32));
    }
    do {
        x = va_arg(ap, s32);
        BTL_SERVER_CMD_WriteU32(w, x);
    } while (x != (s32)0xFFFF0000);
}
