/*
 * function: MUSICAL_DRESSUP_SYS_Init
 * address:  0x02156BD0
 * packet:   pkt_ov010_02156BD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02030734  0x02030734  arm
 *   sMusicalDressupSysFileName  0x02172730  data
 *   ov133_id  0x00000085  data
 */

typedef unsigned int u32;

typedef struct Obj {
    u32 *f00;
    u32 pad[2];
    u32 *f0c;
} Obj;

typedef signed int     s32;
typedef unsigned short u16;
extern int func_02034AC4(s32 handle);
extern char ov133_id[];
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char sMusicalDressupSysFileName[];

int MUSICAL_DRESSUP_SYS_Init(void *a, u32 *out, u32 *src)
{
    Obj *o;
    *out = 0;
    func_02034AC4((u32)ov133_id);
    GFL_HEAP_CreateChildHeap(1, 0x2d, 1 << 18);
    o = PROCSYS_AllocProcWork(a, 0x10, 0x2d);
    o->f00 = func_02030734(0x2d, 0xc, 0, sMusicalDressupSysFileName, 0x4e);
    o->f0c = src;
    o->f00[0] = src[0];
    o->f00[1] = src[1];
    o->f00[2] = src[2];
    return 1;
}
