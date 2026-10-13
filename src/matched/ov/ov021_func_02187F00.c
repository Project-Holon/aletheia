/*
 * function: FIELDMAP_ProcInit
 * address:  0x02187F00
 * packet:   pkt_ov021_02187F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   FIELDMAP_GetHeapSizeForMapType  0x02189BBC  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_RegisterBlockHeap  0x02030678  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   FIELDMAP_Create  0x02188030  thumb
 *   GAMESYSTEM_SetFieldMap  0x02012110  thumb
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   sFieldMapHeapBuffer     0x021DE700  data
 */

extern char sFieldMapHeapBuffer[];

struct Ctx;
unsigned char *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *x);
struct Rec44;
unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *x);
int FIELDMAP_GetHeapSizeForMapType(int x);
void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
typedef unsigned int   u32;
struct Ctx;
void GFL_HEAP_RegisterBlockHeap(void *a, u32 b, u32 c);
struct Obj0203159C;
void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
void *FIELDMAP_Create(int a, int b);
void GAMESYSTEM_SetFieldMap(struct Ctx *p, void *v);
unsigned int GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *x);
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *x);
struct Comm;
u32 GAME_COMM_GetKind(void *obj);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);

int FIELDMAP_ProcInit(struct Obj0203159C *a, int *state, int b)
{
    switch (*state) {
    case 0:
        {
            int sz = FIELDMAP_GetHeapSizeForMapType(GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)b))) - 0xD000;
            GFL_HEAP_CreateChildHeap(1, 0x15, sz);
        }
        GFL_HEAP_CreateChildHeap(1, 0x70, 0xD000);
        GFL_HEAP_CreateChildHeap(0x15, 0x50, 0xC000);
        GFL_HEAP_RegisterBlockHeap(sFieldMapHeapBuffer, 0x10000, 0x89);
        GFL_HEAP_CreateChildHeap(0x89, 0x92, 0x6400);
        GFL_HEAP_CreateChildHeap(0x89, 0x93, 0x7400);
        GFL_HEAP_CreateChildHeap(0x89, 0x96, 0x500);
        {
            void **w = (void **)PROCSYS_AllocProcWork(a, 4, 0x15);
            void *p = FIELDMAP_Create(b, 0x15);
            *w = p;
            GAMESYSTEM_SetFieldMap((void *)b, p);
        }
        (*state)++;
        break;
    case 1:
        if (GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)b) == 0) {
            int t = GAMESYSTEM_GetGameComm((const struct Ctx *)b);
            switch (GAME_COMM_GetKind((void *)t)) {
            case 1:
            case 2:
                GAME_COMM_RequestExitNoCallback((struct Comm *)t);
                break;
            }
        }
        return 1;
    }
    return 0;
}
