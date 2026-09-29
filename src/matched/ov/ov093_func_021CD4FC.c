/*
 * function: func_021CD4FC
 * address:  0x021CD4FC
 * packet:   pkt_ov093_021CD4FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021EFF14  0x021EFF14  data
 *   data_021F3B44  0x021F3B44  data
 *   func_021CCC0C  0x021CCC0C  thumb  ov093
 *   func_021CCAE0  0x021CCAE0  thumb  ov093
 *   func_021CCAA8  0x021CCAA8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    u32 wpos;
    u32 rpos;
} Buf;

extern u8 data_021EFF14[];
extern int data_021F3B44[];
extern void func_021CCC0C(void *w, u32 id, int cmd, s32 *a);
extern void func_021CCAE0(void *w, u16 v);
extern void func_021CCAA8(void *w, u8 v);

u32 func_021CD4FC(Buf *w, u32 id)
{
    u8 cmd;
    u8 n;
    u8 i;
    u8 len;
    u16 pos;

    cmd = data_021EFF14[id];
    n = cmd & 0xf;
    i = 0;
    if (n != 0) {
        do {
            data_021F3B44[i] = 0;
            i++;
        } while (i < n);
    }
    pos = w->wpos;
    func_021CCC0C(w, id, cmd, data_021F3B44);
    len = w->wpos - pos;
    w->wpos = pos;
    func_021CCAE0(w, 0x5f);
    func_021CCAA8(w, len - 3);
    w->wpos = pos + len;
    return pos;
}
