/*
 * function: func_0221336C
 * address: 0x0221336C
 * packet: pkt_ov199_0221336C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   d_02213D04 0x02213D04 data ov199 a1
 */
#include "../include/Obj08373.h"
extern int POKE_REGULATION_GetDataSize(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned int);
extern const char d_02213D04[];
void func_0221336C(char *p, int heap)
{
    int size;
    ((struct Obj08373 *)p)->f28 = func_02030734(heap, POKE_REGULATION_GetDataSize() + 0xd4, 0, d_02213D04, 0x72d);
    size = POKE_REGULATION_GetDataSize() + 0xd4;
    func_02082BCC(((struct Obj08373 *)p)->f28, 0, size);
    ((struct Obj08373 *)p)->f2C = func_02030734(heap, POKE_REGULATION_GetDataSize() + 0xd4, 0, d_02213D04, 0x72f);
    size = POKE_REGULATION_GetDataSize() + 0xd4;
    func_02082BCC(((struct Obj08373 *)p)->f2C, 0, size);
}
