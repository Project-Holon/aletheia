/*
 * packet: pkt_ov186_021FFA98
 * function: func_021FFA98, func_021FFACC, func_021FFAD8, func_021FFAE4, func_021FFAF0, func_021FFAFC, func_021FFB08
 * unit: yes
 * address: 0x021FFA98
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6A08 0x021D6A08 thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 */
#include "../include/Obj14483.h"
#include "../include/Obj24867.h"
#include "../include/Obj24868.h"
#include "../include/Obj24869.h"
#include "../include/Obj24870.h"
#include "../include/Obj24871.h"
#include "../include/Obj24872.h"
typedef unsigned int   u32;
extern int func_021D6A08(char *p, int a, int b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021FFB68(char *, int);
extern void func_021FF8E4(void *, int, int);
extern const char d_02200D98[];
void func_021FFA98(char *p, int unused, char *q)
{
    if (!func_021D6A08(q, ((struct Obj14483 *)q)->f5B0, ((struct Obj14483 *)q)->f5B4))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}
void func_021FFACC(char *p) { ((struct Obj24867 *)p)->f5B8 = 1; }
void func_021FFAD8(char *p) { ((struct Obj24868 *)p)->f5BC = 1; }
void func_021FFAE4(char *p) { ((struct Obj24869 *)p)->f5C0 = 1; }
void func_021FFAF0(char *p) { ((struct Obj24870 *)p)->f5C8 = 1; }
void func_021FFAFC(char *p) { ((struct Obj24871 *)p)->f5C4 = 1; }
void func_021FFB08(char *p) { ((struct Obj24872 *)p)->f5D8 = 1; }
