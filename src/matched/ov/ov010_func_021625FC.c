/*
 * function: func_021625FC
 * address: 0x021625FC
 * packet: pkt_ov010_021625FC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 150-byte function followed by two alignment bytes at 02162692.
 * lever: read-only const source parameter schedules the final signed-id
 * truncation after the argument loads; exact callee widths keep B on r1.
 * interface: callee argument id is s16 as caller's explicit asrs shows;
 * k stays full-width because the original forwards it without truncation.
 * symbols:
 *   func_021625CC 0x021625CC thumb ov010
 *   func_020140F8 0x020140F8 thumb
 *   func_02014110 0x02014110 thumb
 *   func_02014134 0x02014134 thumb
 *   func_02162C84 0x02162C84 thumb ov010
 *   func_02162D90 0x02162D90 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { u16 a, b; s16 c; u16 d; } B;
typedef struct { int x, y, z; } A;
extern void *func_021625CC(char *p, unsigned i);
extern void func_020140F8(int p0);
extern void func_02014110(int *, u16, s16, u16, int, unsigned, unsigned, unsigned);
extern void func_02014134(int *, u16, s16, u16, int, u16, u16, s16);
extern void func_02162C84(u8 *, int, A *);
extern void func_02162D90(u8 *, int, B *);
int func_021625FC(const u8 *q, int *out, int id, int k)
{
    u8 *r;
    A s;
    B t;
    r = func_021625CC((char *)q, id);
    if (r == 0) return 0;
    func_020140F8((int)out);
    if (*(u16 *)(r + 2) == 0x100) *out = 3;
    else *out = 2;
    if (*(u16 *)(r + 6) == 0) {
        func_02162C84(r, k, &s);
        func_02014110(out, *(u16 *)(q + 0x10), id, r[4], k, s.x, s.y, s.z);
    } else {
        func_02162D90(r, k, &t);
        func_02014134(out, *(u16 *)(q + 0x10), id, r[4], k, t.a, t.d, t.c);
    }
    return 1;
}
