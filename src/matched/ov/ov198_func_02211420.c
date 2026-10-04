/*
 * function: func_02211420
 * address: 0x02211420
 * packet: pkt_ov198_02211420
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022113B8 0x022113B8 thumb ov198
 *   func_0221139C 0x0221139C thumb ov198
 *   func_022113FC 0x022113FC thumb ov198
 *   func_022110A4 0x022110A4 thumb ov198
 *   func_0220F2DC 0x0220F2DC thumb ov198
 *   data_02212550 0x02212550 data ov198
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern u8 data_02212550[];
extern struct WinMgr *func_0202C9B4(u32 a, u32 n, u16 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 a, u32 b, u32 c);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, void *src);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern int func_0202CE40(struct WinMgr *mgr, u32 idx);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void *func_02030734(u16 heap, u32 size, u32 c, void *d, u32 e);
extern void func_020307B0(void *);
extern void func_022113B8(u8 *dst, unsigned bg, unsigned which);
extern void func_0221139C(u8 *, u8 *, unsigned);
extern void func_022113FC(u8 *p, int a, int b);
extern void func_022110A4(u8 *p, int a, int b);
extern void func_0220F2DC(u8 *p, int a, int b);

#define MGR (*(struct WinMgr **)(p + 0x2194))

int func_02211420(u8 *p)
{
    s8 xy[4];
    s8 pos[4];
    s8 pos2[4];
    switch (p[0x1e98]) {
    case 0: {
        u8 *buf;
        MGR = func_0202C9B4(2, 4, *(u16 *)(*(u8 **)p + 0x10));
        func_0202CA3C(MGR, 0, 5, 0x10, 6);
        func_0202CA3C(MGR, 1, 6, 0x10, 6);
        func_0202CA3C(MGR, 2, 5, 0x10, 6);
        func_0202CA3C(MGR, 3, 6, 0x10, 6);
        buf = func_02030734((u16)(0x8000 | (*(u16 *)(*(u8 **)p + 0x10) & 0x7fff)), 0xc0, 0, data_02212550, 0xb89);
        func_022113B8(buf, 5, p[0x2499]);
        func_0202CAC4(MGR, 0, buf);
        func_022113B8(buf, 6, p[0x2499]);
        func_0202CAC4(MGR, 1, buf);
        func_022113B8(buf, 5, p[0x249a]);
        func_0202CAC4(MGR, 2, buf);
        func_022113B8(buf, 6, p[0x249a]);
        func_0202CAC4(MGR, 3, buf);
        func_020307B0(buf);
        func_0221139C((u8 *)&xy[1], (u8 *)&xy[0], p[0x2499]);
        func_0202CB4C(MGR, 0, xy[1], xy[0]);
        func_0202CB4C(MGR, 1, xy[1], xy[0]);
        func_0221139C((u8 *)&xy[1], (u8 *)&xy[0], p[0x249a]);
        func_0202CB4C(MGR, 2, xy[1], xy[0]);
        func_0202CB4C(MGR, 3, xy[1], xy[0]);
        func_0202CD94(MGR);
        p[0x1e98]++;
        break;
    }
    case 1:
        if (p[0x2499] & 1) {
            func_0202CD64(MGR, 0, 1, 0, 0x10);
            func_0202CD64(MGR, 1, 1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 0, -1, 0, 0x10);
            func_0202CD64(MGR, 1, -1, 0, 0x10);
        }
        if (p[0x249a] & 1) {
            func_0202CD64(MGR, 2, 1, 0, 0x10);
            func_0202CD64(MGR, 3, 1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 2, -1, 0, 0x10);
            func_0202CD64(MGR, 3, -1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 2: {
        func_0202CD94(MGR);
        func_022113FC(p, p[0x2499], 0);
        func_022113FC(p, p[0x249a], 0);
        func_0202CF98(MGR, 0, &pos[3], &pos[2]);
        func_0202CF98(MGR, 2, &pos[1], &pos[0]);
        if (func_0202CE40(MGR, 0) != 0) break;
        func_022110A4(p, p[0x2499], p[0x249a]);
        func_0202CB4C(MGR, 0, pos[1], pos[0]);
        func_0202CB4C(MGR, 1, pos[1], pos[0]);
        func_0202CB4C(MGR, 2, pos[3], pos[2]);
        func_0202CB4C(MGR, 3, pos[3], pos[2]);
        func_0220F2DC(p, p[0x2499], p[0x249a]);
        p[0x1e98]++;
        break;
    }
    case 3:
        func_0202CD94(MGR);
        if (p[0x249a] & 1) {
            func_0202CD64(MGR, 0, -1, 0, 0x10);
            func_0202CD64(MGR, 1, -1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 0, 1, 0, 0x10);
            func_0202CD64(MGR, 1, 1, 0, 0x10);
        }
        if (p[0x2499] & 1) {
            func_0202CD64(MGR, 2, -1, 0, 0x10);
            func_0202CD64(MGR, 3, -1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 2, 1, 0, 0x10);
            func_0202CD64(MGR, 3, 1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 4: {
        func_0202CD94(MGR);
        func_022113FC(p, p[0x2499], 1);
        func_022113FC(p, p[0x249a], 1);
        func_0202CF98(MGR, 0, &pos2[3], &pos2[2]);
        func_0202CF98(MGR, 2, &pos2[1], &pos2[0]);
        if (func_0202CE40(MGR, 0) == 0) p[0x1e98]++;
        break;
    }
    case 5:
        func_0202CA0C(MGR);
        MGR = 0;
        p[0x1e98] = 0;
        return 0;
    }
    return 1;
}
