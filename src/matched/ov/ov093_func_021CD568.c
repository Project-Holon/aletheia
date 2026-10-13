/*
 * function: BTL_SERVER_CMD_FillReserved
 * address:  0x021CD568
 * packet:   pkt_ov093_021CD568
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadU16  0x021CCB18  thumb  ov093
 *   BTL_SERVER_CMD_ReadU8  0x021CCAD4  thumb  ov093
 *   BTL_SERVER_CMD_WriteCommand  0x021CCC0C  thumb  ov093
 *   gBtlServerCmdLayouts  0x021EFF14  data
 *   gBtlServerCmdArgBuffer  0x021F3B44  data
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

typedef struct {
    u32 wpos;
    u32 rpos;
} Buf;

extern const u8 gBtlServerCmdLayouts[];
extern s32 gBtlServerCmdArgBuffer[];
extern u16 BTL_SERVER_CMD_ReadU16(void *r);
extern u8 BTL_SERVER_CMD_ReadU8(u8 *p);
extern void BTL_SERVER_CMD_WriteCommand(void *w, u32 id, int cmd, s32 *a);

void BTL_SERVER_CMD_FillReserved(Buf *w, u32 x, u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = gBtlServerCmdLayouts[id];
    u32 n = cmd & 0xF;
    u16 pos;

    va_start(ap, id);
    for (; i < n; i++) {
        gBtlServerCmdArgBuffer[i] = va_arg(ap, s32);
    }
    pos = w->rpos;
    w->rpos = x;
    BTL_SERVER_CMD_ReadU16(w);
    BTL_SERVER_CMD_ReadU8((u8 *)w);
    w->rpos = pos;
    if (id != 0x5f) {
        pos = w->wpos;
        w->wpos = x;
        BTL_SERVER_CMD_WriteCommand(w, id, cmd, gBtlServerCmdArgBuffer);
        w->wpos = pos;
    }
}
