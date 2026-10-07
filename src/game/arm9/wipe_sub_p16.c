/*
 * file:     wipe_sub_p16.c
 * unit:     yes
 * function: func_02024224, func_02024230, func_0202428C, func_020242A4, func_020242C0, func_020242D8, func_02024344, func_0202435C, func_02024368, func_0202441C
 * address:  0x02024224
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
 *   func_020355D8 0x020355D8 arm
 *   _ll_mul        0x0209C054  arm
 *   tbl_020A1B38   0x020A1B38  data
 *   func_02024598  0x02024598  thumb
 *   Table_0209F724   0x0209F724  data
 *   func_0201EC64    0x0201EC64  thumb
 *   func_0201ED04    0x0201ED04  thumb
 *   func_0201EFC8    0x0201EFC8  thumb
 *   func_0201EFFC    0x0201EFFC  thumb
 *   func_0201F250    0x0201F250  thumb
 *   func_020457B0    0x020457B0  arm
 *   func_02045808    0x02045808  arm
 *   func_02045B38    0x02045B38  arm
 *   func_02045C04    0x02045C04  arm
 *   func_02045EC0    0x02045EC0  arm
 *   sub_02045B38    0x02045B38  arm
 *   sub_02045EC0    0x02045EC0  arm
 */
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
typedef unsigned short   u16;

typedef signed short     s16;

typedef signed int       s32_02024230;

typedef unsigned int     u32;

typedef signed long long s64;

typedef int             s32_0202428C;

typedef int             s32;

typedef unsigned char  u8;

struct Struct_0202441C {
    u16 arcFileIdx;
    u16 strIdx;
};

