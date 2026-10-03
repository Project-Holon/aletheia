/*
 * function: func_021C83DC
 * address: 0x021C83DC
 * packet: pkt_ov128_021C83DC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes at 0x021C846E precede labelled 021C8470.
 * symbols:
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_021C8388 0x021C8388 thumb ov128
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long long u64;
typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;
extern void *func_0201283C(void *);
typedef unsigned int   u32;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern int func_021C87A0(s16 *);
extern u64 func_021C8388(u8 *, u8 *);
extern void *func_02027778(TextConfig *,void *);
void func_021C83DC(u8 *p, u8 *a, void *unused, int heap)
{
    TextConfig config;
    void *q = func_0201283C(*(void **)(a + 4));
    int result = func_02009864(q, (a + func_021C87A0((s16 *)p))[24], 9);
    config.heap = heap;
    config.count = 4;
    if (result == 2) {
        config.entries = p + (func_021C8388(p, a) != 0 ? 0x148 : 0x118);
        *(int *)(p + 0x198) = 1;
    } else {
        config.entries = p + 0x118;
        *(int *)(p + 0x198) = 0;
    }
    config.mode = 1;
    config.x = 32; config.y = 24; config.a = 17; config.b = 3;
    *(void **)(p + 0x194) = func_02027778(&config, *(void **)(p + 0x190));
}
