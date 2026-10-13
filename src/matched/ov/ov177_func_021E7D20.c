/*
 * function: func_021E7D20
 * address: 0x021E7D20
 * packet: pkt_ov177_021E7D20
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   d_021E8DBC 0x021E8DBC data a1
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 */
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
extern const char d_021E8DBC[];
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern int func_021E5978(int *p, int i);
extern void *CLACT_CreateActor(void *, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void **func_021E7D20(void *owner, void *src, unsigned heap)
{
    void **objs;
    Request req;
    objs = func_02030734(heap, 8, 0, d_021E8DBC, 0xBEF);
    MI_CpuFill8(objs, 0, 8);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x80;
    req.y = 0x60;
    req.id = 1;
    req.a = 1;
    req.flag = 1;
    objs[0] = CLACT_CreateActor(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), &req, 0, heap);
    CLACT_SetActorAutoAnim(objs[0], 1);
    req.id = 0;
    req.a = 0;
    req.flag = 1;
    objs[1] = CLACT_CreateActor(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), &req, 0, heap);
    CLACT_SetActorAutoAnim(objs[1], 1);
    return objs;
}
