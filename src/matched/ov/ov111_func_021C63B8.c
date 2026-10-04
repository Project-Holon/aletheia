/*
 * function: func_021C63B8
 * address:  0x021C63B8
 * packet:   pkt_ov111_021C63B8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D304  0x0201D304  thumb
 *   func_021C6380  0x021C6380  thumb  ov111
 *   func_021C68F0  0x021C68F0  thumb  ov111
 *   func_021C69D4  0x021C69D4  thumb  ov111
 *   func_021C6A84  0x021C6A84  thumb  ov111
 *   func_021C6C7C  0x021C6C7C  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x28];
    u16 h28;
    u8 pad2A[0x33 - 0x2A];
    u8 b33;
    u8 pad34[0x38 - 0x34];
    u32 f38;
    u32 f3C;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 f58;
    u16 h5C;
    u16 h5E;
    u16 h60;
    u16 h62;
    u16 h64;
} Info;

typedef struct {
    u8 pad0[0x28];
    Info *info;
    u8 pad2C[0x31FC - 0x2C];
    void *f31FC;
    u8 pad3200[0x3208 - 0x3200];
    void *f3208;
    u8 pad320C[0x3214 - 0x320C];
    void *f3214;
    u8 pad3218[0x3240 - 0x3218];
    void *win[17];
    u8 pad3284[0x328C - 0x3284];
    void *f328C;
} Work;

struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_021C6380(void *a, Work *p, int x, int y, void *s, int idx);
extern void func_021C68F0(Work *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx);
extern void func_021C69D4(Work *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
extern void func_021C6A84(Work *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
extern void func_021C6C7C(Work *p, void *a, int y, const Info *info, void *s, int idx);

void func_021C63B8(Work *p, void *a, u32 sel, int y, int idx)
{
    void *s = p->f3214;
    Info *info = p->info;
    u32 w;

    switch (sel) {
    case 0:
        func_021C6380(a, p, 0, y, p->win[0], idx);
        func_021C68F0(p, a, 0x60, 0, y, s, info->h28, 5, 2, idx);
        break;
    case 1:
        func_021C6380(a, p, 0, y, p->win[1], idx);
        func_021C6C7C(p, a, y, p->info, p->f3208, idx);
        break;
    case 2:
        func_021C6380(a, p, 0, y, p->win[2], idx);
        break;
    case 3:
        func_021C69D4(p, a, 0xD8, 0, y, s, 0, idx);
        break;
    case 4:
        func_021C6380(a, p, 0, y, p->win[3], idx);
        break;
    case 5:
        if (info->b33 != 0) {
            func_021C6A84(p, a, 0xD8, 0, y, s, 0, idx);
        } else {
            w = func_0201D304(p->f328C, (u32)p->f31FC, 0);
            func_021C6380(a, p, 0xD8 - w, y, p->f328C, idx);
        }
        break;
    case 6:
        func_021C6380(a, p, 0, y, p->win[4], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f38, 9, 1, idx);
        break;
    case 7:
        func_021C6380(a, p, 0, y, p->win[5], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f3C, 9, 1, idx);
        break;
    case 8:
        func_021C6380(a, p, 0, y, p->win[6], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f40, 9, 1, idx);
        break;
    case 9:
        func_021C6380(a, p, 0, y, p->win[7], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f44, 9, 1, idx);
        break;
    case 10:
        func_021C6380(a, p, 0, y, p->win[8], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f4C, 9, 1, idx);
        break;
    case 11:
        func_021C6380(a, p, 0, y, p->win[9], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f50, 9, 1, idx);
        break;
    case 12:
        func_021C6380(a, p, 0, y, p->win[10], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f54, 9, 1, idx);
        break;
    case 13:
        func_021C6380(a, p, 0, y, p->win[11], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->f58, 5, 1, idx);
        break;
    case 14:
        func_021C6380(a, p, 0, y, p->win[12], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->h5C, 4, 1, idx);
        break;
    case 15:
        func_021C6380(a, p, 0, y, p->win[13], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->h5E, 2, 1, idx);
        break;
    case 16:
        func_021C6380(a, p, 0, y, p->win[14], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->h60, 4, 1, idx);
        break;
    case 17:
        func_021C6380(a, p, 0, y, p->win[15], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->h62, 3, 1, idx);
        break;
    case 18:
        func_021C6380(a, p, 0, y, p->win[16], idx);
        func_021C68F0(p, a, 0xD8, 8, y, s, info->h64, 4, 1, idx);
        break;
    }
}
