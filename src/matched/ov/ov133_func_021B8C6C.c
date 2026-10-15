/*
 * function: func_021B8C6C
 * address: 0x021B8C6C
 * packet: pkt_ov133_021B8C6C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
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
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
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
extern void *func_021BA184(char *p);
extern u32 func_021BA218(u8 *p);
extern u16 func_021BA250(char *p);
extern u8 *func_021BA238(u8 *p);
extern u8 *func_021BA228(u8 *p);
extern u32 func_021BA240(u8 *);
extern u32 func_021BA208(u8 *p);
extern void func_021BA24C(char *p, u32 v);
extern void func_021BA148(u8 *p, u8 *q);
extern void func_021BA1D8(u8 *p, u8 *q);
extern void func_021BA22C(u8 *p, const u8 *src);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
extern void MUSICAL_MCSS_SetElemPos(int, int, Vec *);
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
            cnt = func_021BA250((char *)e);
            A = (int *)func_021BA238(e);
            B = (int *)func_021BA228(e);
            s = (s16)func_021BA240(e);
            e = (u8 *)func_021BA208(e);
            n = (u16)(cnt - 1);
            if (n != 0) {
                x = s + ((0x1000 - s) * n) / 10;
                sx = x;
                MUSICAL_MCSS_SetElemRotZ((u32)p->f1884, data, sx, sx);
                MUSICAL_MCSS_SetElemScale((int)p->f1884, data, (u32)(&v1));
                w = 10 - (u16)n;
                a0 = A[0];
                x = B[0] - a0;
                x *= w;
                x = a0 + x / 10;
                if (x > 0) v1.x = (int)(0.5f + (float)(x << 12));
                else v1.x = (int)((float)(x << 12) - 0.5f);
                a1 = A[1];
                x = B[1] - a1;
                x *= w;
                x = a1 + x / 10;
                if (x > 0) v1.y = (int)(0.5f + (float)(x << 12));
                else v1.y = (int)((float)(x << 12) - 0.5f);
                v1.z = 0x46000;
                MUSICAL_MCSS_SetElemPos((int)p->f1884, data, &v1);
                func_021BA24C((char *)cur, n);
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
            cnt0 = func_021BA250((char *)e);
            if (cnt0 != 0) {
                data2 = (u32)func_021BA218(e);
                A2 = (int *)func_021BA238(e);
                B2 = (int *)func_021BA228(e);
                n2 = (u16)(cnt0 - 1);
                if (n2 != 0) {
                    MUSICAL_MCSS_SetElemScale((int)p->f1884, data2, (u32)(&v2));
                    wb = 10 - n2;
                    a0b = A2[0];
                    x = B2[0] - a0b;
                    x *= wb;
                    x = a0b + x / 10;
                    if (x > 0) v2.x = (int)(0.5f + (float)(x << 12));
                    else v2.x = (int)((float)(x << 12) - 0.5f);
                    a1b = A2[1];
                    x = B2[1] - a1b;
                    x *= wb;
                    x = a1b + x / 10;
                    if (x > 0) v2.y = (int)(0.5f + (float)(x << 12));
                    else v2.y = (int)((float)(x << 12) - 0.5f);
                    MUSICAL_MCSS_SetElemPos((int)p->f1884, data2, &v2);
                } else {
                    MUSICAL_MCSS_SetElemScale((int)p->f1884, data2, (u32)(&v3));
                    if (B2[0] > 0) v3.x = (int)(0.5f + (float)(B2[0] << 12));
                    else v3.x = (int)((float)(B2[0] << 12) - 0.5f);
                    if (B2[1] > 0) v3.y = (int)(0.5f + (float)(B2[1] << 12));
                    else v3.y = (int)((float)(B2[1] << 12) - 0.5f);
                    MUSICAL_MCSS_SetElemPos((int)p->f1884, data2, &v3);
                    func_021BA22C(e, (const u8 *)B2);
                }
                func_021BA24C((char *)e, n2);
            }
            e = (u8 *)func_021BA208(e);
            if (e == 0 && flag == 0) {
                flag = 1;
                e = func_021BA184(p->f1824);
            }
        } while (e);
    }
}
