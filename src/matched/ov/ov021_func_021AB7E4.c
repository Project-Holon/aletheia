/*
 * function: FLD_SCENEAREA_LOADER_Create
 * address:  0x021AB7E4
 * packet:   pkt_ov021_021AB7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   gFldSceneAreaLoaderFileName  0x021DE000  data  a4
 *   gFldSceneAreaArcIds  0x021D8EEC  data  a4
 */

typedef struct {
    int pad[2];
    int f8[2];
} S;

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern char gFldSceneAreaLoaderFileName[];
extern const int gFldSceneAreaArcIds[];

S *FLD_SCENEAREA_LOADER_Create(int heap)
{
    S *p = func_02030734(heap, 0x10, 1, gFldSceneAreaLoaderFileName, 0x81);
    int i;
    for (i = 0; i < 2; i++) {
        p->f8[i] = (int)func_020490F4(gFldSceneAreaArcIds[i], heap);
    }
    return p;
}
