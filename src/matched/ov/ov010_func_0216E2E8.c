/*
 * function: FLDMMDL_LoadObjCodeParam
 * address: 0x0216E2E8
 * packet: pkt_ov010_0216E2E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Direct halfword-aligned 28-byte Record assignments restore ctx=r5/id=r4/out=r6.
 * A named u16 offset and const context parameter restore the last stack store.
 * symbols:
 * FLDMMDL_SysSearchUseMmdl 0x0216DD1C thumb ov010
 * FLDMMDL_GetObjCode 0x0216D598 thumb ov010
 * func_0200F128 0x0200F128 thumb
 * ARC_TOOL_ReadHandleMemberRange 0x0204944C arm
 */
#include "../include/Obj12405.h"
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 FLDMMDL_GetObjCode(void *p);
extern u32 func_0200F128(u32 id);
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);

typedef struct Record { u16 fields[14]; } Record;

void FLDMMDL_LoadObjCodeParam(const char *ctx, u32 id, Record *out)
{
    u16 offset;
    int i;
    u32 j;
    u16 n;
    u16 *tbl;
    u32 iter;
    void *rec;

    tbl = *(u16 * *)&((struct Obj12405 *)ctx)->f44;
    n = tbl[0];

    if (n < 0x1a) {
        u16 k = ((n + 1) / 2) * 2;
        char *recs = (char *)tbl + (k + 2) * 2;
        for (i = 0; i < n; i++) {
            if (id == tbl[i + 1]) {
                u16 *src = (u16 *)(recs + i * 0x1c);
                *out = *(Record *)src;
                return;
            }
        }
    }
    iter = 0;
    if (FLDMMDL_SysSearchUseMmdl((void *)ctx, (struct Rec **)(&rec), &iter)) {
        do {
            if (id == FLDMMDL_GetObjCode(rec)) {
                u16 *src = (u16 *)((char *)rec + 0xe4);
                *out = *(Record *)src;
                return;
            }
        } while (FLDMMDL_SysSearchUseMmdl((void *)ctx, (struct Rec **)(&rec), &iter));
    }
    offset = func_0200F128(id) * 0x1c + 4;
    ARC_TOOL_ReadHandleMemberRange(((struct Obj12405 *)ctx)->f14, 0, offset, 0x1c, out);
}
