
/*
 * function: func_021B88DC
 * address:  0x021B88DC
 * packet:   pkt_ov021_021B88DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * closed 2026-10-02 (share-A lane A2-09).  Three source facts turned the
 * 2026-09-27 near miss (end spilled, frame 0x54) into the image's allocation
 * (end in r7 for the whole body, frame 0x6c):
 *  - arm 93D4: flag = 0 is assigned after the 9404 call, through a local
 *    (r = 9404(dir); flag = 0; e1 = 8514(row, r, ...)); with flag = 0 ahead
 *    of the nested call, flag takes r6 and end is spilled.
 *  - arm 93D4: the e2 probe is two sequential ifs (8674, then 868C), not an
 *    else-if as in the other two-way probes of arms f08/93D4.
 *  - arms 9404/9434: each half has its own row/e locals; in arm 9434 the two
 *    spilled 8674-path lengths are block-level locals declared second-half
 *    first (the image has the first half's at the lower slot).
 * Arm-subset compiles (only f08, f08+9404, f08+9434) matched the image's
 * allocation exactly, which isolated the 93D4 arm as the cause.
 * symbols:
 *   func_021B8514  0x021B8514  thumb  ov021
 *   func_021B854C  0x021B854C  thumb  ov021
 *   func_021B8674  0x021B8674  thumb  ov021
 *   func_021B868C  0x021B868C  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   func_021B9278  0x021B9278  thumb  ov021
 *   func_021B9280  0x021B9280  thumb  ov021
 *   func_021B9338  0x021B9338  thumb  ov021
 *   func_021B93D4  0x021B93D4  thumb  ov021
 *   func_021B9404  0x021B9404  thumb  ov021
 *   func_021B9434  0x021B9434  thumb  ov021
 *   func_021B9530  0x021B9530  thumb  ov021
 *   func_021B96AC  0x021B96AC  thumb  ov021
 */

typedef struct {
    int f00;
    int f04;
    int f08;
} Ov021Seg;

typedef struct {
    int f00;
    Ov021Seg *f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    void *f24;
    void *f28;
} Ov021Mover;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7);
int func_021B8674(u8 *p, u32 *q, u32 v);
int func_021B868C(u8 *p, u32 *q, void *v);
u8 *func_021B87D8(u8 *p, u32 idx);
int func_021B9278(void *e, int a, void *map);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4);
int func_021B93D4(int dir);
int func_021B9404(int dir);
int func_021B9434(int dir);
void func_021B9530(u16 *t, u8 *p, int dx, int dy, int a6);
int func_021B96AC(u8 *a, u8 *b);

