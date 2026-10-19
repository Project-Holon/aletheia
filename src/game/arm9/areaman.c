/*
 * file:     areaman.c
 * unit:     yes
 * function: AREAMAN_Create, AREAMAN_Delete, AREAMAN_Alloc, AREAMAN_AllocUp, AREAMAN_AllocShortUp, AREAMAN_AllocLongUp, AREAMAN_AllocDown, AREAMAN_AllocShortDown, AREAMAN_AllocLongDown, AREAMAN_AllocAt, AREAMAN_Free, AREAMAN_FindClearRunUp, AREAMAN_FindClearRunDown, AREAMAN_ClearByteRun, AREAMAN_MarkUsed, AREAMAN_TraceByte, AREAMAN_TraceBitmap, AREAMAN_TraceAlloc
 * address:  0x02033C00
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from savedata.c by lane A4 (tools/splitfile.py). This is the original
 * areaman.c, the bitmap allocator for runs of equal-sized areas. The run is
 * anchor-fixed at 0x02033C00 by the "areaman.c" __FILE__ string at 0x020A7958
 * (pool site 0x02033C94 inside AREAMAN_Create, layout/file_anchors.txt);
 * savedata.c ends exactly there.
 *
 * symbols:
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   GFL_HEAP_Free    0x020307B0  arm
 *   MI_CpuFill8      0x02082BCC  arm
 *   areaman_File     0x020A7958  data
 *   _LongestFreeRun  0x020A06A0  data
 *   _TrailingFreeRun 0x020A05A0  data
 *   _LeadingFreeRun  0x020A04A0  data
 *   _TopBitsMask     0x020A048C  data
 *   _LowBitsMask     0x020A0495  data
 */

#include "../types.h"

/* ---- areaman.c: bitmap allocator for runs of equal-sized areas ---- */

struct AreaMan {
    u16 area_count;         /* +0x00, number of areas (bits) */
    u16 bitmap_bytes;       /* +0x02, bytes of bitmap, multiple of 4 */
    u32 *guard;             /* +0x04, guard word just past the bitmap */
    u32 trace_enabled;      /* +0x08, nonzero: dump bitmap changes */
    u8 bitmap[1];           /* +0x0c, one bit per area, bit 7 first */
};

#define AREAMAN_GUARD_WORD 0x573C765A

extern void *GFL_HEAP_Alloc(u32 heap_id, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);

struct AreaMan *AREAMAN_Create(u32 area_count, u16 heap_id);
u32 AREAMAN_Delete(void *areaman);
s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len);
s32 AREAMAN_AllocUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocShortUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocLongUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocShortDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocLongDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocAt(struct AreaMan *areaman, u32 start, u32 len);
void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len);
s32 AREAMAN_FindClearRunUp(u32 byte_bits, u32 start, u32 len);
s32 AREAMAN_FindClearRunDown(u32 byte_bits, u32 start, u32 len);
void AREAMAN_ClearByteRun(u8 *byte_ptr, u32 start, u32 len);
s32 AREAMAN_MarkUsed(struct AreaMan *areaman, s32 start, u32 len);
void AREAMAN_TraceByte(u8 byte_value);
void AREAMAN_TraceBitmap(struct AreaMan *areaman);
void AREAMAN_TraceAlloc(struct AreaMan *areaman, s32 pos, u32 len, u32 line);

extern const char areaman_File[];
extern const u8 _LongestFreeRun[256];
extern const u8 _TrailingFreeRun[256];
extern const u8 _LeadingFreeRun[256];
extern const u8 _TopBitsMask[];
extern const u8 _LowBitsMask[];

/*
 * AREAMAN_Create: constructor of the area manager.  `area_count` is a count
 * of areas; the object carries a bitmap with one bit per area.  The byte
 * count is rounded up from the bit count and then up again to a multiple of
 * four.  The allocation is 0xC bytes of header, the bitmap and a four-byte
 * guard word (0x573C765A) written just past the bitmap, and the bitmap is
 * cleared.  The pool word for the file name holds 0x020A7958 ("areaman.c"),
 * which is what anchors this range.
 */
