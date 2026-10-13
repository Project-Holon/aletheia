/*
 * function: BTLV_GAUGE_DrawLevel
 * address: 0x02208550
 * packet: pkt_ov094_02208550
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialize the reusable heap offset; assign enum VRAM in each
 *   copy arm; split addr = base; addr = addr + off and add buf.w[1] last.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201F35C 0x0201F35C thumb
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_GetPixels 0x020437D4 arm
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_02082A60 0x02082A60 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Delete 0x020437AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int w[9]; } Struct36;
typedef struct { void *f0; char p4[0x40]; int f44; char p48[0x24]; u8 f6c; } E;
typedef struct { char p0[8]; void *f8; char pc[0x43c]; u16 heap; } O;
struct Bmp;
struct Struct36;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Bmp;
struct CharBuf;
struct Obj020437AC;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F35C(void *, int, u32, u32, u32);
extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, int);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_Delete(struct Obj020437AC *p);
void BTLV_GAUGE_DrawLevel(O *o, E *e)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    u32 off = 0x448;
    int addr;
    enum { VRAM = 0x06400000 } base;
    v = STRBUF_Create(4, (u16)((*(u16 *)((char *)o + off) & 0x7fff) | 0x8000));
    bmp = BMP_Create(3, 2, 32, (u16)((*(u16 *)((char *)o + off) & 0x7fff) | 0x8000));
    BMP_Clear(bmp, 0);
    func_0201F35C(v, e->f6c, 3, 0, 0);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(1, 4, 0);
    PRINTSYS_Print(bmp, 0, 5, v, o->f8);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(e->f0, (struct Struct36 *)(&buf));
    if (e->f44 != 0) {
        base = VRAM;
        off += 0x38;
        addr = base;
        addr = addr + off;
        func_02082A60(pixels, (void *)(addr + buf.w[1]), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x580 + buf.w[1]), 0x60);
    } else {
        base = VRAM;
        off += 0x18;
        addr = base;
        addr = addr + off;
        func_02082A60(pixels, (void *)(addr + buf.w[1]), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x560 + buf.w[1]), 0x60);
    }
    STRBUF_Delete(v);
    BMP_Delete(bmp);
}