int func_021B88DC(Ov021Mover *p, int dir, int d)
{
    int end;
    Ov021Seg *seg;
    int r;

    seg = p->f04;
    end = p->f10;
    if (dir == seg->f08) {
        void *row;
        void *e0;
        void *e1;
        void *e2;
        int flag;

        row = func_021B87D8(p->f24, seg->f04);
        flag = 0;
        e0 = func_021B8514(row, dir, p->f24, p->f28, flag);
        e1 = func_021B8514(row, func_021B9434(dir), p->f24, p->f28, flag);
        e2 = func_021B8514(row, func_021B9404(dir), p->f24, p->f28, flag);
        func_021B9530(p->f28, (u8 *)p, d, 0, dir);
        if (p->f0C < end) {
            r = func_021B9280((u8 *)seg, p->f0C, end, p->f24);
            if (r >= (p->f14 < 0 ? -p->f14 : p->f14)) {
                return dir;
            }
            flag = 1;
        }
        if (e0 != 0 && flag == 0) {
            int len;
            int pos;
            func_021B96AC(row, p->f24);
            len = func_021B9278(e0, p->f1C, p->f24);
            pos = func_021B9280(e0, p->f0C - end, len, p->f24);
            r = func_021B854C((u8 *)p, e0, dir, p->f0C - end, p->f14, len, pos);
            if (r != 0) {
                return r;
            }
        }
        if (e1 != 0 && p->f14 <= 0) {
            if (func_021B8674(p->f24, e1, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, -p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, -p->f14, p->f0C - end, len, pos);
                if (r != 0) {
                    return r;
                }
            } else if (func_021B868C(p->f24, e1, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, len + p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, len + p->f14, -(p->f0C - end), len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (e2 != 0 && p->f14 >= 0) {
            if (func_021B8674(p->f24, e2, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, p->f14, -(p->f0C - end), len, pos);
                if (r != 0) {
                    return r;
                }
            } else if (func_021B868C(p->f24, e2, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, len - p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, len - p->f14, p->f0C - end, len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (flag) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        if (p->f0C <= end) {
            return dir;
        }
        p->f0C = p->f0C - d;
        return 0;
    } else if (dir == func_021B93D4(seg->f08)) {
        void *row;
        void *e1;
        void *e2;
        void *e0;
        int flag;

        row = func_021B87D8(p->f24, seg->f00);
        r = func_021B9404(dir);
        flag = 0;
        e1 = func_021B8514(row, r, p->f24, p->f28, flag);
        e2 = func_021B8514(row, func_021B9434(dir), p->f24, p->f28, flag);
        e0 = func_021B8514(row, dir, p->f24, p->f28, flag);
        func_021B9530(p->f28, (u8 *)p, -d, 0, dir);
        if (p->f0C >= 0) {
            r = func_021B9280((u8 *)seg, p->f0C, end, p->f24);
            if (r >= (p->f14 < 0 ? -p->f14 : p->f14)) {
                return dir;
            }
            flag = 1;
        }
        if (e0 != 0 && flag == 0) {
            int len;
            int pos;
            func_021B96AC(row, p->f24);
            len = func_021B9278(e0, p->f1C, p->f24);
            pos = func_021B9280(e0, len - (p->f0C < 0 ? -p->f0C : p->f0C), len, p->f24);
            r = func_021B854C((u8 *)p, e0, dir, len - (p->f0C < 0 ? -p->f0C : p->f0C), p->f14, len, pos);
            if (r != 0) {
                return r;
            }
        }
        if (e1 != 0 && p->f14 <= 0) {
            if (func_021B8674(p->f24, e1, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, -p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, -p->f14, p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            } else if (func_021B868C(p->f24, e1, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e1, p->f1C, p->f24);
                pos = func_021B9280(e1, len + p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e1, dir, len + p->f14, -p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (e2 != 0 && p->f14 >= 0) {
            if (func_021B8674(p->f24, e2, (u32)row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, p->f14, -p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            }
            if (func_021B868C(p->f24, e2, row)) {
                int len;
                int pos;
                func_021B96AC(row, p->f24);
                len = func_021B9278(e2, p->f1C, p->f24);
                pos = func_021B9280(e2, len - p->f14, len, p->f24);
                r = func_021B854C((u8 *)p, e2, dir, len - p->f14, p->f0C, len, pos);
                if (r != 0) {
                    return r;
                }
            }
        }
        if (flag) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        p->f0C = p->f0C + d;
        return 0;
    } else if (dir == func_021B9404(seg->f08)) {
        func_021B9530(p->f28, (u8 *)p, 0, d, dir);
        if (p->f14 > 0 && p->f14 % 16 == 0) {
            void *row;
            void *e;
            void *row2;
            void *e2;

            row = func_021B87D8(p->f24, seg->f00);
            e = func_021B8514(row, dir, p->f24, p->f28, 0);
            if (e != 0) {
                if (func_021B8674(p->f24, e, (u32)row)) {
                    int len;
                    int pos;
                    func_021B96AC(row, p->f24);
                    len = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, p->f14, -p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e, row)) {
                    int len;
                    int pos;
                    func_021B96AC(row, p->f24);
                    len = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, len - p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, len - p->f14, p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
            row2 = func_021B87D8(p->f24, seg->f04);
            e2 = func_021B8514(row2, dir, p->f24, p->f28, 0);
            if (e2 != 0) {
                if (func_021B8674(p->f24, e2, (u32)row2)) {
                    int len;
                    int pos;
                    func_021B96AC(row2, p->f24);
                    len = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, p->f14, end - p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e2, row2)) {
                    int len;
                    int pos;
                    func_021B96AC(row2, p->f24);
                    len = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, len - p->f14, len, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, len - p->f14, -(end - p->f0C), len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
        }
        if (p->f14 > 0 && p->f14 <= p->f18) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        return dir;
    } else if (dir == func_021B9434(seg->f08)) {
        func_021B9530(p->f28, (u8 *)p, 0, -d, dir);
        if (p->f14 < 0 && (p->f14 < 0 ? -p->f14 : p->f14) % 16 == 0) {
            void *row;
            void *e;
            void *row2;
            void *e2;
            int lenB;
            int lenA;

            row = func_021B87D8(p->f24, seg->f00);
            e = func_021B8514(row, dir, p->f24, p->f28, 0);
            if (e != 0) {
                if (func_021B8674(p->f24, e, (u32)row)) {
                    int pos;
                    func_021B96AC(row, p->f24);
                    lenA = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, (p->f14 < 0 ? -p->f14 : p->f14), lenA, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, (p->f14 < 0 ? -p->f14 : p->f14), p->f0C, lenA, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e, row)) {
                    int len;
                    int pos;
                    func_021B96AC(row, p->f24);
                    len = func_021B9278(e, p->f1C, p->f24);
                    pos = func_021B9280(e, len - (p->f14 < 0 ? -p->f14 : p->f14), len, p->f24);
                    r = func_021B854C((u8 *)p, e, dir, len - (p->f14 < 0 ? -p->f14 : p->f14), -p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
            row2 = func_021B87D8(p->f24, seg->f04);
            e2 = func_021B8514(row2, dir, p->f24, p->f28, 0);
            if (e2 != 0) {
                if (func_021B8674(p->f24, e2, (u32)row2)) {
                    int pos;
                    func_021B96AC(row2, p->f24);
                    lenB = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, (p->f14 < 0 ? -p->f14 : p->f14), lenB, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, (p->f14 < 0 ? -p->f14 : p->f14), -(end - p->f0C), lenB, pos);
                    if (r != 0) {
                        return r;
                    }
                }
                if (func_021B868C(p->f24, e2, row2)) {
                    int len;
                    int pos;
                    func_021B96AC(row2, p->f24);
                    len = func_021B9278(e2, p->f1C, p->f24);
                    pos = func_021B9280(e2, len - (p->f14 < 0 ? -p->f14 : p->f14), len, p->f24);
                    r = func_021B854C((u8 *)p, e2, dir, len - (p->f14 < 0 ? -p->f14 : p->f14), end - p->f0C, len, pos);
                    if (r != 0) {
                        return r;
                    }
                }
            }
        }
        if (p->f14 < 0 && (p->f14 < 0 ? -p->f14 : p->f14) <= p->f18) {
            return func_021B9338((u8 *)p, (u8 *)seg, end, dir);
        }
        return dir;
    }
    return 0;
}