struct AreaMan *AREAMAN_Create(u32 area_count, u16 heap_id)
{
    struct AreaMan *areaman;
    u32 n;
    u16 nbytes;

    n = ((area_count & 7) != 0) + (area_count >> 3);
    while ((n & 3) != 0) {
        n++;
    }
    nbytes = (u16)n;

    areaman = GFL_HEAP_Alloc(heap_id, nbytes + 0x10, 0, areaman_File, 0x94);
    areaman->area_count = (u16)area_count;
    areaman->bitmap_bytes = nbytes;
    areaman->guard = (u32 *)(areaman->bitmap + nbytes);
    *areaman->guard = AREAMAN_GUARD_WORD;
    areaman->trace_enabled = 0;
    MI_CpuFill8(areaman->bitmap, 0, nbytes);
    return areaman;
}

/*
 * AREAMAN_Delete: release the manager.  A bare tail call: a pool word and a
 * bx (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so the callee's
 * arguments and result pass straight through.
 */
u32 AREAMAN_Delete(void *areaman)
{
    return GFL_HEAP_Free(areaman);
}

/*
 * AREAMAN_Alloc: allocate a run of `len` areas anywhere in the bitmap.  It
 * forwards to the ranged form with a start of zero and a limit of the area
 * count.  The forwarding call to the next function in the same file still
 * costs a pool word (one section per function), and keeping both in one unit
 * makes that site local.
 */
s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len)
{
    return AREAMAN_AllocUp(areaman, 0, areaman->area_count, len);
}

/*
 * AREAMAN_AllocUp: validate the request against the bitmap extent and
 * dispatch on the run length: runs shorter than eight areas go to the
 * bit-at-a-time scanner, longer runs to the byte-at-a-time scanner.  Both
 * arms are written as their own return so that each gets its own `bl`/`pop`
 * pair, as in the original.
 */
s32 AREAMAN_AllocUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    if (limit < len || start + len > areaman->area_count) {
        return -1;
    }

    if (len < 8) {
        return AREAMAN_AllocShortUp(areaman, start, limit, len);
    }

    return AREAMAN_AllocLongUp(areaman, start, limit, len);
}

/*
 * AREAMAN_AllocShortUp: bit-at-a-time upward search for a free run shorter
 * than eight areas.  Bit 0 of an area byte is the most significant bit.
 * Looks inside the first byte, then at every following byte, either for a
 * run inside it or for a run that starts in its trailing free bits and
 * continues in the leading free bits of the next byte.  The found run is
 * marked used and traced.
 */
s32 AREAMAN_AllocShortUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 found;
    s32 last;
    s32 last_byte;
    s32 i;
    s32 bit;
    u32 trailing;

    last = start + limit + 1 - len;
    last_byte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) + len <= 8) {
        bit = AREAMAN_FindClearRunUp(areaman->bitmap[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i <= last_byte) {
        if (_LongestFreeRun[areaman->bitmap[i]] >= len) {
            bit = AREAMAN_FindClearRunUp(areaman->bitmap[i], 0, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            trailing = _TrailingFreeRun[areaman->bitmap[i]];
            if (trailing != 0 && i < last_byte) {
                if (_LeadingFreeRun[areaman->bitmap[i + 1]] >= len - trailing) {
                    found = (8 - trailing) + i * 8;
                    goto done;
                }
            }
        }
        i++;
    }

done:
    if (found != -1 && found <= last) {
        if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
            return -1;
        }
        AREAMAN_TraceAlloc(areaman, found, len, 0x17c);
        return found;
    }
    return -1;
}

/*
 * AREAMAN_AllocLongUp: byte-at-a-time upward search for a free run of eight
 * areas or more.  It anchors on the trailing free run of byte `i`, skips
 * whole zero bytes, and then checks the leading free run of the byte the
 * remainder lands in.
 */
s32 AREAMAN_AllocLongUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    u32 last;
    s32 last_byte;
    s32 run;
    s32 trailing_run;
    s32 remaining;
    s32 i;
    s32 full_bytes;
    s32 next;
    s32 rest_bits;
    s32 found;

    i = start >> 3;
    last = start + limit - len;
    last_byte = last / 8;

    run = 8 - (start & 7);
    trailing_run = _TrailingFreeRun[areaman->bitmap[i]];
    if (trailing_run < run) {
        run = trailing_run;
    }

    while (i <= last_byte) {
        if (run != 0) {
            remaining = len - run;
            full_bytes = remaining / 8;
            rest_bits = remaining % 8;
            next = i + 1;
            while (full_bytes != 0) {
                if (areaman->bitmap[next] != 0) {
                    break;
                }
                next++;
                full_bytes--;
            }
            if (full_bytes == 0) {
                found = -1;
                if (rest_bits == 0) {
                    found = (8 - run) + i * 8;
                } else if (_LeadingFreeRun[areaman->bitmap[next]] >= rest_bits) {
                    found = (8 - run) + i * 8;
                }
                if (found != -1) {
                    if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
                        return -1;
                    }
                    AREAMAN_TraceAlloc(areaman, found, len, 0x1db);
                    return found;
                }
            }
        }
        i++;
        if (i <= last_byte) {
            run = _TrailingFreeRun[areaman->bitmap[i]];
        }
    }

    return -1;
}