extern void func_020355D8(void *);
extern void func_02024598(void *p0, int p1, int p2);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFC8(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFFC(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void  *func_020457B0(u32 size, u16 heap);
extern void func_02045808(struct U16Vec *vec);
extern void  *func_02045B38(int a, int b, u32 id, u16 heap);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
void func_02024224(void *a,void *b);
void func_02024230(s16 *out, u32 count, u16 step, s32_02024230 amp);
void sub_0202428C(void *obj);
void func_020242A4(void *obj, u32 id);
void func_020242C0(void *a, void *b, void *c);
void func_020242D8(void *slot, u32 idx);
void func_02024344(void *obj);
void *func_0202435C(void *slots, unsigned int heap);
void *sub_02024368(u16 *slots, u32 heap, int count);
extern const s16 tbl_020A1B38[];
extern u16 Table_0209F724[];



/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
void func_02024224(void *a,void *b) { func_020355D8(b); }




/*
 * pmsi_param.c: fill out[0..count) with amp * sin(phase), phase advancing
 * by step through 16 bits.  The table is FX_SinCosTable_ at 0x020A1B38
 * (sin/cos s16 pairs, hence the stride of two halfwords: the SDK's
 * FX_SinIdx); the old notes misread the pool word as 0x02021B38.
 *
 * The last byte of docs/notes/func_02024230.c.txt was the phase type: it is
 * a plain u16.  The wrap is then `lsrs` (u16 narrowing) and the index is
 * still `asrs` because the u16 promotes to int before the shift.  The s64
 * temporary for the widened table value is the permuter's find from wave 5.
 */
void func_02024230(s16 *out, u32 count, u16 step, s32_02024230 amp)
{
    u32 i;
    u16 phase;

    phase = 0;
    i = 0;
    while (i < count) {
        s64 v = (s64)tbl_020A1B38[(phase >> 4) * 2];
        s64 prod = v * (s64)amp;

        out[i] = (s16)((s32_02024230)((prod + 0x800) >> 12) >> 12);
        i++;
        phase = (u16)(phase + step);
    }
}




/*
 * A slot-clearing sibling of func_020242A4 (src/matched/sub_020242A4.c):
 * the same three-halfword sentinel fill, but the leading id field is
 * also set to the sentinel instead of taking a caller-supplied id, so
 * there is no second parameter. The loop counter is signed, the same
 * `blt` tell as the sibling function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202428C.c \
 *       --func sub_0202428C --addr 0x0202428C --cc 1.1p1 --thumb
 */
void sub_0202428C(void *obj)
{
    u16 *p = (u16 *)obj;
    s32_0202428C i;

    p[0] = 0xFFFF;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}




/*
 * The common slot initialiser shared by func_02024344 and the four arms of
 * func_020242D8 (src/matched/unit_020242D8.c): store the id, zero the
 * flag halfword at +2, then a two-iteration loop seeds the trailing
 * halfwords at +4 and +6 with a shared 0xFFFF sentinel. The loop counter
 * is signed (the original's `blt`, not `blo`, on a literal trip count of
 * 2); an unsigned counter compiles to `blo` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020242A4.c \
 *       --func func_020242A4 --addr 0x020242A4 --cc 1.1p1 --thumb
 */
void func_020242A4(void *obj, u32 id)
{
    u16 *p = (u16 *)obj;
    s32 i;

    p[0] = (u16)id;
    p[1] = 0;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}




void func_020242C0(void *a, void *b, void *c)
{
    func_020242A4(a, (u32)b);
    func_02024598(a, (int)b, (int)c);
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * func_020242D8 dispatches on a 0..3 index through a dense jump table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md); an index
 * over 3 lands on the shared epilogue with neither a call nor a store,
 * which only a `default: break;` with nothing else in it produces. Each
 * arm calls the shared initialiser func_020242A4 (its own file,
 * src/matched/sub_020242A4.c, EXACT) with a small id, then overwrites the
 * flag halfword and one trailing field with plain 16-bit constants; the
 * four constants are narrowed by the `strh`, not addresses. Case 3 passes
 * the same id as case 1 (2) but a different flag (0xd instead of 0), so
 * the four arms cannot be collapsed by id alone.
 *
 * func_02024344 is the same shape as one switch arm inlined outside a
 * switch: call func_020242A4 with id 0, then overwrite the flag and
 * trailing field it just set.
 *
 * The two functions are contiguous with no gap: func_020242D8's own
 * literal pool (the four constants) runs right up to func_02024344's
 * entry point.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020242D8.c \
 *       --addr 0x020242D8 --thumb
 */
void func_020242D8(void *slot, u32 idx)
{
    u16 *p = (u16 *)slot;

    switch (idx) {
    case 0:
        func_020242A4(slot, 1);
        p[1] = 0;
        p[2] = 0x5D2;
        break;
    case 1:
        func_020242A4(slot, 2);
        p[1] = 0;
        p[2] = 0x5CD;
        break;
    case 2:
        func_020242A4(slot, 3);
        p[1] = 0;
        p[2] = 0x667;
        break;
    case 3:
        func_020242A4(slot, 2);
        p[1] = 0xd;
        p[2] = 0x573;
        break;
    default:
        break;
    }
}




void func_02024344(void *obj)
{
    u16 *p = (u16 *)obj;

    func_020242A4(obj, 0);
    p[1] = 1;
    p[2] = 0x58F;
}




/*
 * sub_02024368 with a count of 2: a tail call through the pool.  Seeded in
 * layout/function_starts.txt from the bl sites in ov010, ov069 and ov093
 * (w6_fix18).
 */
void *func_0202435C(void *slots, unsigned int heap)
{
    return sub_02024368(slots, heap, 2);
}




/*
 * Archived graphics-slot loader: opens the bank named by the id table at
 * 0x0209F724 for the requested stream, unpacks a scratch buffer out of
 * it, and walks the caller's two-halfword slot array telling the slot
 * manager what each entry is.
 *
 * A slot word of 0xffff means "empty" and is registered with the
 * fixed-size flag; otherwise bit 11 of the word says whether the value
 * carries a 0x7ff payload (registered masked) or is a plain size
 * (registered whole).  The two branches into the size-carrying
 * registration merge on one call site, so they are written as two
 * separate calls in the source and left to the compiler.
 *
 * The 0x100 buffer request is materialised as `movs r5, #2` followed by
 * `adds r5, #0xfe`: the 2 already sits in r5 from the previous call's
 * argument, and 2 + 0xfe is four bytes either way.
 */
void *sub_02024368(u16 *slots, u32 heap, int count)
{
    void *obj;
    void *buf;
    void *slot;
    void *k;
    int i;

    obj = func_0201EC64((u16)heap);
    for (i = 0; i < count; i++) {
        u16 v = slots[i + 2];

        if (v != 0xffff) {
            if ((v >> 11) & 1) {
                func_0201EFFC(obj, i, v & 0x7ff);
            } else {
                func_0201EFC8(obj, i, v);
            }
        } else {
            func_0201EFFC(obj, i, 1);
        }
    }
    slot = func_02045B38(0, 2, Table_0209F724[slots[0]], (u16)heap);
    buf = func_020457B0(0x100, (u16)heap);
    k = func_02045EC0(slot, slots[1]);
    func_0201F250(obj, buf, k);
    func_02045808(k);
    func_02045C04(slot);
    func_0201ED04(obj);
    return buf;
}


void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId)
{
    void *str;
    void *bank;
    u16 hid = (u16)heapId;

    bank = sub_02045B38(0, 2, Table_0209F724[obj->arcFileIdx], hid);
    str = sub_02045EC0(bank, obj->strIdx);
    func_02045C04(bank);

    return str;
}
