/*
 * file:     config.c
 * unit:     yes
 * function: func_020082DC, func_020082EC, func_02008314, func_02008320, func_02008374, func_0200837C, func_02008390, func_02008398, func_020083AC, func_020083B4, func_020083C8, func_020083D0, func_020083E4, func_020083EC, func_02008414, func_02008428, func_02008430, func_02008448, func_02008450, func_02008468, func_0200846C, func_02008494, func_020084A0, sub_020084BC, sub_020084D4, sub_020084E4, sub_020084F4, sub_020084F8, sub_02008500, sub_02008510, sub_0200852C, sub_02008530, sub_02008534, sub_0200853C, sub_02008540, sub_0200854C, sub_02008550, sub_02008554, sub_02008558, sub_0200855C, sub_02008560, sub_02008564, sub_02008568, sub_0200856C, sub_02008570, sub_02008574, sub_0200857C, sub_020085A0, sub_020085D4, sub_0200863C, sub_0200864C, sub_02008650, sub_02008654, sub_02008658, sub_020086C8, sub_020086D0, sub_020086D8, sub_020086E0, sub_020086E8, sub_020086F0, sub_020086F8, sub_02008700, sub_02008704, sub_02008730, sub_0200873C, sub_02008748, sub_02008754, sub_02008764, sub_02008774, sub_02008784, sub_020087A8, sub_020087C0, sub_020087D4, sub_020087E8, sub_02008808, sub_02008828, sub_0200882C, sub_02008844, sub_02008848, sub_0200884C, sub_02008850, sub_02008854, sub_02008860, sub_020088B8, sub_0200890C, sub_0200892C, sub_0200893C, sub_0200894C, sub_02008954, sub_0200895C, sub_02008964, sub_0200896C, sub_02008970, sub_02008978, sub_02008980, sub_02008988, sub_02008990, sub_02008998, sub_020089A0
 * address:  0x020082DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02008254_File  0x020A708C  data
 *   func_02030734      0x02030734  arm
 *   g_0209DD64      0x0209DD64  data
 *   g_020A70A0      0x020A70A0  data
 *   func_02082BCC    0x02082BCC  arm
 *   func_020461D4  0x020461D4  arm
 *   g_020A70AC      0x020A70AC  data
 *   g_020A70C4      0x020A70C4  data
 *   g_0209DDB4      0x0209DDB4  data
 *   g_020A716C      0x020A716C  data
 *   func_02082D44  0x02082D44  arm
 *   sub_0201F41C        0x0201F41C  thumb
 *   sub_02045924        0x02045924  arm
 *   sub_02045A38        0x02045A38  arm
 *   sub_020457B0        0x020457B0  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   RTC_GetDate         0x02088864  arm
 *   RTC_GetTime         0x0208890C  arm
 *   sub_0200857C_File   0x020A70B8  data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   sub_02008320    0x02008320  thumb
 *   sub_020084A0    0x020084A0  thumb
 *   sub_020085A0    0x020085A0  thumb
 *   sub_020071CC    0x020071CC  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 */
#include "../../matched/include/Obj15570.h"
#include "../../matched/include/Obj15571.h"
#include "../../matched/include/Obj15574.h"

struct Flags02008320;
struct Sub0200852CObj;
struct Strbuf;
struct U16Vec;
struct PlayTime;
struct Sub020071CCCtrl;
struct Sub02014444Obj;
typedef signed short   s16;

typedef unsigned short u16;

typedef unsigned int   u32;

struct MyItemSave {
    s16 unk00[5];
    s16 unk0A[5];
    u16 unk14;
    u16 unk16;
    s16 unk18[4];
    s16 unk20[4];
    u16 unk28;
    u16 unk2A;
};

/* one u16 of packed flags: the seven low fields are written one at a time. */
struct Flags02008320 {
    u16 a : 4;
    u16 b : 2;
    u16 c : 1;
    u16 d : 1;
    u16 e : 1;
    u16 f : 1;
    u16 g : 1;
    u16 h : 5;
};

typedef struct {
    unsigned short a : 4;
    unsigned short b : 2;
    unsigned short c : 1;
    unsigned short d : 1;
    unsigned short e : 1;
    unsigned short f : 1;
} BF;

typedef unsigned char  u8;

struct Flags02008414 {
    u16 lo  : 8;
    u16 b8  : 1;
    u16 b9  : 1;
    u16 b10 : 1;
    u16 hi  : 5;
};

struct Flags02008450 {
    u16 lo   : 10;
    u16 flag : 1;
    u16 hi   : 5;
};

struct Sub0200852CObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
};

struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
};

struct PlayTimeStamp {
    u32 year   : 7;
    u32 month  : 4;
    u32 day    : 5;
    u32 hour   : 5;
    u32 minute : 6;
};

struct PlayTime {
    u16 hours;
    u8  minutes;
    u8  seconds;
    struct PlayTimeStamp stamp;
};

