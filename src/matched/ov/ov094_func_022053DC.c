/*
 * function: func_022053DC
 * address: 0x022053DC
 * packet: pkt_ov094_022053DC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: 022053DE reserves 0x28 bytes: 16 outgoing argument bytes plus
 *   a 24-byte local. Only its first 16 bytes are read/initialized here;
 *   pad10 preserves the observed allocation without naming unknown fields.
 *   Palette field reads retain the A386/A387 pools as one extern plus addend.
 * symbols:
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D5528 0x021D5528 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_02204CC0 0x02204CC0 thumb ov094
 *   func_02205F88 0x02205F88 thumb ov094
 *   func_02021848 0x02021848 thumb
 *   d_0220A386 0x0220A386 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u16 value[4]; u8 a[4], b[4]; u8 pad10[8]; } Buffer;
typedef struct { u8 first, second; } Palette;
typedef struct { char pad[0x68]; u32 lo : 19; u32 index : 2; } Flags;
extern int func_021D5448(void *);
extern u16 func_021D5528(u8 *, u8, u8 *, u8 *);
extern int func_021D5B68(void *);
extern void func_02204CC0(void *, Buffer *);
extern void func_02205F88(char *p);
extern int func_02021848(void *, u16, u16, s16, u8, u8, u16, void *);
extern const Palette d_0220A386[];
#define INDEX (((Flags *)m)->index)
#define OBJECT (*(u8 **)(m + INDEX * 4 + 0x2a4))
void func_022053DC(char *m)
{
    int i;
    Buffer buf;
    for (i = 0; i < 4; i++) {
        buf.value[i] = 0;
        buf.a[i] = 0;
        buf.b[i] = 0;
    }
    for (i = 0; i < func_021D5448(OBJECT); i++)
        buf.value[i] = func_021D5528(OBJECT, i, &buf.a[i], &buf.b[i]);
    func_02204CC0(m, &buf);
    *(u8 *)(m + 0x25f) = d_0220A386[INDEX].first;
    *(u8 *)(m + 0x260) = d_0220A386[INDEX].second;
    *(int *)(m + 0x220) = 1;
    for (i = 0; i < 4; i++) {
        if (*(int *)(m + INDEX * 16 + i * 4 + 0x2b0) == 1)
            *(int *)(m + 0x220) = 0;
    }
    if (func_021D5B68(OBJECT)) {
        for (i = 0; i < 4; i++)
            *(u8 *)(m + i + 0x25a) = 0;
        *(int *)(m + 0x220) = 0;
        func_02021848(*(void **)(m + 0x64), 2, 0x3e00, 0, 8, 8, 0, *(void **)m);
        func_02021848(*(void **)(m + 0x64), 8, 0x700, 0, 8, 8, 0, *(void **)m);
        return;
    }
    if (*(int *)(m + 0x220) == 1) {
        *(u8 *)(m + 0x25a) = 1;
        func_02205F88(m);
        func_02021848(*(void **)(m + 0x64), 2, 0x3e00, 0, 8, 8, 0, *(void **)m);
        func_02021848(*(void **)(m + 0x64), 8, 0x700, 0, 8, 8, 0, *(void **)m);
        return;
    }
    func_02021848(*(void **)(m + 0x64), 2, 0x3e00, 0, 0, 0, 0, *(void **)m);
    func_02021848(*(void **)(m + 0x64), 8, 0x700, 0, 0, 0, 0, *(void **)m);
}
