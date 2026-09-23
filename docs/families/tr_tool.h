/*
 * docs/families/tr_tool.h -- shared declarations for the tr_tool.c family
 * (0x0202A440..0x0202AAF4 in the ARM9 image, Thumb, dsi/1.1p1 -O4,p).
 * Anchor: __FILE__ at 0x020A76DC (func_0202A440, func_0202A4B4).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Evidence:
 * src/matched/func_0202A3AC.c, func_0202A3BC.c, func_0202A3CC.c,
 * func_0202A440.c, func_0202A4B4.c (wave 15), func_0202A994.c,
 * func_0202A9F4.c (wave 15).
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef struct {        /* trainer record, 0x14 bytes (func_0202A3AC) */
    u8  type;           /* +0x00 party entry format 0..3 */
    u8  cls;            /* +0x01 trainer class: gender table index and LCG steps */
    u8  f02;
    u8  count;          /* +0x03 party size */
    u8  f04[8];         /* +0x04 copied out by func_0202A440 */
    u32 f0c;
    u32 f10;
} TrData;

/* Party entries (func_0202A3BC fills a 0x6C-byte table). */
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; } TrMon0;                             /*  8 */
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; u16 moves[4]; } TrMon1;               /* 16 */
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; u16 item; } TrMon2;                   /* 10 */
typedef struct { u8 dv; u8 abil; u16 level; u16 species; u16 form; u16 item; u16 moves[4]; } TrMon3;     /* 18 */

void func_0202A3AC(u32 id, TrData *td);          /* load trainer record */
void func_0202A3BC(u32 id, void *tp);            /* load party table */
u8   func_0202A3CC(u32 cls);                     /* 1: class is female */
void func_0202A440(u32 id, void *out, u32 heap);
void func_0202A4B4(u32 trid, void *party, u16 heap);        /* build party */
void func_0202A994(u32 species, u32 form, int abil, u32 *gender, u16 heap);
void func_0202A9F4(u32 trid, void *mon, u32 form, u32 abil); /* per-mon fixups */

/*
 * Levers (wave 15):
 *  - func_0202A9F4: `adds r6, r4, #0` before the move loop is the constant 0
 *    (NULL third argument and `found = 0`), not a copy of the counter; the
 *    tail is `% 25` (remainder in r1), not `/ 25`.
 *  - func_0202A4B4: see its header; pid/seed/j/iv at function scope, dv/
 *    level/species per case (docs/idioms/function-scope-versus-block-scope-
 *    decides-spill-slot-order.md).
 */
