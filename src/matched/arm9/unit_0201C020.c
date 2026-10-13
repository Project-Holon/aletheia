/*
 * unit:     yes
 * address:  0x0201C020
 * packet:   pkt_0201BD28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WAZA_TOOL_GetRankEffectCount, WAZA_TOOL_GetRankEffect
 *
 * waza_tool.c: two more readers over a move record, each with its own copy of
 * the cache lookup src/matched/unit_0201BD28.c and
 * src/matched/unit_0201C1F4.c also carry.  WAZA_TOOL_GetRankEffectCount counts how many of
 * the three bytes at +0x15 are set; WAZA_TOOL_GetRankEffect hands one of the three
 * signed bytes at +0x18 back through an out-parameter, or zero when the
 * matching +0x15 byte is clear.
 *
 * The +0x18 read is a `movs`/`ldrsb` register-offset pair because the index
 * is a run-time value and Thumb has no immediate-offset `ldrsb`, which is
 * also the only evidence that the field is signed where its +0x15 neighbour
 * is not (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * symbols:
 *   _pWazaTool   0x02146530  data
 *   _WazaTempData  0x02146534  data
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C020.c  *       --addr 0x0201C020 --thumb
 */

#include "../include/G_WazaTool.h"

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Waza {
    u8  unk00[0x15];
    u8  unk15[3];
    s8  unk18[3];
};

extern struct WazaTool *_pWazaTool;
extern struct Waza _WazaTempData;

extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

u8 WAZA_TOOL_GetRankEffectCount(u16 id)
{
    struct Waza *rec;
    s32 i;
    u32 k;
    u32 n;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (((u16 *)_pWazaTool->vals)[i] == 0) {
                ((u16 *)_pWazaTool->vals)[i] = id;
                ARC_TOOL_ReadMember(_pWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == ((u16 *)_pWazaTool->vals)[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            ((u16 *)_pWazaTool->vals)[i] = id;
            ARC_TOOL_ReadMember(_pWazaTool->recs[i], 0x15, id);
        }
        rec = _pWazaTool->recs[i];
    } else {
        rec = &_WazaTempData;
        ARC_TOOL_ReadMember(rec, 0x15, id);
    }
    n = 0;
    for (k = 0; k < 3; k++) {
        if (rec->unk15[k] != 0) {
            n++;
        }
    }
    return (u8)n;
}

u8 WAZA_TOOL_GetRankEffect(u16 id, u32 idx, s32 *out)
{
    struct Waza *rec;
    s32 i;
    u8 v;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            if (((u16 *)_pWazaTool->vals)[i] == 0) {
                ((u16 *)_pWazaTool->vals)[i] = id;
                ARC_TOOL_ReadMember(_pWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == ((u16 *)_pWazaTool->vals)[i]) {
                break;
            }
        }
        if (i == _pWazaTool->count) {
            i--;
            ((u16 *)_pWazaTool->vals)[i] = id;
            ARC_TOOL_ReadMember(_pWazaTool->recs[i], 0x15, id);
        }
        rec = _pWazaTool->recs[i];
    } else {
        rec = &_WazaTempData;
        ARC_TOOL_ReadMember(rec, 0x15, id);
    }
    v = rec->unk15[idx];
    if (v != 0) {
        *out = rec->unk18[idx];
    } else {
        *out = 0;
    }
    return v;
}
