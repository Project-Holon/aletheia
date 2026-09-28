/*
 * function: func_021CD64C
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
 *   func_021CCAE0  0x021CCAE0  thumb  ov093
 *   func_021CCB98  0x021CCB98  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

extern void func_021CCAE0(void *w, u16 v);
extern void func_021CCB98(void *w, s32 v);

void func_021CD64C(void *w, u8 id, ...)
{
    va_list ap;
    u16 v;
    s32 x;

    va_start(ap, id);
    v = va_arg(ap, s32);
    func_021CCAE0(w, id);
    func_021CCAE0(w, v);
    if (id == 0x5C) {
        func_021CCAE0(w, va_arg(ap, s32));
    }
    do {
        x = va_arg(ap, s32);
        func_021CCB98(w, x);
    } while (x != (s32)0xFFFF0000);
}