/*
 * AREAMAN_AllocDown: like AREAMAN_AllocUp but searching towards lower
 * positions: short runs go to the bit scanner, long runs to the byte
 * scanner; the result is traced with line 0x230.
 */
s32 AREAMAN_AllocDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 pos;

    if (limit < len) {
        return -1;
    }

    if (len < 8) {
        pos = AREAMAN_AllocShortDown(areaman, start, limit, len);
    } else {
        pos = AREAMAN_AllocLongDown(areaman, start, limit, len);
    }

    AREAMAN_TraceAlloc(areaman, pos, len, 0x230);
    return pos;
}

/*
 * AREAMAN_AllocShortDown: the downward bit-at-a-time scanner, the mirror of
 * AREAMAN_AllocShortUp walking towards lower addresses.
 */
s32 AREAMAN_AllocShortDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 i;
    s32 last;
    s32 last_byte;
    s32 found;
    s32 bit;
    u32 leading;

    last = start - limit + 1;
    last_byte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) != 0) {
        bit = AREAMAN_FindClearRunDown(areaman->bitmap[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i >= last_byte) {
        if (_LongestFreeRun[areaman->bitmap[i]] >= len) {
            bit = AREAMAN_FindClearRunDown(areaman->bitmap[i], 7, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            leading = _LeadingFreeRun[areaman->bitmap[i]];
            if (leading != 0 && i > last_byte) {
                if (_TrailingFreeRun[areaman->bitmap[i - 1]] >= len - leading) {
                    found = (8 - (len - leading)) + (i - 1) * 8;
                    goto done;
                }
            }
        }
        i--;
    }

done:
    if (found != -1 && found >= last) {
        if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
            found = -1;
        }
        return found;
    }
    return -1;
}

/*
 * AREAMAN_AllocLongDown: the downward byte-at-a-time scanner, the mirror of
 * AREAMAN_AllocLongUp.  The anchor is the leading free run of byte `i`,
 * whole zero bytes are skipped downwards, and the trailing free run of the
 * byte the remainder lands in closes the request.
 */
s32 AREAMAN_AllocLongDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 i;
    u32 last;
    s32 last_byte;
    s32 run;
    s32 rest_bits;
    s32 leading_run;
    s32 remaining;
    s32 full_bytes;
    s32 next;
    s32 found;

    last = start - limit + 1;
    i = start >> 3;
    last_byte = last / 8;

    run = (start & 7) + 1;
    leading_run = _LeadingFreeRun[areaman->bitmap[i]];
    if (leading_run < run) {
        run = leading_run;
    }

    while (i >= last_byte) {
        if (run != 0) {
            remaining = len - run;
            full_bytes = remaining / 8;
            rest_bits = remaining % 8;
            next = i - 1;
            while (full_bytes != 0) {
                if (next < last_byte || areaman->bitmap[next] != 0) {
                    break;
                }
                next--;
                full_bytes--;
            }
            if (full_bytes == 0) {
                found = -1;
                if (rest_bits == 0) {
                    found = (next + 1) * 8;
                } else if (next >= last_byte && _TrailingFreeRun[areaman->bitmap[next]] >= rest_bits) {
                    found = (8 - rest_bits) + next * 8;
                }
                if (found != -1 && found >= last) {
                    if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
                        found = -1;
                    }
                    return found;
                }
            }
        }
        i--;
        if (i >= last_byte) {
            run = _LeadingFreeRun[areaman->bitmap[i]];
        }
    }

    return -1;
}