struct Sub02008700Obj {
    u32 unk00;
    struct Sub0200852CObj unk04;
    struct PlayTime unk24;
    u8  unk2C;
    u8  unk2D[3];
    u16 unk30[10];
    u32 unk44[9];
};

/* The carrier the 0x20-byte sub-object is copied to and from. */
struct Sub020087E8Arg {
    u8 unk00[0x20];
    struct Sub0200852CObj unk20;
};

/* The twelve bytes that move as one unit. */
struct Sub02008860Inner {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

/* The 0x1C-byte record the block keeps at +0x80. */
struct Sub02008828Rec {
    u16 unk00;
    struct Sub02008860Inner unk04;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    s16 unk18;
    u8  unk1A;
    u8  unk1B;
};

/* The buffer the record is exchanged with.  Its first 0x1C bytes line up with */
/* the record but the last two fields do not; see the header. */
struct Sub02008860Buf {
    u16 unk00;
    struct Sub02008860Inner unk04;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u8  unk1C[0x24];
    u32 unk40;
};

struct Sub02008828Obj {
    u8  unk00[0x38];
    u8  unk38[0x1C];
    u8  unk54[0x1C];
    u8  unk70[2];
    u8  unk72;
    u8  unk73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u32 unk78;
    u16 unk7C;
    u16 unk7E;
    struct Sub02008828Rec unk80;
};

typedef unsigned long long u64;

struct Sub020089A8Rec {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
};

struct Sub020089A8Obj {
    u32 unk000[384];
    u16 unk600;
    u8  unk602;
    u8  unk603;
    struct Sub020089A8Rec unk604[8];
    union {
        u64 whole;
        struct {
            u32 lo;
            u32 hi;
        } half;
    } unk624;
    u8  unk62C[0xC];
    u16 unk638[16];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020362A4(const void *p);
extern void func_02008320(struct Flags02008320 *p);
void func_020082DC(void);
void *func_020082EC(int a0);
extern void func_02082D44(void *dst, void *src, int n);
extern void func_02082BCC(void *p, int c, u16 n);
unsigned int func_02008374(int a0);
void func_0200837C(BF *p, unsigned int v);
void func_02008314(void *a0, void *a1);
extern u8 func_020461D4(u32 v);
unsigned int func_02008390(char *a0);
void func_02008398(BF *p, unsigned int v);
unsigned int func_020083AC(BF *p);
void func_020083B4(BF *p, unsigned int v);
unsigned int func_020083C8(BF *p);
void func_020083D0(BF *p, unsigned int v);
int func_020083E4(unsigned short *p);
void func_020083EC(unsigned short *p, unsigned int v);
extern void func_020084A0(struct Sub0200852CObj *obj);
int func_02008468(void);
void *func_0200846C(int a0);
extern void func_02008560(struct Sub0200852CObj *obj, u8 value);
int func_02008428(unsigned short *p);
void func_02008430(BF *p, unsigned int v);
unsigned int func_02008448(int a0);
void func_02008494(void *src, void *dst);
extern u32   sub_0201F41C(void *dst, u32 value, u32 size);
extern void sub_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void sub_02045924(struct Strbuf *o, const u16 *src);
extern struct U16Vec *sub_020457B0(u32 capacity, u32 heapId);
int sub_020084BC(const u16 *values);
/* Two argument-swapping tail calls. The `ldr r3, <pool>; bx r3` shape is what */ /* -interworking produces for a tail call to an extern whose instruction set */ /* the compiler cannot see; 0x0201F41C is Thumb (the pool word is odd) and */ /* 0x02045A38 is ARM (it is even), and the same code covers both. */ u32 sub_020084D4(u32 value, void *dst);
void sub_020084E4(u16 *out, struct U16Vec *vec);
u32 sub_020084F8(void *dst, u32 value, u32 size);
/* The argument swap survives into a tail call here too, but this one is 16 */ /* bytes rather than 12: the extra `adds` is the third scratch register the */ /* swap needs when only two arguments are live. */ void sub_02008500(void *a, void *b);
/* call, not a u16 parameter: a u16 parameter is truncated by the caller. */ void *sub_02008510(void *a, int tag);
extern void RTC_GetDate(struct RTCDate *date);
extern void RTC_GetTime(struct RTCTime *time);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
/* The debug allocator: heap, size, alignment, __FILE__, __LINE__.  The last */
/* two arrive as a pointer into the packed string area and the constant 32. */
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void sub_020085A0(struct PlayTime *p);
/* playtime.c's constructor, and the function that gives the file its name. */ void *sub_0200857C(u32 heap);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void sub_02008320(struct Flags02008320 *p);
extern void sub_020084A0(struct Sub0200852CObj *obj);
/* Save-block lookup: returns the block with the given id. */
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void sub_02014464(struct Sub02014444Obj *o, u8 v);
u32 sub_02008700(void);
u32 sub_02008828(void);
extern char g_0209DD64[];
extern char g_020A70A0[];
extern char g_020A70AC[];
extern const char sub_0200857C_File[];


void func_020082DC(void)
{
    func_020362A4(g_0209DD64);
}


void *func_020082EC(int a0)
{
    void *p = func_02030734((unsigned short)a0, 4, 0, g_020A70A0, 0x4d);
    func_02008320(p);
    return p;
}


void func_02008314(void *a0, void *a1)
{
    func_02082D44(a0, a1, 4);
}


void func_02008320(struct Flags02008320 *p)
{
    func_02082BCC(p, 0, 4);
    p->a = 1;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 1;
    p->g = 0;
}


unsigned int func_02008374(int a0){ return ((unsigned int)((((struct Obj15570 *)((char *)(a0)))->f0 << 0x1c)) >> 0x1c); }


/*
 * Unlabelled leaf setter on a u16 bitfield word (witness for ov068 callers).
 */
void func_0200837C(BF *p, unsigned int v) { p->a = (unsigned short)v; }


unsigned int func_02008390(char *a0){ return (unsigned int)(((struct Obj15571 *)a0)->f0 << 0x1a) >> 0x1e; }


void func_02008398(BF *p, unsigned int v) { p->b = (unsigned short)v; }


/*
 * Unlabelled leaf getter on a u16 bitfield word (witness for ov068 callers).
 */
unsigned int func_020083AC(BF *p) { return p->d; }


void func_020083B4(BF *p, unsigned int v) { p->d = (unsigned short)v; }


unsigned int func_020083C8(BF *p) { return p->c; }


void func_020083D0(BF *p, unsigned int v) { p->c = (unsigned short)v; }


/*
 * Unlabelled leaf accessor: bit 9 of the u16 at *p.
 */
int func_020083E4(unsigned short *p)
{
    return ((unsigned int)*p << 23) >> 31;
}


/*
 * Unlabelled Thumb leaf: set (or clear) bit 9 of the u16 at *p from the low
 * bit of v, re-read that bit, and tail-call func_020461D4 with it as a byte.
 * Mask pool word 0xFFFFFEFF, tail-target pool word 0x020461D4.
 */
void func_020083EC(unsigned short *p, unsigned int v)
{
    unsigned short w = (unsigned short)v;

    *p = (*p & 0xFFFFFEFF) | (((unsigned int)w << 31) >> 23);

    func_020461D4((unsigned char)(((unsigned int)*p << 23) >> 31));
}


/*
 * The packet 0x02008414..0x02008448 is three functions, two of which carry no
 * label in the generated listing (neither saves lr): the 14-byte wrapper at the
 * packet start and the two accessors at 0x02008428 and 0x02008430 that the
 * extent to the next label swallows.  All three reach the same halfword of the
 * object through a bitfield, which is why the read is an unequal lsls/lsrs
 * pair and the write of the middle one narrows its argument to the field's
 * u16 base type before shifting it into place.
 */
u8 func_02008414(const struct Flags02008414 *p)
{
    return func_020461D4((u8)p->b8);
}


/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
int func_02008428(unsigned short *p)
{
    return ((unsigned int)*p << 22) >> 31;
}


void func_02008430(BF *p, unsigned int v) { p->f = (unsigned short)v; }


unsigned int func_02008448(int a0){ return ((unsigned int)((((struct Obj15574 *)((char *)(a0)))->f0 << 0x15)) >> 0x1f); }


/*
 * Setter for bit 10 of a u16 flag word; func_02008448 (EXACT*, the four
 * bytes before it) is the matching getter.  An unlabelled leaf: it saves
 * no lr, so disasm.py never gave it a label, and its only reference in the
 * image is the tail-call pool word in func_02012BC8.  Filed as a compiled
 * witness for that call (class `matched`); wants seeding into
 * layout/function_starts.txt.
 */
void func_02008450(struct Flags02008450 *p, int on)
{
    p->flag = (u16)on;
}

int func_02008468(void){ return 0x20; }

void *func_0200846C(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x20, 0, g_020A70AC, 0x34);
    func_020084A0(p);
    return p;
}


/*
 * Copy of 0x20 bytes: a tail call through the pool with the length in r2.
 * Seeded in layout/function_starts.txt from the bl sites in ov010, ov011,
 * ov012, ov018, ov021 and others (w6_fix18).
 */
void func_02008494(void *src, void *dst)
{
    func_02082D44(src, dst, 0x20);
}


void func_020084A0(struct Sub0200852CObj *obj)
{
    func_02082BCC(obj, 0, 0x20);
    obj->unk1A = 2;
    func_02008560(obj, 0x15);
}

/*
 * A second whole translation unit, chosen because it contains literal pools
 * and a padding gap, which the accessor run at 0x0200852C does not.  Written
 * from the disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020084F8, sub_02008500, sub_02008510
 *
 * 0x020084BC..0x0200852C, 112 bytes, seven functions.  Three of the seven had
 * no label in the generated listing because they have no register-saving
 * prologue; they were recovered here by reading the bytes, and two of them
 * (0x020084D4 and 0x020084E4) are now seeded from layout/function_starts.txt
 * on the strength of the overlay calls that reach them, so the listing shows
 * them as code too.
 *
 * This range ends exactly where unit_0200852C.c begins, so the two files
 * together cover 0x020084BC..0x0200857C, 190 contiguous bytes and 23
 * functions, with no gap and no overlap.  They are almost certainly two
 * halves of one original source file, and both are EXACT.
 *
 * What this unit adds over unit_0200852C.c:
 *
 *   - two literal pools, one per function that needs one, each sitting at the
 *     end of its own function rather than at the end of the unit.
 *   - the same address, 0x0201F41C, is loaded by two different functions in
 *     the unit and is stored twice, once in each pool.  The compiler does not
 *     share a literal between two functions of the same translation unit
 *     even when they are adjacent and the value is identical.  That is the
 *     original image's own evidence for per-function pooling, independent of
 *     anything this project compiles.
 *   - a two-byte 0x00 gap after the empty function at 0x020084F4, which is
 *     the linker's inter-section fill.
 *
 * All six relocations resolve: the four pool words are ABS32 against
 * functions the listings label and other code calls directly, the blx is a
 * THM_CALL the compiler emitted as a plain bl (it cannot see that
 * func_020457B0 is ARM) and match.py rewrites to BLX exactly as the linker
 * would, and the bl to sub_02008500 is internal to this unit and follows
 * from where the unit is placed.  So the verdict is EXACT.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020084BC.c \
 *       --addr 0x020084BC --thumb
 */
int sub_020084BC(const u16 *values)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (values[i] != 0) {
            return 0;
        }
    }
    return 1;
}


