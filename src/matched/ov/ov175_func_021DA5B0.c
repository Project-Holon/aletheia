/*
 * function: func_021DA5B0
 * address:  0x021DA5B0
 * packet:   pkt_021DA5B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DB228  0x021DB228  thumb
 *   func_021DB218  0x021DB218  thumb
 *   func_021DB248  0x021DB248  thumb
 *   func_021DB238  0x021DB238  thumb
 *   func_021DB160  0x021DB160  thumb
 *   func_021DAFB8  0x021DAFB8  thumb
 *   func_02034714  0x02034714  arm
 *   func_0203D378  0x0203D378  arm
 *   d_021E2EF8     0x021E2EF8  data
 *
 * Arms a storage-server report: resets the report state words, stores mode and the result slot, and picks the report callback at +0x158 from mode (0: plain, 1 with a result slot, or 1 without one, which also stores a3 and the two record words) and kind (0 or 2; anything else asserts).
 */
#include "../include/Obj01069.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef int (*ReportFn)(u32 *ctx);

extern int func_021DB228(u32 *ctx);
extern int func_021DB218(u32 *ctx);
extern int func_021DB248(u32 *ctx);
extern int func_021DB238(u32 *ctx);
extern void func_021DB160(int *ctx, int *input, int invert);
extern void func_021DAFB8(int *ctx, const u32 *record, int invert);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0203D378(void);
extern const char d_021E2EF8[];

void func_021DA5B0(char *obj, int mode, int kind, u32 a3, u32 *rec, u32 slot)
{
    ((struct Obj01069 *)obj)->f1494 = 0;
    ((struct Obj01069 *)obj)->f12C = 0;
    ((struct Obj01069 *)obj)->f1A8 = 1;
    ((struct Obj01069 *)obj)->f14C = 0;
    ((struct Obj01069 *)obj)->f138 = 0;
    ((struct Obj01069 *)obj)->f1AC = mode;
    ((struct Obj01069 *)obj)->f160 = slot;
    ((struct Obj01069 *)obj)->f164 = 0;
    ((struct Obj01069 *)obj)->f168 = 0;
    ((struct Obj01069 *)obj)->f16C = 0;
    if (mode == 0) {
        switch (kind) {
        case 0:
            *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB228;
            break;
        case 2:
            *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB218;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    } else if (mode == 1) {
        if (slot != 0) {
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB248;
                break;
            case 2:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB238;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        } else {
            func_0203D378();
            ((struct Obj01069 *)obj)->f180 = a3;
            ((struct Obj01069 *)obj)->f184 = rec[0];
            ((struct Obj01069 *)obj)->f188 = rec[4];
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = (ReportFn)func_021DB160;
                break;
            case 2:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = (ReportFn)func_021DAFB8;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
    }
}