/*
 * AREAMAN_AllocAt: try to take the run [start, start+len) at a fixed place.
 * AREAMAN_MarkUsed fails when any bit is already set; on success the change
 * is traced with line 0x304.  The three arguments live in callee-saved
 * registers across the first call because the second call needs them again.
 */
s32 AREAMAN_AllocAt(struct AreaMan *areaman, u32 start, u32 len)
{
    if (AREAMAN_MarkUsed(areaman, start, len) == 0) {
        return 0;
    }

    AREAMAN_TraceAlloc(areaman, start, len, 0x304);
    return 1;
}

/*
 * AREAMAN_Free: clear `len` bits starting at bit `start` of the bitmap.  A
 * run inside one byte goes to AREAMAN_ClearByteRun; otherwise the head bits
 * are cleared with the low-bits mask, whole bytes are zeroed and the top-bits
 * mask clears the head of the last byte.  AREAMAN_TraceBitmap then reports
 * the new state.
 *
 * The byte cursor past the head is the PARAMETER reused, `start = idx + 1;`,
 * not idx incremented.  That puts the cursor in start's own register r1 and
 * rotates the zero and the count to the image's r2 / r3; the same lever
 * closes AREAMAN_MarkUsed.
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 */
void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len)
{
    u32 bit = start % 8;
    u32 idx = start / 8;
    s32 avail;
    s32 rest;
    u32 full_bytes;
    u32 rest_bits;
    u32 mask;

    if ((bit + len) <= 8) {
        AREAMAN_ClearByteRun(&areaman->bitmap[idx], bit, len);
    } else {
        avail = 8 - bit;
        mask = _LowBitsMask[avail];
        rest = len - avail;
        full_bytes = rest / 8;
        rest_bits = rest % 8;
        areaman->bitmap[idx] &= (u8)~mask;
        start = idx + 1;
        while (full_bytes-- != 0) {
            areaman->bitmap[start] = 0;
            start++;
        }
        areaman->bitmap[start] &= (u8)~_TopBitsMask[rest_bits];
    }
    AREAMAN_TraceBitmap(areaman);
}

/*
 * AREAMAN_FindClearRunUp: inside one bitmap byte, starting at bit `start`,
 * walk the run mask down and return the first bit position at which `len`
 * consecutive bits are all clear, or -1.
 *
 * _TopBitsMask is a nine byte table, 00 80 C0 E0 F0 F8 FC FE FF, the mask of
 * the top `len` bits of a byte; the entry for len == 8 is the last, which is
 * why the length guard is `> 8` here and `>= 8` in the downward scanner
 * (that one indexes the same table after adding one).  The address has three
 * pool words in the image, so compiling this function alone leaves two of
 * them outside the compared range.
 */
s32 AREAMAN_FindClearRunUp(u32 byte_bits, u32 start, u32 len)
{
    u8 mask;
    u32 last;

    if (len <= 8) {
        last = 8 - len;
        mask = _TopBitsMask[len] >> start;

        while (start <= last) {
            if ((byte_bits & mask) == 0) {
                return start;
            }
            mask >>= 1;
            start++;
        }
    }

    return -1;
}

/*
 * AREAMAN_FindClearRunDown: the backward twin of AREAMAN_FindClearRunUp:
 * same mask table, but the cursor walks down from `start`, so the mask is
 * shifted left each step and the loop ends when the signed cursor goes
 * negative.  The cursor really is signed: the original reuses the flags of
 * the `subs` that computes it for both the entry guard (`bmi`) and the loop
 * back edge (`bpl`).
 */