/* Two argument-swapping tail calls.  The `ldr r3, <pool>; bx r3` shape is what */
/* -interworking produces for a tail call to an extern whose instruction set */
/* the compiler cannot see; 0x0201F41C is Thumb (the pool word is odd) and */
/* 0x02045A38 is ARM (it is even), and the same code covers both. */
u32 sub_020084D4(u32 value, void *dst)
{
    return sub_0201F41C(dst, value, 8);
}


void sub_020084E4(u16 *out, struct U16Vec *vec)
{
    sub_02045A38(vec, out, 8);
}

const void *sub_020084F4(const void *p)
{
    return p;
}


u32 sub_020084F8(void *dst, u32 value, u32 size)
{
    return sub_0201F41C(dst, value, size);
}


/* The argument swap survives into a tail call here too, but this one is 16 */
/* bytes rather than 12: the extra `adds` is the third scratch register the */
/* swap needs when only two arguments are live. */
void sub_02008500(void *a, void *b)
{
    sub_02045924(b, a);
}

/* call, not a u16 parameter: a u16 parameter is truncated by the caller. */
void *sub_02008510(void *a, int tag)
{
    void *p = sub_020457B0(8, (u16)tag);
    sub_02008500(a, p);
    return p;
}


/*
 * A whole translation unit, matched as one byte range rather than one
 * function at a time.  Written from the disassembly in
 * asm/arm9/src/001_02007664.s.
 *
 *           sub_02008540, sub_0200854C, sub_02008550, sub_02008554,
 *           sub_02008558, sub_0200855C, sub_02008560, sub_02008564,
 *           sub_02008568, sub_0200856C, sub_02008570, sub_02008574
 *
 * 0x0200852C..0x0200857C is 80 bytes of nothing but accessors on one object,
 * sixteen of them, and the address range is closed on both sides: the
 * function before it ends exactly at 0x0200852C and the function after it
 * starts exactly at 0x0200857C.  That preceding function is the last one in
 * unit_020084BC.c, so the two files together cover 0x020084BC..0x0200857C,
 * 190 contiguous bytes and 23 functions, with no gap and no overlap.
 *
 * Four of the sixteen carry no label in the
 * generated listing at all (0x0200852C, 0x02008540, 0x0200854C, 0x02008564),
 * because they have no register-saving prologue and disasm.py's labeller only
 * fires on one; they are recovered here by reading the bytes.
 *
 * The run is the TU-granularity experiment.  What it shows, in order:
 *
 *   - source order is emission order.  mwccarm writes one PROGBITS section
 *     per function, in the order the functions appear in the file, and the
 *     linker concatenates them in that order.  These sixteen are in the
 *     original's address order and nothing had to be permuted.
 *   - alignment padding is reproduced.  Two of the functions are an odd
 *     number of halfwords long (0x02008540 is 10 bytes, 0x02008574 is 6) and
 *     each is followed by two bytes of 0x00 before the next four-byte
 *     boundary.  That fill is the linker's, not the compiler's: it is the gap
 *     between two sections, and it is zero, where compiler-internal padding
 *     inside a section is a Thumb nop (0xC0 0x46).  Both kinds are visible in
 *     this neighbourhood; see docs/MATCHING.md.
 *   - there is no literal pool anywhere in the range, because no function in
 *     it references anything outside itself.  Pool placement is tested
 *     separately in docs/MATCHING.md, and it is per function, not per unit.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200852C.c \
 *       --addr 0x0200852C
 */
