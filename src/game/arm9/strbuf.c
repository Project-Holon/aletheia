/*
 * file:     strbuf.c
 * unit:     yes
 * function: STRBUF_SetEosChar, STRBUF_Create, STRBUF_Delete, STRBUF_Clear, STRBUF_Copy, STRBUF_Clone, STRBUF_IsEqual, STRBUF_GetLength, STRBUF_Truncate, STRBUF_SetString, STRBUF_SetStringN, STRBUF_SetChars, STRBUF_ToChars, STRBUF_GetChars, STRBUF_GetEosChar, STRBUF_Append, STRBUF_AppendChar
 * address:  0x020457A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from bmp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   sStrbufStatics  0x020A7E7C  data
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "bmp_shared_types.h"

struct Strbuf;

/*
 * The data at 0x020A7E7C is one small object, not two independent
 * words: STRBUF_Create loads 0x020A7E80 out of a pool as the allocators
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */
struct StrbufStatics {
    u16  eosChar;    /* 0x020A7E7C, the end-of-string code (0xFFFF) */
    u16  pad;
    char file[1];    /* 0x020A7E80, the "strbuf.c" file name handed to the allocator */
};

#define STRBUF_MAGIC 0xB6F8D2ECu

/* A bounded string of u16 characters; chars[] holds capacity entries plus the end code. */
struct Strbuf {
    u16 capacity;    /* +0x00 */
    u16 length;      /* +0x02 */
    u32 magic;       /* +0x04, STRBUF_MAGIC while live */
    u16 chars[1];    /* +0x08 */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void STRBUF_SetEosChar(u16 eosChar);

struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

void STRBUF_Delete(struct Strbuf *strbuf);

void STRBUF_Clear(struct Strbuf *strbuf);

void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);

struct Strbuf *STRBUF_Clone(struct Strbuf *src, u32 heapId);

int STRBUF_IsEqual(struct Strbuf *lhs, struct Strbuf *rhs);

u16 STRBUF_GetLength(struct Strbuf *strbuf);

void STRBUF_Truncate(struct Strbuf *strbuf, u32 newLength);

void STRBUF_SetString(struct Strbuf *strbuf, const u16 *srcChars);

void STRBUF_SetStringN(struct Strbuf *strbuf, const u16 *srcChars, u32 charCount);

void STRBUF_SetChars(struct Strbuf *strbuf, const void *srcChars, u32 charCount);

void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 maxChars);

u16 *STRBUF_GetChars(struct Strbuf *strbuf);

u16 STRBUF_GetEosChar(void);

void STRBUF_Append(struct Strbuf *dst, struct Strbuf *src);

void STRBUF_AppendChar(struct Strbuf *strbuf, u16 ch);

extern struct StrbufStatics sStrbufStatics;

/*
 * Setter for the allocator family's global u16 stamp at 0x020A7E7C: the
 * value every object of this family copies into its own +0x8 field when
 * it is constructed (STRBUF_Create) or reset (STRBUF_Clear). Those two
 * functions are its readers, and their literal pools at 0x02045804 and
 * 0x02045834 are the outside witnesses for this file's own pool word,
 * which is why the three are kept in separate files rather than folded
 * into one unit: a single tu over 0x020457A0..0x02045838 would swallow
 * every pool copy of the address and cap at MATCH
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * 0x020A7E7C sits immediately before the __FILE__ string at 0x020A7E80
 * that STRBUF_Create passes to the allocator, so it is the last word of
 * data before the packed string area.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetEosChar.c \
 *       --func STRBUF_SetEosChar --addr 0x020457A0 --cc 1.1p1 --arm
 */
void STRBUF_SetEosChar(u16 eosChar)
{
    sStrbufStatics.eosChar = eosChar;
}