s32 AREAMAN_FindClearRunDown(u32 byte_bits, u32 start, u32 len)
{
    u8 mask;
    s32 i;

    if (len < 8) {
        i = (s32)(start + 1) - (s32)len;
        mask = _TopBitsMask[len] >> i;

        while (i >= 0) {
            if ((byte_bits & mask) == 0) {
                return i;
            }
            mask <<= 1;
            i--;
        }
    }

    return -1;
}

/*
 * AREAMAN_ClearByteRun: clear a run of `len` bits starting at bit `start`
 * inside one bitmap byte, with the same top-bits mask table as the scanners.
 * The `and r1, r1, #0xff` after the complement is the u8 truncation, not a
 * mask written in the source.
 */
void AREAMAN_ClearByteRun(u8 *byte_ptr, u32 start, u32 len)
{
    u8 mask = _TopBitsMask[len] >> start;

    *byte_ptr = *byte_ptr & (u8)~mask;
}

/*
 * AREAMAN_MarkUsed: mark `len` bits starting at bit `start` of the bitmap as
 * used.  Fails (0) past the managed range or when any target bit is already
 * set (dumping the mask and the byte through AREAMAN_TraceByte when tracing
 * is enabled); otherwise it sets the head bits, fills whole bytes with 0xFF
 * and ORs the tail mask into the last byte.
 *
 * The byte index is the PARAMETER reused, `start = start / 8;`, not a fresh
 * local: that is the image's `asr r1, r1, #3` into start's own register,
 * which rotates the index/count/tail registers to r1/r3/r2; with it the
 * then-arm zeros go in the natural order `full_bytes = 0; rest_bits = 0;`.
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 */
s32 AREAMAN_MarkUsed(struct AreaMan *areaman, s32 start, u32 len)
{
    u32 bit;
    u32 avail;
    u32 full_bytes;
    u32 rest_bits;
    u32 mask;
    u8 *byte_ptr;
    u8 value;

    if (start + len > areaman->area_count) {
        return 0;
    }

    bit = start % 8;
    avail = 8 - bit;
    start = start / 8;
    if (avail >= len) {
        mask = _TopBitsMask[len] >> bit;
        full_bytes = 0;
        rest_bits = 0;
    } else {
        len = len - avail;
        mask = _LowBitsMask[avail];
        full_bytes = len >> 3;
        rest_bits = len & 7;
    }
    byte_ptr = &areaman->bitmap[start];
    value = areaman->bitmap[start];
    if ((mask & value) != 0) {
        if (areaman->trace_enabled != 0) {
            AREAMAN_TraceByte((u8)mask);
            AREAMAN_TraceByte(areaman->bitmap[start]);
        }
        return 0;
    }
    start++;
    *byte_ptr = value | (u8)mask;
    while (full_bytes-- != 0) {
        areaman->bitmap[start] = 0xFF;
        start++;
    }
    if (rest_bits != 0) {
        areaman->bitmap[start] |= _TopBitsMask[rest_bits];
    }
    return 1;
}

/*
 * AREAMAN_TraceByte: the trace hook, a single `bx lr`.  An empty function
 * body, kept as a real entry point because AREAMAN_TraceBitmap calls it once
 * per loop iteration (the debug output was compiled out of the release
 * build).
 */
void AREAMAN_TraceByte(u8 byte_value)
{
}

/*
 * AREAMAN_TraceBitmap: when tracing is enabled, pass every bitmap byte to
 * AREAMAN_TraceByte.
 */
void AREAMAN_TraceBitmap(struct AreaMan *areaman)
{
    if (areaman->trace_enabled != 0) {
        int i;
        for (i = 0; i < areaman->bitmap_bytes; i++) {
            AREAMAN_TraceByte(areaman->bitmap[i]);
        }
    }
}

/*
 * AREAMAN_TraceAlloc: guard-and-forward: report the bitmap through
 * AREAMAN_TraceBitmap only when tracing is enabled.  The position, length
 * and source line are only used by the debug build of the trace.
 */
void AREAMAN_TraceAlloc(struct AreaMan *areaman, s32 pos, u32 len, u32 line)
{
    if (areaman->trace_enabled != 0) {
        AREAMAN_TraceBitmap(areaman);
    }
}
