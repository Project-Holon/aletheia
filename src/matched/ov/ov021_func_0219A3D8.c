/*
 * function: FLDMMDL_MOVECODE_GetMoveRect
 * address:  0x0219A3D8
 * packet:   pkt_ov021_0219A3D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb  ov010
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb  ov010
 *   FLDMMDL_GetMoveLimitX  0x0216D660  thumb  ov010
 *   FLDMMDL_GetMoveLimitZ  0x0216D66C  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 * Addresses are Black-image addresses.
 * Store order in each arm is left, right, top, bottom (x pair, then y pair);
 * the field order left, top, right, bottom puts stores to +0/+8 first.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { int left, top, right, bottom; } Rect;
extern int FLDMMDL_GetGridInitX(void *p);
extern int FLDMMDL_GetGridInitZ(void *p);
extern int FLDMMDL_GetMoveLimitX(void *p);
extern int FLDMMDL_GetMoveLimitZ(void *p);
extern u16 FLDMMDL_GetMoveCode(void *p);

void FLDMMDL_MOVECODE_GetMoveRect(u32 a, Rect *r)
{
    int x;
    int y;
    int w;
    int h;

    x = FLDMMDL_GetGridInitX((void *)a);
    y = FLDMMDL_GetGridInitZ((void *)a);
    w = FLDMMDL_GetMoveLimitX((void *)a);
    h = FLDMMDL_GetMoveLimitZ((void *)a);
    switch (FLDMMDL_GetMoveCode((void *)a)) {
    case 6:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y;
        break;
    case 7:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 8:
        r->left = x - w;
        r->right = x;
        r->top = y;
        r->bottom = y + h;
        break;
    case 9:
        r->left = x;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    case 10:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 11:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 12:
        r->left = x - w;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 13:
        r->left = x - w;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    }
}