/*
 * The constructor of the u16-array object, and a clean specimen of the
 * debug-allocator calling convention this whole family is built on:
 *
 *   GFL_HEAP_Alloc(heapId, size, clear, site, tag)
 *
 * The fifth argument is a u16 passed on the stack, which the callee reads
 * back with a halfword load at [sp, #0x18]; here it is 100. It looks like
 * a __LINE__-style debug tag, but that is not established: the fourth
 * argument, which would be the matching __FILE__, is 0x020A7E80, and that
 * address is above the arm9 static image end (0x020A6800, from
 * layout/layout.json), so it is BSS, not a string constant in a packed
 * string area. Whatever the pair means, it is not the literal
 * __FILE__/__LINE__ shape of
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md, and it is
 * deliberately not written as such here.
 *
 * The allocation size, 2 * capacity + 0xa, is what pins the object
 * layout: a 0xa-byte header followed by capacity u16 entries.
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic, 0xECD2F8B6 while live
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The zero that becomes the allocator's third argument is the same
 * register that later stores `used = 0`, so the two share one `mov
 * r4, #0`; writing the third argument as a named local instead splits
 * them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Create.c \
 *       --func STRBUF_Create --addr 0x020457B0 --cc 1.1p1 --arm
 */
struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId)
{
    struct Strbuf *strbuf;

    strbuf = (struct Strbuf *)GFL_HEAP_Alloc(heapId, capacity * 2 + 0xa, 0,
                                        sStrbufStatics.file, 100);
    strbuf->magic = STRBUF_MAGIC;
    strbuf->capacity = (u16)capacity;
    strbuf->length = 0;
    strbuf->chars[0] = sStrbufStatics.eosChar;
    return strbuf;
}

/*
 * The destructor of the u16-array object STRBUF_Create builds: it kills
 * the 0xECD2F8B6 liveness magic at +0x4 and then tail-calls the family's
 * generic free at 0x020307B0, which is the counterpart of the allocation
 * entry at 0x02030734 (it is also what BMP_WIN_Delete finishes with).
 * Clearing the magic before the free is what makes a stale pointer
 * detectable rather than merely dangling.
 *
 * The tail call is the usual shape for this compiler: one section per
 * function means no displacement branch is available, so the target
 * becomes a pool word and a bx
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). The pool word at
 * 0x02045818 is the whole reason the listing extent runs to 0x0204581C.
 *
 * layout/symbols_sdk.json carries the name ENV_SetResourceSet for
 * 0x020307B0. That looks like a signature-matcher false positive rather
 * than a real SDK export (0x020307B0 is game code in arm9_main and its
 * only observed role here is teardown), so the canonical sub_ name is
 * used instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Delete.c \
 *       --func STRBUF_Delete --addr 0x02045808 --cc 1.1p1 --arm
 */
void STRBUF_Delete(struct Strbuf *strbuf)
{
    strbuf->magic = 0;
    GFL_HEAP_Free(strbuf);
}

/*
 * Resets one of the allocator family's u16-array objects in place: drops
 * the used count back to zero and re-stamps the object from the global at
 * 0x020A7E7C. It is the constructor body of STRBUF_Create minus the
 * allocation, the capacity store and the magic store, so it is the "reuse
 * this buffer" entry of the pair.
 *
 * The object shape, from STRBUF_Create's allocation of 2 * capacity + 0xa
 * bytes:
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic (0xECD2F8B6 when live, 0 once STRBUF_Delete kills it)
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The pool word is attested by the copies in STRBUF_SetEosChar and
 * STRBUF_Create, which is why this function is its own file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Clear.c \
 *       --func STRBUF_Clear --addr 0x0204581C --cc 1.1p1 --arm
 */
void STRBUF_Clear(struct Strbuf *strbuf)
{
    strbuf->length = 0;
    strbuf->chars[0] = sStrbufStatics.eosChar;
}

/*
 * Copies the live part of one u16-array object into another, refusing the
 * copy if the destination cannot hold it. The guard is `capacity <=
 * used`, not `<`, so the destination needs strictly more capacity than
 * the source has entries; the extra slot is the +0x8 stamp, which the
 * copy carries along by starting two bytes before the entry array and
 * moving (used + 1) halfwords.
 *
 * See src/matched/STRBUF_Create.c for the object layout. The trailing
 * `dst->used = src->used` re-reads the field rather than reusing the
 * cached value the guard and the length computation share: the two
 * objects are unrelated pointers, so the MI_CpuCopy8 call may alias
 * src->used and the load cannot be hoisted across it. Writing the tail as
 * an assignment from the cached local instead loses that reload and four
 * bytes with it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Copy.c \
 *       --func STRBUF_Copy --addr 0x02045838 --cc 1.1p1 --arm
 */
