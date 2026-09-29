/*
 * function: func_021C99A0
 * address:  0x021C99A0
 * packet:   pkt_ov093_021C99A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C5DAC  0x021C5DAC  thumb  ov093
 *   func_021C5EFC  0x021C5EFC  thumb  ov093
 *   func_021C5E48  0x021C5E48  thumb  ov093
 *   func_021C5F98  0x021C5F98  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Msg {
    u16 a;
    u16 kind : 8;
    u16 n : 7;
    u16 flag : 1;
    u8 data[0x1C];
    u32 w20;
};

extern void func_021C5DAC(void *w, u32 a, u32 n, const void *d);
extern void func_021C5EFC(void *w, u32 a, u32 n, const void *d);
extern void func_021C5E48(void *w, u32 a, u32 x, u32 n, const void *d);
extern void func_021C5F98(void *w, u32 a, u32 x, u32 n, const void *d);

int func_021C99A0(void *w, const struct Msg *m)
{
    if (!m->flag) {
        switch (m->kind) {
        case 1:
            func_021C5DAC(w, m->a, m->n, m->data);
            return 1;
        case 2:
            func_021C5EFC(w, m->a, m->n, m->data);
            return 1;
        }
    } else {
        u16 x = m->w20;
        switch (m->kind) {
        case 1:
            func_021C5E48(w, m->a, x, m->n, m->data);
            return 1;
        case 2:
            func_021C5F98(w, m->a, x, m->n, m->data);
            return 1;
        }
    }
    return 0;
}
