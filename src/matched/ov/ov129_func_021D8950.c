/*
 * function: WF2DMAP_SCENE_SetSlot
 * address: 0x021D8950
 * packet: pkt_ov129_021D8950
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj01937.h"

void WF2DMAP_SCENE_SetSlot(char *p,int v)  {
    ((struct Obj01937 *)p)->f244=((struct Obj01937 *)p)->f240;
    ((struct Obj01937 *)p)->f240=v;
    ((struct Obj01937 *)p)->f248=0;
    ((struct Obj01937 *)p)->f24C=0;
    ((struct Obj01937 *)p)->f250=0;
    ((struct Obj01937 *)p)->f254=0;
    if(v)  {
        ((struct Obj01937 *)p)->f248=*(unsigned short *)(p+(v-1)*4+0x21c);
        ((struct Obj01937 *)p)->f24C=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
    if(((struct Obj01937 *)p)->f244)  {
        v=((struct Obj01937 *)p)->f244;
        ((struct Obj01937 *)p)->f250=*(unsigned short *)(p+(v-1)*4+0x21c);
        ((struct Obj01937 *)p)->f254=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
}