void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src)
{
    u16 length;

    length = src->length;
    if (dst->capacity <= length) {
        return;
    }
    MI_CpuCopy8(&src->chars[0], &dst->chars[0], (length + 1) * 2);
    dst->length = src->length;
}

/*
 * Clones a u16-array object: allocate one with exactly enough room
 * (used + 1 slots, the +1 being the stamp slot that STRBUF_Copy's guard
 * insists on), then copy into it.
 *
 * The heap id is never touched in this function's body. STRBUF_Create
 * takes (capacity, heapId) and only r0 is set up here, so r1 arrives
 * untouched from this function's own second parameter: the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse, where the "leftover" register really is a passed
 * argument and naming it is what makes the code compile to two
 * instructions instead of three.
 *
 * `used + 1` reaches STRBUF_Create with no narrowing, which is what pins
 * that function's first parameter to a full word rather than the u16 its
 * own body would suggest: see
 * docs/idioms/a-missing-truncation-at-the-call-site-widens-the-parameter.md.
 * With a u16 prototype this function comes out eight bytes long and
 * STRBUF_Create still matches, so the call site is the only evidence for
 * the width.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Clone.c  *       --func STRBUF_Clone --addr 0x02045874 --cc 1.1p1 --arm
 */
struct Strbuf *STRBUF_Clone(struct Strbuf *src, u32 heapId)
{
    struct Strbuf *clone;

    clone = STRBUF_Create(src->length + 1, heapId);
    STRBUF_Copy(clone, src);
    return clone;
}

/*
 * Halfword-string equality with the buffer module's terminator stamp: the
 * first element is compared directly, then the loop walks both strings while
 * they agree, succeeding as soon as either side meets the global terminator
 * (0xFFFF) rather than the other buffer.
 *
 * Two shapes are load-bearing:
 *  - `int i = 0;` at its declaration puts the `mov ip, #0` ahead of the
 *    guard's compare; assigning i after the guard lands it after the
 *    terminator pool load instead.
 *  - The guard must NOT be a bare `if (..) return 0;`: mwcc predicates that
 *    into `movne r0, ip; popne {r3, pc}`.  Folding it into one shared exit
 *    (the `if (a->w[0] == b->w[0])` arm holding the loop, a single
 *    `return 0;` after it) makes the guard a real `bne` to that exit, which
 *    is what the image has.  The identical `goto fail` spelling compiles to
 *    the same bytes.
 *
 * The 0x020A7E7C ABS32 sits in this function's own pool (0x020458F4, inside
 * the compared range) and resolves off the `literal` class: the same word is
 * in the pools of the already-matched STRBUF_SetString, STRBUF_SetStringN and
 * STRBUF_SetEosChar.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_IsEqual.c \
 *       --func STRBUF_IsEqual --addr 0x0204589C --cc 1.1p1 --arm
 */
int STRBUF_IsEqual(struct Strbuf *lhs, struct Strbuf *rhs)
{
    int index = 0;

    if (lhs->chars[0] == rhs->chars[0]) {
        do {
            if (lhs->chars[index] == sStrbufStatics.eosChar) {
                return 1;
            }
            index++;
        } while (lhs->chars[index] == rhs->chars[index]);
    }

    return 0;
}

/*
 * Reads the used-slot count of a u16-array object (see
 * src/matched/STRBUF_Create.c for the layout). A relocation-free leaf; it
 * is the public reader for the field STRBUF_Truncate and STRBUF_Copy write
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetLength.c  *       --func STRBUF_GetLength --addr 0x020458F8 --cc 1.1p1 --arm
 */
u16 STRBUF_GetLength(struct Strbuf *strbuf)
{
    return strbuf->length;
}

