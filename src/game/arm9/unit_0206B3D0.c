/*
 * file:     unit_0206B3D0.c
 * function: NNSi_G3dAnmBlendVis
 * address:  0x0206B3D0
 * packet:   pkt_0206AFE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define ANMOBJ_MAPDATA_MASK  0x300
#define ANMOBJ_MAPDATA_EXIST 0x100
#define ANMOBJ_MAPDATA_ID    0xff

/* NNSG3dAnmObj as far as the blend function reads it. */
typedef struct AnmObj {
    u8 unused00[0xc];
    void (*funcAnm)(u32 *pResult, struct AnmObj *pAnmObj, u32 dataIdx);
    struct AnmObj *next;
    u8 unused14[5];
    u8 numMapData;
    u16 mapData[1];
} AnmObj;

/*
 * NNSi_G3dAnmBlendVis shape: walk the chain of animation objects and OR the
 * result of every object that maps this node into *pResult. Returns 1 when
 * at least one object contributed.
 */
int NNSi_G3dAnmBlendVis(u32 *pResult, AnmObj *pAnmObj, unsigned nodeIdx)
{
    int hasResult = 0;
    u32 objResult;

    *pResult = 0;
    do {
        if (nodeIdx < pAnmObj->numMapData) {
            u16 mapData = *(u16 *)((char *)pAnmObj + 0x1a + nodeIdx * 2);
            if ((mapData & ANMOBJ_MAPDATA_MASK) == ANMOBJ_MAPDATA_EXIST) {
                if (pAnmObj->funcAnm != 0) {
                    pAnmObj->funcAnm(&objResult, pAnmObj, mapData & ANMOBJ_MAPDATA_ID);
                    *pResult |= objResult;
                    hasResult = 1;
                }
            }
        }
        pAnmObj = pAnmObj->next;
    } while (pAnmObj != 0);
    return hasResult;
}
