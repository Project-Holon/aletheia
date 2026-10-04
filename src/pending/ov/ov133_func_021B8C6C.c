/*
 * function: func_021B8C6C
 * address: 0x021B8C6C
 * packet: pkt_ov133_021B8C6C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note-2026-10-04: DIFF, 8 bytes in 4 places (full structure, frame size, slots and all calls match). Residue: in each of the four lerp blocks the original computes `subs r1,r1,r0` (diff dest = B0 reg) then `ldr r0,[w slot]` before `muls r0,r1,r0`; ours gives `subs r0,r1,r0; ldr r1,[w]`. Tried: w*(d) vs (d)*w, d local, a0 local vs A[0] CSE (shifts slots). Wins: real struct fields (f1820 f1824 f1828 f1884 in a local struct) give the hoisted offset slots; separate Vec and separate a0/w/a1 locals per part, declared in reverse slot order; int n (signed div); s16 sx local for the first EB4 call; FX rounding via (int)(0.5f + (float)(x<<12)) / -0.5f.
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA250 0x021BA250 thumb ov133
 *   func_021BA238 0x021BA238 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA240 0x021BA240 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA24C 0x021BA24C thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA1D8 0x021BA1D8 thumb ov133
 *   func_021BA22C 0x021BA22C thumb ov133
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
struct O {
    u8 pad0[0x1820];
    void *f1820;
    void *f1824;
    void *f1828;
    u8 pad1[0x1884 - 0x182c];
    void *f1884;
};
extern u8 *func_021BA184(void *);
extern u8 *func_021BA218(u8 *);
extern u16 func_021BA250(u8 *);
extern int *func_021BA238(u8 *);
extern int *func_021BA228(u8 *);
extern u32 func_021BA240(u8 *);
extern u8 *func_021BA208(u8 *);
extern void func_021BA24C(u8 *, u32);
extern void func_021BA148(void *, u8 *);
extern void func_021BA1D8(u8 *, void *);
extern void func_021BA22C(u8 *, int *);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021F4EA4(int, int, Vec *);
extern void func_021F4E8C(int, int, Vec *);
void func_021B8C6C(struct O *p)
{
    Vec v1;
    Vec v2;
    Vec v3;
    u32 cnt0;
    u8 *cur;
    int *A;
    int *B;
    int s;
    int flag;
    int n2;
    int *A2;
    int a0;
    int w;
    int a1;
    int a0b;
    int wb;
    int a1b;
    u8 *e;
    u32 data;
    u32 cnt;
    int n;
    int x;
    int d;
    s16 sx;
    int *B2;
    u32 data2;
    e = func_021BA184(p->f1828);
    if (e) {
        do {
            cur = e;
            data = (u32)func_021BA218(e);
            cnt = func_021BA250(e);
            A = func_021BA238(e);
            B = func_021BA228(e);
            s = (s16)func_021BA240(e);
            e = func_021BA208(e);
            n = (u16)(cnt - 1);
            if (n != 0) {
                x = s + ((0x1000 - s) * n) / 10;
                sx = x;
                func_021F4EB4((u32)p->f1884, data, sx, sx);
                func_021F4EA4((int)p->f1884, data, &v1);
                w = 10 - (u16)n;
                a0 = A[0];
                x = (w * (B[0] - a0)) / 10 + a0;
                if (x > 0) v1.x = (int)(0.5f + (float)(x << 12));
                else v1.x = (int)((float)(x << 12) - 0.5f);
                a1 = A[1];
                x = (w * (B[1] - a1)) / 10 + a1;
                if (x > 0) v1.y = (int)(0.5f + (float)(x << 12));
                else v1.y = (int)((float)(x << 12) - 0.5f);
                v1.z = 0x46000;
                func_021F4E8C((int)p->f1884, data, &v1);
                func_021BA24C(cur, n);
            } else {
                func_021BA148(p->f1828, cur);
                func_021BA1D8(cur, p->f1884);
            }
        } while (e);
    }
    flag = 0;
    e = func_021BA184(p->f1820);
    if (e == 0) {
        flag = 1;
        e = func_021BA184(p->f1824);
    }
    if (e) {
        do {
            cnt0 = func_021BA250(e);
            if (cnt0 != 0) {
                data2 = (u32)func_021BA218(e);
                A2 = func_021BA238(e);
                B2 = func_021BA228(e);
                n2 = (u16)(cnt0 - 1);
                if (n2 != 0) {
                    func_021F4EA4((int)p->f1884, data2, &v2);
                    wb = 10 - n2;
                    a0b = A2[0];
                    x = (wb * (B2[0] - a0b)) / 10 + a0b;
                    if (x > 0) v2.x = (int)(0.5f + (float)(x << 12));
                    else v2.x = (int)((float)(x << 12) - 0.5f);
                    a1b = A2[1];
                    x = (wb * (B2[1] - a1b)) / 10 + a1b;
                    if (x > 0) v2.y = (int)(0.5f + (float)(x << 12));
                    else v2.y = (int)((float)(x << 12) - 0.5f);
                    func_021F4E8C((int)p->f1884, data2, &v2);
                } else {
                    func_021F4EA4((int)p->f1884, data2, &v3);
                    if (B2[0] > 0) v3.x = (int)(0.5f + (float)(B2[0] << 12));
                    else v3.x = (int)((float)(B2[0] << 12) - 0.5f);
                    if (B2[1] > 0) v3.y = (int)(0.5f + (float)(B2[1] << 12));
                    else v3.y = (int)((float)(B2[1] << 12) - 0.5f);
                    func_021F4E8C((int)p->f1884, data2, &v3);
                    func_021BA22C(e, B2);
                }
                func_021BA24C(e, n2);
            }
            e = func_021BA208(e);
            if (e == 0 && flag == 0) {
                flag = 1;
                e = func_021BA184(p->f1824);
            }
        } while (e);
    }
}