void sub_0200852C(struct Sub0200852CObj *obj, u32 value)
{
    obj->unk10 = value;
}

u32 sub_02008530(const struct Sub0200852CObj *obj)
{
    return obj->unk10;
}

u16 sub_02008534(const struct Sub0200852CObj *obj)
{
    return (u16)obj->unk10;
}

u32 sub_0200853C(const struct Sub0200852CObj *obj)
{
    return obj->unk14;
}

/* Set once: the store is skipped if the field is already non-zero.  The */
/* compare-and-branch is over the store, which is why this one function is 10 */
/* bytes and drags two bytes of fill in behind it. */
void sub_02008540(struct Sub0200852CObj *obj, u32 value)
{
    if (obj->unk14 == 0) {
        obj->unk14 = value;
    }
}

void sub_0200854C(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1D = value;
}

u8 sub_02008550(const struct Sub0200852CObj *obj)
{
    return obj->unk1D;
}

u8 sub_02008554(const struct Sub0200852CObj *obj)
{
    return obj->unk1C;
}

void sub_02008558(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1C = value;
}

u8 sub_0200855C(const struct Sub0200852CObj *obj)
{
    return obj->unk1B;
}

void sub_02008560(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1B = value;
}

u8 sub_02008564(const struct Sub0200852CObj *obj)
{
    return obj->unk1A;
}

