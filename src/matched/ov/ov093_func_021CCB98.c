/*
 * function: func_021CCB98
 * address:  0x021CCB98
 * packet:   pkt_ov093_021CCB98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021F3A84  0x021F3A84  data
 *   func_02034714  0x02034714  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[0xBB5];
} Buf;

extern char data_021F3A84[];
extern void func_02034714(void *a, int b, void *c);

void func_021CCB98(Buf *w, u32 v)
{
    if (w->wpos >= 0xBB5) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 24;
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}
