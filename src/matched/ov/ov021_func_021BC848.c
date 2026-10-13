/*
 * function: FIELD_PLACE_NAME_SpawnNextLetter
 * address:  0x021BC848
 * packet:   pkt_ov021_021BC848
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetMessage  0x021BD134  thumb  ov021
 *   PLACE_NAME_LETTER_GetWidth  0x021BD1EC  thumb  ov021
 *   PLACE_NAME_LETTER_Setup  0x021BD19C  thumb  ov021
 *   STRBUF_ToChars  0x02045A38  arm
 *   sub_0201DC6C   0x0201DC6C  thumb
 *   gPlaceNameLetterDefaultParam     0x021D9B88  data  a4
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *
 * The x accumulation is a compound add inside each if/else arm (the two arms
 * cross-jump into one shared `ldr x; _fadd; str x` tail), then `+= 1.0f`
 * after the join, which is why the original re-loads x it has just stored:
 * a single `x += w` after the if/else forwards the value instead.
 * The call argument is the assignment itself: `f(p->fC8[n] = v, &prm)`
 * gives the `str r0, [r2, r1]` with the fC8 base hoisted.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float x;
    float f14;
    float f18;
    float f1C;
    u32 f20;
    u16 ch;
    u16 pad;
} Params;

typedef struct {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50[30];
    u32 fC8[32];
    u8 count;
    u8 pad149[2];
    u8 skip;
} Obj;

extern const Params gPlaceNameLetterDefaultParam;
extern u32 FIELD_PLACE_NAME_GetMessage(u8 *p);
extern int PLACE_NAME_LETTER_GetWidth(u8 *a0);
extern int PLACE_NAME_LETTER_Setup(u32 a, u32 b);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
struct Font;
extern u32 sub_0201DC6C(struct Font *p, u16 ch);

void FIELD_PLACE_NAME_SpawnNextLetter(Obj *p)
{
    int n;
    int i;
    u16 buf[32];
    Params prm;

    n = p->count;
    STRBUF_ToChars((struct U16Vec *)FIELD_PLACE_NAME_GetMessage((u8 *)p), buf, 32);
    prm = gPlaceNameLetterDefaultParam;
    prm.f20 = p->f18;
    prm.ch = buf[n];
    for (i = 0; i < n; i++) {
        if (p->fC8[i] == 0) {
            prm.x += sub_0201DC6C((struct Font *)p->f18, 0x20);
        } else {
            prm.x += PLACE_NAME_LETTER_GetWidth((u8 *)p->fC8[i]);
        }
        prm.x += 1.0f;
    }
    if (prm.ch == 0x20) {
        p->fC8[n] = 0;
        p->skip++;
    } else {
        PLACE_NAME_LETTER_Setup(p->fC8[n] = p->f50[n - p->skip], (u32)(&prm));
    }
    p->count++;
}
