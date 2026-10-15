/*
 * function: DIGITALCARDCHECK_Create
 * address: 0x0217D398
 * packet: pkt_ov176_0217D398
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_VIEW_LoadBgPalette 0x021E58A4 thumb ov177
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   DIGITALCARDCHECK_SelectPhase 0x0217D458 thumb ov176
 *   d_0217E61C 0x0217E61C data a1
 */
typedef struct { int mode; int v[7]; } Config;
typedef struct { int a,b,c,d,callback; Config config; unsigned short heap; } Request;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int unused, int mode, unsigned color);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int WORDSET_Create(int,int,int);
extern int *WIFIBATTLEMATCH_UTIL_CreateCallback(int a, int b, int c);
extern void DIGITALCARDCHECK_SelectPhase(int a, int unused, char *p);
extern const char d_0217E61C[];
Request *DIGITALCARDCHECK_Create(Config *p, int heap)
{
    Request *r;
    r = func_02030734(heap, 0x38, 0, d_0217E61C, 0x9A);
    MI_CpuFill8(r, 0, 0x38);
    r->config = *p;
    r->heap = heap;
    WIFIBATTLEMATCH_VIEW_LoadBgPalette(r->config.v[4], 3, heap);
    r->a = (int)func_02045B38(0, 2, 0xD2, heap);
    r->b = WORDSET_Create(8, 0x40, heap);
    r->callback = (int)WIFIBATTLEMATCH_UTIL_CreateCallback((int)r, (int)DIGITALCARDCHECK_SelectPhase, heap);
    return r;
}
