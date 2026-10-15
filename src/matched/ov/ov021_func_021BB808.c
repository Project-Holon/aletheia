/*
 * function: FLDEFF_GYOE_StepAnimation
 * address:  0x021BB808
 * packet:   pkt_ov021_021BB808
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   FLDEFF_GYOE_RotateByCamera  0x021BB7B4  thumb  ov021
 *   VEC_Add  0x0207C9D0  arm
 */

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef unsigned int   u32;
typedef unsigned char  u8;
void *FIELDMAP_GetCamera(void *p);
u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
void FLDEFF_GYOE_RotateByCamera(int a, int b, int c);
void VEC_Add(Vec *a, Vec *b, Vec *c);

void FLDEFF_GYOE_StepAnimation(int *o, Vec *out)
{
    int r3;
    Vec w;

    switch (o[7]) {
    case 0:
        o[10] += o[11];
        if (o[10] != 0) {
            o[11] = o[11] - 0x2000;
        } else {
            o[11] = 0;
            o[7] = o[7] + 1;
        }
        break;
    case 1:
        o[8] = o[8] + 1;
        if (o[8] >= 30) {
            o[7] = o[7] + 1;
            o[9] = 1;
        }
        break;
    }
    r3 = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera((void *)o[6]));
    {
        Vec v = {0, 0, 0};

        v.y = o[10] + 0x16000;
        w = v;
    }
    FLDEFF_GYOE_RotateByCamera(r3, (int)(&w), (int)(&w));
    VEC_Add(&w, out, out);
}
