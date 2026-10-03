/*
 * function: func_021C5350
 * address: 0x021C5350
 * packet: pkt_ov093_021C5350
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const entry source schedules byte arguments early; k precedes entry in declarations.
 * symbols:
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021BA1CC 0x021BA1CC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };
extern u8 *func_021B9BF0(u8 *, u8);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *, u32, ...);
extern int func_021D69B8(u8 *, u32 *, u8 *);
extern void func_021BA1CC(void *, int, u32);
int func_021C5350(u8 *p, u8 *g, const struct Entry *q)
{
    u32 i;
    int result = 0;
    u8 *a;
    int k;
    u32 value;
    int cmd;
    const struct Entry *entry;
    u32 remaining;
    for (i = 0; i < 6; i++) {
        entry = &q[i];
        if (!entry->value) continue;
        a = func_021B9BF0(g, i);
        if (func_021D59B4(a, 15) >= 100) continue;
        value = entry->value;
        cmd = entry->flag ? 0x2b : 0x2a;
        k = func_021D5440(a);
        func_021CD64C(*(void **)(p + 12), 0x5a, (u16)cmd, k, value, 0xffff0000);
        func_021CD4B0(*(void **)(p + 12), 0x3e, k, q->a, q->b, q->c, q->d, q->e, q->f);
        remaining = value;
        while (func_021D69B8(a, &remaining, p + 0x4c0)) {}
        func_021CD4B0(*(void **)(p + 12), 0x45, k, value);
        func_021BA1CC(*(void **)(p + 4), 0x1b, value);
        result = 1;
    }
    return result;
}
