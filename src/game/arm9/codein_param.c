/*
 * file:     codein_param.c
 * unit:     yes
 * function: CODEIN_PARAM_Create, CODEIN_PARAM_Delete
 * address:  0x0202E4EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from codein_param.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   STRBUF_Create    0x020457B0  arm
 *   codein_param_File 0x020A77D0  data
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "../types.h"

struct Strbuf;

/* Text input parameters (the code-entry screen). */
struct CodeinParam {
    u32 mode;
    u32 maxLength;
    u32 values[4];
    u32 unused;           /* never read; keeps the allocation 0x24 bytes */
    u32 initialPage;
    struct Strbuf *text;
};

extern u32 GFL_HEAP_Free(void *p);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void STRBUF_Delete(struct Strbuf *str);
extern struct Strbuf *STRBUF_Create(u32 capacity, u16 heapId);



struct CodeinParam *CODEIN_PARAM_Create(u32 heapId, u32 mode, u32 initialPage, u32 maxLength, u32 *values);

void CODEIN_PARAM_Delete(struct CodeinParam *param);

extern const char codein_param_File[];

/*
 * Levers that decided this one:
 *   - the heap parameter must be u32 with an explicit (u16) cast at each use;
 *     declared u16 the allocator kept the wrong value in r7 and the frame
 *     came out 88 bytes instead of 96.
 *   - `int i;` is declared BEFORE the result pointer, which is what puts the
 *     loop counter in r4 and the result in r5
 *     (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *   - the struct has a dead u32 at +0x18 between items[4] and w1c, so the
 *     allocator's size argument is 0x24, not 0x20.
 *
 * TU: codein_param.c (__FILE__ 0x020A77D0, line 0x37).
 */
struct CodeinParam *CODEIN_PARAM_Create(u32 heapId, u32 mode, u32 initialPage, u32 maxLength, u32 *values)
{
    int i;
    struct CodeinParam *param;

    param = GFL_HEAP_Alloc((u16)heapId, sizeof(struct CodeinParam), 0, codein_param_File, 0x37);
    param->mode = mode;
    param->maxLength = maxLength;
    param->text = STRBUF_Create(maxLength + 1, (u16)heapId);
    param->initialPage = initialPage;
    for (i = 0; i < 3; i++) {
        param->values[i] = values[i];
    }
    param->values[i] = values[i - 1];

    return param;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * A destructor: release the one owned handle at offset 0x20, then free
 * the object.
 *
 * Matched as a one-function unit because the two bytes of `00 00` at
 * 0x0202E55E are the linker's inter-section fill before 0x0202E560.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E54C.c \
 *       --addr 0x0202E54C --thumb
 */
void CODEIN_PARAM_Delete(struct CodeinParam *param)
{
    STRBUF_Delete(param->text);
    GFL_HEAP_Free(param);
}
