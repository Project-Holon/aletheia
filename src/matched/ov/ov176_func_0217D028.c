/*
 * function: func_0217D028
 * address: 0x0217D028
 * packet: pkt_ov176_0217D028
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217D15E before existing 0217D160.
 * ABI: 0200AE14 is an empty void callee leaving its supplied pointer in r0; caller reads it.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B204 0x0200B204 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_0200E918 0x0200E918 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200B074 0x0200B074 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200B078 0x0200B078 thumb
 *   func_021E6118 0x021E6118 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 image[0x94]; u32 f94, f98; int f9c; u16 fa0, fa2, fa4, fa6, fa8, faa; } Record;
typedef signed int     s32;
struct Big;
struct Reg2;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern int func_0200AE14(void *);
extern void *func_0200B358(void *);
extern int func_0200B204(void *, int);
extern int func_02012944(void *);
extern int func_021E5548(int *);
extern void func_02082BCC(void *, int, u32);
extern u8 func_0200E918(const u8 *, u32);
extern int func_0200AE54(int, int);
extern int func_02008554(int);
extern int func_0200B074(void *);
extern void func_02082D44(int, void *, u32);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern int func_021E6118(Record *, int, int, int, int, int, int, int, int, int, u16);
void func_0217D028(u8 *p)
{
    Record rec;
    void *base;
    int box, aux, x, table, a, b, c, d;
    if (*(int *)(p + 0x10)) return;
    base = func_02012EBC(*(void **)(p + 0x1B8));
    func_0200BAC8(base);
    box = func_0200AE14(*(void **)(p + 0x38));
    aux = func_0200B204(func_0200B358(base), 1);
    x = func_02012944(*(void **)(p + 0x1B8));
    table = func_021E5548(*(int **)(p + 0x1B4));
    func_02082BCC(&rec, 0, 0xAC);
    rec.fa0 = func_0200E918(*(u8 **)(p + 0x34), 1);
    rec.fa2 = func_0200E918(*(u8 **)(p + 0x34), 2);
    rec.fa4 = func_0200E918(*(u8 **)(p + 0x34), 0);
    rec.fa6 = func_0200AE54(box, 0x16);
    rec.f9c = func_02008554(x);
    func_02082D44(func_0200B074(*(void **)(p + 0x38)), &rec, 0x92);
    a = func_0200B078(*(void **)(p + 0x38), 6);
    b = func_0200B078(*(void **)(p + 0x38), 5);
    c = func_0200B078(*(void **)(p + 0x38), 4);
    rec.f94 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    a = func_0200B078(*(void **)(p + 0x38), 9);
    b = func_0200B078(*(void **)(p + 0x38), 8);
    c = func_0200B078(*(void **)(p + 0x38), 7);
    rec.f98 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    rec.fa8 = func_0200B078(*(void **)(p + 0x38), 11);
    *(int *)(p + 0x10) = func_021E6118(&rec, x, table, *(int *)(p + 0x1B0), *(int *)(p + 0x1A8), *(int *)(p + 0x1AC), *(int *)(p + 0x24), *(int *)(p + 0x2C), aux, 0, *(u16 *)(p + 0x1C8));
}