/*
 * Truncates a u16-array object back to `index` slots, writing the stamp
 * into the slot that becomes the new terminator. It is the inverse of
 * whatever appends, and it is a no-op when `index` is not strictly below
 * the current count, so it can only ever shrink.
 *
 * The whole body is predicated on `lo` with no branch at all, which is
 * why the guard has to be an unsigned comparison: `index` is a full u32
 * (nothing masks it before `add r3, r0, r1, lsl #1`) while `used` is a
 * zero-extended u16, so the comparison is unsigned on both sides and a
 * signed `int` index produces `lt` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Truncate.c  *       --func STRBUF_Truncate --addr 0x02045900 --cc 1.1p1 --arm
 */
void STRBUF_Truncate(struct Strbuf *strbuf, u32 newLength)
{
    if (newLength < strbuf->length) {
        strbuf->chars[newLength] = sStrbufStatics.eosChar;
        strbuf->length = newLength;
    }
}

/*
 * strbuf.c's `strcpy`-into-a-bounded-buffer: the terminator is the halfword
 * at 0x020A7E7C (0xFFFF), the buffer's capacity is the halfword at +0 and
 * the count is kept at +2, with the halfword array starting at +8.  The
 * first copy stops on the terminator, the second on a full buffer, and the
 * terminator is always written at the end - which is why the exit block is
 * shared and why the count is re-read there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetString.c \
 *       --func STRBUF_SetString --addr 0x02045924 --cc 1.1p1 --arm
 */
void STRBUF_SetString(struct Strbuf *strbuf, const u16 *srcChars)
{
    strbuf->length = 0;
    while (*srcChars != sStrbufStatics.eosChar) {
        if (strbuf->length >= strbuf->capacity - 1)
            break;
        strbuf->chars[strbuf->length++] = *srcChars;
        srcChars++;
    }
    strbuf->chars[strbuf->length] = sStrbufStatics.eosChar;
}

/*
 * strbuf.c's bounded copy of a counted string: refuse anything longer than
 * the buffer, copy until the source's own terminator shows up or the last
 * usable slot is filled, and only when the whole source was copied (the
 * count landed exactly on n-1) append the terminator.  The `n > cap` guard
 * is a predicated `pophi`, and the final conditional store is the ARM
 * `ldreq`/`addeq`/`strheq` triple.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetStringN.c \
 *       --func STRBUF_SetStringN --addr 0x02045994 --cc 1.1p1 --arm
 */
void STRBUF_SetStringN(struct Strbuf *strbuf, const u16 *srcChars, u32 charCount)
{
    u32 index;

    if (charCount > strbuf->capacity)
        return;

    for (index = 0; index < charCount - 1; index++) {
        strbuf->chars[index] = srcChars[index];
        if (strbuf->chars[index] == sStrbufStatics.eosChar)
            break;
    }

    strbuf->length = index;
    if (index == charCount - 1)
        strbuf->chars[charCount - 1] = sStrbufStatics.eosChar;
}

/*
 * Append n halfwords to a counted buffer: the count is the halfword at +2,
 * the current length is the halfword at +0, the data starts at +8, and the
 * whole thing is halfword-indexed, which is why the copy size is `n * 2`.
 * A null count and an over-long count are both refused, each as its own
 * predicated early return on the entry compare (`movs` for the first, a
 * `pophi` for the unsigned second).
 *
 * The stored count is one less than n, and it is computed from the incoming
 * value rather than by re-reading the field, so it is a subtraction on r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetChars.c \
 *       --func STRBUF_SetChars --addr 0x02045A00 --cc 1.1p1 --arm
 */
void STRBUF_SetChars(struct Strbuf *strbuf, const void *srcChars, u32 charCount)
{
    if (charCount == 0)
        return;
    if (charCount > strbuf->capacity)
        return;

    MI_CpuCopy8(srcChars, strbuf->chars, charCount * 2);
    strbuf->length = charCount - 1;
}