void sub_02008568(struct Sub0200852CObj *obj, u8 value)
{
    obj->unk1A = value;
}

u8 sub_0200856C(const struct Sub0200852CObj *obj)
{
    return obj->unk18;
}

u8 sub_02008570(const struct Sub0200852CObj *obj)
{
    return obj->unk19;
}

void sub_02008574(struct Sub0200852CObj *obj, u8 a, u8 b)
{
    obj->unk18 = a;
    obj->unk19 = b;
}


/* playtime.c's constructor, and the function that gives the file its name. */
/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_0200864C, sub_02008650, sub_02008654, sub_02008658,
 *           sub_020086C8, sub_020086D0, sub_020086D8, sub_020086E0,
 *           sub_020086E8, sub_020086F0, sub_020086F8
 *
 * alias: the original source file is named in the image.  The function at
 * 0x0200857C, immediately before this range, loads 0x020A70B8 into its literal
 * pool as an argument to the debug allocator at 0x02030734, and the bytes at
 * 0x020A70B8 spell "playtime.c".  So this is the play-time counter: an eight
 * byte object holding an hours/minutes/seconds running total and a packed
 * calendar stamp of when the save was started.  The names below stay
 * sub_<address> because the individual entry points are not attested by
 * anything; the file identity is.
 *
 * Object layout, read off the accessors:
 *
 *   +0  u16  hours    saturating at 999 (0x3E7)
 *   +2  u8   minutes  0..59
 *   +3  u8   seconds  0..59
 *   +4  u32  a packed date/time: year:7, month:4, day:5, hour:5, minute:6,
 *            leaving the top five bits unused.  The five widths are readable
 *            three ways over and they agree: the AND masks 0xFFFFF87F,
 *            0xFFFF07FF, 0xFFE0FFFF and 0xF81FFFFF in sub_020085A0, the
 *            shift pairs in the five getters at 0x020086C8 and on, and the
 *            RTCDate / RTCTime fields sub_02008658 feeds them from.
 *
 * Two things in this unit were new for the project and are worth naming:
 *
 *  - the four unsigned divisions in sub_020085D4 compile to calls to the
 *    compiler's own runtime helper, which mwccarm emits as an undefined
 *    reference named `_u32_div_f`.  The relocation carries that name, so it
 *    can be pinned in the symbols: block like any other extern even though no
 *    line of this file mentions it; 0x0209C2B0 is attested as a label by 57
 *    callers elsewhere in the image.  `a / b` and `a % b` on the same operands
 *    produce two separate calls: the helper returns the quotient in r0 and the
 *    remainder in r1, but the compiler does not know that and does not common
 *    them up, which is why the original calls it twice in a row with identical
 *    arguments.
 *  - the packed field is a nested four-byte struct of bitfields, not five
 *    bitfields inlined into the outer object.  sub_020086F0 and sub_020086F8
 *    copy it whole with a single ldr/str pair, which is a struct assignment;
 *    with the bitfields flattened into PlayTime there is no lvalue of the
 *    right type to assign and the natural spellings all cost extra
 *    instructions.
 *
 * The unit starts at 0x0200857C, where the original file begins: the
 * constructor below is the function that names the file.  It passes
 * 0x020A70B8 to the debug allocator, and the bytes there spell "playtime.c".
 * That pool word is the only place in the image that names the string, so it
 * used to be unresolvable and the unit had to start at 0x020085A0 instead.
 * The `string` attestation class closes it: "mystatus.c" ends with its NUL at
 * 0x020A70B6, which fixes where the next string begins without reading the
 * pool word under test.  See "The string class" in docs/MATCHING.md.  This
 * file supersedes src/matched/unit_020085A0.c, which covered all of it but
 * the first 36 bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200857C.c \
 *       --addr 0x0200857C --thumb
 */
