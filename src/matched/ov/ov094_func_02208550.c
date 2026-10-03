/*
 * function: func_02208550
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
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F35C 0x0201F35C thumb
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_020437D4 0x020437D4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02045808 0x02045808 arm
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int w[9]; } Struct36;
typedef struct { void *f0; char p4[0x40]; int f44; char p48[0x24]; u8 f6c; } E;
typedef struct { char p0[8]; void *f8; char pc[0x43c]; u16 heap; } O;
extern void *func_020457B0(u32, u16);
extern void *func_02043678(u32, u32, u32, u16);
struct Bmp;
struct CharBuf;
struct Obj020437AC;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F35C(void *, int, u32, u32, u32);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_0204B7C8(void *, Struct36 *);
extern void func_02082A60(const void *, void *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
void func_02208550(O *o, E *e)
{
    void *v, *bmp;
    char *pixels;
    Struct36 buf;
    u8 c[3];
    u32 off = 0x448;
    int addr;
    enum { VRAM = 0x06400000 } base;
    v = func_020457B0(4, (*(u16 *)((char *)o + off) & 0x7fff) | 0x8000);
    bmp = func_02043678(3, 2, 32, (*(u16 *)((char *)o + off) & 0x7fff) | 0x8000);
    func_02043B5C(bmp, 0);
    func_0201F35C(v, e->f6c, 3, 0, 0);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 4, 0);
    func_0201C7A4(bmp, 0, 5, v, o->f8);
    func_0201DD78(c[2], c[1], c[0]);
    pixels = func_020437D4(bmp);
    func_0204B7C8(e->f0, &buf);
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
    func_02045808(v);
    func_020437AC(bmp);
}
