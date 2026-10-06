/*
 * function: func_0220D6DC
 * address: 0x0220D6DC
 * packet: pkt_ov197_0220D6DC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * caller-width: constructor heap parameter is u16 because caller truncates before blx.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021640 0x02021640 thumb
 */
#include "../include/Obj02914.h"
#include "../include/Obj25103.h"
#include "../include/Obj25104.h"
#include "../include/Obj25105.h"
#include "../include/Obj25106.h"
#include "../include/Obj25107.h"
#include "../include/Obj25108.h"
#include "../include/Obj25109.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049238(void *);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
extern void func_02021640(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16);
void func_0220D6DC(char *p)
{
    void *handle = func_020490F4(99,(u16)((((struct Obj25103 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC & 0x7fff) | 0x8000));
    func_02049658(handle, 0, 6, 0, 0, 1, ((struct Obj25104 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020498F4(handle, 3, 6, 0, 0, 1, ((struct Obj25105 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020498F4(handle, 2, 7, 0, 0, 1, ((struct Obj25106 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020216B4(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, (void *)((u32)handle), 1, ((struct Obj25107 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC, 1, 224, 0);
    func_02049238(handle);
    func_0201F5BC(4, 1, 11, 0, ((struct Obj25108 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, 1, 176, 32);
    func_02021640(*(struct PalAnmSlot * *)&((struct Obj02914 *)p)->f8, 23, 5, ((struct Obj25109 *)(*(char * *)&((struct Obj02914 *)p)->f0))->fC, 1, 32, 192);
}