void *sub_0200857C(u32 heap)
{
    struct PlayTime *p = sub_02030734(heap, sizeof(struct PlayTime), 1,
                                      sub_0200857C_File, 32);
    sub_020085A0(p);
    return p;
}


void sub_020085A0(struct PlayTime *p)
{
    p->hours        = 0;
    p->minutes      = 0;
    p->seconds      = 0;
    p->stamp.year   = 0;
    p->stamp.month  = 0;
    p->stamp.day    = 0;
    p->stamp.hour   = 0;
    p->stamp.minute = 0;
}

/* Add `delta` seconds, carrying into minutes and hours and saturating at */
/* 999:59:59.  The leading guard is the saturation test, and it returns */
/* without touching the object once the counter is full. */
void sub_020085D4(struct PlayTime *p, u32 delta)
{
    u32 h, m, s;

    h = p->hours;
    if (h == 999 && p->minutes == 59 && p->seconds == 59) {
        return;
    }
    s = p->seconds + delta;
    m = p->minutes;
    if (s > 59) {
        m += s / 60;
        s = s % 60;
        if (m > 59) {
            h += m / 60;
            m = m % 60;
            if (h >= 999) {
                h = 999;
                m = 59;
                s = 59;
            }
        }
    }
    p->hours   = h;
    p->minutes = m;
    p->seconds = s;
}

void sub_0200863C(struct PlayTime *dest, const struct PlayTime *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PlayTime));
}

u16 sub_0200864C(const struct PlayTime *p)
{
    return p->hours;
}

u8 sub_02008650(const struct PlayTime *p)
{
    return p->minutes;
}

u8 sub_02008654(const struct PlayTime *p)
{
    return p->seconds;
}

/* Stamp the object with the wall clock. */
void sub_02008658(struct PlayTime *p)
{
    struct RTCDate date;
    struct RTCTime time;

    RTC_GetDate(&date);
    RTC_GetTime(&time);

    p->stamp.year   = date.year;
    p->stamp.month  = date.month;
    p->stamp.day    = date.day;
    p->stamp.hour   = time.hour;
    p->stamp.minute = time.minute;
}

u32 sub_020086C8(const struct PlayTime *p)
{
    return p->stamp.year;
}

u32 sub_020086D0(const struct PlayTime *p)
{
    return p->stamp.month;
}

u32 sub_020086D8(const struct PlayTime *p)
{
    return p->stamp.day;
}

u32 sub_020086E0(const struct PlayTime *p)
{
    return p->stamp.hour;
}

u32 sub_020086E8(const struct PlayTime *p)
{
    return p->stamp.minute;
}

void sub_020086F0(const struct PlayTime *p, struct PlayTimeStamp *out)
{
    *out = p->stamp;
}

void sub_020086F8(struct PlayTime *p, const struct PlayTimeStamp *in)
{
    p->stamp = *in;
}


#define BLOCK_ID_1B 0x1B


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008748, sub_02008754, sub_02008764, sub_02008774,
 *           sub_02008784, sub_020087A8, sub_020087C0, sub_020087D4,
 *           sub_020087E8, sub_02008808
 *
 * alias: a save block and its accessors.  The unit is bounded on both sides by
 * the "how big is my block" function each of these files opens with:
 * sub_02008700 returns 0x68, which is exactly what sub_02008704 clears, and
 * the four bytes at 0x02008828 are the same two instructions returning 0x9C,
 * which is what the function after them clears.  So the range is
 * 0x02008700..0x02008828, 296 bytes and fourteen functions, closed at both
 * ends by that shape.
 *
 * Every accessor here reaches its object the same way: sub_020071CC(sys, 0x1B).
 * 0x1B is this block's id, and the call is the only thing the fourteen
 * functions have in common, which is what says they are one file.  The three
 * sub-objects sub_02008704 initialises identify the layout:
 *
 *   +0x00  4 bytes   initialised by sub_02008320
 *   +0x04  0x20      the accessor object of unit_0200852C.c, initialised by
 *                    sub_020084A0, which is the function immediately before
 *                    unit_020084BC.c and calls sub_02008560 out of it
 *   +0x24  8 bytes   the playtime object of unit_020085A0.c
 *   +0x2C  u8        a flag, set by sub_02008764 and cleared by sub_02008774
 *   +0x30  u16[10]   a table of marks, each either 0 or 0xC21E
 *   +0x44  u32[9]    a table sub_020087D4 hands out addresses into
 *                    (0x44 + 9 * 4 = 0x68, which closes the object)
 *
 * Two shapes in here are worth naming:
 *
 *  - sub_020087E8 and sub_02008808 copy the 0x20-byte sub-object in and out
 *    with four ldm/stm pairs and no call.  That is a plain struct assignment:
 *    mwccarm inlines an aggregate copy of this size rather than calling a
 *    memcpy, and it uses the padded sizeof (0x20) rather than the 0x1E bytes
 *    of declared members.
 *  - sub_0200873C is a tail call through a pool word with the second argument
 *    set up first (`ldr r3, =sub_020071CC+1; movs r1, #0x1B; bx r3`), which is
 *    what `return sub_020071CC(sys, 0x1B);` compiles to when nothing follows
 *    the call.  Its neighbours all do something to the result and therefore
 *    keep a real frame.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008700.c \
 *       --addr 0x02008700 --thumb
 */
