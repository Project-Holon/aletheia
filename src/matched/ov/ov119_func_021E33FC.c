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
 * the call to MCSS_GetSizeX (unlabelled arm9 Thumb leaf). Its witness is
 * filed as src/matched/arm9/MCSS_GetSizeX.c (EXACT); once the integrator
 * seeds 0x02015F04 in layout/function_starts.txt this re-verifies as EXACT.
 * The empty-then if/else on *dir gives the original `bge; b` shape.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   MCSS_GetSizeX 0x02015F04 thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
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
typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u8 POKE_TOOL_GetGender(void *p);
extern u16 MCSS_GetSizeX(void *p);
extern s16 MCSS_GetOfsX(void *p);
extern void MCSS_SetOfsPosition(void *p, u32 *src);

#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))

void func_021E33FC(void *p0, int *dir, int p2, void *mon)
{
    Vec v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = POKE_TOOL_GetPartyValue(mon, 5, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
    c = POKE_TOOL_GetGender(mon);
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
        MCSS_GetSizeX(p0);
        c = MCSS_GetOfsX(p0);
        if (*dir < 0)
            f = 0.33f * (float)c;
        else
            f = 0.33f * (float)-c;
        v.x = F32_TO_FX32(f);
        v.y = 0;
        v.z = 0;
    }
    MCSS_SetOfsPosition(p0, (u32 *)(&v));
}
