/*
 * function: func_021CD4B0
 * address:  0x021CD4B0
 * packet:   pkt_ov093_021CD4B0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CCC0C  0x021CCC0C  thumb  ov093
 *   data_021EFF14  0x021EFF14  data  ov093
 *   data_021F3B44  0x021F3B44  data  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

extern const u8 data_021EFF14[];
extern s32 data_021F3B44[];
extern void func_021CCC0C(void *w, u32 id, int cmd, s32 *a);
void func_021CD4B0(void *w, volatile u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = data_021EFF14[id];
    u32 n = cmd & 0xF;
    va_start(ap, id);
    for (; i < n; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    func_021CCC0C(w, id, cmd, data_021F3B44);
}