/*
 * Copies at most `n` slots out of a u16-array object into a caller's
 * buffer, stopping after the slot that equals the stamp, and forcing a
 * stamp into the last output slot if the loop ran to the limit without
 * finding one. In other words the stamp is this container's terminator
 * value and this is its bounded, always-terminated extraction.
 *
 * Two shape tells worth keeping:
 *
 *  - The stamp is re-read from the global on every iteration
 *    (`ldrh ip, [r3]` inside the loop, from a pool base hoisted out of
 *    it). It is not volatile: the store into the caller's buffer may
 *    alias it, so the load cannot be hoisted. Caching it in a local
 *    before the loop removes the reload and shortens the body.
 *  - The final store is written as a pointer expression, not a subscript.
 *    `add r1, r1, r2, lsl #1` followed by `strh r0, [r1, #-2]` scales,
 *    adds, then subtracts the element size, which is what
 *    `*(out + n - 1)` produces; `out[n - 1]` folds to a single scaled
 *    offset instead
 *    (docs/idioms/pointer-minus-one-scales-before-the-subtraction.md).
 *
 * The loop is the compiler's usual rotation of a counted `for`: a
 * zero-trip guard at the top, the increment and the bound test at the
 * bottom, and the `break` falling straight into the `i == n` test that
 * distinguishes "found the terminator" from "ran out of room". Because
 * `break` leaves the counter un-incremented, that one comparison is the
 * whole post-condition and no separate flag is needed. The entire tail is
 * predicated on `eq`, so it costs no branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_ToChars.c \
 *       --func STRBUF_ToChars --addr 0x02045A38 --cc 1.1p1 --arm
 */
void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 maxChars)
{
    u32 index;
    u16 ch;

    for (index = 0; index < maxChars; index++) {
        ch = strbuf->chars[index];
        out[index] = ch;
        if (sStrbufStatics.eosChar == ch) {
            break;
        }
    }
    if (index == maxChars) {
        *(out + maxChars - 1) = sStrbufStatics.eosChar;
    }
}

/*
 * Returns the address of the u16-array object's slot array, which begins
 * at +0x8 with the stamp slot. A single `add r0, r0, #8` and `bx lr`: the
 * function exists only so callers outside this file need not know the
 * header size.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetChars.c  *       --func STRBUF_GetChars --addr 0x02045A90 --cc 1.1p1 --arm
 */
u16 *STRBUF_GetChars(struct Strbuf *strbuf)
{
    return strbuf->chars;
}

/*
 * A two-instruction ARM read accessor used all over the ARM9 image (the
 * halfword at 0x020A7E7C, a UI/input mode word).  The literal pool word is
 * attested by sole-ref/data: 0x020A7E7C is a mapped pool-word object with 99
 * referring sites, none of them this 16-byte range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetEosChar.c \
 *       --func STRBUF_GetEosChar --addr 0x02045A98 --cc 1.1p1 --arm --region arm9
 */
u16 STRBUF_GetEosChar(void)
{
    return sStrbufStatics.eosChar;
}

/*
 * The two mutators of the u16 vector STRBUF_Create allocates, folded into one
 * translation unit covering 0x02045AA8..0x02045B38 (both functions and the
 * single trailing pool word).  See src/matched/STRBUF_AppendChar.c for the object
 * layout this pair pins down, in particular why the entries begin at +0x8
 * and why one slot past `capacity` is reserved for a terminator.
 *
 * STRBUF_Append concatenates one vector onto another, copying src->used + 1
 * halfwords so that the source's terminator becomes the destination's.
 * STRBUF_AppendChar pushes a single entry and re-plants the terminator behind it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045AA8.c \
 *       --addr 0x02045AA8 --arm
 */
void STRBUF_Append(struct Strbuf *dst, struct Strbuf *src)
{
    u16 count = src->length;

    if (dst->length + count + 1 > dst->capacity)
        return;

    MI_CpuCopy8(&src->chars[0], &dst->chars[dst->length], (count + 1) * 2);
    dst->length = dst->length + src->length;
}

void STRBUF_AppendChar(struct Strbuf *strbuf, u16 ch)
{
    if (strbuf->length + 1 >= strbuf->capacity)
        return;

    strbuf->chars[strbuf->length++] = ch;
    strbuf->chars[strbuf->length] = sStrbufStatics.eosChar;
}
