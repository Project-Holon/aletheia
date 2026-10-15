/*
 * function: MYSTERY_NET_Create
 * address: 0x021DE2A0
 * packet: pkt_ov121_021DE2A0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_NET_InitTask 0x021DEE68 thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 *   d_021DFBC0 0x021DFBC0 data ov121 a1
 */
#include "../include/Obj13959.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void MYSTERY_NET_InitTask(void *,int,void *);
extern void MYSTERY_NET_NoopHandler(void);
extern const char d_021DFBC0[];
void *MYSTERY_NET_Create(void *arg,int heap)
{
    char *p;
    p=func_02030734(heap,0x17a8,0,d_021DFBC0,315);
    MI_CpuFill8(p,0,0x17a8);
    ((struct Obj13959 *)p)->f58=heap;
    ((struct Obj13959 *)p)->f794=arg;
    MYSTERY_NET_InitTask(p,(int)p,MYSTERY_NET_NoopHandler);
    return p;
}
