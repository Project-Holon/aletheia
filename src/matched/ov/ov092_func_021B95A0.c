/*
 * function: EVENT_BATTLE_RETURN_Init
 * address:  0x021B95A0
 * packet:   pkt_ov092_021B95A0
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   PROCSYS_Create  0x02031324  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x20];
    u32 f2c;
    u32 f30;
    u32 f34;
    u8 pad38[4];
    u16 f3c;
    u8 pad3e[2];
    u32 f40;
    u32 f44;
    u32 f48;
};

extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *PROCSYS_Create(int a0);

int EVENT_BATTLE_RETURN_Init(struct Obj0203159C *a0)
{
    struct W *p;

    GFL_HEAP_CreateChildHeap(1, 0x52, 0x1000);
    p = PROCSYS_AllocProcWork(a0, 0x4c, 0x52);
    p->f04 = (u32)STRBUF_Create(0x20, 0x52);
    p->f00 = 0;
    p->f08 = 0;
    p->f2c = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f3c = 0x52;
    p->f40 = (u32)PROCSYS_Create(p->f3c);
    p->f44 = 0;
    p->f48 = 0;
    return 1;
}
