/*
 * function: func_021CC5D8
 * address:  0x021CC5D8
 * packet:   pkt_ov021_021CC5D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: reads a mode byte and a result variable, then stores one of two values from the save-data block selected by the mode.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1A4  0x0200C1A4  thumb
 *   func_0200C184  0x0200C184  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x14];
    u8 *pc;
} ScriptVM;

extern u16 *func_02159AE8(ScriptVM *vm, void *ctx);
extern void *func_0215A5E4(void *ctx);
extern void *func_02012EBC(void *p);
extern void *func_0200C0F0(void *p);
extern u16 func_0200C1A4(void *p);
extern u16 func_0200C184(void *p);

int func_021CC5D8(ScriptVM *vm, void *ctx)
{
    u8 mode;
    u16 *dst;
    void *p;

    mode = *vm->pc;
    vm->pc++;
    dst = func_02159AE8(vm, ctx);
    p = func_0200C0F0(func_02012EBC(func_0215A5E4(ctx)));

    switch (mode) {
    case 0:
        *dst = func_0200C1A4(p);
        break;
    case 1:
        *dst = func_0200C184(p);
        break;
    }
    return 0;
}
