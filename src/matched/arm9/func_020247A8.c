/*
 * function: PMS_WORD_Create
 * address:  0x020247A8
 * packet:   pkt_020247A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   g_pmsWordSourceFile   0x020A746C  data  a1
 *   tbl_0209F7AC   0x0209F7AC  data  a2
 *
 * pms_word.c: allocate the 0x38-byte word-message system and open its
 * thirteen message archives (ids from the u16 table at 0x0209F7AC).  The
 * heap id store sits inside the loop in the image, so it is inside the
 * loop here.  The r4/r5 swap of docs/notes/pkt_02024768.c.txt was the
 * declaration order: the counter is declared before the result pointer
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md),
 * found by tools/permuter.py and reduced to that one change.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PmsWordSys {
    u32   heapId;
    void *msg[13];
};

extern const char g_pmsWordSourceFile[];
extern const u16  tbl_0209F7AC[];
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern void *func_02045B38(u32 a, u32 b, u32 id, u16 heap);

struct PmsWordSys *PMS_WORD_Create(u32 heapId)
{
    int i;
    struct PmsWordSys *p;

    p = func_02030734((u16)heapId, 0x38, 0, g_pmsWordSourceFile, 0x32);
    for (i = 0; i < 13; i++) {
        p->heapId = heapId;
        p->msg[i] = func_02045B38(0, 2, tbl_0209F7AC[i], heapId);
    }
    return p;
}
