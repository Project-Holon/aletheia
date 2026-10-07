/*
 * file:     fldmmdl_p22.c
 * unit:     yes
 * function: func_0216D63C, func_0216D65C, func_0216D660, func_0216D668, func_0216D66C
 * address:  0x0216D63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj17809.h"
#include "../../matched/include/Obj17810.h"
#include "../../matched/include/Obj17811.h"
#include "../../matched/include/Obj17812.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

int func_0216D63C(char *a0, int a1);
void func_0216D65C(void *p, u16 v);
int func_0216D660(void *p);
void func_0216D668(void *p, u16 v);
int func_0216D66C(void *p);


/*
 * Recursive MATCH unblocker: dependency of func_0217C294 (ov018 tail-call
 * thunk), which unblocks func_0216AC90 and func_0216ACCC.
 */
int func_0216D63C(char *a0, int a1)
{
    switch (a1) {
    case 0:
        return ((struct Obj00113 *)a0)->f20;
    case 1:
        return ((struct Obj00113 *)a0)->f22;
    case 2:
        return ((struct Obj00113 *)a0)->f24;
    default:
        return 0;
    }
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D65C.c \
 *       --func func_0216D65C --addr 0x0216D65C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D65C(void *p, u16 v) { ((struct Obj17809 *)p)->f2C = v; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D660.c \
 *       --func func_0216D660 --addr 0x0216D660 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D660(void *p) { return ((struct Obj17810 *)p)->f2C; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D668.c \
 *       --func func_0216D668 --addr 0x0216D668 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D668(void *p, u16 v) { ((struct Obj17811 *)p)->f2E = v; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D66C.c \
 *       --func func_0216D66C --addr 0x0216D66C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D66C(void *p) { return ((struct Obj17812 *)p)->f2E; }
