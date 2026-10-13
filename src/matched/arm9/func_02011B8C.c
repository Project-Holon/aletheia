/*
 * function: func_02011B8C
 * address:  0x02011B8C
 * packet:   pkt_0201183C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Applies an HSV tint to a camera/light pair.  func_02011638 reports
 * the three fixed-point 4.12 HSV channels for the current scene; each
 * is converted to float, wrapped into range by repeated subtraction,
 * rescaled to the 0..65535 range func_020520FC wants, and turned back
 * into RGB.  The resulting colour is combined with the two constant
 * vectors at 0x0209DF84 and 0x0209DF90 (copied in as whole 12-byte
 * aggregates, ldm/stm), the scene's own basis is fetched by
 * func_02011610, and the three results are installed on the target.
 *
 * PARKED AT MATCH, not EXACT.  All 356 bytes are byte-correct and 33 of
 * the 35 relocation sites resolve; the two that do not are the ABS32
 * pool words at +0x150 and +0x154:
 *
 *   0209DF84   witnesses image wide: 1, of them inside this range: 1
 *   0209DF90   witnesses image wide: 1, of them inside this range: 1
 *
 * Blocking evidence class: `literal', and there is none.  Each address
 * appears in exactly one literal pool in the whole image (0x02011CDC
 * and 0x02011CE0), which is this function's own pool, so the only
 * witness for each is inside the compared range and attest() refuses
 * it.  `--suggest-split' confirms no cut helps: the range is one
 * function, and it reports "0 piece(s), 1 function(s) left out".
 * Nothing in the C is in question -- this unsticks the moment some
 * other function referencing 0x0209DF84 or 0x0209DF90 is filed EXACT,
 * or the two objects gain a `matched' witness of their own.
 *
 * Shape notes that cost real time and are worth keeping:
 *   - the three channel values must be bound to named `u16' locals
 *     before the func_020520FC call.  Written inline as
 *     `(u16)(u32)(65535.0f * (h / 360.0f))' the lsls/lsrs #0x10 pair
 *     after each _ffixu disappears (about 10 bytes short).
 *   - the scratch the two func_0207B51C calls share is 36 bytes, not
 *     12: `struct Vec3 rgb[3]'.  With a plain `struct Vec3' the whole
 *     frame comes out `sub sp, #0x68' instead of `sub sp, #0x80' and
 *     nothing else differs, so the 24 extra bytes are real declared
 *     storage above 0x5c that this function never reads back.
 *   - the wrap-around is `h += 360.0f': 0x0209C95C is the soft-float
 *     add.  `h = h + 360.0f' puts the constant first (see docs/idioms/
 *     a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-
 *     assignment.md) and no longer matches.
 *   - declaration order is stack order: rgb highest, then hsv, a, b,
 *     basis, out, t0, t1.  Any other order shifts every sp offset.
 *
 * symbols:
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _IcaCameraForward  0x0209DF84  data
 *   _IcaCameraUp  0x0209DF90  data
 *   func_02011610  0x02011610  thumb
 *   func_02011638  0x02011638  thumb
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_020520FC  0x020520FC  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 */

typedef unsigned short u16;
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

extern struct Vec3 _IcaCameraForward;
extern struct Vec3 _IcaCameraUp;

struct IcaAnime;
struct Rec12;
extern u32 func_02011610(struct IcaAnime *ctx, struct Rec12 *out);
extern u32 func_02011638(struct IcaAnime *ctx, struct Rec12 *hsv);
extern void func_02048AFC(void *dst, struct Vec3 *v);
extern void func_02048B20(void *dst, struct Vec3 *v);
extern void func_02048B44(void *dst, struct Vec3 *v);
struct Mtx33;
extern void func_020520FC(int h, int s, int v, struct Mtx33 *out);
extern void func_0207B51C(struct Vec3 *a, struct Vec3 *b, struct Vec3 *out);
extern void func_0207C9D0(struct Vec3 *a, struct Vec3 *b, struct Vec3 *out);

void func_02011B8C(void *dst, void *ctx)
{
    struct Vec3 rgb[3];
    s32 hsv[3];
    struct Vec3 a;
    struct Vec3 b;
    struct Vec3 basis;
    struct Vec3 out;
    struct Vec3 t0;
    struct Vec3 t1;
    u16 ch;
    u16 cs;
    u16 cv;
    float h;
    float s;
    float v;

    a = _IcaCameraForward;
    b = _IcaCameraUp;

    func_02011638(ctx, (struct Rec12 *)hsv);

    h = hsv[0] / 4096.0f;
    s = hsv[1] / 4096.0f;
    v = hsv[2] / 4096.0f;

    while (h < 0.0f) {
        h += 360.0f;
    }
    while (s < 0.0f) {
        s += 360.0f;
    }
    while (v < 0.0f) {
        v += 360.0f;
    }

    ch = (u16)(u32)(65535.0f * (h / 360.0f));
    cs = (u16)(u32)(65535.0f * (s / 360.0f));
    cv = (u16)(u32)(65535.0f * (v / 360.0f));
    func_020520FC(ch, cs, cv, (struct Mtx33 *)rgb);

    func_0207B51C(&a, rgb, &t0);
    func_0207B51C(&b, rgb, &t1);

    func_02011610(ctx, (struct Rec12 *)&basis);
    func_0207C9D0(&basis, &t0, &out);

    func_02048AFC(dst, &basis);
    func_02048B44(dst, &out);
    func_02048B20(dst, &t1);
}
