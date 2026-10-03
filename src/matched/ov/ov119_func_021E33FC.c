/*
 * function: func_021E33FC
 * address: 0x021E33FC
 * packet: pkt_ov119_021E33FC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-03 (wave B3): all concrete bytes match. The one open relocation is
 * the call to func_02015F04 (unlabelled arm9 Thumb leaf). Its witness is
 * filed as src/matched/arm9/func_02015F04.c (EXACT); once the integrator
 * seeds 0x02015F04 in layout/function_starts.txt this re-verifies as EXACT.
 * The empty-then if/else on *dir gives the original `bge; b` shape.
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_02015F04 0x02015F04 thumb
 *   func_02015F14 0x02015F14 thumb
 *   func_02015C78 0x02015C78 thumb
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _fflt 0x0209BDBC arm
 *   d_021E7B9C 0x021E7B9C data a4
 */
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    float x;
    float y;
    float z;
} Entry;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

extern Entry d_021E7B9C[4];
extern int func_02017E1C(void *p, int id, int arg);
extern int func_02017F00(void *p);
extern void func_02015F04(void *p);
extern int func_02015F14(void *p);
extern void func_02015C78(void *p, Vec *v);

#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))

void func_021E33FC(void *p0, int *dir, int p2, void *mon)
{
    Vec v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = func_02017E1C(mon, 5, 0);
    b = func_02017E1C(mon, 0x6f, 0);
    c = func_02017F00(mon);
    if (p2 == 0)
        flag = 1;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (a == d_021E7B9C[i].a && b == d_021E7B9C[i].b
            && (d_021E7B9C[i].c == 3 || c == d_021E7B9C[i].c)
            && (d_021E7B9C[i].d == 2 || flag == d_021E7B9C[i].d)) {
            v.x = F32_TO_FX32(d_021E7B9C[i].x);
            if (*dir >= 0)
                v.x = -v.x;
            v.y = F32_TO_FX32(d_021E7B9C[i].y);
            v.z = F32_TO_FX32(d_021E7B9C[i].z);
            found = 1;
            break;
        }
    }
    if (!found) {
        func_02015F04(p0);
        c = func_02015F14(p0);
        if (*dir < 0)
            f = 0.33f * (float)c;
        else
            f = 0.33f * (float)-c;
        v.x = F32_TO_FX32(f);
        v.y = 0;
        v.z = 0;
    }
    func_02015C78(p0, &v);
}
