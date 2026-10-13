/*
 * function: FIELD_TASK_UpdatePlayerDrop
 * address:  0x021C7730
 * packet:   pkt_ov021_021C7730
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   FIELD_TASK_CalcDropOffset  0x021C76C4  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u8    st;
    u32   w4;
    u16   h8;
    u16   ha;
    float fc;
    u32   w10;
} Fx;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FIELD_TASK_CalcDropOffset(Vec *out, float a, float b, float c);
extern void FLDMMDL_SetDrawOffset(u32 a, Vec *v);
extern void FLDEFF_KEMURI_Start(u32 a, u32 b);
extern void func_020061E4(u32 a);

int FIELD_TASK_UpdatePlayerDrop(Fx *o)
{
    Vec v;
    u32 s;

    FIELDMAP_GetFieldPlayer((struct Obj00020 *)o->w4);
    s = o->w10;
    switch (o->st) {
    case 0:
        FIELD_TASK_CalcDropOffset(&v, (float)(u32)o->h8, (float)(u32)o->ha, o->fc);
        FLDMMDL_SetDrawOffset(s, &v);
        func_020061E4(0x681);
        o->st = o->st + 1;
        break;
    case 1:
        o->h8 = o->h8 + 1;
        FIELD_TASK_CalcDropOffset(&v, (float)(u32)o->h8, (float)(u32)o->ha, o->fc);
        FLDMMDL_SetDrawOffset(s, &v);
        if (o->ha <= o->h8) {
            FLDEFF_KEMURI_Start(s, FIELDMAP_GetEffect((u8 *)o->w4));
            func_020061E4(0x682);
            return 1;
        }
        break;
    }
    return 0;
}
