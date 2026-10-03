/*
 * unit: yes
 * function: func_021D71D8, func_021D72EC, func_021D72F8
 * address: 0x021D71D8
 * packet: pkt_ov125_021D71D8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8D28 0x021D8D28 data a4
 *   func_021D85E8 0x021D85E8 arm ov125
 *   func_021D85F4 0x021D85F4 arm ov125
 *   func_02034714 0x02034714 arm
 *   func_021D732C 0x021D732C thumb ov125
 *   func_021D7354 0x021D7354 thumb ov125
 *   func_021D73B8 0x021D73B8 thumb ov125
 *   func_021D73F0 0x021D73F0 thumb ov125
 *   func_021D74B4 0x021D74B4 thumb ov125
 *   func_021D7520 0x021D7520 thumb ov125
 *   func_021D7064 0x021D7064 thumb ov125
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned short u16;
extern char d_021D8D28[];
extern u16 *func_021D85E8(void);
extern void func_021D85F4(void);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021D732C(char *, const u16 *);
extern int func_021D7354(char *, const u16 *);
extern int func_021D73B8(char *, const u16 *);
extern int func_021D73F0(char *, const u16 *);
extern int func_021D74B4(char *, const u16 *);
extern int func_021D7520(char *, const u16 *);
extern int func_021D7064(char *, const u16 *);
extern void MI_CpuFill8(void *, int, unsigned int);
int func_021D71D8(char *p)
{
    const u16 *state;
    int result = 1;
    state = func_021D85E8();
    func_021D85F4();
    if (*(int *)(p + 0x3dc) != state[0]) func_02034714(d_021D8D28, 0, d_021D8D28);
    *(int *)(p + 0x3f0) = 0;
    switch (state[0]) {
    case 0: break;
    case 21000:
        result = func_021D732C(p, state);
        *(int *)(p + 0x3f0) = *(int *)(p + 0x14c);
        break;
    case 21001:
        result = func_021D7354(p, state);
        *(int *)(p + 0x3f0) = *(int *)(p + 0x150);
        break;
    case 22000:
        result = func_021D73B8(p, state);
        *(int *)(p + 0x3f0) = *(int *)(p + 0x154);
        if (result == 1) *(void **)(p + 0x3fc) = (void *)func_021D7064;
        break;
    case 22001:
        result = func_021D73F0(p, state);
        *(int *)(p + 0x3f0) = *(int *)(p + 0x158);
        break;
    case 22002:
        result = func_021D74B4(p, state);
        *(int *)(p + 0x3f0) = *(int *)(p + 0x15c);
        break;
    case 22003:
        result = func_021D7520(p, state);
        *(int *)(p + 0x3f0) = *(int *)(p + 0x160);
        break;
    }
    if (result == 0) {
        *(int *)(p + 0x168) = 2;
        *(int *)(p + 0x16c) = state[0];
        *(int *)(p + 0x170) = state[1];
        *(int *)(p + 0x164) = 1;
    } else *(int *)(p + 0x164) = 0;
    return result;
}
int func_021D72EC(char *p, int **out)
{
    *out = (int *)(p + 0x164);
    return *(int *)(p + 0x164);
}
void func_021D72F8(char *p)
{
    MI_CpuFill8(p + 0x164, 0, 16);
}
