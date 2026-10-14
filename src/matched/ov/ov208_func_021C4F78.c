/*
 * function: ZUKAN_DETAIL_FORM_InitModelSystem
 * address:  0x021C4F78
 * packet:   pkt_ov208_021C4F78
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  MCSS_SetTaskSystem witness (src/matched/arm9/MCSS_SetTaskSystem.c) has no shard yet; EXACT once the integrator builds it (2026-10-02)
 *
 * The last call takes the 3D heap handle as its second argument (r1 still
 * holds it), which is why the image copies the result to r1 before the store.
 *
 * symbols:
 *   MCSS_Init  0x02014B08  thumb
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb
 *   MCSS_SetOrthoMode  0x02015BF0  thumb
 *   POKEGRA_GetArcID  0x0202D060  thumb
 *   MCSS_OpenHandle  0x02014CB8  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   MCSS_SetTaskSystem  0x02014CEC  thumb
 *   func_02030734  0x02030734  arm
 *   data_021C8E64  0x021C8E64  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u32 f0;
    u32 f4;
    u32 cam;
    u8  padc[0x110];
    void *mem;
    void *heap3d;
};

struct Sub02014CB8Obj;
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *p, u32 v);
extern void MCSS_SetOrthoMode(void *obj);
struct Ctx;
extern int POKEGRA_GetArcID(void);
extern void MCSS_OpenHandle(struct Sub02014CB8Obj *o, u32 x);
extern u32  func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void MCSS_SetTaskSystem(u8 *p, u32 value);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char data_021C8E64[];

void ZUKAN_DETAIL_FORM_InitModelSystem(u16 *heap, struct Ov208Menu *p)
{
    p->cam = (u32)MCSS_Init(4, (void *)(*heap));
    MCSS_SetTextureTransAdrs((void *)p->cam, 0);
    MCSS_SetOrthoMode((void *)p->cam);
    MCSS_OpenHandle((struct Sub02014CB8Obj *)p->cam, POKEGRA_GetArcID());
    p->mem = func_02030734(*heap, func_02030CB0(4), 0, data_021C8E64, 0xa53);
    p->heap3d = func_02030CBC(4, p->mem);
    MCSS_SetTaskSystem((u8 *)p->cam, (u32)p->heap3d);
}
