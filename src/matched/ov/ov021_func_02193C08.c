/*
 * function: FIELD_WFBC_LoadResources
 * address:  0x02193C08
 * packet:   pkt_ov021_02193C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   FIELD_WFBC_PEOPLE_Clear  0x02193F6C  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable  0x02186830  thumb
 *   sFieldWfbcFileName     0x021DDA60  data  a4
 */
#include "../include/Obj00485.h"

typedef unsigned char u8;

extern int sFieldWfbcFileName;
extern int *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int a, int id);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
struct E50;
extern void FIELD_WFBC_PEOPLE_Clear(struct E50 *e);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(int, int, int);

void FIELD_WFBC_LoadResources(char *p, int heap)
{
    int i;

    if (((struct Obj00485 *)p)->fC == 0) {
        i = 0;
        ((struct Obj00485 *)p)->fC = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heap);
        ((struct Obj00485 *)p)->f4 = func_02030734(heap, 0x320, 1, (const char *)&sFieldWfbcFileName, 0x39e);
        for (i = 0; i < 10; i++) {
            FIELD_WFBC_PEOPLE_Clear((struct E50 *)((char *)*(int *)&((struct Obj00485 *)p)->f4 + i * 0x50));
        }
        ((struct Obj00485 *)p)->f10 = func_020490F4(0x9a, heap);
        ((struct Obj00485 *)p)->f14 = func_02030734(heap, 0x600, 1, (const char *)&sFieldWfbcFileName, 0x3ab);
        *(int *)&((struct Obj00485 *)p)->f118 = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(((struct Obj00485 *)p)->fC, ((struct Obj00485 *)p)->f0, heap);
    }
}
