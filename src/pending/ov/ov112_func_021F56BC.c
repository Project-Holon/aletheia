/*
 * function: func_021F56BC
 * address:  0x021F56BC
 * packet:   pkt_ov112_021F56BC
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; func_021F65EC;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two func_021F5EDC calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: func_021F5EDC (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * symbols:
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_0207B67C 0x0207B67C arm
 *   func_02082B60 0x02082B60 arm
 *   func_0207ADE8 0x0207ADE8 arm
 *   func_0207B5C0 0x0207B5C0 arm
 *   func_0207BE14 0x0207BE14 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D8FC 0x0207D8FC arm
 *   func_0207D888 0x0207D888 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021F660C 0x021F660C thumb ov112
 *   func_021F65EC 0x021F65EC thumb ov112
 *   func_021F5EDC 0x021F5EDC thumb ov112
 *   d_02148D8C 0x02148D8C data
 *   d_02148D98 0x02148D98 data
 *   d_02148DA4 0x02148DA4 data
 *   d_021F8310 0x021F8310 data ov112
 *   d_021F831C 0x021F831C data ov112
 *   d_021F8304 0x021F8304 data ov112
 *   d_02148B98 0x02148B98 data
 *   d_020A1B38 0x020A1B38 data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef long long      s64;

#define REG(a) (*(volatile u32 *)(a))

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 id;
    u16 rot;
    int sx;
    int sy;
    s16 dx;
    s16 dz;
} Pose;

typedef struct {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
    u8 parts[8];
} Ent;

typedef struct {
    u32 f0, f4;
    u32 x, z;
    u32 f10;
} Part;

typedef struct {
    s16 v[0x38];
} Big;

extern const s16 d_020A1B38[];
extern const Vec d_02148D8C, d_02148D98, d_02148DA4;
extern const Vec d_021F8310, d_021F831C, d_021F8304;
extern const u8 d_02148B98[];

extern void func_0207D7C4(const Vec *a, const Vec *b, const Vec *c, int d);
extern void func_0207B67C(const void *a, void *m);
extern void func_02082B60(void *a, void *b);
extern void func_0207ADE8(void *a, void *b);
extern void func_0207B5C0(void *m);
extern void func_0207BE14(const void *a, void *b, void *c);
extern int func_0207C768(int a, int b);
extern void func_0207D8FC(void *m);
extern void func_0207D888(int s, int c);
extern void func_0207AF38(void *m, int s, int c);
extern void func_0207B51C(void *v, void *m, void *out);
extern void func_0207CA00(void *a, void *b, void *c);
extern void func_021F660C(const int *p, const int *m, u32 *out, u32 *w);
extern void func_021F65EC(void);
extern void func_021F5EDC(char *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, Pose *q, Pose *r,
                          int j, int flag, void *w, int h);

static inline int RoundF(int v)
{
    return (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f);
}

static inline void LoadPose(Pose *r, char *src, int one)
{
    char *q = *(char **)src;
    u32 kind = (u16)*(u32 *)(*(char **)(src + 0x1c) + 4);
    if (kind == 0) {
        s16 *s = *(s16 **)q;
        r->id = s[0];
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = 0;
        r->dz = 0;
    } else if (kind == 1) {
        *r = **(Pose **)q;
    } else if (kind == 2) {
        s16 *s = *(s16 **)q;
        r->id = s[0];
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = s[2];
        r->dz = s[3];
    }
}

void func_021F56BC(int *p, int arg)
{
    u8 m1[0x24];
    u8 m2[0x30];
    u8 m3[0x40];
    u8 m4[0x30];
    u8 m5[0x24];
    Vec pos;
    Vec tv;
    Pose pose;
    Pose sub;
    u32 w[2];
    int i, j, k;
    char *obj;
    int ox, oy;
    u8 flag;
    int one;
    Ent *ent;

    REG(0x04000444) = 0;
    REG(0x04000440) = 0;
    REG(0x0400044C) = 0;
    REG(0x04000440) = 3;
    REG(0x04000454) = 0;
    REG(0x04000440) = 2;
    if ((p[2] & 1) == 0)
        func_0207D7C4(&d_02148D8C, &d_02148D98, &d_02148DA4, 1);
    else
        func_0207D7C4(&d_021F8310, &d_021F831C, &d_021F8304, 1);
    func_0207B67C(d_02148B98, m1);
    func_02082B60(m1, m2);
    func_0207ADE8(m2, m3);

    for (i = 0; i < p[0]; i++) {
        obj = ((char **)p[1])[i];
        if (obj == 0 || ((*(u32 *)(obj + 0xEC) >> 2) & 1))
            continue;
        REG(0x04000444) = 0;
        w[0] = 0;
        LoadPose(&pose, obj + 0x28, 0x1000);
        pos.x = *(int *)(obj + 0xC8);
        pos.y = *(int *)(obj + 0xCC);
        pos.z = *(int *)(obj + 0xD0);
        if ((p[2] & 1) == 0) {
            ox = pose.dx << 8;
            oy = -pose.dz << 8;
        } else {
            func_0207B5C0(m4);
            func_0207BE14(m4, m4, m4);
            func_021F660C(&pos.x, (int *)m4, (u32 *)&pos, w);
            pos.x = func_0207C768(pos.x, w[0]);
            pos.y = func_0207C768(pos.y, w[0]);
            func_021F660C(&pos.x, (int *)m5, (u32 *)&pos, w);
            ox = RoundF(pose.dx);
            oy = RoundF(-pose.dz);
        }
        pos.z = *(int *)(obj + 0xD0);
        flag = 0;
        if (*(int *)(obj + 0xD4) < 0)
            flag = (u8)(flag + 1);
        REG(0x04000470) = pos.x;
        REG(0x04000470) = pos.y;
        REG(0x04000470) = pos.z;
        if ((p[2] & 1) == 0)
            func_0207D8FC(m3);
        REG(0x04000470) = ox;
        REG(0x04000470) = oy;
        REG(0x04000470) = 0;
        {
            u16 a = (flag & 1) ? (u16)(0x10000 - pose.rot) : pose.rot;
            func_0207D888(-d_020A1B38[(a >> 4) * 2], d_020A1B38[(a >> 4) * 2 + 1]);
        }
        {
            int sy = (int)(((s64)pose.sy * *(int *)(obj + 0xD8) + 0x800) >> 12);
            int sx = (int)(((s64)pose.sx * *(int *)(obj + 0xD4) + 0x800) >> 12);
            REG(0x0400046C) = sx;
            REG(0x0400046C) = sy;
            REG(0x0400046C) = 0x1000;
            one = 0x1000;
        }
        {
            u16 a = *(u16 *)(obj + 0xFC);
            func_0207AF38(m5, -d_020A1B38[(a >> 4) * 2], d_020A1B38[(a >> 4) * 2 + 1]);
            func_0207B51C(obj + 0x100, m5, obj + 0x10C);
            func_0207CA00(obj + 0x100, obj + 0x10C, obj + 0x10C);
            *(int *)(obj + 0x10C) = func_0207C768(*(int *)(obj + 0x10C), *(int *)(obj + 0xD4));
            *(int *)(obj + 0x110) = func_0207C768(*(int *)(obj + 0x110), *(int *)(obj + 0xD8));
        }
        REG(0x04000450) = 0x1D;
        func_021F65EC();
        {
            u32 *a = (u32 *)(obj + 0x90);
            REG(0x040004A8) = (a[7] << 29) | (a[4] << 23) | (a[3] << 20) | 0xF0000 |
                              (a[5] << 26) | (a[0] >> 3) | 0x40000000;
        }
        {
            u16 *list = *(u16 **)(*(char **)(p[0x1B] + 4) + pose.id * 8 + 0);
            char *tab = *(char **)(*(char **)(p[0x1B] + 4) + pose.id * 8 + 4);
            (void)list;
            for (j = 0; j < *(u16 *)(*(char **)(p[0x1B] + 4) + pose.id * 8); j++) {
                u16 h = *(u16 *)(tab + j * 8 + 6);
                char *src = *(char **)(obj + 0x68) + ((h & 0xFF00) >> 8) * 0x5C;
                LoadPose(&sub, src, one);
                ent = (Ent *)(p[8] + 4 + sub.id * 0x38);
                if (ent->f20 != 0) {
                    if (*(u32 *)(obj + 0xEC) & 1)
                        func_021F5EDC((char *)p, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                      ent->f2C + ent->f24, &sub, &pose, j, p[2] & 1, m1, flag);
                    else
                        func_021F5EDC((char *)p, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                      ent->f2C, &sub, &pose, j, p[2] & 1, m1, flag);
                }
                func_021F5EDC((char *)p, ent->f0, ent->f4, ent->f8, ent->fC, ent->f10, ent->f14,
                              &sub, &pose, j, p[2] & 1, m1, flag);
                for (k = 0; k < 8; k++) {
                    u8 b = ent->parts[k];
                    Part *pt;
                    u16 ang;
                    int s, c, fx, fz, rx, rz;
                    if (b == 0xFF)
                        break;
                    ang = (u16)(pose.rot + sub.rot);
                    pt = (Part *)(p[9] + b * 0x14);
                    s = d_020A1B38[(ang >> 4) * 2];
                    c = d_020A1B38[(ang >> 4) * 2 + 1];
                    fx = (int)(((s64)pose.sx * sub.sx + 0x800) >> 12);
                    fz = (int)(((s64)pose.sy * sub.sy + 0x800) >> 12);
                    rx = (int)(((s64)fx * (int)(pt->x * c - pt->z * s) + 0x800) >> 12);
                    rz = (int)(((s64)fz * (int)(pt->x * s + pt->z * c) + 0x800) >> 12);
                    tv.x = *(int *)(obj + 0xC8) + rx + RoundF(sub.dx);
                    tv.y = *(int *)(obj + 0xCC) - rz + RoundF(sub.dz);
                    tv.z = *(int *)(obj + 0xD0);
                    ((void (*)(u8, Vec *, int))p[0x3E])((u8)pt->f4, &tv, arg);
                    if (pt->f4 == 5) {
                        *(int *)(obj + 0x10C) = tv.x;
                        *(int *)(obj + 0x110) = tv.y;
                        *(int *)(obj + 0x114) = 0;
                    }
                }
            }
        }
        REG(0x04000448) = 1;
    }
    REG(0x04000448) = 1;
}