u32 sub_02008700(void)
{
    return sizeof(struct Sub02008700Obj);
}


void sub_02008704(struct Sub02008700Obj *obj)
{
    MIi_CpuClear32(0, obj, sizeof(struct Sub02008700Obj));
    sub_02008320((struct Flags02008320 *)(&obj->unk00));
    sub_020084A0(&obj->unk04);
    sub_020085A0(&obj->unk24);
    obj->unk2C = 0;
}

struct Sub0200852CObj *sub_02008730(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    return &obj->unk04;
}

struct Sub02008700Obj *sub_0200873C(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID_1B);
}

struct PlayTime *sub_02008748(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    return &obj->unk24;
}

u8 sub_02008754(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    return obj->unk2C;
}

void sub_02008764(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    obj->unk2C = 1;
}

void sub_02008774(void *sys)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    obj->unk2C = 0;
}

int sub_02008784(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    if (obj->unk30[index] == 0xC21E) {
        return 1;
    }
    return 0;
}

void sub_020087A8(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    obj->unk30[index] = 0xC21E;
}

void sub_020087C0(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    obj->unk30[index] = 0;
}

u32 *sub_020087D4(void *sys, u32 index)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    return &obj->unk44[index];
}

void sub_020087E8(void *sys, const struct Sub020087E8Arg *src)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    obj->unk04 = src->unk20;
}

void sub_02008808(void *sys, struct Sub020087E8Arg *dest)
{
    struct Sub02008700Obj *obj = sub_020071CC(sys, BLOCK_ID_1B);
    dest->unk20 = obj->unk04;
}


#define BLOCK_ID_1C 0x1C


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_0200884C, sub_02008850, sub_02008854, sub_02008860,
 *           sub_020088B8, sub_0200890C, sub_0200892C, sub_0200893C,
 *           sub_0200894C, sub_02008954, sub_0200895C, sub_02008964,
 *           sub_0200896C, sub_02008970, sub_02008978, sub_02008980,
 *           sub_02008988, sub_02008990, sub_02008998, sub_020089A0
 *
 * alias: the save block with id 0x1C, 0x9C bytes, and its accessors.  The
 * range is closed the same way unit_02008700.c is: it opens with the four
 * bytes that return the block size (0x9C, which is what sub_0200882C clears)
 * and ends where the next such function returns 0x658, at 0x020089A8.  That is
 * the whole 384-byte, twenty-four function file.
 *
 * It was committed as two files for a while, because the pair at 0x0200892C
 * and 0x0200893C reach 0x02014468 and 0x02014464 and nothing else in
 * arm9_main does, so neither address had a witness outside the bytes under
 * test.  Both do have one: ov010 and ov020 branch to them, 0x02014464 is
 * seeded into layout/function_starts.txt from those branches so disasm.py
 * labels it, and cross-region branches now count as `label` evidence.  The
 * file is one unit again and src/matched/unit_0200894C.c is gone.
 *
 * Layout, from the accessors:
 *
 *   +0x00  0x38     untouched here
 *   +0x38  0x1C     handed out by sub_02008848
 *   +0x54  0x1C     handed out by sub_0200884C
 *   +0x70  2        handed out by sub_02008850
 *   +0x72  u8       written and read by the two unverifiable functions
 *   +0x73  u8
 *   +0x74  u8
 *   +0x76  u16      the only field sub_0200882C seeds, with 0x1AB
 *   +0x78  u32
 *   +0x7C  u16
 *   +0x7E  u16
 *   +0x80  0x1C     a record, copied in and out field by field by
 *                   sub_02008860 and sub_020088B8 and copied whole by
 *                   sub_0200890C
 *
 * Four of the ten carry no label in the generated listing: they are
 * two-instruction accessors with no register-saving prologue, so disasm.py's
 * sweep never fires on them and the listing emits them as data words.  They
 * were read out of the bytes.
 *
 * Three details pinned this one:
 *
 *  - the record at +0x80 and the buffer sub_02008860 fills it from are not the
 *    same type, even though their first 0x1C bytes line up.  Two fields cross
 *    over: the record's +0x1A comes from the buffer's +0x1B, and the record's
 *    +0x1B comes from the buffer's +0x40, a word truncated to a byte.  Writing
 *    it as one struct assignment collapses the whole function to an ldm/stm
 *    run and is 80 bytes short.
 *  - the twelve bytes at +0x04 of the record are a nested struct, for the same
 *    reason as in unit_02008700.c: they move as one ldm/stm pair plus a
 *    trailing word while the halfwords around them move one at a time.
 *  - the record's +0x18 is signed and the buffer's is not.  sub_020088B8 reads
 *    it with `movs r0, #0x98; ldrsh r0, [r2, r0]` where every other read in the
 *    function is an immediate-offset ldrh; ldrsh has no immediate form, so the
 *    signedness of one field is what costs that instruction its extra
 *    register.  sub_02008860, going the other way, uses a plain ldrh.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008828.c \
 *       --addr 0x02008828 --thumb
 */
