/*
 * function: func_021FAC74
 * address: 0x021FAC74
 * packet: pkt_ov132_021FAC74
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0201121C 0x0201121C thumb
 *   func_0201126C 0x0201126C thumb
 *   func_0201127C 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 */
#include "../include/Obj01157.h"
#include "../include/Obj23236.h"
#include "../include/Obj23237.h"
#include "../include/Obj23238.h"
#include "../include/Obj23239.h"
#include "../include/Obj23240.h"
#include "../include/Obj23241.h"
#include "../include/Obj23242.h"
#include "../include/Obj23243.h"
#include "../include/Obj23245.h"
#include "../include/Obj23246.h"
#include "../include/Obj23247.h"
#include "../include/Obj23248.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDCEC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct ScriptVm;
struct ScriptVmParams;
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
struct ScriptVm;
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern char d_021FDC2C[];
void *func_021FAC74(char *p, void *arg, int flag)
{
    u8 i;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) == 0) break;
    ((char **)(p + 0xc))[i] = func_02030734(((struct Obj01157 *)p)->f0, 0x1c, 0, d_021FDCEC, 0xc4);
    ((struct Obj23236 *)(((char **)(p + 0xc))[i]))->f8 = arg;
    ((struct Obj23237 *)(((char **)(p + 0xc))[i]))->fC = 0;
    ((struct Obj23238 *)(((char **)(p + 0xc))[i]))->f14 = 0;
    ((struct Obj23239 *)(((char **)(p + 0xc))[i]))->f10 = 0;
    ((struct Obj23240 *)(((char **)(p + 0xc))[i]))->f16 = 0;
    ((struct Obj23241 *)(((char **)(p + 0xc))[i]))->f18 = 0;
    ((struct Obj23242 *)(((char **)(p + 0xc))[i]))->f19 = i;
    if (flag == 1) ((struct Obj23243 *)(((char **)(p + 0xc))[i]))->f16 |= 2;
    *(char **)((char **)(p + 0xc))[i] = p;
    ((struct Obj23245 *)(((char **)(p + 0xc))[i]))->f4 = func_0201121C(((struct Obj01157 *)p)->f0, (const struct ScriptVmParams *)d_021FDC2C);
    func_0201126C(((struct Obj23246 *)(((char **)(p + 0xc))[i]))->f4, ((char **)(p + 0xc))[i]);
    func_0201127C(((struct Obj23247 *)(((char **)(p + 0xc))[i]))->f4, ((struct Obj23248 *)(((char **)(p + 0xc))[i]))->f8);
    return ((char **)(p + 0xc))[i];
}
