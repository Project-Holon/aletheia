/*
 * unit:     yes
 * function: ISS_SYS_GetLocation, ISS_SYS_GetZoneId, ISS_SYS_GetCurrentBgmId
 * address:  0x0202B7F8
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three iss_3ds_sys.c tail-call units that resolve without any further
 * work: ISS_SYS_GetLocation forwards the +4 field to GAME_DATA_GetMyPlayerWork,
 * ISS_SYS_GetZoneId chains it into GAME_DATA_GetPlayerZoneId, and ISS_SYS_GetCurrentBgmId is a bare
 * thunk to GFL_USE_GetBgmNo.  All three are named in the `function:` field
 * above so that the `matched` class attests all three addresses: the 32
 * bytes laid out by `tu` cover all three entry points, and
 * src/pending/ISS_SYS_EnterZone.c needs 0x0202B804 as a witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B7F8.c \
 *       --addr 0x0202B7F8 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 */
#include "../include/Obj17267.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
struct SaveBlock;
struct Rec44;

extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
typedef unsigned short u16;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u16 GFL_USE_GetBgmNo(void);

void *ISS_SYS_GetLocation(struct Obj *o)
{
    return GAME_DATA_GetMyPlayerWork((struct SaveBlock *)((struct Obj17267 *)o)->f4);
}

u16 ISS_SYS_GetZoneId(struct Obj *o)
{
    return GAME_DATA_GetPlayerZoneId(ISS_SYS_GetLocation(o));
}

u32 ISS_SYS_GetCurrentBgmId(void)
{
    return GFL_USE_GetBgmNo();
}
