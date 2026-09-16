/*
 * port/sdk/os_alloc.c -- the OS heap module shim, onto malloc/free.
 *
 * The DS build carves fixed arenas out of main RAM and hands out blocks from
 * them by heap id; the matched game code never sees the arena, only the id
 * and the pointer.  On the host there is no reason to reproduce the arena:
 * the ids are kept as an argument and ignored, and every block comes from
 * malloc.  What the port *does* reproduce is the alignment contract, because
 * the game's allocator honours the `align` argument and some matched code
 * relies on it.
 *
 * Two layers are shimmed here:
 *
 *   OS_AllocFromHeap / OS_FreeToHeap   the SDK names
 *   func_02030734 / func_020307B0      the game's debug-allocator wrappers,
 *                                      which take the caller's __FILE__ and
 *                                      __LINE__ as the last two arguments
 *                                      (see any caller in src/matched/)
 *
 * The wrappers are a common hub: docs/HANDOFF.md lists eleven matched
 * forwarder thunks that do nothing but tail-call func_020307B0.
 */

#include <stdlib.h>
#include <string.h>

#include "port.h"

/*
 * An over-aligned block stores its malloc base in the word immediately
 * before the pointer handed out, so free can recover it.  Alignments up to
 * 32 bytes cover every value the matched code passes (4, 8, 0x20).
 */
#define BW_HEAP_HEADER 16u

static void *aligned_alloc_with_header(u32 size, u32 align)
{
    unsigned char *base;
    unsigned char *user;
    size_t slack;

    if (align < 4) {
        align = 4;
    }
    if (align > 256) {
        align = 256;
    }
    slack = (size_t)align + BW_HEAP_HEADER;
    base = (unsigned char *)malloc((size_t)size + slack);
    if (base == NULL) {
        return NULL;
    }
    user = base + BW_HEAP_HEADER;
    user += (align - ((size_t)(user - (unsigned char *)0) % align)) % align;
    memcpy(user - sizeof(unsigned char *), &base, sizeof(unsigned char *));
    return user;
}

static void aligned_free_with_header(void *p)
{
    unsigned char *base;

    if (p == NULL) {
        return;
    }
    memcpy(&base, (unsigned char *)p - sizeof(unsigned char *), sizeof(base));
    free(base);
}

/* ------------------------------------------------------------------ */
/* SDK names                                                           */
/* ------------------------------------------------------------------ */

/*
 * Portability note, and the first real one this lane found.  Some matched
 * sources declare these as all-u32, e.g.
 *
 *     extern void OS_FreeToHeap(u32 a, u32 b, u32 heap);
 *
 * because on the DS a pointer *is* a u32 and the matcher only needs the
 * relocation, not the type.  On an LP64 host that declaration cannot carry a
 * pointer.  Neither of these two is in the current port closure, so nothing
 * is broken today; when a TU that declares them this way enters the closure,
 * the fix belongs in the port layer (a wrapper include that predeclares the
 * pointer-typed form before the matched file's own extern), never in the
 * matched file, which must keep its DS bytes.
 */
void *OS_AllocFromHeap(u32 arena, void *heap, u32 size)
{
    (void)arena;
    (void)heap;
    return aligned_alloc_with_header(size, 4);
}

void OS_FreeToHeap(u32 arena, void *heap, void *block)
{
    (void)arena;
    (void)heap;
    aligned_free_with_header(block);
}

/* ------------------------------------------------------------------ */
/* The game's debug-allocator wrappers                                  */
/* ------------------------------------------------------------------ */

void *func_02030734(u32 heap, u32 size, u32 align, const char *file, u32 line)
{
    (void)heap;
    (void)file;
    (void)line;
    return aligned_alloc_with_header(size, align);
}

void func_020307B0(void *block)
{
    aligned_free_with_header(block);
}