u32 sub_02008828(void)
{
    return sizeof(struct Sub02008828Obj);
}


void sub_0200882C(struct Sub02008828Obj *obj)
{
    MI_CpuFill8(obj, 0, sizeof(struct Sub02008828Obj));
    obj->unk76 = 0x1AB;
}

void sub_02008844(void)
{
}

void *sub_02008848(struct Sub02008828Obj *obj)
{
    return obj->unk38;
}

void *sub_0200884C(struct Sub02008828Obj *obj)
{
    return obj->unk54;
}

void *sub_02008850(struct Sub02008828Obj *obj)
{
    return obj->unk70;
}

struct Sub02008828Obj *sub_02008854(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID_1C);
}

void sub_02008860(void *sys, const struct Sub02008860Buf *src)
{
    struct Sub02008828Obj *obj = sub_02008854(sys);

    obj->unk80.unk00 = src->unk00;
    obj->unk80.unk04 = src->unk04;
    obj->unk80.unk10 = src->unk10;
    obj->unk80.unk12 = src->unk12;
    obj->unk80.unk14 = src->unk14;
    obj->unk80.unk16 = src->unk16;
    obj->unk80.unk18 = src->unk18;
    obj->unk80.unk1A = src->unk1B;
    obj->unk80.unk1B = src->unk40;
}

void sub_020088B8(void *sys, struct Sub02008860Buf *dest)
{
    struct Sub02008828Obj *obj = sub_02008854(sys);

    dest->unk00 = obj->unk80.unk00;
    dest->unk04 = obj->unk80.unk04;
    dest->unk10 = obj->unk80.unk10;
    dest->unk12 = obj->unk80.unk12;
    dest->unk14 = obj->unk80.unk14;
    dest->unk16 = obj->unk80.unk16;
    dest->unk18 = obj->unk80.unk18;
    dest->unk1B = obj->unk80.unk1A;
    dest->unk40 = obj->unk80.unk1B;
}

void sub_0200890C(void *sys, struct Sub02008828Rec *dest)
{
    struct Sub02008828Obj *obj = sub_02008854(sys);

    *dest = obj->unk80;
}

/* The getter/setter pair on some other object's byte at +6, through which the */
/* +0x72 field of this block is exchanged.  Both are four-byte leaves in the */
/* middle of a literal-pool run at 0x02014464 and 0x02014468, and neither is */
/* reachable from anything else in arm9_main, which is why these two functions */
/* were the last unverifiable ones in this file.  See "The two near misses in */
/* this run" in docs/MATCHING.md. */
extern u8 sub_02014468(struct Sub02014444Obj *o);


void sub_0200892C(struct Sub02008828Obj *obj, const void *src)
{
    obj->unk72 = sub_02014468((struct Sub02014444Obj *)src);
}

void sub_0200893C(const struct Sub02008828Obj *obj, void *dest)
{
    sub_02014464(dest, obj->unk72);
}

void sub_0200894C(struct Sub02008828Obj *obj, u8 value)
{
    obj->unk73 = value;
}

void sub_02008954(const struct Sub02008828Obj *obj, u8 *out)
{
    *out = obj->unk73;
}

void sub_0200895C(struct Sub02008828Obj *obj, u8 value)
{
    obj->unk74 = value;
}

void sub_02008964(const struct Sub02008828Obj *obj, u8 *out)
{
    *out = obj->unk74;
}

void sub_0200896C(struct Sub02008828Obj *obj, u32 value)
{
    obj->unk78 = value;
}

void sub_02008970(const struct Sub02008828Obj *obj, u32 *out)
{
    *out = obj->unk78;
}

u16 sub_02008978(const struct Sub02008828Obj *obj)
{
    return obj->unk7C;
}

void sub_02008980(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk7C = value;
}

void sub_02008988(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk7E = value;
}

u16 sub_02008990(const struct Sub02008828Obj *obj)
{
    return obj->unk7E;
}

u16 sub_02008998(const struct Sub02008828Obj *obj)
{
    return obj->unk76;
}

void sub_020089A0(struct Sub02008828Obj *obj, u16 value)
{
    obj->unk76 = value;
}


#define BLOCK_ID_21 0x21


