/*
 * function: STA_ACTING_UpdateCamera
 * address: 0x021F8EA8
 * packet: pkt_ov132_021F8EA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 G3D_CAMERA_SetEye and G3D_CAMERA_SetUp have no external witnesses; the integrator owns them.
 * blocker C (read-only root show):
 *   void G3D_CAMERA_SetEye(char *p, const Vec *v) { *(Vec *)(p + 0x20) = *v; }
 *   void G3D_CAMERA_SetUp(char *p, const Vec *v) { *(Vec *)(p + 0x38) = *v; }
 * symbols:
 *   STA_ACT_LIGHT_ElemOpA 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_GetElemPos 0x021F6F04 thumb ov112
 *   STA_ACT_LIGHT_SetModelFrame 0x021F7098 thumb ov112
 *   STA_ACT_LIGHT_SetElemFrame 0x021F75DC thumb ov112
 *   STA_ACT_OBJ_SetCount 0x021F6AF0 thumb ov112
 *   STA_ACT_AUDIENCE_SetBgScroll 0x021FA57C thumb ov132
 *   KEY_GetCont 0x0203630C arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetUp 0x02048B44 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_02040618 0x02040618 arm
 *   d_021FDBEC 0x021FDBEC data a4
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fgr 0x0209BBB0 arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021FDBEC;
extern u32 KEY_GetCont(void);
extern void STA_ACT_LIGHT_ElemOpA(void *unused, u32 *p, u32 *q);
extern void STA_ACT_LIGHT_GetElemPos(void *, void *, Vec *);
struct Light;
extern void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v);
extern void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);
extern void STA_ACT_OBJ_SetCount(void *, u16);
extern void STA_ACT_AUDIENCE_SetBgScroll(void *unused, int x);
extern void G3D_CAMERA_SetEye(void *, const Vec *);
extern void G3D_CAMERA_SetUp(void *, const Vec *);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_02040618(u32, u32, u32);
#define FX(x) ((int)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
void STA_ACTING_UpdateCamera(u8 *p)
{
    Vec v;
    s16 target;
    u8 index;
    if (KEY_GetCont() & 16) {
        if (*(u16 *)(p + 6) + 2 < 256) *(u16 *)(p + 6) = *(u16 *)(p + 6) + 2;
        else *(u16 *)(p + 6) = 256;
    }
    if (KEY_GetCont() & 32) {
        if (*(u16 *)(p + 6) - 2 > 0) *(u16 *)(p + 6) = *(u16 *)(p + 6) - 2;
        else *(u16 *)(p + 6) = 0;
    }
    if (!(KEY_GetCont() & 48) && !*(int *)(p + 0x14) && !*(int *)(p + 0x10) && !*(int *)(p + 0xC)) {
        if (*(u8 *)(p + 0xF2) == 4) {
            index = *(u8 *)(p + 0xF1);
            if (index == 4) index = *(u8 *)(p + 0xA);
            if (*(void **)(p + 0x44 + index * 4)) {
                STA_ACT_LIGHT_ElemOpA(*(void **)(p + 0x40), *(void **)(p + 0x44 + index * 4), (u32 *)(&v));
                target = (float)v.x / 4096.0f - 128.0f;
            }
        } else {
            STA_ACT_LIGHT_GetElemPos(*(void **)(p + 0x90), *(void **)(p + 0x94 + *(u8 *)(p + 0xF2) * 4), &v);
            target = (float)v.x / 4096.0f - 128.0f;
        }
        if (target > 256) target = 256;
        else if (target < 0) target = 0;
        if (target != *(u16 *)(p + 4)) *(u16 *)(p + 6) = target;
    }
    if (*(u16 *)(p + 6) != *(u16 *)(p + 4)) {
        Vec scale = d_021FDBEC;
        Vec translation = {0, 0, 0};
        if (*(u16 *)(p + 4) > *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) > 4 && *(u16 *)(p + 4) - 4 > *(u16 *)(p + 6)) *(u16 *)(p + 4) -= 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        } else if (*(u16 *)(p + 4) < *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) + 4 < *(u16 *)(p + 6)) *(u16 *)(p + 4) += 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        }
        scale.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        translation.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        G3D_CAMERA_SetEye(*(void **)(p + 0xA8), &scale);
        G3D_CAMERA_SetUp(*(void **)(p + 0xA8), &translation);
        G3D_CAMERA_Reset(*(void **)(p + 0xA8));
        func_02040618(2, 0, *(u16 *)(p + 4));
        STA_ACT_LIGHT_SetModelFrame(*(void **)(p + 0x3C), *(u16 *)(p + 4));
        STA_ACT_LIGHT_SetElemFrame(*(void **)(p + 0x40), *(u16 *)(p + 4));
        STA_ACT_OBJ_SetCount(*(void **)(p + 0x54), *(u16 *)(p + 4));
        STA_ACT_AUDIENCE_SetBgScroll(*(void **)(p + 0xB8), *(u16 *)(p + 4));
    }
    if (*(u16 *)(p + 8) == 224) *(int *)(p + 0xC) = 0;
    func_02040618(2, 3, *(u16 *)(p + 8));
}
